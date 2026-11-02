#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")/../.."
export PATH="$PWD/.venv/bin:$PATH"
command -v arm-none-eabi-gcc >/dev/null || { echo 'Add the Arm GNU toolchain bin directory to PATH.' >&2; exit 1; }
command -v qmk >/dev/null || { echo 'Run util/init40/setup.sh first.' >&2; exit 1; }
# Fresh compilation: never reuse the vendor package's build artifacts.
make init40/init40:vial:clean
make init40/init40:vial -j"${JOBS:-4}"
