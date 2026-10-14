#!/usr/bin/env bash
# Regression check for the dm32uv-re Docker image - run after any change to vendor/*, the
# Dockerfile, or docker-compose.yml, to confirm the whole pipeline still works without a full
# manual re-verification. Run from the docker/ directory:
#   ./smoke_test.sh              # builds the image first if needed, then runs all checks
#   ./smoke_test.sh --no-build   # skip the build step (image must already exist)
#
# Exits nonzero on the first failing check. Each check mirrors something that was actually
# verified by hand at least once during this pipeline's development - see
# dm32uv-re's own project history for what each one caught historically (a bad JAVA_HOME
# default, a too-old packaged Gradle, feature-test-macro gating, two independent copies of the
# same upstream C-SKY binutils bug, an incompatible host-C++ GDB build, ...). A green run here
# does not re-derive any of that reasoning; it only confirms the already-built image still
# produces the expected outputs.
set -euo pipefail
cd "$(dirname "${BASH_SOURCE[0]}")"

if [ "${1:-}" != "--no-build" ]; then
    echo "== building image =="
    docker compose build
fi

RUN="docker compose run --rm -T dm32uv-re -c"
fail=0

check() {
    local name="$1"; shift
    echo ""
    echo "== $name =="
    if "$@"; then
        echo "  OK"
    else
        echo "  FAIL: $name"
        fail=1
    fi
}

check_cross_compiler() {
    $RUN "
        csky-abiv2-elf-gcc -mcpu=ck803s --version | head -1 &&
        echo 'int main(void) { return 0; }' > /tmp/smoke.c &&
        csky-abiv2-elf-gcc -mcpu=ck803s -c /tmp/smoke.c -o /tmp/smoke.o &&
        csky-abiv2-elf-readelf -h /tmp/smoke.o | grep -q 'Machine:.*CSKY' &&
        echo 'compiled real CK803S object (Machine: CSKY confirmed)'
    "
}

check_cskybuild_wrapper() {
    $RUN "cskybuild.sh csky-abiv2-elf-gcc -mcpu=ck803s --version | head -1"
}

check_qemu() {
    $RUN "qemu-system-cskyv2 -M help | grep -q '^dm32 ' && echo 'dm32 machine registered'"
}

check_pyghidra() {
    $RUN "cd /work/tools && uv run python3 -c 'import pyghidra; print(pyghidra.__file__)'"
}

# The export scripts write their output at a fixed repo-relative path (meta/disasm.jsonl,
# meta/sectors.json), and meta/ is bind-mounted READ-WRITE from the host - so running them
# against /work directly would overwrite the host's committed corpus (export_disasm --limit 3
# truncated meta/disasm.jsonl to 3 rows). Run them on a scratch copy inside the container
# instead: their REPO_ROOT is derived from __file__, so a copy writes into the copy. The baked
# .venv (pyghidra) is used by absolute path, since `uv run` would resolve /tmp/w/tools instead.
SCRATCH="rm -rf /tmp/w && mkdir -p /tmp/w/tools /tmp/w/data &&
         cp -r /work/meta /tmp/w/ && cp -r /work/data/firmware /tmp/w/data/ &&
         cp -r /work/tools/src /tmp/w/tools/ && cd /tmp/w/tools"

check_export_disasm() {
    $RUN "$SCRATCH && /work/tools/.venv/bin/python src/dm32_patch_tools/export_disasm.py --limit 3 2>&1 | grep -q 'wrote .* rows'"
}

check_export_pure_python() {
    $RUN "$SCRATCH && python3 src/dm32_patch_tools/export_sectors.py 2>&1 | grep -q 'wrote .* sectors'"
}

check_build_patch() {
    # synthetic sector + synthetic handler - exercises assemble -> place -> hook -> verify
    # end to end without depending on any real hardware-specific patch state.
    $RUN "
        cd /work/tools &&
        printf '.text\n.globl _smoke\n_smoke:\n\tmovi r0, 1\n\trts\n' > /tmp/smoke_handler.S &&
        python3 -c \"
data = bytearray(b'\xff' * 0x1000)
data[0x10:0x14] = bytes.fromhex('08ea0000')
open('/tmp/smoke_sector.bin', 'wb').write(data)
\" &&
        python3 src/dm32_patch_tools/build_patch.py \
            --handler /tmp/smoke_handler.S \
            --stock-sector /tmp/smoke_sector.bin \
            --sector-base 0x0300e000 \
            --hook-addr 0x0300e010 \
            --expect-hook-bytes 08ea0000 \
            --hook-kind br \
            --out /tmp/smoke_out.bin 2>&1 | grep -q 'handler placed'
    "
}

check_capstone_csky() {
    # cs_disasm.py's primary backend: the image's own capstone-csky (DM32_CAPSTONE_LIB/HDR).
    # 0x03012e14 is the keypad-scan pin-mux helper; its first instruction is a push16 lr and it
    # sets IO_DIPLEX2 bits with ori32 ...0xfe00 (see ../CLAUDE.md gotcha 0).
    $RUN "
        cd /work/tools &&
        python3 src/dm32_patch_tools/cs_disasm.py --backend capstone \
            --bin /work/data/firmware/DM32.00.01.048.bin --addr 0x03012e14 > /tmp/cs.txt &&
        head -4 /tmp/cs.txt &&
        grep -q '^# capstone-csky disassembly' /tmp/cs.txt &&
        grep -q '03012e14 .*push16 *lr' /tmp/cs.txt &&
        grep -q 'ori32 .*0xfe00' /tmp/cs.txt
    "
}

check_objdump_fallback() {
    # cs_disasm.py's fallback backend, used automatically when capstone-csky is absent.
    $RUN "
        cd /work/tools &&
        python3 src/dm32_patch_tools/cs_disasm.py --backend objdump \
            --bin /work/data/firmware/DM32.00.01.048.bin --addr 0x03012e14 > /tmp/od.txt &&
        head -4 /tmp/od.txt &&
        grep -q '03012e14 .*push' /tmp/od.txt
    "
}

check_ghidra_movih_fix() {
    # vendor/ghidra_csky's movih Sleigh fix (the immediate is shifted AFTER zero-extension;
    # the old `zext( imm:2 << 16 )` shifted a 2-byte value left by 16 = always 0) must be in
    # the extension actually installed into this image's Ghidra, not just in the source tree.
    $RUN "
        sinc=\$(ls /opt/ghidra/Ghidra/Extensions/*/data/languages/32b_data.sinc) &&
        grep -n 'zext( i32_imm16_imm:2 ) << 16' \$sinc &&
        ! grep -q 'zext( i32_imm16_imm:2 << 16 )' \$sinc
    "
}

# verify_patch.py exit status (see its --help): 0 PASS / PASS with warnings / dynamic skipped,
# 1 FAIL, 2 bad arguments, 3 DIFFERS, 4 INCONCLUSIVE.
#   run_verify_patch <expect_rc> <expect_verdict|""> <prelude shell cmd|""> <verify_patch args...>
# Runs the prelude then `verify_patch.py <args>` in ONE container (each $RUN is a fresh --rm
# container, so a sector written by a separate $RUN would be gone). Passes iff the exit status is
# <expect_rc> AND, when <expect_verdict> is non-empty, the printed verdict line matches it - the
# verdict line is what proves the dynamic half actually ran, since "dynamic step skipped" (no
# qemu-system-cskyv2 on PATH) also exits 0.
run_verify_patch() {
    local expect_rc="$1" expect_verdict="$2" prelude="${3:-true}"; shift 3
    local log rc=0
    log=$(mktemp)
    $RUN "cd /work/tools && { ${prelude:-true}; } &&
          python3 src/dm32_patch_tools/verify_patch.py $*" > "$log" 2>&1 || rc=$?
    grep -E '^== VERDICT|^ERROR|FAIL:|WARN:|stock   |patched |Traceback' "$log" \
        | sed 's/^/    /' || true
    echo "    exit status: $rc (expected $expect_rc)"
    local ok=0
    [ "$rc" -eq "$expect_rc" ] || { ok=1; tail -20 "$log" | sed 's/^/    | /'; }
    if [ -n "$expect_verdict" ] && ! grep -qx "== VERDICT: $expect_verdict ==" "$log"; then
        echo "    verdict line '== VERDICT: $expect_verdict ==' not found"
        ok=1
    fi
    rm -f "$log"
    return $ok
}

check_verify_patch_bad_args() {
    # a 0-byte "sector" must be rejected as bad arguments (2) before any QEMU work.
    run_verify_patch 2 "" "" --sector /dev/null --offset 0x50000
}

check_verify_patch_identity() {
    # stock sector written back unchanged: stock vs stock must compare equal (the probe is
    # deterministic by design - see qemu_boot_diff.py's docstring), so anything but PASS/0 means
    # the harness itself is broken or nondeterministic. Exercises the whole dynamic half:
    # compose both images (ALPU bypass etc.), boot both to standby, drive the MENU/BACK probe,
    # compare screens and code coverage.
    run_verify_patch 0 "PASS" "python3 -c \"
d = open('/work/data/firmware/patching/progmem_stock_DP570UV_20260926_FULL.bin', 'rb').read()
assert len(d) == 0x100000, 'stock image is %d bytes, not 1 MB' % len(d)
open('/tmp/identity_sector.bin', 'wb').write(d[0x50000:0x51000])
\"" --sector /tmp/identity_sector.bin --offset 0x50000
}

check "cross-compiler: csky-abiv2-elf-gcc compiles real CK803S code" check_cross_compiler
check "cskybuild.sh drop-in wrapper" check_cskybuild_wrapper
check "qemu-system-cskyv2 has the dm32 machine" check_qemu
check "pyghidra imports" check_pyghidra
check "export_disasm.py (pyghidra-driven static analysis)" check_export_disasm
check "export_sectors.py (pure-python static analysis)" check_export_pure_python
check "build_patch.py (assemble + splice a synthetic patch)" check_build_patch
check "cs_disasm.py via the image's capstone-csky" check_capstone_csky
check "cs_disasm.py objdump fallback backend" check_objdump_fallback
check "Ghidra C-SKY extension has the movih Sleigh fix" check_ghidra_movih_fix
check "verify_patch.py rejects a bad sector (exit 2)" check_verify_patch_bad_args
check "verify_patch.py dynamic half: identity patch is PASS (exit 0)" check_verify_patch_identity

echo ""
if [ "$fail" -eq 0 ]; then
    echo "== ALL CHECKS PASSED =="
else
    echo "== ONE OR MORE CHECKS FAILED - see above =="
fi
exit "$fail"
