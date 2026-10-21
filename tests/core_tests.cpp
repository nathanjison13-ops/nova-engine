#include <nova/core/engine.hpp>
#include <nova/core/log.hpp>

#include <iostream>
#include <string_view>

namespace {

struct CapturedLog {
    int count{0};
    nova::LogLevel level{nova::LogLevel::off};
    std::string_view category{};
    std::string_view message{};
};

void capture_log(nova::LogLevel level,
                 std::string_view category,
                 std::string_view message,
                 void* user_data) noexcept {
    auto* captured = static_cast<CapturedLog*>(user_data);
    captured->count += 1;
    captured->level = level;
    captured->category = category;
    captured->message = message;
}

bool test_engine_lifecycle() {
    nova::Engine engine;

    if (engine.is_initialized()) return false;
    if (!engine.initialize()) return false;
    if (!engine.is_initialized()) return false;
    if (!engine.initialize() || !engine.is_initialized()) return false;

    engine.shutdown();
    if (engine.is_initialized()) return false;
    engine.shutdown();
    return !engine.is_initialized();
}

bool test_logger_filters_and_custom_sink() {
    CapturedLog captured;
    nova::Logger logger(nova::LogLevel::warning, &capture_log, &captured);

    logger.log(nova::LogLevel::info, "test", "below threshold");
    if (captured.count != 0) return false;

    logger.log(nova::LogLevel::warning, "runtime", "warning message");
    if (captured.count != 1) return false;
    if (captured.level != nova::LogLevel::warning) return false;
    if (captured.category != "runtime") return false;
    if (captured.message != "warning message") return false;

    logger.log(nova::LogLevel::critical, "runtime", "critical message");
    if (captured.count != 2 || captured.level != nova::LogLevel::critical) {
        return false;
    }

    logger.set_minimum_level(nova::LogLevel::off);
    logger.log(nova::LogLevel::error, "runtime", "filtered message");
    if (captured.count != 2) return false;

    logger.set_minimum_level(nova::LogLevel::trace);
    logger.log(nova::LogLevel::off, "runtime", "off is never emitted");
    if (captured.count != 2) return false;

    return logger.minimum_level() == nova::LogLevel::trace;
}

} // namespace

int main() {
    if (!test_engine_lifecycle()) {
        std::cerr << "Engine lifecycle tests failed.\n";
        return 1;
    }

    if (!test_logger_filters_and_custom_sink()) {
        std::cerr << "Logger tests failed.\n";
        return 2;
    }

    if (nova::log_level_name(nova::LogLevel::critical) != "CRITICAL") {
        std::cerr << "Log level naming test failed.\n";
        return 3;
    }

    std::cout << "Nova core tests passed.\n";
    return 0;
}
