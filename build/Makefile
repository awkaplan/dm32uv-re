# Build the decompiled DM-32UV corpus.
#
# GENERATED FILE - do not edit by hand.
#
# WHAT THIS BUILDS, AND WHAT IT DOES NOT
# --------------------------------------
# This Makefile compiles decompiled C. It does NOT produce a flashable firmware image, and no
# target here attempts to: the corpus covers part of the application region, thousands of globals
# are `extern` declarations at absolute addresses with no definition, and hundreds of call targets
# are unresolved placeholders. `make image` deliberately does not exist. See README.md in this
# directory for the full accounting.
#
# What compiling IS good for: it type-checks a reconstruction against a real compiler for the real
# target. A function that compiles for ck803s has a self-consistent signature, body and callee
# expectations. One that does not has an identifiable analysis gap - which is why `make report`
# ranks the failures rather than hiding them.
#
# TARGETS
#   make check      host syntax-check only (fast, no cross-toolchain needed)
#   make cross      cross-compile every function to real CK803S objects
#   make report     cross-compile and write a ranked failure report
#   make one FILE=src/rtos/foo.c    build a single file, showing all diagnostics
#   make clean
#
# CONFIGURATION
#   CROSS_CC   cross-compiler (default: csky-abiv2-elf-gcc; must be on PATH)
#   CC         host compiler for `make check` (default: cc)
#   CPU        -mcpu value (default: ck803s, the core in this SoC)
#   O          object output directory (default: build/_obj)

CC        ?= cc
CROSS_CC  ?= csky-abiv2-elf-gcc
CPU       ?= ck803s
O         ?= _obj

# Paths are kept RELATIVE to the repository root, and every rule runs from there. That is not a
# style choice: the cross-compiler may be a shim that forwards into a container with the repo
# bind-mounted at a different prefix, and an absolute host path would not resolve inside it.
ROOT      := $(patsubst %/,%,$(dir $(abspath $(lastword $(MAKEFILE_LIST)))))/..
INCLUDE   := include
SRCS      := $(shell cd $(ROOT) && find src -name '*.c' | sort)

# -w: the corpus is decompiler output. Warnings on reconstructed code are noise; only hard errors
# indicate a real analysis gap. The generated HEADERS are separately -Wall-clean.
CFLAGS_COMMON := -w -I$(INCLUDE)
CROSS_CFLAGS  := -mcpu=$(CPU) $(CFLAGS_COMMON)
HOST_CFLAGS   := -fsyntax-only $(CFLAGS_COMMON)

.PHONY: all check cross report one clean help
all: help

help:
	@sed -n '3,30p' $(lastword $(MAKEFILE_LIST)) | sed 's/^# \?//'

# ---- host syntax check -------------------------------------------------------------------
check:
	@cd $(ROOT) && pass=0; fail=0; \
	for f in $(SRCS); do \
	    if $(CC) $(HOST_CFLAGS) "$$f" 2>/dev/null; then pass=$$((pass+1)); \
	    else fail=$$((fail+1)); fi; \
	done; \
	total=$$((pass+fail)); \
	echo "host syntax-check: $$pass/$$total clean ($$((100*pass/total))%), $$fail with errors"

# ---- cross-compile to real target objects ------------------------------------------------
cross:
	@command -v $(CROSS_CC) >/dev/null 2>&1 || { \
	    echo "ERROR: $(CROSS_CC) not on PATH."; \
	    echo "       Needs a C-SKY ELF ABIv2 toolchain built for -mcpu=$(CPU)."; exit 1; }
	@mkdir -p $(ROOT)/build/$(O)
	@cd $(ROOT) && pass=0; fail=0; \
	for f in $(SRCS); do \
	    obj="build/$(O)/$$(echo $${f#src/} | tr / _ | sed 's/\.c$$/.o/')"; \
	    if $(CROSS_CC) $(CROSS_CFLAGS) -c -o "$$obj" "$$f" 2>/dev/null; then pass=$$((pass+1)); \
	    else fail=$$((fail+1)); fi; \
	done; \
	total=$$((pass+fail)); \
	echo "cross-compile ($(CPU)): $$pass/$$total objects built ($$((100*pass/total))%), $$fail failed"

# ---- ranked failure report ----------------------------------------------------------------
# Groups errors by shape so the biggest analysis gap is obvious rather than buried in 1600 logs.
report:
	@command -v $(CROSS_CC) >/dev/null 2>&1 || { \
	    echo "ERROR: $(CROSS_CC) not on PATH."; exit 1; }
	@mkdir -p $(ROOT)/build/$(O)
	@cd $(ROOT) && : > build/$(O)/errors.txt && for f in $(SRCS); do \
	    $(CROSS_CC) $(CROSS_CFLAGS) -c -o /dev/null "$$f" 2>>build/$(O)/errors.txt || true; \
	done
	@echo "=== cross-compile failures by error shape ==="
	@grep -oE 'error: .*' $(ROOT)/build/$(O)/errors.txt \
	  | sed "s/[0-9]\{2,\}/N/g; s/'[A-Za-z_][A-Za-z0-9_]*'/X/g" \
	  | sort | uniq -c | sort -rn | head -20
	@echo
	@echo "full log: build/$(O)/errors.txt"

# ---- single file, all diagnostics ---------------------------------------------------------
one:
	@test -n "$(FILE)" || { echo "usage: make one FILE=src/<subsystem>/<fn>.c"; exit 1; }
	@cd $(ROOT) && $(CROSS_CC) $(CROSS_CFLAGS) -c -o /dev/null $(FILE)

clean:
	rm -rf $(ROOT)/build/$(O)
