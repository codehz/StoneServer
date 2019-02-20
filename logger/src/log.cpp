#include "../include/log.h"
#include <cstdio>
#include <ctime>

LogLevel Log::MIN_LEVEL = LogLevel::LOG_INFO;

void Log::vlog(LogLevel level, const char *tag, const char *text, va_list args) {
  char *buffer;
  vasprintf(&buffer, text, args);

  char tbuf[16];
  tbuf[0] = '\0';

  time_t t = time(nullptr);
  tm tm;
  localtime_r(&t, &tm);
  strftime(tbuf, sizeof(tbuf), "%H:%M:%S", &tm);

  for (auto hook : hooks) hook(static_cast<int>(level), tag, buffer);

  if (static_cast<int>(level) < static_cast<int>(MIN_LEVEL)) {
    free(buffer);
    return;
  }

  printf("%s %s [%s] %s\n", tbuf, getLogLevelString(level), tag, buffer);
  fflush(stdout);
  free(buffer);
}

std::vector<std::function<void(int, std::string, std::string)>> Log::hooks;