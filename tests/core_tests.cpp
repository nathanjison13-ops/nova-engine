#include <nova/core/engine.hpp>

#include <iostream>

int main() {
    nova::Engine engine;

    if (engine.is_initialized()) {
        std::cerr << "A new engine must start uninitialized.\n";
        return 1;
    }
    if (!engine.initialize()) {
        std::cerr << "Starter core initialization should succeed.\n";
        return 1;
    }
    if (!engine.is_initialized()) {
        std::cerr << "Engine should report initialized after startup.\n";
        return 1;
    }
    if (!engine.initialize() || !engine.is_initialized()) {
        std::cerr << "Repeated initialization should be safe.\n";
        return 1;
    }

    engine.shutdown();
    if (engine.is_initialized()) {
        std::cerr << "Engine should report stopped after shutdown.\n";
        return 1;
    }
    engine.shutdown();
    if (engine.is_initialized()) {
        std::cerr << "Repeated shutdown should be safe.\n";
        return 1;
    }

    std::cout << "Nova core lifecycle tests passed.\n";
    return 0;
}
