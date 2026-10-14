"""Generate a clangd compilation database for this repo's C sources.

WHY THIS EXISTS: patch sources (tools/examples, tools/link/example, tools/patches/*) are built
with csky-abiv2-elf-gcc inside the docker image, and the decompiled corpus (src/) with
build/Makefile. Without a compile_commands.json an editor's clangd parses every file as host C
(arm64 macOS: 64-bit pointers and longs, signed char) with no include path, so patch code against
tools/include/dm32_patch_api.h shows bogus errors and wrong sizeof/struct offsets.

WHAT IT WRITES (default directory: out/, which .gitignore already covers):
  out/compile_commands.json        clangd-parseable entries (see FLAGS below)
  out/compile_commands.csky.json   the SAME files with the REAL cross-compiler command lines, for
                                   reference and for tools that run inside the docker image
Why out/ and not the repo root: the entries hold absolute paths (clangd requires an absolute
"directory"), so the file is machine-specific and must not be committed - out/ is already
ignored, the repo root is not. clangd does not look in out/ by itself; point it there with a
`.clangd` file at the repo root containing

    CompileFlags:
      CompilationDatabase: out

or `clangd --compile-commands-dir=out`, or pass `--out-dir .` to this script (then add
compile_commands*.json to .gitignore yourself).

FLAGS, AND WHY THEY ARE NOT THE REAL ONES: clang has no C-SKY backend (`clang -print-targets`
lists none), so `-mcpu=ck803s` is an error to clangd. Each entry instead parses for
`--target=thumbv7m-none-eabi`, the closest target clang always ships, chosen to match the ABI
facts that change what C means, each checked against `csky-abiv2-elf-gcc -mcpu=ck803s -dM -E`
(GCC 6.3.0, docker image dm32uv-re-pipeline):
  32-bit int/long/pointers, size_t = unsigned int   both
  little-endian                                     both (__CSKYLE__)
  plain char is UNSIGNED                            both (__CHAR_UNSIGNED__); -funsigned-char
                                                    is passed anyway so this never drifts
  long double is 8 bytes, long long 8               both
  soft-float                                        thumbv7m has no FPU either
The one known mismatch: __BIGGEST_ALIGNMENT__ is 4 on C-SKY, 8 on ARM EABI, so `long long`/
`double` members inside a struct may sit at different offsets under clangd than on the target.
Treat a clangd-reported offsetof()/sizeof() of a struct containing 64-bit members as advisory.
ARM's own predefined macros (__arm__, __thumb__, __ARM_EABI__, ...) are undefined and the real
toolchain's C-SKY ones defined in their place (CSKY_DEFINES below - the exact set GCC predefines,
copied from -dM output; GCC 6.3 defines __CKCORE__, not a lowercase __ckcore__), so any
`#ifdef __CSKY__` path is the one clangd sees. -ffreestanding: there is no ARM sysroot on a dev
machine, and clang's own stdint.h/stddef.h are self-contained only in freestanding mode
(the target build is nominally hosted but no source here includes a libc header).
-std=gnu11 is GCC 6.3's default. Warning flags match the real build (-Wall for patch code,
-w for the decompiled corpus, as build/Makefile does - its warnings are decompiler noise).

Usage:
    python3 gen_compile_commands.py                  # patch sources + corpus -> out/
    python3 gen_compile_commands.py --no-corpus      # patch sources only (fast clangd index)
    python3 gen_compile_commands.py --out-dir .      # write at the repo root instead
"""
from __future__ import annotations

import argparse
import json
import pathlib

REPO_ROOT = pathlib.Path(__file__).resolve().parent.parent.parent.parent

CLANG_TARGET = "thumbv7m-none-eabi"
# Exact predefined-macro set of `csky-abiv2-elf-gcc -mcpu=ck803s` (GCC 6.3.0) that is C-SKY
# specific; generic ones (__ELF__, __SIZEOF_*__, __CHAR_UNSIGNED__ ...) clang already agrees on.
CSKY_DEFINES = ["__CSKY__=2", "__CSKYABI__=2", "__CSKYABIV2__=1", "__CSKYLE__=1",
                "__CKCORE__=2", "__CK803__=1", "__CK803S__=1", "__CSKY_SOFT_FLOAT__=1"]
ARM_UNDEFINES = ["__arm__", "__thumb__", "__thumb2__", "__ARM_EABI__", "__ARMEL__",
                 "__ARM_ARCH", "__ARM_ARCH_7M__"]
CLANG_COMMON = ([f"--target={CLANG_TARGET}", "-std=gnu11", "-funsigned-char", "-ffreestanding"]
                + [f"-U{u}" for u in ARM_UNDEFINES] + [f"-D{d}" for d in CSKY_DEFINES])

CROSS_CC = "csky-abiv2-elf-gcc"


def patch_entries() -> list[dict]:
    """(directory, file, real gcc flags) for every patch source, mirroring its real build."""
    rows = []
    tools = REPO_ROOT / "tools"
    # tools/examples/*.c - README: run from tools/examples with -I../include
    for f in sorted((tools / "examples").glob("*.c")):
        rows.append((tools / "examples", f, ["-mcpu=ck803s", "-I../include"]))
    # tools/examples/snake/*.c - build_snake_patch.py: -mcpu=ck803s -O2 -Wall -ffunction-sections
    # (it includes ../../include/dm32_patch_api.h by relative path; -I is harmless and lets a
    # newly added file use the plain "dm32_patch_api.h" spelling)
    for f in sorted((tools / "examples" / "snake").glob("*.c")):
        rows.append((tools / "examples" / "snake", f,
                     ["-mcpu=ck803s", "-O2", "-Wall", "-ffunction-sections", "-I../../include"]))
    # tools/link/example/*.c - tools/Makefile link-example, run from tools/
    for f in sorted((tools / "link" / "example").glob("*.c")):
        rows.append((tools, f, ["-mcpu=ck803s", "-O2", "-Wall", "-ffunction-sections",
                                "-fdata-sections", "-Iinclude"]))
    # tools/patches/<name>/*.c - future per-patch directories; same flags as the link example
    for f in sorted((tools / "patches").glob("*/*.c")) if (tools / "patches").is_dir() else []:
        rows.append((tools, f, ["-mcpu=ck803s", "-O2", "-Wall", "-ffunction-sections",
                                "-fdata-sections", "-Iinclude"]))
    return [dict(directory=d, file=f, real=r, warn=["-Wall"] if "-Wall" in r else [])
            for d, f, r in rows]


def corpus_entries() -> list[dict]:
    """build/Makefile: run from the repo root, CROSS_CFLAGS = -mcpu=ck803s -w -Iinclude."""
    return [dict(directory=REPO_ROOT, file=f, real=["-mcpu=ck803s", "-w", "-Iinclude"], warn=["-w"])
            for f in sorted((REPO_ROOT / "src").rglob("*.c"))]


def to_clangd(e: dict) -> dict:
    # keep -I/-D/-O/-f flags from the real command, drop the C-SKY-only -mcpu
    keep = [a for a in e["real"] if not a.startswith("-mcpu=") and a not in ("-Wall", "-w")]
    rel = e["file"].relative_to(e["directory"])  # every source sits under its build dir
    args = ["clang", *CLANG_COMMON, *keep, *e["warn"], "-c", str(rel)]
    return {"directory": str(e["directory"]), "file": str(e["file"]), "arguments": args}


def to_real(e: dict) -> dict:
    rel = e["file"].relative_to(e["directory"])
    args = [CROSS_CC, *e["real"], "-c", str(rel)]
    return {"directory": str(e["directory"]), "file": str(e["file"]), "arguments": args}


def main(argv: list[str] | None = None) -> None:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--out-dir", type=pathlib.Path, default=REPO_ROOT / "out",
                    help="where to write compile_commands.json (default: out/, gitignored)")
    ap.add_argument("--no-corpus", action="store_true",
                    help="omit the ~3400 decompiled src/**/*.c files")
    a = ap.parse_args(argv)

    entries = patch_entries()
    n_patch = len(entries)
    if not a.no_corpus:
        entries += corpus_entries()
    out_dir = a.out_dir.resolve()
    out_dir.mkdir(parents=True, exist_ok=True)
    (out_dir / "compile_commands.json").write_text(
        json.dumps([to_clangd(e) for e in entries], indent=1) + "\n")
    (out_dir / "compile_commands.csky.json").write_text(
        json.dumps([to_real(e) for e in entries], indent=1) + "\n")
    print(f"wrote {out_dir / 'compile_commands.json'}: {n_patch} patch source(s) + "
          f"{len(entries) - n_patch} corpus file(s)")
    print(f"wrote {out_dir / 'compile_commands.csky.json'} (real {CROSS_CC} command lines)")
    if out_dir != REPO_ROOT:
        print(f"clangd: add a .clangd with 'CompileFlags: {{CompilationDatabase: "
              f"{out_dir.relative_to(REPO_ROOT) if out_dir.is_relative_to(REPO_ROOT) else out_dir}}}' "
              f"or run clangd --compile-commands-dir={out_dir}")


if __name__ == "__main__":
    main()
