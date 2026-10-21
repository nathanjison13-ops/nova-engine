#include <nova/core/engine.hpp>

namespace nova {

bool Engine::initialize() noexcept {
    initialized_ = true;
    return true;
}

void Engine::shutdown() noexcept {
    initialized_ = false;
}

bool Engine::is_initialized() const noexcept {
    return initialized_;
}

} // namespace nova
