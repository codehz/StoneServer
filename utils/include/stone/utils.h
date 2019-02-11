#pragma once
#include <minecraft/ServerInstance.h>
#include <interface/locator.hpp>

#include <condition_variable>
#include <cstdarg>
#include <functional>
#include <type_traits>
#include <mutex>
#include <string>

void *&MinecraftHandle();

namespace utils_internal {
inline static std::mutex mtx;
inline static std::condition_variable cv;
} // namespace utils_internal

std::string GetEnvironmentVariableOrDefault(const std::string &variable_name, const std::string &default_value);
template <typename F> inline static std::invoke_result_t<F> EvalInServerThread(F fn) {
  using namespace utils_internal;
  using namespace interface;
  volatile bool done = false;
  std::invoke_result_t<F> ret;
  Locator<ServerInstance>()->queueForServerThread([&] {
    std::lock_guard<std::mutex> guard(mtx);
    ret  = fn();
    done = true;
    cv.notify_one();
  });
  std::unique_lock<std::mutex> lk(mtx);
  cv.wait(lk, [&] { return done; });
  return ret;
}

template <typename F> inline static void QueueForServerThread(F fn) {
  using namespace interface;
  Locator<ServerInstance>()->queueForServerThread(fn);
}

template <std::size_t buffer = 1024> __attribute__((format(printf, 1, 2))) inline std::string strformat(const char *temp, ...) {
  std::string result;
  result.reserve(buffer);
  va_list args;
  va_start(args, temp);
  vsnprintf((char *)result.data(), buffer, temp, args);
  va_end(args);
  return result;
}