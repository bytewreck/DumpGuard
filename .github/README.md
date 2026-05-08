# DumpGuard
[![BSD3 License](https://img.shields.io/badge/License-BSD%203--Clause-orange.svg?style=flat)](../LICENSE)
[![Slack](https://img.shields.io/badge/Slack-SpecterOps-02B36C)](https://slack.specterops.io)
[![Sponsored by SpecterOps](https://img.shields.io/endpoint?url=https://raw.githubusercontent.com/specterops/.github/main/config/shield.json)](https://github.com/specterops)

![Logo](logo.jpeg)

DumpGuard is a credential dumping and protocol research tool for modern Windows systems. It abuses the _Remote Credential Guard_ protocol to recover credential material even when _Credential Guard_ is enabled, and also includes a Microsoft v1 authentication package path for session-oriented NTLM extraction.

Current functionality includes:
- NTLMv1 responses
- NTLMv2 responses
- Kerberos service tickets
- Microsoft v1 authentication package dumping for local logon sessions

You may download prebuilt copies from the release section of this repository.

**Disclaimer:** This tool is provided strictly for educational and legitimate testing purposes only. The author of this repository does not condone or support any type of misuse and assumes no responsibility for damages or legal consequences incurred as a result of using this tool.

## Usage Overview

DumpGuard uses a `command` plus `target` model.

- `command` selects the extraction technique.
- `target` selects whether to operate on the current session or enumerate sessions.

Supported commands:
- `/command:ntlmv1`
- `/command:ntlmv2`
- `/command:kerbtgs`
- `/command:msv10`

Supported targets:
- `/target:self`
- `/target:all`

Common Remote Credential Guard parameters:
- `/domain:<DOMAIN>`
- `/username:<SAMACCOUNTNAME>`
- `/password:<PASSWORD>`
- `/spn:<SPN>`

Kerberos TGS parameters:
- `/tgsdomain:<DOMAIN>`
- `/tgsspn:<SPN>`

If `/spn` is omitted for a computer account, DumpGuard defaults to `HOST/<computername>`.

The following table summarizes the currently implemented techniques.

| Technique | Command | Target | Requires<br>SYSTEM | Requires<br>SPN Account | Can Dump<br>Credential Guard |
| -------- | ------- | :----: | :----------------: | :---------------------: | :--------------------------: |
| Extract NTLMv1 via Remote Credential Guard | `ntlmv1` | `self` / `all` | `self`: no<br>`all`: yes | ✅ | ✅ |
| Extract NTLMv2 via Remote Credential Guard | `ntlmv2` | `self` / `all` | `self`: no<br>`all`: yes | ✅ | ✅ |
| Extract Kerberos service tickets via Remote Credential Guard | `kerbtgs` | `self` / `all` | `self`: no<br>`all`: yes | ✅ | ✅ |
| Extract NTLM responses via Microsoft v1 authentication package | `msv10` | `all` | ✅ | :x: | :x: |

## Dumping Your Own Session via Remote Credential Guard

To dump credential material for the current user from an unprivileged context, DumpGuard authenticates to an SPN-enabled account using Remote Credential Guard, and then issue follow-up requests over the established security context.

This works regardless of the state of Credential Guard, but requires credentials for an SPN-enabled account.

Privilege requirement: **None**.

NTLMv1:
```text
DumpGuard.exe /command:ntlmv1 /target:self /domain:<DOMAIN> /username:<SAMACCOUNTNAME> /password:<PASSWORD> [/spn:<SPN>]
```

NTLMv2:
```text
DumpGuard.exe /command:ntlmv2 /target:self /domain:<DOMAIN> /username:<SAMACCOUNTNAME> /password:<PASSWORD> [/spn:<SPN>]
```

Kerberos TGS:
```text
DumpGuard.exe /command:kerbtgs /target:self /domain:<DOMAIN> /username:<SAMACCOUNTNAME> /password:<PASSWORD> [/spn:<SPN>] [/tgsdomain:<DOMAIN>] /tgsspn:<service/host>
```

If `/tgsdomain` is omitted, it defaults to the Remote Credential Guard `/domain` value.

## Dumping All Sessions via Remote Credential Guard

To dump credential material for all currently accessible users from a privileged context, DumpGuard impersonates tokens from running processes, authenticates to an SPN-enabled account using Remote Credential Guard, and then issue follow-up requests over the established security context.

This works regardless of the state of Credential Guard, but requires credentials for an SPN-enabled account.

Privilege requirement: **SYSTEM** (or Administrator).

NTLMv1:
```text
DumpGuard.exe /command:ntlmv1 /target:all /domain:<DOMAIN> /username:<SAMACCOUNTNAME> /password:<PASSWORD> [/spn:<SPN>]
```

NTLMv2:
```text
DumpGuard.exe /command:ntlmv2 /target:all /domain:<DOMAIN> /username:<SAMACCOUNTNAME> /password:<PASSWORD> [/spn:<SPN>]
```

Kerberos TGS:
```text
DumpGuard.exe /command:kerbtgs /target:all /domain:<DOMAIN> /username:<SAMACCOUNTNAME> /password:<PASSWORD> [/spn:<SPN>] [/tgsdomain:<DOMAIN>] /tgsspn:<service/host>
```

If `/tgsdomain` is omitted, it defaults to the Remote Credential Guard `/domain` value.

## Dumping All Sessions via the Microsoft v1 Authentication Package

To dump NTLM responses for currently authenticated users from a privileged SYSTEM context, DumpGuard interacts directly with the NTLM SSP and requests challenge responses for every discovered logon session.

This works only under the following conditions:
- Credential Guard is disabled on the local system.
- Remote users are authenticated to the local system from a remote host over Remote Credential Guard.

Privilege requirement: **SYSTEM**.

```text
DumpGuard.exe /command:msv10
```

This attack can also be carried out using [LSA Whisperer](https://github.com/EvanMcBroom/lsa-whisperer) with the following command:

```text
lsa-whisperer.exe msv1_0 Lm20GetChallengeResponse --luid {session id} --challenge {challenge to clients} [flags...]
```

## Bonus Information

I have reverse engineered and recreated the interfaces exposed by Credential Guard (`LsaIso.exe`) and included them in this repository for anyone interested in further research.

As of October 2025, the following interfaces are implemented:
- BCryptIum
- CloudApIum
- KerberosIum
- LsaIsoMgmtIum
- NtlmIum
- ProvIum

## Acknowledgements

Thank you to [SpecterOps](https://specterops.io/) for supporting this research and to my coworkers who have helped with its development.
- [Elad Shamir](https://twitter.com/elad_shamir) - for inspiring this tool and research, and for offering valuable perspective and encouragement whenever I hit a wall.
- [Evan McBroom](https://github.com/EvanMcBroom) - for sharing useful insights on LSA internals and providing ASN.1 encoders for most of the structures used in this project.

## Related Tools

- [LSA Whisperer](https://github.com/EvanMcBroom/lsa-whisperer) ([Evan McBroom](https://github.com/EvanMcBroom)) - A toolset for interacting with authentication packages.
- [Rubeus](https://github.com/GhostPack/Rubeus) ([Will Schroeder](https://github.com/HarmJ0y), [Charlie Clark](https://x.com/exploitph)) - A C# toolset for raw Kerberos interaction and abuses.
- [Mimikatz](https://github.com/gentilkiwi/mimikatz) ([Benjamin Delpy](https://github.com/gentilkiwi)) - A little tool to play with Windows security.
- [Kekeo](https://github.com/gentilkiwi/kekeo) ([Benjamin Delpy](https://github.com/gentilkiwi/kekeo)) - A little toolbox to play with Microsoft Kerberos in C.

## Related Work

- [Oliver Lyak](https://github.com/ly4k) ([2022](https://research.ifcr.dk/pass-the-challenge-defeating-windows-defender-credential-guard-31a892eee22)) - To my knowledge, the only public research on dumping credentials protected by Credential Guard.
- [James Forshaw](https://x.com/tiraniddo) ([2022](https://project-zero.issues.chromium.org/issues/42451433), [2022](https://project-zero.issues.chromium.org/issues/42451435), [2022](https://project-zero.issues.chromium.org/issues/42451397), [2022](https://project-zero.issues.chromium.org/issues/42451436)) - Vulnerability submissions that slightly documents some of the undocumented interfaces that we have researched.
