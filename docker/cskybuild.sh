#!/usr/bin/env bash
# Drop-in replacement for the main repo's firmware/tools/csky-build/cskybuild.sh, for use
# INSIDE this image. Same CLI contract (`cskybuild.sh <toolchain-cmd> [args...]`, current
# working directory is where relative paths resolve), so existing build_*.py scripts that
# shell out to cskybuild.sh work unmodified if pointed at this file instead - but there is no
# nested Docker container to spin up here: csky-abiv2-elf-gcc and friends are already on PATH
# in this image (built from vendor/csky-toolchain-build, see ../Dockerfile), so this just
# execs the requested tool directly.
set -euo pipefail
exec "$@"
