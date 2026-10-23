# Grelied and Nova Engine: Release Status

Last reviewed: 2026-10-23

## Product split

Grelied Studio is the hosted browser editor prototype. Nova Engine is the separate open-source C++20 runtime foundation.

- Browser editor: https://nova-forge-studio-873bjg.v2.appdeploy.ai/
- Release portal: https://grelied-release-portal-4cpjvf.v2.appdeploy.ai/
- Runtime repository: https://github.com/nathanjison13-ops/nova-engine

The browser app and the native C++ project are separate deliverables. The hosted editor does not wrap or launch the native runtime.

## Verified status

The AppDeploy status responses for both hosted URLs reported `ready`. Their returned QA snapshots listed no frontend or network errors. The editor status also listed no backend errors.

Those observations establish deployment status only. They do not establish that every interactive workflow passed.

The editor source contains a five-case regression specification for:
- Running a playtest, collecting a shard, and clearing held keys after focus loss.
- Editing a scene property and retaining it after reload.
- Import/export round trips and rejection of duplicate entity IDs.
- Honest script validation and native/kernel integration status.
- Mobile viewport navigation and touch controls.

The response available during this review did not include a passing end-to-end report, so these cases must not be described as having all passed.

The native repository includes:
- A C++20 core library with an initialize/shutdown lifecycle.
- A logger with severity filtering and a replaceable callback sink.
- A minimal editor executable that reports core initialization.
- Dependency-free tests covering engine lifecycle and logger behavior.
- A CMake build and CTest workflow definition for Ubuntu, Windows, and macOS runners.

### Native checks actually run

The project was cloned in a remote Debian sandbox at the latest main commit available for this review, `5e7eb66295b6fc59521145b8e12b644ea1347c13` (Add reusable runtime logger and unit tests).

- Compiler: `g++ 14.2.0`.
- The core regression test binary compiled with C++20 and `-Wall -Wextra -Wpedantic`.
- The test executable printed `Nova core tests passed.` and exited successfully.
- The minimal editor executable also compiled and ran, printing `Nova Engine 0.1.0 | core foundation initialized`.
- CMake and CTest were not run because CMake is not installed in that sandbox.
- The GitHub combined status lookup for the main commit returned no status checks, and the workflow-run lookup returned an empty list. No Windows or macOS runner result was verified.

These manual checks establish that the core sources compile and their existing test program passes under this particular GCC environment. They do not establish a successful CMake build, registered Actions run, multi-platform support, or graphics functionality.

## Feature status

| Capability | Current state | Evidence and limits |
| --- | --- | --- |
| Hosted browser editor | Available | AppDeploy reports the deployment ready. |
| 2D Canvas playtest | Implemented in the web prototype | Not a native engine render path. |
| Scene hierarchy and inspector | Implemented in the web prototype | Limited to properties and entities supported by that prototype. |
| Browser local storage | Implemented in the web prototype | Browser-profile specific. Export JSON for backup and transfer. |
| Project JSON import/export | Implemented in the web prototype | Project parser validates shape and entity IDs. |
| Script text editing | Implemented, limited | Structural checks are not compilation or execution of arbitrary code. |
| Native C++20 core lifecycle | Implemented in repository | Manual GCC compilation and existing core test executable passed in one remote Debian environment. |
| Native logger | Implemented in repository | Existing logger filters/sink tests passed in the same manual run. |
| Native editor UI | Minimal executable only | Not a production visual editor. |
| Vulkan renderer, shaders, real-time 3D lighting | Planned | Not implemented in the current repository state. |
| Physics, animation, audio, VFX, production scripting | Planned | Not implemented as complete engine systems. |
| Kernel attachment or native OS bridge | Not available | No integration is present. Any future host bridge should use explicit permissions and least privilege. |
| Windows, Linux, macOS native builds | CI targets defined; partial manual validation only | A successful Linux/GCC source compile was run manually. CMake CI on Linux, Windows, and macOS is not verified. |
| Android, iOS, ARM64 / Raspberry Pi | Planned, not verified | No native package or device test evidence was found. |
| Packaged installer and automatic updater | Not available | No native distribution pipeline is verified. |

## Required release gates

1. Obtain a successful native CMake build and CTest run in a clean environment.
2. Confirm the GitHub Actions workflow is registered and returns actual passing results for Linux, Windows, and macOS runners.
3. Keep source and browser regression specifications aligned with implemented behavior.
4. Test mobile and tablet workflows on real devices before making stronger compatibility claims.
5. Add native rendering only as a vertical slice with recorded device/driver evidence and validation checks.
6. Publish native packages only after repeatable build, install, startup, upgrade, and uninstall verification.
7. Review security and project-file validation before enabling external scripting or OS integration.

## Brand schedule

Grelied remains the current studio identity. The planned company identity review for DUFS is scheduled for 2027-01-31. Nova Engine remains the technical repository and runtime name unless the project owner explicitly changes that scope.

## Release language

Preferred wording: “Grelied Studio is an early browser-based game-editor prototype. Nova Engine is an early C++20 runtime foundation under development.”

Do not use claims such as complete cross-platform engine, native Vulkan rendering, compiled scripting, kernel integration, zero latency, or tested Android support until implementation and supporting evidence exist.
