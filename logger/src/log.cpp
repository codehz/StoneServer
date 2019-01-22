#include "../include/log.h"
#include <cstdio>
#include <ctime>

LogLevel Log::MIN_LEVEL = LogLevel::LOG_INFO;

void Log::vlog(LogLevel level, const char *tag, const char *text, va_list args) {
  char buffer[4096];
  int len = vsnprintf(buffer, sizeof(buffer), uintl::gettext(text), args);
  if (len > sizeof(buffer)) len = sizeof(buffer);
  while (len > 0 && (buffer[len - 1] == '\r' || buffer[len - 1] == '\n')) buffer[--len] = '\0';

  char tbuf[16];
  tbuf[0] = '\0';

  time_t t = time(nullptr);
  tm tm;
  localtime_r(&t, &tm);
  strftime(tbuf, sizeof(tbuf), "%H:%M:%S", &tm);

  std::string temp = uintl::gettext(tag);
  for (auto hook : hooks) hook(static_cast<int>(level), temp, buffer);

  if (static_cast<int>(level) < static_cast<int>(MIN_LEVEL)) return;

  printf("%s %s [%s] %s\n", tbuf, getLogLevelString(level), temp.c_str(), buffer);
  fflush(stdout);
}

std::vector<std::function<void(int, std::string, std::string)>> Log::hooks;