#pragma once

#include <string_view>

namespace nova {

enum class LogLevel {
    trace = 0,
    debug,
    info,
    warning,
    error,
    critical,
    off
};

[[nodiscard]] std::string_view log_level_name(LogLevel level) noexcept;

using LogSink = void (*)(LogLevel level,
                         std::string_view category,
                         std::string_view message,
                         void* user_data) noexcept;

class Logger final {
public:
    explicit Logger(LogLevel minimum_level = LogLevel::info,
                    LogSink sink = nullptr,
                    void* user_data = nullptr) noexcept;

    void set_minimum_level(LogLevel level) noexcept;
    [[nodiscard]] LogLevel minimum_level() const noexcept;
    [[nodiscard]] bool should_log(LogLevel level) const noexcept;

    // The sink runs synchronously. A sink must copy string views it wants to
    // keep after this call returns. Configure the logger before sharing it
    // across threads.
    void set_sink(LogSink sink, void* user_data = nullptr) noexcept;
    void log(LogLevel level,
             std::string_view category,
             std::string_view message) const noexcept;

private:
    LogLevel minimum_level_;
    LogSink sink_;
    void* user_data_;
};

} // namespace nova
