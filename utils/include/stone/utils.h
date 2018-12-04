#pragma once
#include <minecraft/ServerInstance.h>

#include <condition_variable>
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