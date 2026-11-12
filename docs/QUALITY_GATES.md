# Quality gates

A feature is complete only when code, tests, docs, and supported-platform statements agree.

## Automated CI checks

- The cross-platform matrix configures, builds, and runs CTest on Windows, Linux, and macOS.
- The Ubuntu quality job checks tracked C++ source and header formatting with `clang-format --dry-run --Werror`.
- The same job builds with `clang-tidy` analyzer checks enabled and treats analyzer diagnostics as errors, then runs CTest against that analyzed build.
- Verified on 2026-10-28: push run [#11](https://github.com/nathanjison13-ops/nova-engine/actions/runs/40611805338) and pull-request run [#12](https://github.com/nathanjison13-ops/nova-engine/actions/runs/40611811399) passed formatting, the clang-tidy analyzed build, and CTest on commit `775d03da87d709b397bb1bab7582f594f54a628f`. Earlier runs #9 and #10 passed on commit `b0c3544d8a6c3dee4ce2a394a12bedd08b76c7fd`. The quality-gate workflow remains on draft PR #8 and has not been merged into main.

## Main branch protection (verified 2026-11-12)

- Main branch protection is enabled and enforced for everyone, including administrators.
- Required status checks are `ubuntu-latest / C++20`, `windows-latest / C++20`, and `macos-latest / C++20`.
- Required checks must be up to date with the base branch.
- Force pushes and branch deletion are disabled.
- No required pull-request review count is configured.
- The formatting/static-analysis job is verified on draft PR #8 but is not yet part of main and is not a required main check.

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
