#include <interface/locator.hpp>
#include <stone/server_hook.h>

#include "../server_properties.h"

#include <netdb.h>
#include <sys/socket.h>
#include <cstring>

namespace {

using namespace interface;

SHook(int, bind, int sockfd, const struct sockaddr *addr, socklen_t addrlen) {
  if (addr->sa_family == AF_INET) {
    addrinfo hints = {
      .ai_flags    = AI_PASSIVE,
      .ai_family   = AF_INET,
      .ai_socktype = SOCK_DGRAM,
    };
    addrinfo *list;
    if (getaddrinfo(Locator<ServerProperties>()->ip.get().c_str(), "1", &hints, &list) == 0) {
      ((sockaddr_in*)list->ai_addr)->sin_port = ((sockaddr_in*)addr)->sin_port;
      auto ret = original(sockfd, list->ai_addr, list->ai_addrlen);
      freeaddrinfo(list);
      return ret;
    }
  }
  if (addr->sa_family == AF_INET6) {
    addrinfo hints = {
      .ai_flags    = AI_PASSIVE,
      .ai_family   = AF_INET6,
      .ai_socktype = SOCK_DGRAM,
    };
    addrinfo *list;
    if (getaddrinfo(Locator<ServerProperties>()->ipv6.get().c_str(), "1", &hints, &list) == 0) {
      ((sockaddr_in6*)list->ai_addr)->sin6_port = ((sockaddr_in6*)addr)->sin6_port;
      auto ret = original(sockfd, list->ai_addr, list->ai_addrlen);
      freeaddrinfo(list);
      return ret;
    }
  }
  auto ret = original(sockfd, addr, addrlen);
  return ret;
}

} // namespace