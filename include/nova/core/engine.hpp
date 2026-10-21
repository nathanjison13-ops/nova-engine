#pragma once

namespace nova {

class Engine final {
public:
    Engine() = default;
    ~Engine() = default;

    Engine(const Engine&) = delete;
    Engine& operator=(const Engine&) = delete;
    Engine(Engine&&) = delete;
    Engine& operator=(Engine&&) = delete;

    [[nodiscard]] bool initialize() noexcept;
    void shutdown() noexcept;
    [[nodiscard]] bool is_initialized() const noexcept;

private:
    bool initialized_{false};
};

} // namespace nova
