# Building this corpus

**GENERATED DIRECTORY — do not edit by hand.**

This directory holds everything needed to compile the decompiled corpus for its real target, and
nothing that pretends to produce a flashable firmware image. Read "Why there is no `make image`"
before assuming otherwise.

| File | What it is |
|---|---|
| `Makefile` | `check` (host syntax), `cross` (real CK803S objects), `report` (ranked failures), `one FILE=…` |
| `dm32.ld` | Target memory map — FLASH/IRAM/SRAM bases and lengths, with the modem SRAM reservation |

## Quick start

```sh
cd build
make check                              # host syntax-check, no cross-toolchain needed
make cross                              # compile every function for ck803s
make report                             # cross-compile, then rank the failures by error shape
make one FILE=src/rtos/OSFlagPend_03068814.c   # one file, all diagnostics
```

`check` needs only a host C compiler. `cross` and `report` need a C-SKY ELF ABIv2 toolchain whose
`csky-abiv2-elf-gcc` supports `-mcpu=ck803s`; point `CROSS_CC` at it if it is not on `PATH`.

If your toolchain runs inside a container, set `CROSS_CC` to a shim that forwards to it. Every
path in the Makefile is relative to the repository root for exactly this reason — an absolute host
path would not resolve inside a container that bind-mounts the repo elsewhere.

## Current state

| Measure | Result |
|---|---|
| Functions in corpus | 3561 |
| Host syntax-clean | 2883 (81.0%) |
| Cross-compile to CK803S objects | not measured |

The cross-compile figure is blank because no `make cross` run was measured when this file was generated. Run `make cross` to produce it; it is deliberately not carried over from a previous run, since a stale compile rate is worse than none.

Neither number is a build gate; both are quality metrics, and the gap between them and 100% is
analysis debt rather than tooling breakage.

The dominant failure, by a wide margin, is type recovery: a global recovered as a scalar that the
code dereferences as a pointer or a struct accounts for the largest share, in two forms
(`undeclared identifier` and `request for member in something not a structure`). Argument-count
mismatches are fewer but matter more than their count suggests — they mean a recovered prototype
disagrees with its own call sites, so the function would receive arguments in the wrong registers
even where it compiles. Run `make report` for the current ranking.

## Why there is no `make image`

Compiling is not linking, and linking this corpus would not produce firmware. Four independent
blockers, each sufficient on its own:

1. **Coverage.** The corpus covers roughly half the application region by bytes. The remainder is
   partly genuine unrecovered code and partly interleaved data — font bitmaps, string tables and
   lookup tables that must be present byte-exactly and are not represented as C here.

2. **Globals are addresses, not storage.** Thousands of globals are `extern` declarations
   annotated with the absolute address they were recovered at. Nothing defines them. A link would
   need every one placed at its exact address, and many of those addresses hold flash constants
   and literal pools whose byte content this repository does not carry.

3. **Unresolved call targets.** Several hundred call targets are declared as varargs placeholders
   that explicitly assert nothing about the real function. Most are addresses in on-chip
   instruction RAM, which is a separate region this corpus does not cover.

4. **No startup path.** There is no reset handler, no vector table, no startup code, and none of
   the assembly that a context switch, interrupt return or special-register access requires on
   this core. Decompiled C cannot express them.

`dm32.ld` is therefore a tool for making per-object link probes meaningful, not a step toward an
image. Producing modified firmware for this radio is done by patching the stock image in place —
keeping the vendor binary and replacing individual flash sectors — which is a different activity
from rebuilding it from reconstructed source.

## What compiling is actually for

A function that compiles for `ck803s` has a self-consistent signature, body, and set of
expectations about everything it calls. A function that does not has a locatable analysis gap, and
`make report` ranks those gaps so the highest-leverage type-recovery work is visible rather than
buried. Raising the cross-compile rate and improving the corpus are the same task.
