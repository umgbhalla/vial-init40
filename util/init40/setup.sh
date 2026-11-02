#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")/../.."
# Only these submodules are required by the INIT40 ARM target.
git submodule update --init --depth 1 lib/chibios lib/chibios-contrib lib/printf
for patch in util/init40/patches/*.patch; do
    module="lib/$(basename "$patch" .patch)"
    patch_path="$PWD/$patch"
    if git -C "$module" apply --reverse --check "$patch_path" 2>/dev/null; then
        printf 'Already applied: %s\n' "$patch"
    else
        git -C "$module" apply --check "$patch_path"
        git -C "$module" apply "$patch_path"
    fi
done
python3 -m venv .venv
.venv/bin/python -m pip install -r util/init40/requirements.lock
