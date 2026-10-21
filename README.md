# Nova Engine

Nova Engine is an open-source, cross-platform game engine and editor project for building 2D and 3D games, authoring models and animation, creating visual effects, scripting gameplay, and shipping projects to supported devices.

Status: early foundation. This repository is not yet a complete engine and does not claim feature parity with Unreal Engine, Blender, Unity, Godot, or any other tool. The roadmap tracks planned systems and implementation status.

## Principles

- C++20 runtime and CMake build.
- Modular rendering, physics, scripting, and platform boundaries.
- Vulkan-first rendering direction with capability checks and fallbacks planned.
- Clean, dockable editor with customizable layouts, shortcuts, colors, and accessible controls.
- Interoperability with open formats and art tools without copying proprietary source code, assets, or protected UI designs.
- Reproducible tests, security reviews, and honest feature status.
- Low-resource mode as a target, with hardware requirements published only after testing.

## Current status

Implemented in this starter:
- C++20 core library and engine lifecycle stub.
- Minimal editor executable.
- Dependency-free core lifecycle test.
- CMake build.
- GitHub Actions build and test workflow definition for Windows, Linux, and macOS.
- CodeRabbit review configuration.
- Architecture and feature roadmap.

Planned, not yet implemented:
- Vulkan renderer, shaders, render graph, materials, lighting, and post-processing.
- Dockable editor UI, scene hierarchy, viewport tools, inspector, asset browser, and project manager.
- Scene graph, ECS, serialization, asset database, import/export, and world streaming.
- Modeling tools, mesh editing, procedural geometry, UV workflows, rigs, and animation graphs.
- Physics, navigation, audio, VFX, scripting, visual scripting, networking, debugging, profiling, and packaging.
- Android and ARM64 support, including Raspberry Pi-class Linux devices, after the desktop base is validated.

See docs/ROADMAP.md, docs/MODULE_CATALOG.md, and docs/PLATFORM_SUPPORT.md.

## Build

Requirements: CMake 3.24 or newer, a C++20 compiler, and Git.

    cmake -S . -B build
    cmake --build build --config Release
    ctest --test-dir build -C Release --output-on-failure

Run the starter executable from the build output folder. Multi-configuration generators may place it under Release.

## Code review

The repository includes .coderabbit.yaml. CodeRabbit must still be installed and authorized for this repository at https://www.coderabbit.ai/. Automated reviews are advisory and do not replace CI, tests, security checks, or human review.

## Contributions and license

Read CONTRIBUTING.md before opening a pull request. Nova Engine is distributed under the MIT License. See LICENSE.

## Scope and compatibility

The goal is broad capability across runtime, modeling, animation, VFX, and editor workflows. No single project can literally include every feature from every engine and modeling package. Nova will prioritize useful, interoperable systems, document compatibility limits, and implement features in tested stages. Console exports depend on authorized SDK access and platform-holder requirements.
