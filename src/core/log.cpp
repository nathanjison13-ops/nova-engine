#include <nova/core/log.hpp>

#include <iostream>
#include <mutex>

namespace nova {
namespace {

void default_log_sink(LogLevel level,
                      std::string_view category,
                      std::string_view message,
                      void*) noexcept {
    static std::mutex output_mutex;
    try {
        const std::lock_guard<std::mutex> lock(output_mutex);
        std::clog << '[' << log_level_name(level) << ']';
        if (!category.empty()) {
            std::clog << " [" << category << ']';
        }
        std::clog << ' ' << message << '\n';
    } catch (...) {
        // Logging must not allow stream exceptions to terminate the runtime.
    }
}

} // namespace

std::string_view log_level_name(LogLevel level) noexcept {
    switch (level) {
    case LogLevel::trace: return "TRACE";
    case LogLevel::debug: return "DEBUG";
    case LogLevel::info: return "INFO";
    case LogLevel::warning: return "WARNING";
    case LogLevel::error: return "ERROR";
    case LogLevel::critical: return "CRITICAL";
    case LogLevel::off: return "OFF";
    }
    return "UNKNOWN";
}

Logger::Logger(LogLevel minimum_level, LogSink sink, void* user_data) noexcept
    : minimum_level_(minimum_level),
      sink_(sink != nullptr ? sink : &default_log_sink),
      user_data_(user_data) {}

void Logger::set_minimum_level(LogLevel level) noexcept {
    minimum_level_ = level;
}

LogLevel Logger::minimum_level() const noexcept {
    return minimum_level_;
}

bool Logger::should_log(LogLevel level) const noexcept {
    if (level == LogLevel::off || minimum_level_ == LogLevel::off) {
        return false;
    }

    return static_cast<int>(level) >= static_cast<int>(minimum_level_);
}

void Logger::set_sink(LogSink sink, void* user_data) noexcept {
    sink_ = sink != nullptr ? sink : &default_log_sink;
    user_data_ = user_data;
}

void Logger::log(LogLevel level,
                 std::string_view category,
                 std::string_view message) const noexcept {
    if (!should_log(level) || sink_ == nullptr) {
        return;
    }

    sink_(level, category, message, user_data_);
}

} // namespace nova
