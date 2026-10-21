# Contributing

## Before coding

1. Check the roadmap and open issues.
2. For large changes, open an issue describing the problem, approach, alternatives, dependencies, and test plan.
3. Keep pull requests focused.
4. Do not copy proprietary engine source code, commercial assets, or protected UI designs. Use documented formats and independently written code.

## Setup

Install CMake 3.24 or newer, a C++20 compiler, and Git.

    cmake -S . -B build
    cmake --build build --config Release
    ctest --test-dir build -C Release --output-on-failure

## Code expectations

- Prefer clear ownership and explicit lifetimes.
- Avoid global mutable state and hidden cross-module dependencies.
- Add tests for bug fixes and behavior changes.
- Keep the base build independent of optional AI accounts or private API keys.
- Review a dependency's purpose, license, maintenance, and platform support before adding it.
- Do not add placeholder buttons or claim a feature is complete when it is not.
- Make errors visible and actionable.

## Pull requests

Complete the checklist in .github/pull_request_template.md. Keep CI green. Automated review does not replace tests or human review.
