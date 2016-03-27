#include "simppl/dispatcher.h"

#include <sys/timerfd.h>
#include <sys/poll.h>

#include <unistd.h>

#include "simppl/detail/util.h"
#include "simppl/timeout.h"
#include "simppl/skeletonbase.h"
#include "simppl/serialization.h"

#define SIMPPL_DISPATCHER_CPP
#include "simppl/serverside.h"
#undef SIMPPL_DISPATCHER_CPP

#define USE_POLL

using namespace std::placeholders;
using namespace std::literals::chrono_literals;


namespace
{

inline
std::chrono::steady_clock::time_point
get_lookup_duetime()
{
   return std::chrono::steady_clock::now() + 5s;
}


struct BlockingResponseHandler0
{
   inline
   BlockingResponseHandler0(simppl::dbus::Dispatcher& disp, simppl::dbus::ClientResponse<>& r)
    : disp_(disp)
    , r_(r)
   {
      r_.handledBy(std::ref(*this));
   }

   inline
   void operator()(const simppl::dbus::CallState& state)
   {
      disp_.stop();
      r_.handledBy(std::nullptr_t());

      if (!state)
         disp_.propagate(state);
   }

   simppl::dbus::Dispatcher& disp_;
   simppl::dbus::ClientResponse<>& r_;
};


DBusHandlerResult signal_filter(DBusConnection* /*connection*/, DBusMessage* msg, void *user_data)
{
    simppl::dbus::Dispatcher* disp = (simppl::dbus::Dispatcher*)user_data;
    return disp->try_handle_signal(msg);
}


short make_poll_events(int flags)
{
    short rc = 0;

    if (flags & DBUS_WATCH_READABLE)
        rc |= POLLIN;
    if (flags & DBUS_WATCH_WRITABLE)
        rc |= POLLOUT;

    return rc;
}


int make_dbus_flags(short events)
{
    int rc = 0;

    if (events & POLLIN)
        rc |= DBUS_WATCH_READABLE;
    if (events & POLLOUT)
        rc |= DBUS_WATCH_WRITABLE;
    if (events & POLLHUP)
        rc |= DBUS_WATCH_HANGUP;
    if (events & POLLERR)
        rc |= DBUS_WATCH_ERROR;

    return rc;
}


}   // namespace


// ---------------------------------------------------------------------------------------


namespace simppl
{

namespace dbus
{

struct Dispatcher::Private
{
    static
    dbus_bool_t add_watch(DBusWatch *watch, void *data)
    {
        return ((simppl::dbus::Dispatcher::Private*)data)->add_watch(watch);
    }

    static
    void remove_watch(DBusWatch *watch, void *data)
    {
        ((simppl::dbus::Dispatcher::Private*)data)->remove_watch(watch);
    }

    static
    void toggle_watch(DBusWatch *watch, void *data)
    {
        ((simppl::dbus::Dispatcher::Private*)data)->toggle_watch(watch);
    }

    static
    dbus_bool_t add_timeout(DBusTimeout *timeout, void *data)
    {
        return ((simppl::dbus::Dispatcher::Private*)data)->add_timeout(timeout);
    }

    static
    void remove_timeout(DBusTimeout *timeout, void *data)
    {
        ((simppl::dbus::Dispatcher::Private*)data)->remove_timeout(timeout);
    }

    static
    void toggle_timeout(DBusTimeout *timeout, void *data)
    {
        ((simppl::dbus::Dispatcher::Private*)data)->toggle_timeout(timeout);
    }


    Private(DBusConnection* conn)
    {
#ifdef USE_POLL
        dbus_connection_set_watch_functions(conn, &add_watch, &remove_watch, &toggle_watch, this, nullptr);
        dbus_connection_set_timeout_functions (conn, &add_timeout, &remove_timeout, &toggle_timeout, this, nullptr);
#endif
    }


    dbus_bool_t add_watch(DBusWatch* w)
    {
        auto iter = std::find_if(fds_.begin(), fds_.end(), [w](auto& pfd){ return dbus_watch_get_unix_fd(w) == pfd.fd; });
        if (iter == fds_.end())
        {
            pollfd fd = { 0 };

            fd.fd = dbus_watch_get_unix_fd(w);

            if (dbus_watch_get_enabled(w))
                fd.events = make_poll_events(dbus_watch_get_flags(w));

            fds_.push_back(fd);

            DBusWatch* rd = 0;
            DBusWatch* wr = 0;

            if (fd.events & POLLIN)
            {
                rd = w;
            }
            else
                wr = w;

            watch_handlers_[fd.fd] = std::make_tuple(rd, wr);
        }
        else
        {
            iter->events |= make_poll_events(dbus_watch_get_flags(w));

            if (dbus_watch_get_flags(w) == DBUS_WATCH_READABLE)
            {
                std::get<0>(watch_handlers_[iter->fd]) = w;
            }
            else
                std::get<1>(watch_handlers_[iter->fd]) = w;
        }

        return TRUE;
    }


    void remove_watch(DBusWatch* w)
    {
        //std::cout << "remove_watch fd=" << dbus_watch_get_unix_fd(w) << std::endl;
        /*auto iter = std::find_if(fds_.begin(), fds_.end(), [w](auto& pfd){ return dbus_watch_get_unix_fd(w) == pfd.fd; });
        if (iter != fds_.end())
        {
            watch_handlers_.erase(iter->fd);
            fds_.erase(iter);
        }*/
    }


    void toggle_watch(DBusWatch* w)
    {
        //std::cout << "toggle_watch fd=" << dbus_watch_get_unix_fd(w) << std::endl;
     /*   auto iter = std::find_if(fds_.begin(), fds_.end(), [w](auto& pfd){ return dbus_watch_get_unix_fd(w) == pfd.fd; });
        if (iter != fds_.end())
        {
            if (dbus_watch_get_enabled(w))
            {
                iter->events = make_poll_events(dbus_watch_get_flags(w));
            }
            else
                iter->events = 0;
        }*/
    }


    dbus_bool_t add_timeout(DBusTimeout* t)
    {
        pollfd fd;
        fd.fd = timerfd_create(CLOCK_MONOTONIC, 0);
        fd.events = POLLIN;

        //std::cout << "add_timeout fd=" << fd.fd << std::endl;

        if (dbus_timeout_get_enabled(t))
        {
            int interval_ms = dbus_timeout_get_interval(t);

            struct itimerspec spec = {
                { interval_ms / 1000, (interval_ms % 1000) * 1000000L },
                { interval_ms / 1000, (interval_ms % 1000) * 1000000L }
            };

            timerfd_settime(fd.fd, 0, &spec, 0);
        }

        dbus_timeout_set_data(t, reinterpret_cast<void*>(fd.fd), 0);

        fds_.push_back(fd);
        tm_handlers_[fd.fd] = t;

        return TRUE;
    }


    void remove_timeout(DBusTimeout* t)
    {
        //std::cout << "remove_timeout fd=" << reinterpret_cast<int>(dbus_timeout_get_data(t)) << std::endl;
        auto iter = std::find_if(fds_.begin(), fds_.end(), [t](auto& pfd){ return reinterpret_cast<int64_t>(dbus_timeout_get_data(t)) == pfd.fd; });
        if (iter != fds_.end())
        {
            tm_handlers_.erase(iter->fd);
            ::close(iter->fd);

            fds_.erase(iter);
        }
    }


    void toggle_timeout(DBusTimeout* t)
    {
        //std::cout << "toggle_timeout" << std::endl;
        auto iter = std::find_if(fds_.begin(), fds_.end(), [t](auto& pfd){ return reinterpret_cast<int64_t>(dbus_timeout_get_data(t)) == pfd.fd; });
        if (iter != fds_.end())
        {
            if (dbus_timeout_get_enabled(t))
            {
                int interval_ms = dbus_timeout_get_interval(t);

                struct itimerspec spec = {
                    { interval_ms / 1000, (interval_ms % 1000) * 1000000L },
                    { interval_ms / 1000, (interval_ms % 1000) * 1000000L }
                };

                timerfd_settime(iter->fd, 0, &spec, 0);
            }
            else
                timerfd_settime(iter->fd, 0, 0, 0);
        }
    }


    int poll(int timeout)
    {
        //std::cout << "poll" << std::endl;
        if (::poll(&fds_[0], fds_.size(), timeout) > 0)
        {
            for(auto& pfd : fds_)
            {
                if (pfd.revents)
                {
                    auto iter = watch_handlers_.find(pfd.fd);

                    if (iter != watch_handlers_.end())
                    {
                        int fd = pfd.fd;

                        //std::cout << "handle watch" << std::endl;
                        if (pfd.revents & POLLIN)
                            dbus_watch_handle(std::get<0>(iter->second), make_dbus_flags(pfd.revents));
                        else
                            dbus_watch_handle(std::get<1>(iter->second), make_dbus_flags(pfd.revents));
                    }
                    else
                    {
                        auto t_iter = tm_handlers_.find(pfd.fd);

                        if (t_iter != tm_handlers_.end())
                        {
                            int64_t data;
                            (void)::read(pfd.fd, &data, sizeof(data));

//                            std::cout << "handle timeout" << std::endl;
                            dbus_timeout_handle(t_iter->second);
                        }
                    }

                    break;
                }
            }
        }

        return 0;
    }


    std::vector<pollfd> fds_;

    std::map<int, std::tuple<DBusWatch*, DBusWatch*>> watch_handlers_;
    std::map<int, DBusTimeout*> tm_handlers_;
};


DBusObjectPathVTable stub_v_table = { nullptr, &SkeletonBase::method_handler, nullptr, nullptr, nullptr, nullptr };


Dispatcher::Dispatcher(const char* busname)
 : running_(false)
 , conn_(nullptr)
 , request_timeout_(DBUS_TIMEOUT_USE_DEFAULT)
 , d(nullptr)
{
   // FIXME make this part of the dispatcher interface...
   dbus_threads_init_default();

   DBusError err;
   dbus_error_init(&err);

   assert(!busname || !strncmp(busname, "dbus:", 5));

   if (!busname || !strcmp(busname, "dbus:session"))
   {
      conn_ = dbus_bus_get_private(DBUS_BUS_SESSION, &err);
   }
   else
      conn_ = dbus_bus_get_private(DBUS_BUS_SYSTEM, &err);

   assert(!dbus_error_is_set(&err));
   dbus_error_free(&err);

   dbus_connection_add_filter(conn_, &signal_filter, this, 0);

   // register for busname change notifications
   // response is (name, old, new)
   dbus_error_init(&err);
   dbus_bus_add_match(conn_, "type='signal',interface='org.freedesktop.DBus',member='NameOwnerChanged',path='/org/freedesktop/DBus',sender='org.freedesktop.DBus'", &err);
   assert(!dbus_error_is_set(&err));
   dbus_error_free(&err);

   dbus_error_init(&err);
   std::ostringstream match_string;
   match_string
       << "type='signal',interface='org.simppl.dispatcher',member='notify_client',path='/org/simppl/dispatcher/" << ::getpid() << '/' << this << "'";

   dbus_bus_add_match(conn_, match_string.str().c_str(), &err);
   assert(!dbus_error_is_set(&err));
   dbus_error_free(&err);

   // call ListNames to get list of available services on the bus
   DBusMessage* msg = dbus_message_new_method_call("org.freedesktop.DBus", "/org/freedesktop/DBus", "org.freedesktop.DBus", "ListNames");

   dbus_error_init(&err);
   DBusMessage* reply = dbus_connection_send_with_reply_and_block(conn_, msg, 1000, &err);
   assert(reply);
   dbus_error_free(&err);

   std::vector<std::string> busnames;

   detail::Deserializer ds(reply);
   ds >> busnames;

   for(auto& busname : busnames)
   {
      if (busname[0] != ':')
         this->busnames_.insert(busname);
   }

   dbus_message_unref(msg);
   dbus_message_unref(reply);

   d = new Dispatcher::Private(conn_);
}


Dispatcher::~Dispatcher()
{
   dbus_connection_close(conn_);
   dbus_connection_unref(conn_);

   delete d;
   d = 0;
}


void Dispatcher::notify_clients(const std::string& boundname, ConnectionState state)
{
   auto range = stubs_.equal_range(boundname);

   std::for_each(range.first, range.second, [state](auto& entry){
      entry.second->connection_state_changed(state);
   });
}


void Dispatcher::addServer(SkeletonBase& serv)
{
   DBusError err;
   dbus_error_init(&err);

   std::ostringstream busname;
   busname << serv.iface() << '.' << serv.role();

   dbus_bus_request_name(conn_, busname.str().c_str(), DBUS_NAME_FLAG_REPLACE_EXISTING, &err);
   assert(!dbus_error_is_set(&err));

   dbus_error_free(&err);

   // isn't this double the information?
   dynamic_cast<detail::BasicInterface*>(&serv)->conn_ = conn_;

   // register same path as busname, just with / instead of .
   dbus_connection_register_object_path(conn_, serv.objectpath(), &stub_v_table, &serv);

   serv.disp_ = this;
}


void Dispatcher::registerSignal(StubBase& stub, ClientSignalBase& sigbase)
{
   DBusError err;
   dbus_error_init(&err);

   std::string signalname(stub.boundname() + "." + sigbase.name());

   auto iter = signal_matches_.find(signalname);

   if (iter == signal_matches_.end())
   {
       // FIXME do we really need dependency to dispatcher?
       std::ostringstream match_string;
       match_string << "type='signal'";
       match_string << ",sender='" << stub.boundname() << "'";
       match_string << ",interface='" << stub.iface() << "'";
       match_string << ",member='" << sigbase.name() << "'";

       dbus_bus_add_match(conn_, match_string.str().c_str(), &err);
       assert(!dbus_error_is_set(&err));

       dbus_error_free(&err);

       signal_matches_[signalname] = 1;
   }
   else
       ++iter->second;
}


void Dispatcher::unregisterSignal(StubBase& stub, ClientSignalBase& sigbase)
{
    std::string signalname(stub.boundname() + "." + sigbase.name());

    auto iter = signal_matches_.find(signalname);

    if (iter != signal_matches_.end())
    {
        if (--iter->second == 0)
        {
            DBusError err;
            dbus_error_init(&err);

            std::ostringstream match_string;
            match_string << "type='signal'";
            match_string << ", sender='" << stub.boundname() << "'";
            match_string << ", interface='" << stub.iface() << "'";
            match_string << ", member='" << sigbase.name() << "'";

            dbus_bus_remove_match(conn_, match_string.str().c_str(), &err);
            assert(!dbus_error_is_set(&err));

            dbus_error_free(&err);

            signal_matches_.erase(iter);
        }
    }
}


DBusHandlerResult Dispatcher::try_handle_signal(DBusMessage* msg)
{
    if (dbus_message_get_type(msg) == DBUS_MESSAGE_TYPE_SIGNAL)
    {
        //std::cout << this << ": having signal '" << dbus_message_get_member(msg) << "'" << std::endl;

        if (!strcmp(dbus_message_get_member(msg), "notify_client"))
        {
           std::string busname;

           detail::Deserializer ds(msg);
           ds >> busname;

           if (busnames_.find(busname) != busnames_.end())
            notify_clients(busname, ConnectionState::Connected);
        }
        else if (!strcmp(dbus_message_get_member(msg), "NameOwnerChanged"))
        {
           // bus name, not interface

           std::string bus_name;
           std::string old_name;
           std::string new_name;

           detail::Deserializer ds(msg);
           ds >> bus_name >> old_name >> new_name;

           if (bus_name[0] != ':')
           {
               if (old_name.empty())
               {
                   busnames_.insert(bus_name);
                   notify_clients(bus_name, ConnectionState::Connected);
               }
               else if (new_name.empty())
               {
                   busnames_.erase(bus_name);
                   notify_clients(bus_name, ConnectionState::Disconnected);
               }
           }

           return DBUS_HANDLER_RESULT_HANDLED;
        }

        // ordinary signals...

        // here we expect that pathname is the same as busname, just with / instead of .
        char originator[256];
        strncpy(originator, dbus_message_get_path(msg)+1, sizeof(originator));
        originator[sizeof(originator)-1] = '\0';

        char* p = originator;
        while(*++p)
        {
           if (*p == '/')
              *p = '.';
        }

        auto range = stubs_.equal_range(originator);

        std::for_each(range.first, range.second, [msg](auto& entry){
            entry.second->try_handle_signal(msg);
        });

        return DBUS_HANDLER_RESULT_HANDLED;
    }

    return DBUS_HANDLER_RESULT_NOT_YET_HANDLED;
}


void Dispatcher::waitForResponse(const detail::ClientResponseHolder& resp)
{
   assert(resp.r_);
   assert(!isRunning());

   ClientResponse<>* r = safe_cast<ClientResponse<>*>(resp.r_);
   assert(r);

   BlockingResponseHandler0 handler(*this, *r);
   loop();
}


void Dispatcher::stop()
{
   running_.store(false);
}


bool Dispatcher::isRunning() const
{
   return running_.load();
}


void Dispatcher::addClient(StubBase& clnt)
{
   assert(!clnt.disp_);   // don't add it twice

   clnt.disp_ = this;

   // isn't this double the information?
   dynamic_cast<detail::BasicInterface*>(&clnt)->conn_ = conn_;

//   std::cout << "Adding stub: " << clnt.boundname() << std::endl;
   stubs_.insert(std::make_pair(clnt.boundname(), &clnt));

   // send connected request from event loop
   auto iter = busnames_.find(clnt.boundname());
   if (iter != busnames_.end())
   {
      std::ostringstream objpath;
      objpath << "/org/simppl/dispatcher/" << ::getpid() << '/' << this;

      DBusMessage* msg = dbus_message_new_signal(objpath.str().c_str(), "org.simppl.dispatcher", "notify_client");

      detail::Serializer s(msg);
      serialize(s, clnt.boundname());

      dbus_connection_send(conn_, msg, nullptr);
      dbus_message_unref(msg);
   }
}


void Dispatcher::removeClient(StubBase& clnt)
{
   for(auto iter = stubs_.begin(); iter != stubs_.end(); ++iter)
   {
      if (&clnt == iter->second)
      {
         clnt.cleanup();

         stubs_.erase(iter);
         break;
      }
   }
}


void Dispatcher::loop()
{
   run();
}


int Dispatcher::step_ms(int timeout_ms)
{
#ifdef USE_POLL
    d->poll(timeout_ms);

    int rc;
    do
    {
       rc = dbus_connection_dispatch(conn_);

       if (!exceptions_.empty())
       {
          CallState st(std::move(exceptions_.front()));
          exceptions_.pop();

          st.throw_exception();
       }
    }
    while(rc != DBUS_DISPATCH_COMPLETE);
#else
    dbus_connection_read_write_dispatch(conn_, 100);
#endif

   return 0;
}


void Dispatcher::propagate(const CallState& st)
{
   exceptions_.push(st);
}


int Dispatcher::run()
{
   running_.store(true);

   while(running_.load())
   {
       step_ms(100);
   }
}

}   // namespace dbus

}   // namespace simppl