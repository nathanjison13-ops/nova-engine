# Grelied and Nova Engine: Release Status

Last reviewed: 2026-10-23

## Product split

Grelied Studio is the hosted browser editor prototype. Nova Engine is the separate open-source C++20 runtime foundation.

- Browser editor: https://nova-forge-studio-873bjg.v2.appdeploy.ai/
- Release portal: https://grelied-release-portal-4cpjvf.v2.appdeploy.ai/
- Runtime repository: https://github.com/nathanjison13-ops/nova-engine

The browser app and the native C++ project are separate deliverables. The hosted editor does not wrap or launch the native runtime.

## Verified deployment status

The AppDeploy status responses for both hosted URLs reported `ready`. Their returned QA snapshots listed no frontend or network errors. The editor status also listed no backend errors.

Those observations establish deployment status only. They do not establish that every interactive workflow passed.

The editor source contains a five-case regression specification for:
- Running a playtest, collecting a shard, and clearing held keys after focus loss.
- Editing a scene property and retaining it after reload.
- Import/export round trips and rejection of duplicate entity IDs.
- Honest script validation and native/kernel integration status.
- Mobile viewport navigation and touch controls.

The response available during this review did not include a passing end-to-end report, so these cases must not be described as having all passed.

## Native checks actually run

The project was cloned in a remote Debian sandbox at main commit `5e7eb66295b6fc59521145b8e12b644ea1347c13` (Add reusable runtime logger and unit tests).

- Compiler: `g++ 14.2.0`.
- Built core test and native editor programs using C++20 with `-Wall -Wextra -Wpedantic`.
- The core test executable printed `Nova core tests passed.` and exited successfully.
- The minimal editor executable ran and printed `Nova Engine 0.1.0 | core foundation initialized`.
- Built and ran an optimized test build using `-O2 -DNDEBUG`. It printed `Nova core tests passed.`.
- Built and ran the core test suite with AddressSanitizer and UndefinedBehaviorSanitizer. It printed `Nova core tests passed.` and returned no sanitizer diagnostics.
- CMake and CTest were not run because CMake is not installed in that sandbox.

These manual checks establish that the current core sources compile and their existing test program passes under this particular GCC environment. They do not establish a successful CMake build, full platform support, or graphics functionality.

## GitHub Actions blocker

The repository contains a `.github/workflows/ci.yml` definition for a CMake build and CTest matrix on Ubuntu, Windows, and macOS.

However, during this review:
- GitHub's repository workflow-list API returned zero registered workflows.
- A manual dispatch request for `ci.yml` returned 404, saying the workflow was not found or inaccessible.
- The workflow-run lookup returned an empty list.
- The combined status lookup for main commit `5e7eb66295b6fc59521145b8e12b644ea1347c13` returned no status checks.

The cause is not confirmed. Repository Actions settings, workflow registration, or integration permissions need inspection. Do not claim Actions passed until real runner results are available. No Windows or macOS run was verified.

## Feature status

| Capability | Current state | Evidence and limits |
| --- | --- | --- |
| Hosted browser editor | Available | AppDeploy reports the deployment ready. |
| 2D Canvas playtest | Implemented in the web prototype | Not a native engine render path. |
| Scene hierarchy and inspector | Implemented in the web prototype | Limited to properties and entities supported by that prototype. |
| Browser local storage | Implemented in the web prototype | Browser-profile specific. Export JSON for backup and transfer. |
| Project JSON import/export | Implemented in the web prototype | Project parser validates shape and entity IDs. |
| Script text editing | Implemented, limited | Structural checks are not compilation or execution of arbitrary code. |
| Native C++20 core lifecycle | Implemented in repository | Manual GCC compilation and lifecycle tests passed in normal, optimized, and sanitizer builds on one Debian environment. |
| Native logger | Implemented in repository | Existing logger filtering and callback tests passed in the same manual runs. |
| Native editor UI | Minimal executable only | Not a production visual editor. |
| Vulkan renderer, shaders, real-time 3D lighting | Planned | Not implemented in the current repository state. |
| Physics, animation, audio, VFX, production scripting | Planned | Not implemented as complete engine systems. |
| Kernel attachment or native OS bridge | Not available | No integration is present. Any future host bridge should use explicit permissions and least privilege. |
| Windows, Linux, macOS native builds | Partial manual Linux/GCC validation only | GitHub Actions registration and CMake CI remain unverified. |
| Android, iOS, ARM64 / Raspberry Pi | Planned, not verified | No native package or device test evidence was found. |
| Packaged installer and automatic updater | Not available | No native distribution pipeline is verified. |

## Required release gates

1. Resolve why GitHub reports zero registered workflows and obtain a real CMake build and CTest run.
2. Confirm successful runner results for Linux, Windows, and macOS before claiming verified native support.
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
