# Patch-development lifecycle for dm32uv-re: find a target, build a patch, verify it.
#
# NOT generated output - unlike ../build/Makefile (which rebuilds from the corpus every time
# PROVENANCE.md's source analysis changes), this one is hand-maintained and survives
# regeneration, same as the rest of tools/ - see tools/README.md and ../README.md's "Building
# patches" section.
#
# Run from inside the Docker image (../docker/README.md): `docker compose run --rm dm32uv-re`
# drops you at /work/tools with this Makefile already in the working directory.
#
# TARGETS
#   make sectors       regenerate meta/sectors.json (which sector is my target in?)
#   make xrefs         regenerate meta/xrefs.json (needs disasm first)
#   make patch-sites   regenerate meta/patch_sites.json (catalogued patch-site cross-check)
#   make patch-risk    regenerate meta/patch_risk.json (needs sectors/xrefs/patch-sites first)
#   make disasm        regenerate meta/disasm.jsonl (needs Ghidra - uses `uv run`; slow, whole
#                      corpus by default - pass LIMIT=50 for a quick smoke test)
#   make export-all    disasm -> xrefs -> sectors -> patch-sites -> patch-risk, in the
#                      dependency order export_*.py's own docstrings document
#   make build-patch   assemble HANDLER and splice it into STOCK_SECTOR at SECTOR_BASE,
#                      hooking HOOK_ADDR - see its own --help for every variable
#   make verify-patch  corpus pre-flight + QEMU stock-vs-patched boot comparison for SECTOR
#                      at OFFSET (exit 0 PASS, 1 FAIL, 3 DIFFERS, 4 INCONCLUSIVE)
#   make lookup        what is Q? (address / name; ARGS="--search" / "--c" / "--json")
#   make clean         remove the regenerated meta/*.json this Makefile's targets produce
#   make build-manifest MANIFEST=<x.patch.json> [OUT=<dir>] [COMPARE=<ref.bin>] [ARGS=--require-claims]
#                      build a patch from a declarative manifest (build_manifest_patch.py)
#   make snake-manifest   rebuild Snake from its manifest and prove it matches the committed image
#   make new-patch NAME=<name>   scaffold tools/patches/<name>/ (or ARGS="--dest <dir>")
#   make bps-create    make a shareable BPS patch: BPS_TARGET=patched.bin BPS_OUT=x.bps [BPS_NAME=..]
#   make bps-apply     apply one: BPS_PATCH=x.bps BPS_OUT=patched.bin [BPS_SOURCE=<your own
#                      verified backup>] (its per-unit sector 0x0300b000 is kept, never written)
#   make bps-info      show a BPS patch's metadata and changed sectors: BPS_PATCH=x.bps
#   make compile-commands  write ../out/compile_commands.json for clangd (ARGS=--no-corpus)
#   make specs        regenerate ../specs/generated from ../specs/rdl + ../specs/ksy (needs
#                      `uv sync --group specs`; fetches the Kaitai compiler via fetch_ksc.sh)
#   make specs-check   exit 1 if a spec breaks ../specs/README.md's rules or generated/ is stale
#   make link-artifacts / link-check / link-example   patch linking (see the section near the end)
#   make test          host test suite (plain python3, no toolchain/QEMU, a few seconds):
#                      sha256 sidecars, derived IRAM, stage/build safety gates, doc-claim and
#                      link-artifact checks; JUnit XML in ../out/test-results/host.xml
#   make test-all      `test` plus the image suite (Snake golden rebuilds via build_snake_patch.py
#                      and snake.patch.json, Snake QEMU screen fingerprint, verify_patch
#                      stock-vs-stock; ~2 min, repo mounted read-only). From the host it runs
#                      the image suite via `docker run TEST_IMAGE`; inside the image, directly.
#                      JUnit XML in ../out/test-results/image.xml. See ../tests/run_tests.py.
#   make ci            every fast host-side gate in one go: test + link-check + patch-api-check
#                      + check_doc_claims.py - the "definition of done" signal for an agent
#   make doctor        environment check (python, images, toolchain, QEMU, submodules, capstone)
#   make lint-manifest MANIFEST=x.patch.json [ARGS=--strict]
#                      static lint of a manifest/hook sites (hook-at-entry, r15-liveness, ...)
#   make verify-manifest MANIFEST=x.patch.json [ARGS='--image img.bin --json -']
#                      verify a manifest patch against its own "verify" block under QEMU
#   make patch-api / patch-api-check
#                      regenerate ../meta/patch_api.json from include/dm32_patch_api.h /
#                      exit 1 if the committed copy is stale
#
# To regression-check the whole image itself (not a target here - it drives `docker compose`
# from the HOST, so it can't run from inside the container this Makefile runs in): from the
# host, `cd docker && ./smoke_test.sh`.
#
# CONFIGURATION (all have defaults matching this submodule's own layout; override as needed)
#   PYTHON        plain interpreter for the pure-python export_*.py steps (default: python3)
#   UV            pyghidra-aware runner for export_disasm.py (default: uv run python3)
#   HANDLER       patch handler source (.S or .c) for `make build-patch`
#   STOCK_SECTOR  current 4KB sector bytes for `make build-patch`
#   SECTOR_BASE   that sector's own flash address, e.g. 0x030e1000
#   HOOK_ADDR     address of the site to redirect, e.g. 0x030e100c
#   HOOK_BYTES    expected stock bytes at HOOK_ADDR, as hex, e.g. 08ea0000
#   HOOK_KIND     br or bsr (default: br)
#   PLACE_ADDR    explicit handler placement address (default: auto - first erased run found)
#   OUT           output modded sector path for `make build-patch` (default: out.bin)
#   SECTOR        modded sector to check for `make verify-patch` (default: $(OUT))
#   OFFSET        that sector's flash write offset for `make verify-patch`, e.g. 0xE1000
#   KEEP          directory to keep both QEMU runs (logs + frames) in, for `make verify-patch`
#   LIMIT         cap on export_disasm.py's function count (default: unset = whole corpus)
#   MANIFEST      patch manifest (*.patch.json) for `make build-manifest`
#   COMPARE       reference image `make build-manifest` must match byte-for-byte (exit 1 if not)
#   NAME          new patch name for `make new-patch`
#   TEST_IMAGE    docker image for `make test-all`'s image suite
#                 (default: dm32uv-re-pipeline:latest; build it from ../docker/)

PYTHON ?= python3
UV     ?= uv run python3

SRC := src/dm32_patch_tools

HANDLER      ?=
STOCK_SECTOR ?=
SECTOR_BASE  ?=
HOOK_ADDR    ?=
HOOK_BYTES   ?=
HOOK_KIND    ?= br
PLACE_ADDR   ?=
OUT          ?= out.bin
SECTOR       ?= $(OUT)
OFFSET       ?=
LIMIT        ?=
KEEP         ?=
Q            ?=
ARGS         ?=

.PHONY: all help sectors xrefs patch-sites patch-risk disasm export-all build-patch verify-patch lookup clean
all: help

# Print the whole header comment: every line up to the first non-comment line.
help:
	@awk 'NR < 3 { next } /^#/ { sub(/^# ?/, ""); print; next } { exit }' $(lastword $(MAKEFILE_LIST))

# ---- static analysis (pure-python, no Ghidra) --------------------------------------------
sectors:
	$(PYTHON) $(SRC)/export_sectors.py

xrefs:
	$(PYTHON) $(SRC)/export_xrefs.py

patch-sites:
	$(PYTHON) $(SRC)/export_patch_sites.py

patch-risk: sectors xrefs patch-sites
	$(PYTHON) $(SRC)/export_patch_risk.py

# ---- static analysis (needs Ghidra - this image's pyghidra venv, via `uv run`) ------------
disasm:
	$(UV) $(SRC)/export_disasm.py $(if $(LIMIT),--limit $(LIMIT))

export-all: disasm xrefs sectors patch-sites patch-risk
	@echo "all meta/ exports regenerated"

# ---- the patch lifecycle itself ------------------------------------------------------------
build-patch:
	@test -n "$(HANDLER)" || { echo "usage: make build-patch HANDLER=my_handler.S STOCK_SECTOR=<sector.bin> SECTOR_BASE=0x030e1000 HOOK_ADDR=0x030e100c HOOK_BYTES=08ea0000 [HOOK_KIND=br] [OUT=out.bin]"; exit 1; }
	@test -n "$(STOCK_SECTOR)" || { echo "STOCK_SECTOR is required - see 'make help'"; exit 1; }
	@test -n "$(SECTOR_BASE)" || { echo "SECTOR_BASE is required - see 'make help'"; exit 1; }
	@test -n "$(HOOK_ADDR)" || { echo "HOOK_ADDR is required - see 'make help'"; exit 1; }
	@test -n "$(HOOK_BYTES)" || { echo "HOOK_BYTES is required - see 'make help'"; exit 1; }
	$(PYTHON) $(SRC)/build_patch.py \
	    --handler $(HANDLER) --stock-sector $(STOCK_SECTOR) \
	    --sector-base $(SECTOR_BASE) --hook-addr $(HOOK_ADDR) \
	    --expect-hook-bytes $(HOOK_BYTES) --hook-kind $(HOOK_KIND) \
	    $(if $(PLACE_ADDR),--place-addr $(PLACE_ADDR)) \
	    --out $(OUT)

verify-patch:
	@test -n "$(OFFSET)" || { echo "usage: make verify-patch SECTOR=modded.bin OFFSET=0xE1000"; exit 1; }
	$(PYTHON) $(SRC)/verify_patch.py --sector $(SECTOR) --offset $(OFFSET) \
	    $(if $(KEEP),--keep-dir $(KEEP))

lookup:
	@test -n "$(Q)" || { echo "usage: make lookup Q=0x03012e14 [ARGS='--c --full' | ARGS=--search Q=keypad]"; exit 1; }
	@$(PYTHON) $(SRC)/lookup.py $(ARGS) $(Q)

# meta/ is bind-mounted from the host (see ../docker/docker-compose.yml), so this genuinely
# deletes the host's copies, not just a throwaway container path - re-run `make export-all`
# (whole corpus, no LIMIT) to regenerate everything this removes.
clean:
	rm -f ../meta/disasm.jsonl ../meta/xrefs.json ../meta/sectors.json \
	      ../meta/patch_sites.json ../meta/patch_risk.json

# ---- link artifacts: patch building as ordinary embedded-C linking -------------------------
#   make link-artifacts  regenerate link/dm32_stock_symbols.ld + link/dm32_patch_memory.ld
#                        (from ../meta/functions.json, include/dm32_patch_api.h,
#                        ../data/allocations.json) and ../out/dm32_stock.elf (pure python)
#   make link-check      exit 1 if the committed link/*.ld are stale against their inputs
#   make link-example    compile + link link/example/hello_patch.c into ../out/link-example/
#                        (needs the csky-abiv2-elf-* toolchain, i.e. the docker image)
# docker/docker-compose.yml bind-mounts tools/link (rw), tools/include (ro), data/ (ro) and out/ (rw),
# so these targets work inside `docker compose run --rm dm32uv-re` as well as on the host.
CSKY ?= csky-abiv2-elf-
LINK_OUT := ../out/link-example

.PHONY: link-artifacts link-check link-example
link-artifacts:
	$(PYTHON) $(SRC)/gen_link_artifacts.py
	$(PYTHON) $(SRC)/make_stock_elf.py

link-check:
	$(PYTHON) $(SRC)/gen_link_artifacts.py --check

link-example:
	mkdir -p $(LINK_OUT)
	$(CSKY)gcc -mcpu=ck803s -O2 -Wall -ffunction-sections -fdata-sections \
	    -c link/example/hello_patch.c -o $(LINK_OUT)/hello_patch.o
	$(CSKY)ld -L link -T link/example/hello_patch.ld --gc-sections \
	    -Map $(LINK_OUT)/hello_patch.map -o $(LINK_OUT)/hello_patch.elf $(LINK_OUT)/hello_patch.o
	$(CSKY)objcopy -O binary -j .text $(LINK_OUT)/hello_patch.elf $(LINK_OUT)/hello_patch.bin
	$(CSKY)objdump -d $(LINK_OUT)/hello_patch.elf

# ---- tests ---------------------------------------------------------------------------------
# Host suite: stdlib python3 only, safe anywhere (CI runs it, see ../.github/workflows/).
# Image suite: needs csky-abiv2-elf-* + qemu-system-cskyv2; dispatched via `docker run` with the
# repo mounted at /repo when not already inside the image. Nothing writes into the repo except
# the JUnit XML under ../out/test-results/ (git-ignored).
TEST_IMAGE ?= dm32uv-re-pipeline:latest

.PHONY: test test-all
test:
	$(PYTHON) ../tests/run_tests.py --suite host

test-all:
	$(PYTHON) ../tests/run_tests.py --suite all --docker-image $(TEST_IMAGE)

# ---- manifest-driven patches (build_manifest_patch.py / new_patch.py) ---------------------
MANIFEST ?=
COMPARE  ?=
NAME     ?=

.PHONY: build-manifest snake-manifest new-patch
build-manifest:
	@test -n "$(MANIFEST)" || { echo "usage: make build-manifest MANIFEST=path/x.patch.json [OUT=dir] [COMPARE=ref.bin]"; exit 1; }
	$(PYTHON) $(SRC)/build_manifest_patch.py $(MANIFEST) \
	    $(if $(filter-out out.bin,$(OUT)),--out $(OUT)) $(if $(COMPARE),--compare $(COMPARE)) $(ARGS)

snake-manifest:
	$(PYTHON) $(SRC)/build_manifest_patch.py examples/snake/snake.patch.json \
	    --out ../out/patches/snake --compare examples/snake/progmem_SNAKE_patched.bin

new-patch:
	@test -n "$(NAME)" || { echo "usage: make new-patch NAME=my_patch"; exit 1; }
	$(PYTHON) $(SRC)/new_patch.py $(NAME) $(ARGS)

# ---- BPS patches + editor support (pure python, no toolchain) -------------------------------
# BPS_SOURCE defaults to the shipped scrubbed base; point it at your own verified backup to apply.
BPS_SOURCE ?= ../data/firmware/patching/progmem_stock_DP570UV_20260926_FULL.bin
BPS_TARGET ?=
BPS_PATCH  ?=
BPS_OUT    ?=
BPS_NAME   ?=
.PHONY: bps-create bps-apply bps-info compile-commands
bps-create:
	@test -n "$(BPS_TARGET)" -a -n "$(BPS_OUT)" || { echo "usage: make bps-create BPS_TARGET=patched.bin BPS_OUT=x.bps [BPS_NAME=...]"; exit 1; }
	$(PYTHON) $(SRC)/bps_patch.py create $(BPS_SOURCE) $(BPS_TARGET) $(BPS_OUT) $(if $(BPS_NAME),--name "$(BPS_NAME)")
bps-apply:
	@test -n "$(BPS_PATCH)" -a -n "$(BPS_OUT)" || { echo "usage: make bps-apply BPS_PATCH=x.bps BPS_OUT=patched.bin [BPS_SOURCE=my_backup.bin]"; exit 1; }
	$(PYTHON) $(SRC)/bps_patch.py apply $(BPS_SOURCE) $(BPS_PATCH) $(BPS_OUT)
bps-info:
	@test -n "$(BPS_PATCH)" || { echo "usage: make bps-info BPS_PATCH=x.bps"; exit 1; }
	$(PYTHON) $(SRC)/bps_patch.py info $(BPS_PATCH)
compile-commands:
	$(PYTHON) $(SRC)/gen_compile_commands.py $(ARGS)

# ---- machine-readable chip/format specs (../specs/) -----------------------------------------
SPECS_PY ?= uv run --group specs python3
.PHONY: specs specs-check
specs:
	$(SPECS_PY) $(SRC)/gen_rdl.py
	$(SPECS_PY) $(SRC)/gen_ksy.py
specs-check:
	$(SPECS_PY) $(SRC)/gen_rdl.py --check --no-html
	$(SPECS_PY) $(SRC)/gen_ksy.py --check

# ---- environment check, one-gate CI, API index, lint, manifest verification -----------------
.PHONY: doctor ci patch-api patch-api-check lint-manifest verify-manifest
doctor:
	$(PYTHON) $(SRC)/doctor.py $(ARGS)

# The fast host-side "definition of done": the host suite (which includes the doc-claim and
# link-artifact checks) plus the two standalone staleness gates. QEMU/toolchain gates live in
# `test-all` instead.
ci:
	$(PYTHON) ../tests/run_tests.py --suite host
	$(PYTHON) $(SRC)/gen_patch_api.py --check
	$(PYTHON) $(SRC)/check_doc_claims.py

patch-api:
	$(PYTHON) $(SRC)/gen_patch_api.py

patch-api-check:
	$(PYTHON) $(SRC)/gen_patch_api.py --check

lint-manifest:
	@test -n "$(MANIFEST)" || { echo "usage: make lint-manifest MANIFEST=path/x.patch.json [ARGS=--strict]"; exit 1; }
	$(PYTHON) $(SRC)/lint_manifest.py $(MANIFEST) $(ARGS)

verify-manifest:
	@test -n "$(MANIFEST)" || { echo "usage: make verify-manifest MANIFEST=path/x.patch.json [ARGS='--image img.bin --json -']"; exit 1; }
	$(PYTHON) $(SRC)/verify_manifest.py $(MANIFEST) $(ARGS)
