#!/usr/bin/env bash
# One-time (or per-machine) setup for dm32uv-re/tools.
#
# pyghidra cannot come from PyPI here: it has to be the exact build Ghidra itself ships,
# because it loads that installation's Java classes - including this project's C-SKY Sleigh
# extension (../vendor/ghidra_csky, with the andn and movih fixes). A PyPI pyghidra would be a
# different Ghidra version with no guarantee its pcode semantics agree.
#
# Usage:  [GHIDRA_INSTALL_DIR=/path/to/ghidra] ./setup.sh
#
# Ghidra discovery order (first directory containing Ghidra/Features/PyGhidra/pypkg/dist wins):
#   1. $GHIDRA_INSTALL_DIR
#   2. a `ghidraRun` found on PATH (symlinks resolved)
#   3. Homebrew: <brew --prefix>/Cellar/ghidra/*/libexec, /opt/homebrew/..., /usr/local/...
#   4. /opt/ghidra*, /usr/local/ghidra*, ~/ghidra*, ~/opt/ghidra*
# Otherwise it exits with an error telling you to set GHIDRA_INSTALL_DIR.
#
# It then locates the wheel Ghidra bundles, writes a machine-local [tool.uv.sources] entry into
# pyproject.toml (the committed file has none, so do not commit that change), writes
# .env.ghidra, and runs `uv sync` (which regenerates uv.lock; uv.lock embeds the local wheel
# path, so it is not tracked). Re-run whenever Ghidra is upgraded or on a new machine.
set -euo pipefail
cd "$(dirname "${BASH_SOURCE[0]}")"

shopt -s nullglob
if [ -n "${GHIDRA_INSTALL_DIR:-}" ] && [ ! -d "$GHIDRA_INSTALL_DIR/Ghidra/Features/PyGhidra/pypkg/dist" ]; then
    echo "ERROR: GHIDRA_INSTALL_DIR=$GHIDRA_INSTALL_DIR has no Ghidra/Features/PyGhidra/pypkg/dist/" >&2
    exit 1
fi
candidates=()
[ -n "${GHIDRA_INSTALL_DIR:-}" ] && candidates+=("$GHIDRA_INSTALL_DIR")
if run="$(command -v ghidraRun 2>/dev/null)"; then
    run="$(python3 -c 'import os,sys; print(os.path.realpath(sys.argv[1]))' "$run")"
    candidates+=("$(dirname "$run")")
fi
if command -v brew >/dev/null 2>&1; then
    candidates+=("$(brew --prefix 2>/dev/null)"/Cellar/ghidra/*/libexec)
fi
candidates+=(/opt/homebrew/Cellar/ghidra/*/libexec /usr/local/Cellar/ghidra/*/libexec)
candidates+=(/opt/ghidra* /usr/local/ghidra* "$HOME"/ghidra* "$HOME"/opt/ghidra*)

GHIDRA_DIR=""
for c in "${candidates[@]}"; do
    [ -d "$c/Ghidra/Features/PyGhidra/pypkg/dist" ] && { GHIDRA_DIR="$c"; break; }
done

if [ -z "$GHIDRA_DIR" ]; then
    echo "ERROR: could not find a Ghidra install with Ghidra/Features/PyGhidra/pypkg/dist/" >&2
    echo "        set GHIDRA_INSTALL_DIR to your Ghidra install root and re-run." >&2
    exit 1
fi

WHEEL="$(find "$GHIDRA_DIR/Ghidra/Features/PyGhidra/pypkg/dist" -name 'pyghidra-*.whl' | sort | tail -1)"
[ -n "$WHEEL" ] || { echo "ERROR: no pyghidra wheel found under $GHIDRA_DIR" >&2; exit 1; }

VERSION="$(basename "$WHEEL" | sed -E 's/^pyghidra-([0-9.]+)-.*/\1/')"
echo "Found Ghidra at:    $GHIDRA_DIR"
echo "Using pyghidra:      $WHEEL (version $VERSION)"

python3 - "$WHEEL" "$VERSION" <<'PYEOF'
import re, sys
wheel, version = sys.argv[1], sys.argv[2]
p = "pyproject.toml"
text = open(p).read()
text = re.sub(r'"pyghidra==[0-9.]+"', f'"pyghidra=={version}"', text)
entry = f'pyghidra = {{ path = "{wheel}" }}'
if re.search(r'^pyghidra = \{ path = "[^"]*" \}', text, re.M):
    text = re.sub(r'^pyghidra = \{ path = "[^"]*" \}', lambda m: entry, text, flags=re.M)
else:
    text = text.rstrip("\n") + "\n\n[tool.uv.sources]\n" + entry + "\n"
open(p, "w").write(text)
PYEOF

echo ""
echo "GHIDRA_INSTALL_DIR=$GHIDRA_DIR" > .env.ghidra
echo "wrote .env.ghidra (source it, or scripts read it directly)"

uv sync
echo ""
echo "Done. Verify with: uv run python -c 'import pyghidra; print(pyghidra.__file__)'"
