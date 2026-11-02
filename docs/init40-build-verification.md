# INIT40 build verification

Verified locally on macOS ARM64 on 2026-11-02.

- Target: `init40/init40:vial`.
- Compiler: Arm GNU Toolchain 14.2.Rel1 (GCC 14.2.1).
- Python: 3.12.13; dependencies pinned in `util/init40/requirements.lock`.
- Command: `util/init40/setup.sh`, then `util/init40/build.sh` with the toolchain on PATH.
- Result: clean compile and link passed; no compiler warnings or errors in the build log.
- ELF sections: text 87,428 bytes; data 1,764 bytes; BSS 14,592 bytes.
- No device was flashed or tested.

## Binary comparison

| Binary | Bytes | Matches fresh build |
|---|---:|---|
| Fresh build | 89,192 | Yes |
| Downloaded October release | 90,960 | No |
| Binary bundled with source | 90,820 | No |

SHA-256:

- Fresh build: `09b4efc6d98a504835b3e0a6c385c006e05019aa42f12de1809aecc5db045e1f`
- Downloaded October release: `1c8653bca2fa8ef2928fab134e207869c13b7be252004b5e78b2ef2d436ced20`
- Binary bundled with source: `78236588831eb8a9dfa74ae9e527cda0bcdbf90e41e1405a67354730790e8aea`

All three images start with stack pointer `0x20000400` and reset vector `0x191`.
This supports a common firmware image layout; it does not prove equivalent behavior.
The original ELF reports GCC 10.1.0. Compiler, source, and generated build metadata
differences prevent attributing the binary differences to a single cause.
The October download also differs from the source package's prebuilt binary.

Re-run the comparison with:

```sh
util/init40/compare.py init40_init40_vial.bin /path/to/downloaded.bin /path/to/vendor.bin
```

The core vendor files and compiled library retain their supplied implementation.
The Vial JSON filename is normalized to lowercase for Linux builds.
Three ChibiOS-Contrib source changes are applied from the tracked patch; ChibiOS itself
matches its pinned upstream commit.
