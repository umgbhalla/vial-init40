# INIT40 Vial firmware

This repository keeps Vial-QMK history and adds the INIT40 vendor source package.
The integration starts at upstream `dd43959ae5c08d8a28d38a1acf7b04e86b14a344`.
The source package's old build metadata reports `1d9c72972d-dirty` (2026-02-23).
That commit is an ancestor of the integration base, 12 commits behind it. All changes
between those two upstream commits are under `keyboards/`; their shared core is identical.
The metadata alone does not prove the exact vendor source history.

## Build

Install Python 3.12, Git, make, and Arm GNU Toolchain 14.2.Rel1 for `arm-none-eabi`.
Add the toolchain's `bin` directory to PATH, then run:

```sh
git clone https://github.com/umgbhalla/vial-init40.git
cd vial-init40
util/init40/setup.sh
util/init40/build.sh
```

The target is `init40/init40:vial`. Output: `init40_init40_vial.bin`.
The build script starts with a clean target. It sets `SKIP_GIT=yes` because setup
already prepares the required submodules; this also omits Git version metadata. It does not flash a device.
GitHub Actions also builds this target and stores the BIN, ELF, and map as artifacts.

Setup initializes only ChibiOS, ChibiOS-Contrib, and printf. It applies the tracked
ChibiOS-Contrib patch. The submodule then appears modified by design. Re-running
setup accepts an already applied patch and refuses conflicting changes.

## Vendor code

`lib/rdr_lib/librdrcommon.a` is the vendor's precompiled ARM library. Its matching
header is included, but its implementation source was not supplied. Keyboard
transport, report handling, and other vendor functions depend on this library.
This repository can rebuild the firmware around it; it cannot rebuild that library.

The vendor edits include hybrid six-key/NKRO handling, USB protocol and country-code
changes, and INIT40 keyboard definitions. Other upstream keyboards are retained for
history and reference; this fork's CI validates only INIT40.

The source archive's compiled ELF reports GCC 10.1.0. Different compiler versions,
source edits, build dates, and Git metadata can change the resulting binary.
A successful compile does not establish equivalence with a downloaded release or
prove that the firmware works on physical hardware.

See `docs/init40-build-verification.md` for the measured build and binary comparison.
