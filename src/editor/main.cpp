#include <nova/core/engine.hpp>
#include <nova/core/version.hpp>

#include <cstdlib>
#include <iostream>

int main() {
    nova::Engine engine;
    if (!engine.initialize()) {
        std::cerr << "Nova Engine failed to initialize.\n";
        return EXIT_FAILURE;
    }

    std::cout << "Nova Engine " << nova::EngineVersion::string
              << " | core foundation initialized\n";
    engine.shutdown();
    return EXIT_SUCCESS;
}
