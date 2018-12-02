#include "../include/log.h"
#include <cstdio>
#include <ctime>

void Log::vlog(LogLevel level, const char *tag, const char *text, va_list args) {
  char buffer[4096];
  int len = vsnprintf(buffer, sizeof(buffer), uintl::gettext(text), args);
  if (len > sizeof(buffer)) len = sizeof(buffer);
  while (len > 0 && (buffer[len - 1] == '\r' || buffer[len - 1] == '\n')) buffer[--len] = '\0';

  char tbuf[128];
  tbuf[0] = '\0';

  time_t t = time(nullptr);
  tm tm;
  localtime_r(&t, &tm);
  strftime(tbuf, sizeof(tbuf), "%H:%M:%S", &tm);
  printf("%s %s [%s] %s\n", tbuf, getLogLevelString(level), uintl::gettext(tag), buffer);
  fflush(stdout);
}