#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")/../.."
export PATH="$PWD/.venv/bin:$PATH"
command -v arm-none-eabi-gcc >/dev/null || { echo 'Add the Arm GNU toolchain bin directory to PATH.' >&2; exit 1; }
command -v qmk >/dev/null || { echo 'Run util/init40/setup.sh first.' >&2; exit 1; }
# Refuse an unprepared checkout instead of silently building with stock drivers.
for module in lib/chibios lib/chibios-contrib lib/printf; do
    expected=$(git ls-tree HEAD "$module" | awk '{print $3}')
    actual=$(git -C "$module" rev-parse HEAD)
    [ "$actual" = "$expected" ] || { echo "Run util/init40/setup.sh: wrong revision for $module" >&2; exit 1; }
done
for patch in util/init40/patches/*.patch; do
    git -C "lib/$(basename "$patch" .patch)" apply --reverse --check "$PWD/$patch"
done
# Fresh compilation: never reuse the vendor package's build artifacts.
make init40/init40:vial:clean SKIP_GIT=yes
make init40/init40:vial SKIP_GIT=yes -j"${JOBS:-4}"
