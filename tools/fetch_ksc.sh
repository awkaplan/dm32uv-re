#!/usr/bin/env bash
# Fetch the Kaitai Struct compiler (a Java tool; needs a JRE >= 8) into tools/.ksc/ (gitignored).
# Pinned by version AND sha256: the download is refused if the hash differs.
# Usage: tools/fetch_ksc.sh   ->  tools/.ksc/kaitai-struct-compiler-0.11/bin/kaitai-struct-compiler
set -euo pipefail
VER=0.11
SHA256=ff89389d9dc9e770d78a24af328763cb1f8e7b31ce7766c9edf10669a060f2a2
URL="https://github.com/kaitai-io/kaitai_struct_compiler/releases/download/${VER}/kaitai-struct-compiler-${VER}.zip"
DEST="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)/.ksc"
BIN="$DEST/kaitai-struct-compiler-${VER}/bin/kaitai-struct-compiler"
if [ -x "$BIN" ]; then echo "$BIN"; exit 0; fi
TMP="$(mktemp -d)"; trap 'rm -rf "$TMP"' EXIT
curl -fsSL -o "$TMP/ksc.zip" "$URL"
GOT="$( (command -v sha256sum >/dev/null && sha256sum "$TMP/ksc.zip" || shasum -a 256 "$TMP/ksc.zip") | cut -d' ' -f1)"
if [ "$GOT" != "$SHA256" ]; then echo "sha256 mismatch for $URL: got $GOT, want $SHA256" >&2; exit 1; fi
mkdir -p "$DEST"
unzip -q "$TMP/ksc.zip" -d "$DEST"
"$BIN" --version >&2
echo "$BIN"
