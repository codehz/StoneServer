
#include "include/ipc2.h"

#include <pthread.h>


struct Complex
{
   // FIXME implement automatic tuple generation for structs
   typedef Tuple<double, double> type;
   
   // you always need the default constructor
   inline
   Complex()
    : re_(0)
    , im_(0)
   {
      // NOOP
   }
   
   // any other constructor may additionally be defined
   inline
   Complex(double re, double im)
    : re_(re)
    , im_(im)
   {
      // NOOP
   }
   
   double re_;
   double im_;
};


INTERFACE(Interface)
{   
   Request<int> add;
   Request<int> sub;
   
   Request<int, int> addBoth;
   Request<int, int, double> addTriple;
   
   Request<> clear;
   
   Request<std::string> display;
   Request<Complex> addComplex;
   
   Response<int> resultOfAdd;
   Response<int> resultOfSub;
   
   Signal<int> sig1;
   Signal<> cleared;

   Attribute<int> myInt;
   
   Request<Tuple<int, double, std::string> > reqt;
     
   inline
   Interface()
    : INIT_REQUEST(add)
    , INIT_REQUEST(sub)
    , INIT_REQUEST(addBoth)
    , INIT_REQUEST(addTriple)
    , INIT_REQUEST(clear)
    , INIT_REQUEST(display)
    , INIT_REQUEST(addComplex)
    , INIT_RESPONSE(resultOfAdd)
    , INIT_RESPONSE(resultOfSub)
    , INIT_SIGNAL(sig1)
    , INIT_SIGNAL(cleared)
    , INIT_ATTRIBUTE(myInt)
    , INIT_REQUEST(reqt)
   {
      add >> resultOfAdd;
      sub >> resultOfSub;
   }
};


struct InterfaceClient : Stub<Interface>
{
   InterfaceClient(const char* role)
    : Stub<Interface>(role, "tcp:127.0.0.1:9978")   // connect the client to 'myserver'
   {
      resultOfAdd >> std::tr1::bind(&InterfaceClient::handleResultAdd, this, _1);
      resultOfSub >> std::tr1::bind(&InterfaceClient::handleResultSub, this, _1);
   }
   
   void handleCleared()
   {
      std::cout << "CPU was cleared..." << std::endl;
   }
   
   void connected()
   {
      // attach to all wanted signals here
      sig1.attach() >> std::tr1::bind(&InterfaceClient::handleSig1, this, _1);
      
      add(42);
   }
   
   void handleResultAdd(int response)
   {
      std::cout << "Response is " << response << std::endl;
      sub(21);
   }
   
   void handleResultSub(int response)
   {
      std::cout << "Response is " << response << std::endl;
      display("Hello World!");
   }
   
   void handleSig1(int data)
   {
      std::cout << "Got signal 'sig1' with data '" << data << "'" << std::endl;
   }
};


struct InterfaceClient2 : Stub<Interface>
{
   InterfaceClient2(const char* role)
    : Stub<Interface>(role, "tcp:127.0.0.1:9978")   // connect the client to 'myserver'
   {
      // NOOP
   }
   
   void connected()
   {
      sig1.attach() >> std::tr1::bind(&InterfaceClient2::handleSig1, this, _1);
   }
   
   void handleSig1(int data)
   {
      std::cout << "IC2: got signal 'sig1' with data '" << data << "'" << std::endl;
      clear();
   }
};


struct InterfaceClient3 : Stub<Interface>
{
   InterfaceClient3(const char* role)
    : Stub<Interface>(role, "tcp:127.0.0.1:9978")   // connect the client to 'myserver'
   {
      // NOOP
   }
   
   void connected()
   {
      cleared.attach() >> std::tr1::bind(&InterfaceClient3::handleCleared, this);
   }
   
   void handleCleared()
   {
      std::cout << "CPU was cleared...stopping..." << std::endl;
      disp().stop();
   }
};


struct InterfaceServer : Skeleton<Interface>
{
   InterfaceServer(const char* role)
    : Skeleton<Interface>(role)
    , result_(0)
   {      
      add >> std::tr1::bind(&InterfaceServer::handleAdd, this, _1);
      sub >> std::tr1::bind(&InterfaceServer::handleSub, this, _1);
      clear >> std::tr1::bind(&InterfaceServer::handleClear, this);
      display >> std::tr1::bind(&InterfaceServer::handleDisplay, this, _1);
      addComplex >> std::tr1::bind(&InterfaceServer::handleAddComplex, this, _1);
   }
   
   void handleAdd(int i)
   {
      result_ += i;
      std::cout << "adding " << i << ", result=" << result_ << std::endl;  
      
      respondWith(resultOfAdd(result_));
   }
   
   void handleSub(int i)
   {
      result_ -= i;
      std::cout << "subtracting " << i << ", result=" << result_ << std::endl;      
      
      ServerRequestDescriptor rq = deferResponse();
      respondOn(rq, resultOfSub(result_));   // rq will be invalidated here-in
      
      sig1.emit(result_);
   }
   
   void handleClear()
   {
      result_ = 0;
      std::cout << "reset, result=" << result_ << std::endl;      
      cleared.emit();
   }
   
   void handleDisplay(const std::string& str)
   {
      std::cout << "Message from client: '" << str << "'" << std::endl;
   }
   
   void handleAddComplex(const Complex& c)
   {
      std::cout << "Got complex number re=" << c.re_ << ", im=" << c.im_ << std::endl;
   }
   
   int result_;
};


void* server(void* dispatcher)
{
   Dispatcher& d = *(Dispatcher*)dispatcher;
   
   InterfaceServer s1("myrole1");
   d.addServer(s1);
   
   InterfaceServer s2("myrole2");
   d.addServer(s2);
   
   d.run();
   return 0;
}


struct CheckMeToo
{
   typedef Tuple<int, std::map<std::string, std::string> > type;
   
   int i;
   std::map<std::string, std::string> s;
};


struct CheckMe
{
   typedef Tuple<int, double, CheckMeToo> type;
   
   int i;
   double d;
   CheckMeToo t;
};


int main()
{
   // start server dispatcher thread on unix path 'myserver'
   Dispatcher server_dispatcher("tcp:127.0.0.1:9978");
   
   pthread_t tid;
   pthread_create(&tid, 0, server, &server_dispatcher);
   while(!server_dispatcher.isRunning());   // wait for other thread
   
   // run client in separate thread (not really necessary, just for blocking interfaces)
   Dispatcher d;
   
   InterfaceClient c1("myrole1");
   d.addClient(c1);
   
   InterfaceClient2 c2("myrole1");
   d.addClient(c2);
   
   InterfaceClient2 c3("myrole2");
   d.addClient(c3);
   
   InterfaceClient3 c4("myrole1");
   d.addClient(c4);

   d.run();
   
   sleep(1);
   
   server_dispatcher.stop();
   pthread_join(tid, 0);
   
   STATIC_CHECK(isValidType<CheckMe>::value, ooops);
   return 0;
}
