#!/usr/bin/env python3
"""Scaffold a new manifest-built patch from tools/templates/new_patch/.

    python3 tools/src/dm32_patch_tools/new_patch.py my_patch            # -> tools/patches/my_patch/
    python3 tools/src/dm32_patch_tools/new_patch.py my_patch --dest /tmp/my_patch

It writes four files:
  <name>.c           a minimal C handler that calls a stock function BY NAME (a call-site
                     redirect: it does the callee's job, then its own)
  <name>.ld          a linker script that INCLUDEs the generated tools/link/dm32_patch_memory.ld
                     and dm32_stock_symbols.ld, with the entry point placed first
  <name>.patch.json  a build_manifest_patch.py manifest with one hook splice whose address and
                     expected stock bytes are TODO placeholders; the builder refuses to run
                     until they are filled in
  README.md          the steps from a TODO hook site to staged sectors

Why tools/patches/: everything under tools/ is hand-maintained and survives the corpus
regeneration that rewrites src/, include/, meta/, site/ and build/ (CLAUDE.md, README.md).
tools/examples/ holds the curated, documented examples, so a work-in-progress patch goes beside
it rather than inside it. tools/patches/ is gitignored: this repository ships the stock-firmware
documentation, the corpus, the tooling and the two worked examples only; a patch that adds new
radio behaviour belongs in its own repository (see README.md "Scope"), built with
build_manifest_patch.py --extra-allocations for its claims. Use --dest to scaffold there directly.
Build outputs never go here: build_manifest_patch.py defaults to out/patches/<name>/, gitignored.

Refuses to overwrite an existing directory. Pure Python (stdlib) only; no toolchain needed.
"""
from __future__ import annotations

import argparse
import pathlib
import re
import sys

HERE = pathlib.Path(__file__).resolve().parent
REPO_ROOT = HERE.parents[2]
TEMPLATE_DIR = REPO_ROOT / "tools/templates/new_patch"
TOKEN = "__PATCH_NAME__"

# template file -> output file name (TOKEN is substituted in both names and contents)
FILES = {
    "patch.c.tmpl": f"{TOKEN}.c",
    "patch.ld.tmpl": f"{TOKEN}.ld",
    "patch.json.tmpl": f"{TOKEN}.patch.json",
    "README.md.tmpl": "README.md",
}


def scaffold(name: str, dest: pathlib.Path) -> list[pathlib.Path]:
    if not re.fullmatch(r"[a-z][a-z0-9_]{0,40}", name):
        raise ValueError(f"name {name!r} must be a lowercase C identifier ([a-z][a-z0-9_]*, "
                         f"max 41 chars): it becomes symbol names such as {name}_entry")
    if dest.exists():
        raise FileExistsError(f"{dest} already exists; refusing to overwrite it")
    dest.mkdir(parents=True)
    written = []
    for tmpl, out_name in FILES.items():
        text = (TEMPLATE_DIR / tmpl).read_text().replace(TOKEN, name)
        out = dest / out_name.replace(TOKEN, name)
        out.write_text(text)
        written.append(out)
    return written


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("name", help="patch name (lowercase C identifier)")
    ap.add_argument("--dest", type=pathlib.Path, default=None,
                    help="target directory (default: tools/patches/<name>/)")
    args = ap.parse_args(argv)
    dest = (args.dest or REPO_ROOT / "tools" / "patches" / args.name).resolve()
    try:
        files = scaffold(args.name, dest)
    except (ValueError, FileExistsError) as e:
        print(f"FAIL: {e}", file=sys.stderr)
        return 1
    for f in files:
        print(f"wrote {f}")
    manifest = dest / f"{args.name}.patch.json"
    try:
        shown = manifest.relative_to(REPO_ROOT)
    except ValueError:
        shown = manifest
    print(f"\nNext: fill in the TODO hook site in {manifest.name} (see README.md), then\n"
          f"  python3 tools/src/dm32_patch_tools/build_manifest_patch.py {shown}\n"
          f"inside the toolchain image. Until the TODO is filled in, the build fails on purpose.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
