# Quality gates

A feature is complete only when code, tests, docs, and supported-platform statements agree.

## Automated CI checks

- The cross-platform matrix configures, builds, and runs CTest on Windows, Linux, and macOS.
- The Ubuntu quality job checks tracked C++ source and header formatting with `clang-format --dry-run --Werror`.
- The same job builds with `clang-tidy` analyzer checks enabled and treats analyzer diagnostics as errors, then runs CTest against that analyzed build.
- Verified on 2026-10-28: GitHub Actions run #7 passed formatting, the clang-tidy analyzed build, and CTest on the quality-gates branch. Main remains unchanged until review and merge. A successful branch run does not imply that the change is already on main.

## Required checks

- Builds with warnings enabled on the supported CI matrix.
- Tests cover normal behavior, invalid inputs, lifecycle transitions, and regressions.
- Integration tests exercise cross-module behavior through public APIs.
- Hardware-specific sample scenes run on real target hardware when appropriate.
- Sanitizers and static analysis are used where compiler/platform support allows.
- Third-party licenses, notices, maintenance state, and vulnerability status are reviewed.
- Performance claims include hardware, drivers, build settings, scene, and measurement method.
- Security-sensitive code receives threat modeling and review.
- Each editor control has an end-to-end test or documented manual test. A screenshot alone does not prove functionality.

## Pull request checks

- [ ] Explain the user problem and intended behavior.
- [ ] Identify public API and serialized format changes.
- [ ] Add or update tests.
- [ ] Update documentation and roadmap status.
- [ ] Record platform limits and fallback behavior.
- [ ] Review dependencies and licenses.
- [ ] Check error handling, resource lifetime, and performance.
- [ ] Confirm no credentials, private data, or unrelated generated files are included.

## AI and automated review

CodeRabbit and other assistants may find issues but can miss defects. Treat their output as an additional signal. Never merge solely because an automated reviewer approves a change. No external AI service is required to build or use Nova Engine.
