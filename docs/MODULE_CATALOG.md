# Module catalog

This is a coverage map for planning. Each item is planned unless code, tests, and documentation show it is implemented. Listing a feature does not claim parity with another engine.

## Core and world
Lifecycle, logging, events, reflection metadata, serialization, memory diagnostics, task scheduling, performance hooks, crash diagnostics, plugin boundaries, entities, components, systems, transform hierarchy, prefabs, world partitioning, streaming, deterministic update policy, and save/load.

## Rendering and graphics
Vulkan-first backend abstraction, validation, resource barriers, render graph, shader compilation, pipelines, materials, texture systems, cameras, depth, forward/deferred paths, PBR, lighting, shadow maps, environment lighting, HDR, fog, volumetrics, anti-aliasing, post-processing, GPU particles, decals, reflections, global illumination approaches, upscaling, optional ray tracing, 2D renderer, sprite batching, tilemaps, UI rendering, capture tools, GPU timing, and render diagnostics. Status must be specific to backend, hardware, and drivers.

## Modeling and geometry
Primitive creation, vertex/edge/face editing, transforms, extrude, inset, bevel, loop tools, normals, tangents, mirroring, subdivision, smoothing, decimation, remeshing, mesh validation, procedural generation, node-based geometry, instancing, LODs, UV seams and unwrap, packing, texture/material assignment, baking, vertex colors, sculpting, retopology helpers, references, orthographic views, measurements, and export checks.

## Rigging and animation
Skeletons, bones, rig constraints, IK/FK, retargeting, skin weights, clips, timelines, curves, keyframes, animation graphs, state machines, blend spaces, additive animation, morph targets, root motion, motion-capture import, animation layers, markers, events, preview, and batch processing.

## Physics and simulation
Rigid bodies, colliders, joints, raycasts, sweeps, overlaps, character controllers, vehicles, cloth, soft bodies, destruction, fluids, hair, particles, collision diagnostics, nav meshes, pathfinding, dynamic obstacles, steering, avoidance, crowds, and query visualization.

## Materials and assets
Material graphs, texture graphs, texture painting, procedural textures, surface layers, terrain tools, material instances, shader variants, baking, asset metadata, previews, dependency inspection, import presets, batch import, validation, source preservation, derived-data cache, hot reload, and import logs.

## VFX and compositing
Node-based effect graphs, CPU/GPU particles, emitters, forces, trails, ribbons, beams, decals, lights, collisions, sub-emitters, procedural effects, event routing, deterministic seeds where feasible, smoke, fire, fluid, destruction, compositing, and performance budgets.

## Audio
Asset import, buses, mixer, spatial audio, attenuation, reverb sends, snapshots, sound cues, music states, event routing, visualization, and profiling. Verify codec licenses.

## Gameplay and scripting
Native C++ gameplay API, optional Lua, Python editor automation, and C# integration only after runtime, licensing, security, and cross-platform requirements are reviewed. Visual scripting, graph debugger, breakpoints, watch values, state machines, behavior trees, perception, gameplay tags, input mapping, widgets, and data-driven config are targets.

## Editor UX
Project manager, dockable panels, scene hierarchy, inspector, asset browser, viewport, console, log filtering, command palette, shortcut editor, context menus, themes, font scaling, custom colors, saved layouts, undo/redo, search, multi-monitor layouts, gizmos, camera modes, selection filters, snapping, measurements, bookmarks, reference images, accessibility, localization, recovery, and performance telemetry. Every control must be functional or honestly marked as planned.

## Networking
Transport abstraction, encrypted connections, authentication interfaces, server/client model, authority controls, replication, interpolation, prediction, rollback options, lag simulation, metrics, dedicated server builds, session discovery, and reconnect handling. Network security is future work and not a current guarantee.

## Build, ship, and maintain
Build presets, asset cooking, platform packaging, reproducible builds, dependency notices, signing hooks, symbol archives, crash reports, profiling captures, patching strategy, localization, accessibility checks, CI sample projects, and release notes.

## Extension and collaboration
Plugin API, script/native extensions, version checks, API docs, examples, Git workflows, optional shared sessions, conflict handling, and encrypted collaboration services. AI services must remain optional and never be required to build or use the engine.

## Interoperability and boundaries

Initial open-format focus is glTF. FBX, USD, and other formats need separate technical and licensing review. Console builds depend on authorized SDKs and platform-holder approval. No single roadmap can guarantee literal feature equivalence with every engine and model editor.
