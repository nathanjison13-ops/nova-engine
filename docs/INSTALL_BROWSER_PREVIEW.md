# Installation and First Run

This guide separates the hosted browser prototype from the native Nova Engine source tree. There is no native installer published by this release.

## Hosted browser editor

Open the hosted editor:

https://nova-forge-studio-873bjg.v2.appdeploy.ai/

1. Open the starter project.
2. Select an object in the scene hierarchy.
3. Change a supported property in the inspector.
4. Use Run to start the built-in 2D Canvas playtest.
5. Use the script panel to edit text and run structural checks. These checks are not a compiler.
6. Save the project in browser storage and export its JSON to keep a backup.
7. To move work to another device or browser profile, transfer the exported JSON file and import it there.

The hosted editor is accessed through a browser on desktops, tablets, and phones. Actual layout and touch compatibility must be verified on the target device. Browser access does not imply a native Android/iOS app or local desktop installation.

## Build the native source

Repository: https://github.com/nathanjison13-ops/nova-engine

Requirements listed by the project: CMake 3.24 or newer, a C++20 compiler, and Git.

From the repository root:

```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release
ctest --test-dir build -C Release --output-on-failure
```

To configure a Debug build instead:

```sh
cmake -S . -B build-debug -DCMAKE_BUILD_TYPE=Debug
cmake --build build-debug --config Debug
ctest --test-dir build-debug -C Debug --output-on-failure
```

Multi-configuration generators may place executables in a configuration-specific directory such as `build/Release`. Use your generator's output path.

The current CMake project builds a small core library, a minimal editor executable, and the dependency-free core tests. It does not currently build a Vulkan renderer or full game-editor UI.

## Test status warning

Commands above are the project's documented build/test procedure, not a report that they passed on your device. Check the terminal exit codes and test summary. Consult the GitHub Actions run for the exact commit before relying on CI evidence. A workflow configuration file alone is not a successful run.

## Device limitations

- Native kernel integration is not included.
- Native Vulkan rendering and lighting are planned, not included.
- Script structural validation is not compilation.
- Android/iOS, Raspberry Pi/ARM64, and production Windows/Linux/macOS packages are not verified by this release.
- No automatic updater or native package installer is published.
