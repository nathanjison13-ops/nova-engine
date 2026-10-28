# Roadmap

A checked box means implemented and tested, not merely planned.

## Milestone 0: Repository foundation
- [x] Public MIT repository.
- [x] C++20 and CMake project.
- [x] Core lifecycle and basic logger with threshold filtering and callback sink.
- [x] Core smoke tests.
- [x] Windows, Linux, and macOS CI workflow file.
- [x] CodeRabbit configuration.
- [x] Verify remote GitHub Actions registration and first run ([run #1](https://github.com/nathanjison13-ops/nova-engine/actions/runs/40051409293) passed Configure, Build, and Test on Ubuntu, Windows, and macOS on 2026-10-24).
- [x] Verify clang-format and clang-tidy static-analysis checks in CI ([run #9](https://github.com/nathanjison13-ops/nova-engine/actions/runs/40611434064) passed formatting, analyzed build, and CTest on 2026-10-28 on branch `qa/quality-gates-release-2026-10-28`). Main remains unchanged pending review.
- [ ] Add small sample projects for lifecycle, scene serialization, and later renderer bring-up.
- [ ] Publish dependency notices and a version/update policy.
- [ ] Evaluate sanitizers for supported compilers.

## Milestone 1: Stable runtime core
- [x] Basic severity filtering and replaceable logging sink.
- [ ] Structured logging context and configurable output formatting.
- [ ] Error/result types and development assertions.
- [ ] Platform abstraction and runtime capability report.
- [ ] Clock, event system, input abstraction, and job system.
- [ ] Memory and resource ownership rules.
- [ ] Select a test framework after license review.

## Milestone 2: Projects, assets, and scenes
- [ ] Project configuration and schema versioning.
- [ ] Asset UUIDs, metadata, dependencies, and import queue.
- [ ] Scene graph, transforms, ECS, and serialization.
- [ ] Prefabs, undo/redo, save/load, and crash recovery.
- [ ] glTF import/export, followed by formats selected through compatibility tests.

## Milestone 3: Graphics foundation
- [ ] Renderer interface separated from world and editor code.
- [ ] Vulkan instance, device, validation, and swapchain.
- [ ] GPU resource ownership and synchronization tests.
- [ ] Buffer/image utilities and shader compilation pipeline.
- [ ] Render graph and a simple PBR scene.
- [ ] Camera, depth, shadows, HDR, and basic post-processing.
- [ ] Hardware and driver test records.

## Milestone 4: Usable editor
- [ ] Project manager and recent projects.
- [ ] Dockable layout, scene hierarchy, inspector, asset browser, and logs.
- [ ] 2D and 3D viewports with selection, transform controls, and camera input.
- [ ] Undo/redo, shortcuts, themes, keyboard navigation, and layout persistence.
- [ ] Crash recovery, diagnostics, and accessible error screens.
- [ ] Every visible command works or has an honest planned/disabled state.

## Milestone 5: Modeling and animation
- [ ] Primitive and procedural geometry.
- [ ] Mesh editing and non-destructive modifier interface.
- [ ] UVs, normals, tangents, material assignment, and validation.
- [ ] Rigs, constraints, keyframe timeline, curves, and animation graphs.
- [ ] IK, retargeting, blend spaces, morph targets, and interchange.
- [ ] Blender interoperability and format limits documented.

## Milestone 6: Simulation and gameplay
- [ ] Physics abstraction, rigid bodies, collision queries, and constraints.
- [ ] Character controllers, nav meshes, pathfinding, and avoidance.
- [ ] Audio mixer, spatial audio, snapshots, and event triggers.
- [ ] Scripting lifecycle, reload rules, diagnostics, and docs.
- [ ] Optional visual scripting with a debuggable graph.
- [ ] State machines, behavior trees, and perception tools.

## Milestone 7: VFX and advanced rendering
- [ ] Material and VFX graphs.
- [ ] Particle systems, decals, trails, GPU simulation, and profiling.
- [ ] LOD generation, instancing, streaming, and performance budgets.
- [ ] Advanced lighting, volumetrics, GI, upscaling, and ray tracing only with supported capabilities and tests.
- [ ] Modeling tools prioritized by real use cases and benchmark scenes.

## Milestone 8: Platform and production pipeline
- [ ] Validate Linux x86-64, Windows x86-64, and macOS desktop paths.
- [ ] ARM64 Linux testing, including Raspberry Pi-class devices where drivers allow.
- [ ] Android build and lifecycle/input support.
- [ ] Reproducible export pipeline and automated sample-project builds.
- [ ] Packaging, crash diagnostics, profiling, localization, and accessibility.
- [ ] Console support only with authorized SDK access and approval.

## Milestone 9: Collaboration and scale
- [ ] Git-aware asset and project workflow.
- [ ] Optional collaboration server and conflict-safe editing.
- [ ] Authenticated, encrypted transport when networking is added.
- [ ] Replication, profiling, network simulation, prediction, and rollback options.
- [ ] Stable extension SDK and compatibility testing.
- [ ] Release and migration process.

## Priorities

1. Fix data loss, security issues, and build breaks first.
2. Prefer a tested vertical slice over many unfinished buttons.
3. Measure before claiming an optimization.
4. Keep advanced systems optional when they increase size or device requirements.
5. Document status, limitations, and known issues per milestone.
