# dm32uv-re pipeline, containerized.
#
# Builds, in one image, the whole patch lifecycle - find a target in the corpus, write/assemble
# a patch, verify it, with nothing left depending on host-installed tools or a separate
# amd64-emulated Docker wrapper:
#   1. Ghidra 12.1.3 + the awkaplan/ghidra_csky C-SKY Sleigh extension (vendor/ghidra_csky),
#      giving pyghidra a CK803S-aware Ghidra to drive the static-analysis scripts in tools/.
#   2. A qemu-system-cskyv2 binary built from mainline QEMU (GitLab mirror) with the
#      awkaplan/csky-qemu CPU-target overlay (vendor/csky-qemu) and the awkaplan/dm32uv-qemu
#      board model (vendor/dm32uv-qemu) installed on top, for verify_patch.py's dynamic half.
#   3. csky-abiv2-elf-gcc (vendor/csky-toolchain-build, GCC 6.3.0 - the same compiler version
#      the project's existing patch handlers, e.g. megaprobe_handler.S, were built and verified
#      against), built from source so it's native to this image's own arch instead of the
#      Linux-x86-64-only prebuilt binary the project used before - see
#      vendor/csky-toolchain-build/README.md ("Changes on this branch") for the Python 3 port and
#      the other changes it needed to build unattended.
#   4. libcapstone with the CS_ARCH_CSKY module (awkaplan/capstone, branch `csky`, pinned
#      below), for tools/src/dm32_patch_tools/cs_disasm.py's quick single-call-site disassembly.
#      Stock capstone (pip/apt) has no C-SKY support at all.
#
# LAYER ORDER IS DELIBERATE: most-expensive / least-frequently-changed first. The cross-toolchain
# (by far the slowest step) only depends on the apt base and vendor/csky-toolchain-build, then
# QEMU, then the Ghidra extension (vendor/ghidra_csky - edited most often, e.g. Sleigh fixes) and
# everything after it. A Sleigh fix therefore rebuilds only the Gradle extension step and the
# layers after it, not the whole GCC multilib build (which it used to, when the extension came
# first - see ./README.md's former "build-order optimization pending" note). capstone-csky is a separate stage (built in parallel, copied in at the end)
# so bumping its pin never invalidates any of the layers above it either.
#
# See ../tools/README.md for what each script does and ./README.md for how to run this image.

# --- capstone with C-SKY support (separate stage) ----------------------------------------------
# Source: github.com/awkaplan/capstone, branch `csky` - capstone-engine/capstone `next` plus an
# added arch/CSKY module (CS_ARCH_CSKY). Pinned to the exact commit cs_disasm.py was validated
# against (3,316 boundary-aligned DM-32 instructions, 100% mnemonic agreement with
# csky-elfabiv2-objdump - see cs_disasm.py's docstring). Same build flags cs_disasm.py's own
# "not built" message documents for a host build. Installed at a fixed prefix the final stage
# exposes via DM32_CAPSTONE_LIB / DM32_CAPSTONE_HDR (cs_disasm.py's lookup order).
FROM debian:trixie-slim AS capstone-csky
ARG CAPSTONE_CSKY_REPO=https://github.com/awkaplan/capstone.git
ARG CAPSTONE_CSKY_REF=1c7f705409870ee816d8842193daeeb0cd1f2f50
ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get update -qq && apt-get install -y -qq --no-install-recommends \
        ca-certificates git cmake ninja-build build-essential \
    && rm -rf /var/lib/apt/lists/*
RUN git init -q /src/capstone \
    && git -C /src/capstone fetch --depth 1 ${CAPSTONE_CSKY_REPO} ${CAPSTONE_CSKY_REF} \
    && git -C /src/capstone checkout -q FETCH_HEAD \
    && cmake -S /src/capstone -B /src/capstone/build -G Ninja \
        -DCMAKE_BUILD_TYPE=Release \
        -DCMAKE_INSTALL_PREFIX=/opt/capstone-csky -DCMAKE_INSTALL_LIBDIR=lib \
        -DCAPSTONE_ARCHITECTURE_DEFAULT=OFF -DCAPSTONE_CSKY_SUPPORT=ON \
        -DCAPSTONE_BUILD_SHARED_LIBS=ON -DCAPSTONE_BUILD_STATIC_LIBS=OFF \
        -DCAPSTONE_BUILD_LEGACY_TESTS=OFF -DCAPSTONE_BUILD_CSTOOL=OFF \
    && ninja -C /src/capstone/build install \
    && grep -q 'CS_ARCH_CSKY' /opt/capstone-csky/include/capstone/capstone.h \
    && test -e /opt/capstone-csky/lib/libcapstone.so

# --- main image --------------------------------------------------------------------------------
FROM debian:trixie-slim AS base

ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get update -qq && apt-get install -y -qq --no-install-recommends \
        ca-certificates curl git unzip \
        openjdk-21-jdk-headless \
        python3 python3-pip pkg-config ninja-build meson \
        build-essential libglib2.0-dev libpixman-1-dev zlib1g-dev flex bison \
        libslirp-dev \
        texinfo libgmp-dev libmpfr-dev libmpc-dev \
    && rm -rf /var/lib/apt/lists/*

RUN curl -fsSL https://astral.sh/uv/install.sh | sh \
    && mv /root/.local/bin/uv /root/.local/bin/uvx /usr/local/bin/

# Debian trixie's `gradle` apt package is 4.4.1 - too old to parse Ghidra 12.1.3's own
# buildExtension.gradle (it uses a method-reference syntax, e.g. `File::exists`, that
# Gradle 4's Groovy parser rejects outright). Install the real Gradle binary distribution
# instead - 9.7.1 is confirmed working locally against this exact Ghidra version. It's a
# pure-Java zip, so this is arch-independent.
ENV GRADLE_VERSION=9.7.1
RUN curl -fsSL -o /tmp/gradle.zip \
        "https://services.gradle.org/distributions/gradle-${GRADLE_VERSION}-bin.zip" \
    && unzip -q /tmp/gradle.zip -d /opt \
    && rm /tmp/gradle.zip \
    && ln -s /opt/gradle-${GRADLE_VERSION}/bin/gradle /usr/local/bin/gradle

# Debian's openjdk-21-jdk-headless package path is arch-suffixed (java-21-openjdk-amd64,
# -arm64, ...) and this image is built for whatever platform `docker buildx` targets - symlink
# a stable, arch-independent path instead of hardcoding one arch.
RUN ln -s "$(dirname "$(dirname "$(readlink -f "$(which javac)")")")" /usr/lib/jvm/default-java
ENV JAVA_HOME=/usr/lib/jvm/default-java
ENV GHIDRA_VERSION=12.1.3
ENV GHIDRA_BUILD_DATE=20260817
ENV GHIDRA_INSTALL_DIR=/opt/ghidra

# --- Ghidra itself (Apache-2.0, public NSA release) -------------------------------------------
RUN curl -fsSL -o /tmp/ghidra.zip \
        "https://github.com/NationalSecurityAgency/ghidra/releases/download/Ghidra_${GHIDRA_VERSION}_build/ghidra_${GHIDRA_VERSION}_PUBLIC_${GHIDRA_BUILD_DATE}.zip" \
    && unzip -q /tmp/ghidra.zip -d /opt \
    && mv /opt/ghidra_${GHIDRA_VERSION}_PUBLIC ${GHIDRA_INSTALL_DIR} \
    && rm /tmp/ghidra.zip \
    && chmod +x ${GHIDRA_INSTALL_DIR}/support/*.sh ${GHIDRA_INSTALL_DIR}/ghidraRun

# --- csky-abiv2-elf-gcc: CK803S cross-toolchain, built from source ------------------------------
# vendor/csky-toolchain-build's own build-csky-gcc.py clones binutils/gcc from the c-sky GitHub
# org (gdb only with `-m gdb`, which this image does not use) and builds a full multilib toolchain (ck801 through ck860, soft/hard float,
# big/little endian) - the same coverage the project's old prebuilt-binary toolchain had,
# confirmed via `strings` to include `-march=ck803s` as a named multilib variant. Building it
# here instead of fetching that prebuilt binary means a compiler native to THIS image's arch,
# no amd64-emulation-of-a-single-binary wrapper needed the way cskybuild.sh worked before.
COPY vendor/csky-toolchain-build /src/csky-toolchain-build
ENV CSKY_TC_PREFIX=/opt/csky-elfabiv2-toolchain
# This ~2016-era c-sky/binutils-gdb snapshot (bundled readline: display.c/mbutil.c/complete.c)
# calls POSIX/GNU extensions like wcwidth() without ever defining _GNU_SOURCE/_XOPEN_SOURCE -
# it relied on whatever glibc's ambient default was at the time, which declared them in
# <wchar.h> unconditionally. Debian trixie's glibc gates them behind those feature-test
# macros; without one defined, gcc 14 treats the resulting implicit declaration as a hard
# error (older gcc only warned). CFLAGS/CPPFLAGS are environment-inherited by every configure
# and make invocation build-csky-gcc.py's own build_binutils() runs (it never sets them
# itself - confirmed by reading that function - so this isn't overridden), fixing this and
# any other feature-test-macro-gated identifier this old source assumes is always visible, in
# one place instead of patching individual files as each one surfaces. Scoped to this RUN
# only (not a Dockerfile ENV) - this is a workaround for building ~2016 source on a 2026
# glibc, not something a user's OWN patch-handler code compiled later via cskybuild.sh/
# csky-abiv2-elf-gcc should silently inherit.
# inhibit_libc=true as an exported shell env var, not a configure flag: gcc/configure.ac's
# `: ${inhibit_libc=false}` idiom only supplies that default when inhibit_libc ISN'T already
# set in the environment, and nothing later in that script can override an environment-preset
# value back to false (confirmed by reading the whole computation) - the inhibit_libc=true
# branch only ever sets it TRUE, never false, so a pre-set true survives unconditionally.
# This is the ACTUAL lever: dropping --with-headers (see build_gcc_tos in this fork) was
# necessary but not sufficient - the fork's own comment there and its README say dropping it
# alone sets inhibit_libc; in this build it does not, because configure.ac falls back to a DEFAULT target_header_dir
# ($prefix/csky-elfabiv2/sys-include) when --with-headers is simply absent, and the
# `minilibc` component (built right before `gcc` in the chain) has already populated real
# newlib headers there by the time gcc's configure runs, including stdio.h - so the
# auto-detection finds real headers and sets inhibit_libc=false regardless of --with-headers,
# and libgcc/libgcov.h tries to build pid_t/fork/exec wrapper code against this project's
# bundled elf_minilibc_base.tar.gz's broken sys/types.h (verified: no pid_t, just a stray
# sys/cdefs.h guard). Explicitly forcing inhibit_libc=true bypasses that auto-detection
# entirely - the semantically correct choice anyway for a bare CK803S target with no process
# model to wrap.
RUN cd /src/csky-toolchain-build \
    && export CFLAGS=-D_GNU_SOURCE CPPFLAGS=-D_GNU_SOURCE inhibit_libc=true \
    # --minilibc-src points at this checkout itself (not a separate clone): the "minilibc"
    # component's only job is to vendor elf_minilibc_base.tar.gz, which already lives at this
    # fork's own root on THIS branch - the component table's bare
    # https://github.com/c-sky/toolchain-build.git (no branch pinned) clones whatever that
    # repo's default branch is today, which turned out to be a newer, reorganized layout with
    # no such tarball at its root at all. get_component_url() takes the "local" (no-clone) path
    # whenever the given --*-src is already a real directory, so this also skips a wasteful
    # clone of the very code currently running.
    && python3 build-csky-gcc.py --abi=abiv2 --tos=elf --init \
               --minilibc-src=/src/csky-toolchain-build \
    # bfd/csky-callgraph-bfd.{c,h} - a c-sky-specific addition, not upstream GNU binutils -
    # has two real type bugs that older/looser GCC tolerated and GCC 14 correctly rejects:
    # (1) `struct add_ref { ... struct address_ref *next; }` references a type that is
    #     never defined anywhere in the tree - a plain typo for `struct add_ref` itself (a
    #     self-referential linked-list node, consistent with add_ref_list's head/tail being
    #     `struct add_ref *`).
    # (2) callgraph_hash_newfunc is declared to return `struct callgraph_hash_entry *`
    #     directly, and callgraph_hash_table_init's own `newfunc` PARAMETER is independently
    #     declared with that same wrong type inline (THREE separate declarations of one
    #     conceptual function-pointer shape: the definition, the .h extern, and this
    #     parameter - all three needed fixing, not just the first two caught on the first
    #     pass) - all should be the BASE `struct bfd_hash_entry *`, matching what
    #     bfd_hash_table_init's own prototype expects and the convention every other
    #     *_hash_newfunc in this codebase follows (e.g. elf32_arm_link_hash_newfunc in
    #     bfd/elf32-arm.c), casting to the derived type only where a caller needs it
    #     concretely. Fixed here against the freshly cloned tree, not upstream - this is
    #     c-sky/binutils-gdb's own bug, not ours to carry a PR for. Only source/binutils/
    #     needs this now - source/gdb/ (a separate clone of the same repo on a different
    #     branch, which carried its own independent copy of this same bug) no longer exists
    #     at all since gdb is out of the default build (see vendor/csky-toolchain-build/
    #     README.md: its gdb-7.12-era sources do not compile with a current host C++ compiler;
    #     it is a host-side debugger, not needed by the csky-elfabiv2 cross-toolchain).
    && sed -i 's/struct address_ref \*next;/struct add_ref *next;/' \
           source/binutils/bfd/csky-callgraph-bfd.h \
    && sed -i 'N;s/struct callgraph_hash_entry \*\ncallgraph_hash_newfunc/struct bfd_hash_entry *\ncallgraph_hash_newfunc/;P;D' \
           source/binutils/bfd/csky-callgraph-bfd.c \
    && sed -i 'N;s/struct callgraph_hash_entry \*\n *(\*newfunc)/struct bfd_hash_entry *\n                           (*newfunc)/;P;D' \
           source/binutils/bfd/csky-callgraph-bfd.c \
    && sed -i 's/extern struct callgraph_hash_entry \*callgraph_hash_newfunc/extern struct bfd_hash_entry *callgraph_hash_newfunc/' \
           source/binutils/bfd/csky-callgraph-bfd.h \
    && sed -i 'N;s/struct callgraph_hash_entry\n *\*(\*newfunc)/struct bfd_hash_entry\n    *(*newfunc)/;P;D' \
           source/binutils/bfd/csky-callgraph-bfd.h \
    && python3 build-csky-gcc.py --abi=abiv2 --tos=elf --prefix=${CSKY_TC_PREFIX} \
               --minilibc-src=/src/csky-toolchain-build --makejob=$(nproc) \
    && rm -rf /src/csky-toolchain-build/source /src/csky-toolchain-build/build-*
ENV PATH="${CSKY_TC_PREFIX}/bin:${PATH}"

# --- qemu-system-cskyv2: mainline QEMU + csky-qemu (CPU target) + dm32uv-qemu (board model) ----
# Pinned to the exact commit (11.1.50-dev) both overlays' install.sh were verified against: it must
# equal vendor/csky-qemu/QEMU_COMMIT and vendor/dm32uv-qemu/QEMU_COMMIT (see each README's quick
# start, and vendor/csky-qemu/docs/PORT-NOTES.md for the QEMU API changes). `master` drifts; `install.sh`'s `git apply --check`
# already fails loudly if a future bump breaks the patch, so moving QEMU_REF forward is a
# deliberate, visible action instead of silent breakage on every image rebuild.
ARG QEMU_REF=022aa313628fd74154d21de13d7bd66db46c044e
RUN git init -q /src/qemu \
    && git -C /src/qemu fetch --depth 1 https://gitlab.com/qemu-project/qemu.git ${QEMU_REF} \
    && git -C /src/qemu checkout -q FETCH_HEAD
COPY vendor/csky-qemu /src/csky-qemu
COPY vendor/dm32uv-qemu /src/dm32uv-qemu
RUN /src/csky-qemu/install.sh /src/qemu \
    && /src/dm32uv-qemu/install.sh /src/qemu \
    && cd /src/qemu \
    && ./configure --target-list=cskyv2-softmmu --disable-docs --disable-gtk --disable-sdl \
    && ninja -C build qemu-system-cskyv2 \
    && install -Dm755 build/qemu-system-cskyv2 /usr/local/bin/qemu-system-cskyv2 \
    && cp -r pc-bios /usr/local/share/qemu-pc-bios \
    && rm -rf /src/qemu/build

ENV QEMU_PC_BIOS_DIR=/usr/local/share/qemu-pc-bios

# --- the C-SKY Sleigh extension (vendor/ghidra_csky), built against the Ghidra above -----------
COPY vendor/ghidra_csky /src/ghidra_csky
RUN cd /src/ghidra_csky/CSKY \
    && gradle -PGHIDRA_INSTALL_DIR=${GHIDRA_INSTALL_DIR} \
    && unzip -q -o dist/*.zip -d ${GHIDRA_INSTALL_DIR}/Ghidra/Extensions \
    && rm -rf /src/ghidra_csky/CSKY/.gradle /src/ghidra_csky/CSKY/build

# --- capstone-csky, from the stage at the top of this file ------------------------------------
# cs_disasm.py checks --lib/--header, then these two env vars, then a list of generic install
# prefixes (see its own docstring) - the env vars make the image's copy win unambiguously.
COPY --from=capstone-csky /opt/capstone-csky /opt/capstone-csky
ENV DM32_CAPSTONE_LIB=/opt/capstone-csky/lib/libcapstone.so
ENV DM32_CAPSTONE_HDR=/opt/capstone-csky/include/capstone/capstone.h

# Drop-in replacement for the main repo's firmware/tools/csky-build/cskybuild.sh - same CLI
# contract (`cskybuild.sh <toolchain-cmd> [args...]`), so a build_*.py patch-handler script
# written against that wrapper needs only its cskybuild.sh path changed, nothing else, to run
# in this image. See docker/cskybuild.sh's own comment for why it's just an exec here (no
# nested Docker container - the compiler is already on PATH in this image).
COPY docker/cskybuild.sh /usr/local/bin/cskybuild.sh
RUN chmod +x /usr/local/bin/cskybuild.sh

# --- the pyghidra-based patch tooling itself ----------------------------------------------------
# tools/ is NOT generated output (unlike src/include/meta/site/build - see ../PROVENANCE.md and
# tools/README.md). setup.sh writes a machine-specific [tool.uv.sources] (the local Ghidra's
# pyghidra wheel path) into pyproject.toml and builds .venv against it; both are baked here for
# THIS image's /opt/ghidra path. docker-compose.yml bind-mounts tools/src live over this layer at
# run time for host edits, but deliberately does NOT mount pyproject.toml/.venv - see its own
# comment for why overlaying the host's macOS-pathed versions would break pyghidra.
COPY tools /work/tools
RUN cd /work/tools \
    && GHIDRA_INSTALL_DIR=${GHIDRA_INSTALL_DIR} ./setup.sh

# the rest of the (generated) corpus - include/, meta/, data/firmware/, data/allocations.json -
# that the scripts read at run time. Also bind-mounted at runtime (docker-compose.yml) for the
# same reason as tools/ above; the baked copies only matter for a bare `docker run` without
# mounts. (src/ is not baked - it's large and only read by humans/greps, so compose mounts it.)
COPY include /work/include
COPY meta /work/meta
COPY data/firmware /work/data/firmware
COPY data/allocations.json /work/data/allocations.json

WORKDIR /work/tools
ENTRYPOINT ["/bin/bash"]
