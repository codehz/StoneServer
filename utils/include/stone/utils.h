#pragma once
#include <minecraft/ServerInstance.h>

#include <condition_variable>
#include <cstdarg>
#include <functional>
#include <mutex>
#include <string>

void *&MinecraftHandle();

std::string GetEnvironmentVariableOrDefault(const std::string &variable_name, const std::string &default_value);
template <typename T> T EvalInServerThread(ServerInstance &instance, std::function<T()> const &fn) {
  static std::mutex mtx;
  static std::condition_variable cv;
  volatile bool done = false;
  T ret;
  instance.queueForServerThread([&] {
    std::lock_guard<std::mutex> guard(mtx);
    ret  = fn();
    done = true;
    cv.notify_one();
  });
  std::unique_lock<std::mutex> lk(mtx);
  cv.wait(lk, [&] { return done; });
  return ret;
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