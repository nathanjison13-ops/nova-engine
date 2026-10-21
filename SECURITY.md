# Security policy

## Reporting a vulnerability

Do not publish exploit details or secrets in a public issue. Use GitHub private vulnerability reporting for this repository if enabled. If it is unavailable, ask for a private contact route without including exploit details.

## Scope

This starter has very limited functionality and has not received a security audit. This policy does not mean the engine is already secure.

## Expectations

- Never commit credentials, signing keys, private certificates, or personal data.
- Validate untrusted projects, assets, plugins, scripts, and network input.
- Do not execute imported scripts or native plugins automatically.
- Keep project loading and asset import boundaries explicit.
- Add dependency pinning and vulnerability checks as the pipeline expands.
- Review authentication, cryptography, sandboxing, and privilege boundaries before shipping those systems.
- Document supported versions and the response plan for confirmed issues.
