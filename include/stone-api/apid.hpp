#pragma once

#include <apid.h>
#include <cstring>
#include <functional>
#include <string>
#include <type_traits>

namespace api {

template <typename F> inline F *copy_function(F f) {
  if constexpr (std::is_function_v<F>)
    return &f;
  else
    return new F(f);
}

struct Empty {};

struct Buffer {
  inline static constexpr char ZERO[1] = { 0 };
  char *data;
  operator char const *() { return data; }
  static inline Buffer buildKeyEvent(std::string const &service, std::string const &name, std::string const &event) {
    char *ret;
    asprintf(&ret, "%s:%s!%s", service.data(), name.data(), event.data());
    return { ret };
  }
  static inline Buffer buildKeyName(std::string const &service, std::string const &name) {
    char *ret;
    asprintf(&ret, "%s:%s", service.data(), name.data());
    return { ret };
  }
  static inline Buffer copy(std::string const &content) {
    char *ret = strdup(content.data());
    return { ret };
  }
  Buffer(char *data)
      : data(data) {}
  Buffer(Buffer &&rhs)
      : data(rhs.data) {
    rhs.data = nullptr;
  }
  Buffer(Buffer const &) = delete;
  ~Buffer() {
    if (data && data != ZERO) delete[] data;
  }
};

template <typename T> struct Serializble {
  static inline auto write(T const &input) { return T::write(input); }
  static inline T read(char const *input) { return T::read(input); }
};

template <> struct Serializble<Empty> {
  static inline char const *write(Empty const &) { return Buffer::ZERO; }
  static inline Empty read(char const *) { return {}; }
};

template <> struct Serializble<std::string> {
  static inline Buffer write(std::string const &input) {
    size_t n;
    char *buffer = new char[n = input.length() + 1];
    strncpy(buffer, input.c_str(), n);
    return { buffer };
  }
  static inline std::string read(char const *input) { return input; }
};

struct Named {
  std::string name;
  inline Named(std::string const &name)
      : name(name) {}
};

template <typename Side> struct ProxiedService : Side::proxied_service {
  ProxiedService(std::string const &name)
      : Side::proxied_service(name) {}
};
template <typename Side, typename T> struct ProxiedAction : Side::template proxied_action<T> {
  ProxiedAction(std::string const &name)
      : Side::template proxied_action<T>(name) {}
};
template <typename Side, typename T, typename R> struct ProxiedMethod : Side::template proxied_method<T, R> {
  ProxiedMethod(std::string const &name)
      : Side::template proxied_method<T, R>(name) {}
};
template <typename Side, typename T> struct ProxiedProperty : Side::template proxied_property<T> {
  ProxiedProperty(std::string const &name)
      : Side::template proxied_property<T>(name) {}
};
template <typename Side, typename T> struct ProxiedBoardcast : Side::template proxied_broadcast<T> {
  ProxiedBoardcast(std::string const &name)
      : Side::template proxied_broadcast<T>(name) {}
};
template <typename Side, typename T> struct ProxiedPatternBoardcast : Side::template proxied_pattern_broadcast<T> {
  ProxiedPatternBoardcast(std::string const &name)
      : Side::template proxied_pattern_broadcast<T>(name) {}
};
template <typename Side, typename T> struct ProxiedSet : Side::template proxied_set<T> {
  ProxiedSet(std::string const &name)
      : Side::template proxied_set<T>(name) {}
};
template <typename Side, typename K, typename V> struct ProxiedHash : Side::template proxied_hash<K, V> {
  ProxiedHash(std::string const &name)
      : Side::template proxied_hash<K, V>(name) {}
};

template <typename T, typename ServiceRef> class CommonSet : public Named, public ServiceRef {
  template <typename F> static void iterate_stub(bool done, char const *data, void *privdata) {
    F *f = (F *)privdata;
    (*f)(done, done ? T{} : Serializble<T>::read(data));
    if constexpr (!std::is_function_v<F>)
      if (done) delete f;
  }
  template <typename F> static void contains_stub(bool value, void *privdata) {
    F *f = (F *)privdata;
    (*f)(value);
    if constexpr (!std::is_function_v<F>) delete f;
  }

  template <typename F> static void on_clear_stub(char const *data, void *privdata) {
    F *f = (F *)privdata;
    (*f)();
  }

  template <typename F> static void events_stub(char const *data, void *privdata) {
    F *f = (F *)privdata;
    (*f)(Serializble<T>::read(data));
  }

  template <typename F> static void fproxy(long long number, void *privdata) {
    F *f = (F *)privdata;
    if (number) (*f)();
    if constexpr (!std::is_function_v<F>) delete f;
  }

public:
  inline CommonSet(std::string const &name)
      : Named(name) {}

  inline void clear [[gnu::artificial]] () {
    apid_publish(Buffer::buildKeyEvent(this->service->name, name, "clear"), "");
    apid_set_clear(nullptr, nullptr, Buffer::buildKeyName(this->service->name, name));
  }
  template <typename F> inline void on_clear(F f) {
    apid_subscribe(on_clear_stub<F>, copy_function(f), Buffer::buildKeyEvent(this->service->name, name, "clear"));
  }
  inline void operator+= [[gnu::artificial]](T const &input) {
    auto f = [=] { apid_publish(Buffer::buildKeyEvent(this->service->name, name, "add"), Serializble<T>::write(input)); };
    apid_set_add(&fproxy<decltype(f)>, copy_function(f), Buffer::buildKeyName(this->service->name, name), Serializble<T>::write(input));
  }
  template <typename F> inline void on_add(F f) {
    apid_subscribe(events_stub<F>, copy_function(f), Buffer::buildKeyEvent(this->service->name, name, "add"));
  }
  inline void operator-= [[gnu::artificial]](T const &input) {
    auto f = [=] { apid_publish(Buffer::buildKeyEvent(this->service->name, name, "remove"), Serializble<T>::write(input)); };
    apid_set_remove(&fproxy<decltype(f)>, copy_function(f), Buffer::buildKeyName(this->service->name, name), Serializble<T>::write(input));
  }
  template <typename F> inline void on_remove(F f) {
    apid_subscribe(&events_stub<F>, copy_function(f), Buffer::buildKeyEvent(this->service->name, name, "remove"));
  }
  template <typename F> inline void iterate(F f) {
    apid_set_iterate(&iterate_stub<F>, copy_function(f), Buffer::buildKeyName(this->service->name, name));
  }
  template <typename F> inline void contains(T const &input, F f) {
    apid_set_contains(&contains_stub<F>, copy_function(f), Buffer::buildKeyName(this->service->name, name), Serializble<T>::write(input));
  }
};

template <typename K, typename V, typename ServiceRef> class CommonHash : public Named, public ServiceRef {
  template <typename F> static void stub(bool flag, char const *data, void *privdata) {
    F *f = (F *)privdata;
    (*f)(flag, flag ? Serializble<V>::read(data) : V{});
    if constexpr (!std::is_function_v<F>) delete f;
  }

public:
  inline CommonHash(std::string const &name)
      : Named(name) {}

  inline void set(K const &key, V const &value) {
    apid_hash_set(NULL, NULL, Buffer::buildKeyName(this->service->name, name), Serializble<K>::write(key), Serializble<V>::write(value));
  }

  template <typename F> inline void get(K const &key, F f) {
    apid_hash_get(&stub<F>, copy_function(f), Buffer::buildKeyName(this->service->name, name), Serializble<K>::write(key));
  }
};

struct ServerSide {
  class proxied_service : public Named {
  public:
    proxied_service(std::string const &name)
        : Named(name) {}

  private:
    template <typename T> static inline void apid_action_stub(char const *data, void *privdata) {
      ProxiedAction<ServerSide, T> *target = (ProxiedAction<ServerSide, T> *)privdata;
      target->invoke(Serializble<T>::read(data));
    }
    template <typename T, typename R> static inline void apid_method_stub(char const *data, apid_method_reply_ctx *reply) {
      ProxiedMethod<ServerSide, T, R> *target = *(ProxiedMethod<ServerSide, T, R> **)reply;
      target->invoke(Serializble<T>::read(data), [reply](R const &ret) { apid_method_reply(reply, Serializble<R>::write(ret)); });
    }

  protected:
    template <typename T> inline void $(ProxiedAction<ServerSide, T> &action) {
      apid_register_action(Buffer::buildKeyName(name, action.name), &apid_action_stub<T>, (void *)&action);
    }
    template <typename T, typename R> inline void $(ProxiedMethod<ServerSide, T, R> &method) {
      apid_register_method(Buffer::buildKeyName(name, method.name), &apid_method_stub<T, R>, (void *)&method);
    }
    template <typename T> inline void $(ProxiedProperty<ServerSide, T> &prop) { prop.$(this); }
    template <typename T> inline void $(ProxiedBoardcast<ServerSide, T> &broadcast) { broadcast.$(this); }
    template <typename T> inline void $(ProxiedPatternBoardcast<ServerSide, T> &broadcast) { broadcast.$(this); }
    template <typename T> inline void $(ProxiedSet<ServerSide, T> &set) { set.$(this); }
    template <typename K, typename V> inline void $(ProxiedHash<ServerSide, K, V> &set) { set.$(this); }
  };

  template <typename T> class proxied_action : public Named {
    std::function<void(T const &)> func;

  public:
    proxied_action(std::string const &name)
        : Named(name) {}
    inline void operator>>(std::function<void(T const &)> const &f) { func = f; }

  private:
    inline void invoke(T const &value) {
      if (func) func(value);
    }
    friend class proxied_service;
  };

  template <typename T, typename R> class proxied_method : public Named {
    std::function<void(T const &, std::function<void(R)> const &)> func;

  public:
    proxied_method(std::string const &name)
        : Named(name) {}
    inline void operator>>(std::function<void(T const &, std::function<void(R)> const &)> const &f) { func = f; }

  private:
    template <typename F> inline void invoke(T const &value, F const &cb) {
      if (func)
        func(value, cb);
      else
        cb({});
    }
    friend class proxied_service;
  };

  class service_ref {
  protected:
    proxied_service *service;

  private:
    inline void $(proxied_service *service) { this->service = service; }
    friend class proxied_service;
  };

  template <typename T> class proxied_property : public Named, public service_ref {
  public:
    proxied_property(std::string const &name)
        : Named(name) {}
    inline T const &operator=(T const &input) {
      apid_set_prop(nullptr, nullptr, Buffer::buildKeyName(service->name, name), Serializble<T>::write(input));
      return input;
    }
  };

  template <typename T> class proxied_broadcast : public Named, public service_ref {
  public:
    proxied_broadcast(std::string const &name)
        : Named(name) {}
    inline void operator<<(T const &input) { apid_publish(Buffer::buildKeyName(service->name, name), Serializble<T>::write(input)); }
  };

  template <typename T> class proxied_pattern_broadcast : public Named, public service_ref {
  public:
    proxied_pattern_broadcast(std::string const &name)
        : Named(name) {}
    inline void operator<<(T const &input) { apid_publish(Buffer::buildKeyName(service->name, input.build(name)), Serializble<T>::write(input)); }
  };

  template <typename T> using proxied_set              = CommonSet<T, service_ref>;
  template <typename K, typename V> using proxied_hash = CommonHash<K, V, service_ref>;
};

struct ClientSide {
  class proxied_service : public Named {
  public:
    proxied_service(std::string const &name)
        : Named(name) {}

  protected:
    template <typename T> inline void $(T &target) { target.$(this); }
  };

  class service_ref {
  protected:
    proxied_service *service;

  private:
    inline void $(proxied_service *service) { this->service = service; }
    friend class proxied_service;
  };

  template <typename T> class proxied_action : public Named, public service_ref {
    template <typename F> static void stub(void *privdata) {
      F *f = (F *)privdata;
      (*f)();
      if constexpr (!std::is_function_v<F>) delete f;
    }

  public:
    proxied_action(std::string const &name)
        : Named(name) {}
    void operator()(T const &input) { apid_invoke(nullptr, nullptr, Buffer::buildKeyName(service->name, name), Serializble<T>::write(input)); }
    template <typename F> void operator()(T const &input, F f) {
      apid_invoke(&stub<F>, copy_function(f), Buffer::buildKeyName(service->name, name), Serializble<T>::write(input));
    }
  };

  template <typename T, typename R> class proxied_method : public Named, public service_ref {
    template <typename F> static void stub(char const *data, void *privdata) {
      F *f = (F *)privdata;
      (*f)(Serializble<T>::read(data));
      if constexpr (!std::is_function_v<F>) delete f;
    }

  public:
    proxied_method(std::string const &name)
        : Named(name) {}
    template <typename F> void operator()(T const &input, F f) {
      apid_invoke_method(&stub<F>, copy_function(f), Buffer::buildKeyName(service->name, name), Serializble<T>::write(input));
    }
  };

  template <typename T> class proxied_property : public Named, public service_ref {
    template <typename F> static void stub(char const *data, void *privdata) {
      F *f = (F *)privdata;
      (*f)(Serializble<T>::read(data));
      if constexpr (!std::is_function_v<F>) delete f;
    }

  public:
    proxied_property(std::string const &name)
        : Named(name) {}
    template <typename F> void operator>>(F f) { apid_get_prop(&stub<F>, copy_function(f), Buffer::buildKeyName(service->name, name)); }
  };

  template <typename T> class proxied_broadcast : public Named, public service_ref {
    template <typename F> static void stub(char const *data, void *privdata) {
      F *f = (F *)privdata;
      (*f)(Serializble<T>::read(data));
    }

  public:
    proxied_broadcast(std::string const &name)
        : Named(name) {}
    template <typename F> void operator>>(F f) { apid_subscribe(&stub<F>, copy_function(f), Buffer::buildKeyName(service->name, name)); }
  };

  template <typename T> class proxied_pattern_broadcast : public Named, public service_ref {
    template <typename F> static void stub(char const *identify, char const *data, void *privdata) {
      F *f = (F *)privdata;
      (*f)(T::rebuild(identify, data));
    }

  public:
    proxied_pattern_broadcast(std::string const &name)
        : Named(name) {}
    template <typename Filter, typename F> void operator()(Filter filter, F f) {
      apid_subscribe_pattern(&stub<F>, copy_function(f), Buffer::buildKeyName(service->name, T::build_pattern(name, filter)));
    }
    template <typename F> void operator>>(F f) {
      apid_subscribe_pattern(&stub<F>, copy_function(f), Buffer::buildKeyName(service->name, T::build_pattern(name)));
    }
  };

  template <typename T> using proxied_set              = CommonSet<T, service_ref>;
  template <typename K, typename V> using proxied_hash = CommonHash<K, V, service_ref>;
};

} // namespace api
