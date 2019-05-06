#pragma once

#ifndef API_MODE
#define API_MODE server
#endif

#include <rpcws.hpp>

namespace api {

#if API_MODE == server

inline std::unique_ptr<rpcws::RPC> &endpoint() {
  static std::unique_ptr<rpcws::RPC> instance;
  return instance;
}

class Named {
protected:
  std::string name;

public:
  Named(std::string_view name)
      : name(name) {}
};

class Service : Named {
public:
  Service(std::string_view name)
      : Named(name) {}

protected:
  template <typename T> void $(T &rhs) { rhs.$(this); }
  template <typename R, typename T> friend class Method;
  template <typename T> friend class Action;
  template <typename T> friend class Broadcast;
};

template <typename R, typename T> class Method : Named {
  std::function<R(T)> fn;

public:
  Method(std::string_view name)
      : Named(name) {}

  void operator>>(std::function<R(T)> fn) { this->fn = fn; }

protected:
  void $(Service *service) {
    endpoint()->reg(service->name + "." + name, [this](auto client, rpcws::json data) -> rpcws::json {
      T input;
      rpcws::json output;
      nlohmann::from_json(data, input);
      nlohmann::to_json(output, fn(input));
      return output;
    });
  }
  friend class Service;
};

template <typename T> class Action : Named {
  std::function<void(T)> fn;

public:
  Action(std::string_view name)
      : Named(name) {}

  void operator>>(std::function<void(T)> fn) { this->fn = fn; }

protected:
  void $(Service *service) {
    endpoint()->reg(service->name + "." + name, [this](auto client, rpcws::json data) -> rpcws::json {
      T input;
      nlohmann::from_json(data, input);
      fn(input);
      return nullptr;
    });
  }
  friend class Service;
};

template <typename T> class Broadcast : Named {
  std::string mixed;

public:
  Broadcast(std::string_view name)
      : Named(name) {}

  void operator<<(T input) {
    rpcws::json output;
    nlohmann::to_json(output, input);
    endpoint()->emit(mixed, output);
  }

protected:
  void $(Service *service) { endpoint()->event(mixed = service->name + "." + name); }
  friend class Service;
};

#endif

struct Empty {};

inline void to_json(rpc::json &j, const Empty &i) {}

inline void from_json(const rpc::json &j, Empty &i) {}

} // namespace api
