# Platform support

## Target versus verified

The current code is a CMake C++20 starter. The GitHub Actions workflow is configured for Windows, Linux, and macOS. Check the Actions tab before treating these targets as verified.

| Platform | Goal | Current evidence |
| --- | --- | --- |
| Windows x86-64 | Desktop editor/runtime | CI configured, run must pass |
| Linux x86-64 | Desktop editor/runtime | CI configured, run must pass |
| macOS | Desktop editor/runtime | CI configured, run must pass |
| Linux ARM64 | ARM64 builds, including Raspberry Pi-class devices | Planned, not tested |
| Android | Mobile runtime and lifecycle/input support | Planned, not tested |
| iOS | Potential mobile target | Research required |
| WebAssembly | Potential constrained runtime | Research required |
| Consoles | Platform-specific builds | Authorized SDKs and approval required |

## Cross-platform rules

- Isolate filesystem, threading, windowing, input, audio, and graphics surface creation behind platform adapters.
- Query capabilities rather than assuming them from the OS name.
- Define graceful fallback for unsupported GPU features and API limits.
- Avoid assuming POSIX paths or case-sensitive filesystems.
- Test suspend/resume, resize, device loss, and low-memory behavior before advertising mobile support.
- Publish minimum hardware requirements only after reproducible benchmarks.

## Raspberry Pi and low-resource devices

Performance depends on the Pi model, OS image, GPU driver, Vulkan capabilities, memory, cooling, and project content. A low-resource mode with scalable render quality and conservative background work is a goal, not a promise that advanced graphics will run on every Pi.

## Platform completion checklist

1. Clean build from documented steps.
2. Launch and shutdown test.
3. Input, surface lifecycle, and filesystem tests where relevant.
4. Renderer capability report and graceful unsupported-feature handling.
5. Sample project and recorded hardware/software details.
