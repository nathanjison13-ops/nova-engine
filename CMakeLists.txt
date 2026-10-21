cmake_minimum_required(VERSION 3.24)

project(NovaEngine
    VERSION 0.1.0
    DESCRIPTION "Open-source cross-platform game engine foundation"
    LANGUAGES CXX
)

option(NOVA_BUILD_TESTS "Build Nova Engine tests" ON)

add_library(nova_core STATIC
    src/core/engine.cpp
    src/core/log.cpp
)
add_library(Nova::Core ALIAS nova_core)

target_include_directories(nova_core PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)
target_compile_features(nova_core PUBLIC cxx_std_20)

if(MSVC)
    target_compile_options(nova_core PRIVATE /W4 /permissive-)
else()
    target_compile_options(nova_core PRIVATE -Wall -Wextra -Wpedantic)
endif()

add_executable(nova_editor src/editor/main.cpp)
target_link_libraries(nova_editor PRIVATE Nova::Core)
target_compile_features(nova_editor PRIVATE cxx_std_20)

if(NOVA_BUILD_TESTS)
    include(CTest)
    if(BUILD_TESTING)
        add_executable(nova_core_tests tests/core_tests.cpp)
        target_link_libraries(nova_core_tests PRIVATE Nova::Core)
        target_compile_features(nova_core_tests PRIVATE cxx_std_20)
        add_test(NAME nova_core_tests COMMAND nova_core_tests)
    endif()
endif()
