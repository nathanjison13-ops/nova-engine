# Architecture

The starter contains only a small lifecycle stub. The layers below describe the intended architecture, not systems that already exist.

## Planned layers

1. Platform: windows, input, file paths, threads, clocks, capabilities, and platform services.
2. Core runtime: logging, allocators, task scheduling, events, and lifecycle.
3. Asset layer: stable IDs, metadata database, dependency graph, import jobs, caches, serialization, and streaming.
4. World layer: entities, components, systems, transform hierarchy, scenes, prefabs, and world partitioning.
5. Rendering: renderer interface, Vulkan backend first, GPU resource lifetime, shader compilation, frame graph, materials, lighting, and presentation.
6. Simulation: physics interface, collision queries, animation evaluation, navigation, and audio.
7. Scripting: C++ gameplay modules and optional language adapters after ownership, reload, and security rules are defined.
8. Editor: dock layout, command system, asset browser, scene hierarchy, properties, viewport, undo/redo, and customization.
9. Project pipeline: configuration, asset cooking, builds, packaging, platform validation, diagnostics, and profiling.

## Dependency rules

- Core must not depend on the editor.
- Editor-only dependencies must not be required by shipped games.
- Renderer-specific handles must not leak into asset identity or scene formats.
- Query platform capabilities rather than assuming them from OS names.
- Optional systems should sit behind adapters where useful and practical.
- Long-lived serialized formats need versions and migration tests.

## Renderer direction

Vulkan is the first planned explicit graphics backend. First establish device selection, validation, resource ownership, synchronization, swapchain lifecycle, shader compilation, and capability fallbacks. Do not claim advanced global illumination, ray tracing, or platform support before an implementation can be tested.

## Editor direction

Build a real application, not a static mockup. Each visible action must connect to a working command, show an honest disabled state, or be documented as planned. Support docking, saved layouts, keyboard navigation, scalable UI, configurable shortcuts, and recovery after a crash.

## Licensing and interoperability

Check third-party licenses, supported platforms, maintenance, and notices before adding a dependency. Prefer documented formats and plugins over copying protected source code, assets, or UI designs.
