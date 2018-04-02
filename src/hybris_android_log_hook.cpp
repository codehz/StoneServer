#include <mcpelauncher/hybris_utils.h>
#include <log.h>

extern "C" {
#include <hybris/hook.h>
}


typedef enum AndroidLogPriority {
    ANDROID_LOG_UNKNOWN = 0,
    ANDROID_LOG_DEFAULT,
    ANDROID_LOG_VERBOSE,
    ANDROID_LOG_DEBUG,
    ANDROID_LOG_INFO,
    ANDROID_LOG_WARN,
    ANDROID_LOG_ERROR,
    ANDROID_LOG_FATAL,
    ANDROID_LOG_SILENT
};

static LogLevel convertAndroidLogLevel(int level) {
    if (level <= AndroidLogPriority::ANDROID_LOG_VERBOSE)
        return LogLevel::LOG_TRACE;
    if (level == AndroidLogPriority::ANDROID_LOG_DEBUG)
        return LogLevel::LOG_DEBUG;
    if (level == AndroidLogPriority::ANDROID_LOG_INFO)
        return LogLevel::LOG_INFO;
    if (level == AndroidLogPriority::ANDROID_LOG_WARN)
        return LogLevel::LOG_WARN;
    if (level >= AndroidLogPriority::ANDROID_LOG_ERROR)
        return LogLevel::LOG_ERROR;
    return LogLevel::LOG_ERROR;
}
static void __android_log_vprint(int prio, const char *tag, const char *fmt, va_list args) {
    Log::vlog(convertAndroidLogLevel(prio), tag, fmt, args);
}
static void __android_log_print(int prio, const char *tag, const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    Log::vlog(convertAndroidLogLevel(prio), tag, fmt, args);
    va_end(args);
}
static void __android_log_write(int prio, const char *tag, const char *text) {
    Log::log(convertAndroidLogLevel(prio), tag, "%s", text);
}

void HybrisUtils::hookAndroidLog() {
    hybris_hook("__android_log_print", (void*) __android_log_print);
    hybris_hook("__android_log_vprint", (void*) __android_log_vprint);
    hybris_hook("__android_log_write", (void*) __android_log_write);
}