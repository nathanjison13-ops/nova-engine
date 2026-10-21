#pragma once

#include <string_view>

namespace nova {

struct EngineVersion final {
    static constexpr int major = 0;
    static constexpr int minor = 1;
    static constexpr int patch = 0;
    static constexpr std::string_view string = "0.1.0";
};

} // namespace nova
