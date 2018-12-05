#pragma once

#include <cstdarg>
#include <cstdlib>
#include <functional>
#include <uintl.h>
#include <vector>

#define LogFuncDef(name, logLevel)                                                                                                                   \
  static void name(const char *tag, const char *text, ...) __attribute__((format(printf, 2, 3))) {                                                   \
    va_list args;                                                                                                                                    \
    va_start(args, text);                                                                                                                            \
    vlog(logLevel, tag, text, args);                                                                                                                 \
    va_end(args);                                                                                                                                    \
  }

enum class LogLevel { LOG_TRACE, LOG_DEBUG, LOG_INFO, LOG_WARN, LOG_ERROR, LOG_MAX };

class Log {
  static std::vector<std::function<void(int, std::string, std::string)>> hooks;

public:
  static inline void addHook(std::function<void(int, std::string, std::string)> fn) { hooks.push_back(fn); }
  static inline void clearHooks() { hooks.clear(); }

  static inline const char *getLogLevelString(LogLevel lvl) {
    using namespace uintl;
    static char const *lvmap[] = { "Trace"_static_intl, "Debug"_static_intl, "Info "_static_intl, "Warn "_static_intl, "Error"_static_intl };
    if (lvl >= LogLevel::LOG_MAX) return "?";
    return lvmap[(int)lvl];
  }

  static void vlog(LogLevel level, const char *tag, const char *text, va_list args);

  static void log(LogLevel level, const char *tag, const char *text, ...) {
    va_list args;
    va_start(args, text);
    vlog(level, tag, text, args);
    va_end(args);
  }

  // clang-format off
  LogFuncDef(trace, LogLevel::LOG_TRACE)
  LogFuncDef(debug, LogLevel::LOG_DEBUG)
  LogFuncDef(info, LogLevel::LOG_INFO)
  LogFuncDef(warn, LogLevel::LOG_WARN)
  LogFuncDef(error, LogLevel::LOG_ERROR)
  // clang-format on
};

#undef LogFuncDef
