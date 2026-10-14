"""Checklist item C: patch-site index cross-linking proven work.

A curated catalogue of every concretely-documented firmware patch site this project has
installed, designed, or proposed - addresses, hook conventions, hardware-verification
status, and the source doc each claim traces back to. This is NOT derived data like
export_disasm.py/export_sectors.py/export_xrefs.py: every entry in PATCH_SITES below was
hand-verified against the main repo's own documentation (never re-derived from a summary),
because this project has already made the file-offset-vs-VA and load-base mistakes TWICE on
addresses just like these (see ghidra_project.py's module docstring for one; the ALPU-MP
site below needed the same correction before being usable here).

What this script DOES derive automatically, every run: for each catalogued address, which
corpus function (if any) CONTAINS it - not just matches it exactly, since a patch byte is
almost always mid-function, not at a function's entry point. The default expectation
depends on the site's `kind`:

  - "instruction-patch" / "third-party-finding" (both edit bytes inside what was existing
    stock CODE) default to EXPECTING to resolve inside a corpus function.
  - "data-patch" (edits a string or other literal, e.g. the model-name-demo mod) defaults to
    EXPECTING NOT to resolve: the corpus's function byte ranges cover instructions, and a
    string literal commonly sits in an inter-function literal pool or a data region the
    corpus doesn't attribute to any function body at all (see export_disasm.py's item-A
    findings on inline literal pools for exactly this pattern) - it is not evidence of a
    wrong address the way it would be for an instruction edit.
  - "handler" (project-authored code placed in flash the stock firmware never used, e.g.
    MEGAPROBE's sector) defaults to EXPECTING to NOT resolve, because the corpus only covers
    stock code. If it EVER starts resolving, that's the actual signal worth raising: a
    future stock firmware build may have started using that "free" flash for real code - the
    same kind of mistake the main project's blank-check work (no-free-flash-on-the-data-chip)
    already warns about on the other chip.

A site can override this default with an explicit `expected_resolution: True/False` key when
it has a KNOWN, DOCUMENTED reason the simple kind-based rule doesn't apply - e.g. the live-RAM capture
hook at 0x0302a47c is an instruction-patch (so the default says "expect resolved"), but its
exact byte-for-byte stock value was independently verified against the live image (see its
entry below) even though it falls ~38 bytes past the end of the corpus's own recorded
function boundary for `serial_protocol_vframe_command_loop` - a corpus coverage gap, not a
wrong address, so that entry sets `expected_resolution: False` with the gap explained.
"""
from __future__ import annotations

import argparse
import json
import pathlib

REPO_ROOT = pathlib.Path(__file__).resolve().parent.parent.parent.parent
FUNCTIONS_JSON = REPO_ROOT / "meta" / "functions.json"
OUT_JSON = REPO_ROOT / "meta" / "patch_sites.json"

VALID_STATUSES = {"hardware-verified", "hardware-tested-failed", "qemu-only", "theoretical",
                   "reverted"}
VALID_KINDS = {"instruction-patch", "data-patch", "handler", "third-party-finding"}

# Each entry: one concretely documented patch site. `addr` is the address this script
# resolves against the corpus (an absolute VA, e.g. 0x030c6866) - for a hook that modifies
# an existing instruction, that's the instruction's own address; for a handler occupying
# otherwise-unused flash, it's the handler's start address (which usually will NOT resolve to
# a corpus function - the corpus only covers STOCK code, and a handler lives in flash the
# stock firmware never used).
PATCH_SITES: list[dict] = [
    {
        "id": "alpu-mp-bypass",
        "kind": "instruction-patch",
        "addr": "0x030c6866",
        "description": "ALPU-MP anti-clone challenge-response bypass. Patches the gate's "
                        "terminal-failure branch (IRAM 0x16c46, copied to this flash "
                        "address at boot) so the auth-success path is taken unconditionally.",
        "hook_convention": "in-place instruction patch (4 bytes: 20 e9 04 00 -> 03 6c 03 6c "
                            "at sector offset 0x866) - not a hook/trampoline, a direct edit "
                            "of the branch encoding",
        "status": "hardware-verified",
        "status_evidence": "the ALPU-bypass artifacts shipped here document a stock sector "
                            "backup (sector_030c6000_stock.bin) and a patched sector "
                            "(sector_030c6000_alpubypass.bin) as real artifacts, implying "
                            "this was built and applied, not just designed",
        "source": "data/firmware/patching/ (sector_030c6000_stock.bin + _alpubypass.bin)",
    },
    {
        "id": "live-ram-hook",   # stable key: other tooling references it, do not reword
        "kind": "instruction-patch",
        "addr": "0x0302a47c",
        "expected_resolution": False,
        "description": "The base live-RAM capture hook every probe variant (MEGAPROBE/AUDIOPROBE/"
                        "PLLPROBE/CALPROBE/etc.) shares: replaces the stock 'movi r8,0' "
                        "inside serial_protocol_vframe_command_loop's unknown-sub-id "
                        "fallthrough with a bsr into a handler at flash 0x030E1000.",
        "hook_convention": "4-byte in-place instruction edit (08 ea 00 00 -> bsr encoding); "
                            "entry regs documented as r4=buf, r5=serial obj, r8=sub-id, "
                            "r14=frame; all paths end at the shared transmit site 0x0302a480 "
                            "with r8=payload length (build_patch.py:bsr_bytes, "
                            "the capture handler header comment)",
        "status": "hardware-verified",
        "status_evidence": "build_patch.py asserts the stock bytes at this address are "
                            "exactly 08 ea 00 00 before patching, verified independently "
                            "against data/firmware/DM32.00.01.048.bin for this catalogue "
                            "(matches); every probe variant below chains onto this same hook",
        "source": "the live-RAM capture family; see docs/live-ram-capture.md",
        "note": "Falls ~38 bytes PAST the corpus's own recorded end of "
                "serial_protocol_vframe_command_loop (corpus: 1042 bytes, ending 0x302a456; "
                "hook at 0x302a47c) - independently verified as a real corpus coverage gap "
                "(the disassembly between those two points decodes cleanly with no "
                "halt_baddata-style stop), not a wrong address. Do not 'fix' this address "
                "to make it resolve; fix the corpus's function-boundary recovery instead, "
                "if this ever gets revisited.",
    },
    {
        "id": "megaprobe-handler",
        "kind": "handler",
        "addr": "0x030E1000",
        "description": "Combined live-RAM-capture-family probe handler: flash identity (JEDEC ID, "
                        "status register, SFDP header), direct 24-bit flash reads via "
                        "spi_flash_read_mutex_guarded's inlined recipe (no page/mutex "
                        "indirection), and the stock RAM-seek/read sub-ids, unioned into one "
                        "patched sector so a single power-cycle flash covers all of them. "
                        "The LATEST/combined handler occupying this sector - see the other "
                        "probe entries below, which chain onto the same sector over time.",
        "hook_convention": "whole-sector handler (not an in-place edit): unknown sub-ids "
                            "fall through to stock behaviour via 'movi r8,0 ; jmp r15' - "
                            "the project's r8-as-result/length, r15-as-return convention "
                            "for hand-written patch handlers (see tools/README.md's note on "
                            "why this convention has no corpus-function override: it belongs "
                            "to patch code, never to stock firmware)",
        "status": "hardware-verified",
        "status_evidence": "the live-RAM capture notes document real "
                            "serial port usage against a live radio (PORT=/dev/cu.usbserial-110), "
                            "a 'Known session limit' discovered empirically (RAM reads died "
                            "after ~1856 consecutive commands, observed TWICE), and two prior "
                            "flashing failures that 'cost a battery pull' on 2026-09-30 - all "
                            "real-hardware-only failure modes, not something QEMU would show",
        "source": "docs/live-ram-capture.md (MEGAPROBE variant)",
    },
    {
        "id": "audioprobe",
        "kind": "handler",
        "addr": "0x030E1000",
        "description": "Audio-chain MMIO read probe (sub-ids 0x41-0x44: baseband block, "
                        "prompt-tone FIFO + codec registers, clock registers). Shares the "
                        "live-RAM capture sector; superseded in-place by later probe variants.",
        "hook_convention": "same whole-sector handler convention as megaprobe-handler",
        "status": "hardware-verified",
        "status_evidence": "'The probe flashed and connected fine (connected: DP570UV)'; "
                            "the read-only sub-ids 0x41-0x44 are explicitly called "
                            "'known-good'. A separate add-on (beep-probe, sub-id 0x45/0x2c) "
                            "in the same file failed on hardware twice and was closed - see "
                            "the beepprobe entry below, catalogued separately since it is a "
                            "different sub-feature with a different outcome.",
        "source": "docs/live-ram-capture.md (AUDIOPROBE variant)",
    },
    {
        "id": "beepprobe",
        "kind": "handler",
        "addr": "0x030E1000",
        "description": "Attempted beep-trigger probe (sub-id 0x2c, originally 0x45), calling "
                        "into stock alert_code_post_0xb and write_field_and_mbox_post. "
                        "ABANDONED - kept here so the catalogue records what was tried and "
                        "why, not just what worked.",
        "hook_convention": "same whole-sector handler convention as megaprobe-handler",
        "status": "hardware-tested-failed",
        "status_evidence": "'Attempt 1 - rebooted the radio' and 'Attempt 2 ... the radio "
                            "restarted again'; the doc explicitly says 'this route is closed "
                            "rather than iterated' because QEMU cannot validate the "
                            "privileged-register path either",
        "source": "docs/live-ram-capture.md (AUDIOPROBE variant) "
                  "(section 'Beep-probe route: FAILED, and closed'), beepprobe_handler.S",
    },
    {
        "id": "pllprobe",
        "kind": "handler",
        "addr": "0x030E1000",
        "description": "PLL-settling-time probe (sub-ids 0x30-0x33), bit-banging the FD6818 "
                        "frequency-set/register-read sequence to measure real PLL relock "
                        "time. Result fed directly into the FHSS feasibility work.",
        "hook_convention": "same whole-sector handler convention as megaprobe-handler",
        "status": "hardware-verified",
        "status_evidence": "'Status: FLASHED AND WORKING (2026-09-28)' - explicit, with "
                            "measured PLL settling results (<=~40us) cited in "
                            "docs/features/FHSS-implementation-plan.md",
        "source": "docs/live-ram-capture.md (PLLPROBE variant)",
    },
    {
        "id": "calprobe",
        "kind": "handler",
        "addr": "0x030E1000",
        "description": "Attempted calibration-store resolver probe (sub-ids 0x34/0x35), "
                        "calling flash_field_read_cached and flash_block_id_resolve. "
                        "ABANDONED after both the hooked-call route and a RAM-read fallback "
                        "both failed - the calibration extraction this project later "
                        "completed used a different, successful method (see "
                        "docs/CALIBRATION-EXTRACTION.md), not this probe.",
        "hook_convention": "same whole-sector handler convention as megaprobe-handler",
        "status": "hardware-tested-failed",
        "status_evidence": "'RESULT 2026-09-30: v1 FAILED - the same mutex trap as "
                            "PLL-probe v2'; flashed successfully (16/16 blocks "
                            "read-back-confirmed) but both sub-ids returned nothing and "
                            "desynced the session; the RAM-read fallback also failed "
                            "('the target is out of reach')",
        "source": "docs/live-ram-capture.md (CALPROBE variant)",
    },
    {
        "id": "sysinfo-dangling-hook-0302b65e",
        "kind": "third-party-finding",
        "addr": "0x0302b65e",
        "description": "A 4-byte bsr-shaped overwrite inside the CPS handshake "
                        "command-dispatch function, found already present on this unit's "
                        "flash and NOT authored by this project (checked against every "
                        "backup and build artifact this project has; none created it). "
                        "Targeted 0x030E1434, which this project's own repeated erase/"
                        "rewrite cycles of the 0x030E1000 sector had left entirely erased "
                        "(0xFF) - a dangling reference to a handler that no longer exists. "
                        "Branching into erased flash during the CPS SYSINFO step caused the "
                        "radio to hang/reboot, blocking every live-RAM capture-driven operation. "
                        "REVERTED 2026-09-29 by reflashing sector 0x0302B000 from the "
                        "verified stock backup; confirmed working (SYSINFO succeeded, full "
                        "32KB SRAM dump completed) immediately after. No longer present on "
                        "the radio as of the revert.",
        "hook_convention": "in-place 4-byte bsr-shaped overwrite, same CK803S bsr opcode "
                            "shape this project's own hook-building code uses, but of "
                            "unknown/third-party origin",
        "status": "reverted",
        "status_evidence": "the undocumented-hook notes' "
                            "'UPDATE 2026-09-29' section documents the live crash-to-fix "
                            "sequence and the specific revert action taken",
        "source": "docs/live-ram-capture.md (undocumented hook at 0x0302B65E)",
        "note": "CORRECTED 2026-10-06: this doc originally also flagged 0x030C6866 as a "
                "second undocumented/third-party diff. That was wrong - 0x030C6866 is this "
                "project's own alpu-mp-bypass (see that entry above), misattributed because "
                "the 2026-09-29 investigation never cross-referenced the project's own "
                "2026-09-27 ALPU-MP work. Fixed in the source doc directly; this note exists "
                "so the correction is visible from this catalogue too.",
    },
    {
        "id": "ui-overlay-hook",
        "kind": "instruction-patch",
        "addr": "0x0301899c",
        "description": "Proof-of-concept UI draw-call overlay hook, installed AFTER the "
                        "prologue of display_draw_string_gb2312 (not at its entry, 0x03018998 "
                        "- entry-hooking was tried first and explicitly documented as "
                        "broken: it clobbers r15 before the function's own push saves it).",
        "hook_convention": "4-byte bsr hook after the function prologue, into a trampoline "
                            "that re-executes the two displaced stock instructions before "
                            "running overlay code, guarded by an SRAM re-entrancy flag at "
                            "0x18007FE0",
        "status": "qemu-only",
        "status_evidence": "'Not run on hardware. Flashing this requires the full CLAUDE.md "
                            "safety procedure.' Verified only by booting the patched image "
                            "under qemu-system-cskyv2 against a emulator-only flash image "
                            "(flash_overlay.bin), not any hardware backup.",
        "source": "tools/examples/ (overlay trampoline)",
    },
    {
        "id": "model-name-demo-mod",
        "kind": "data-patch",
        "addr": "0x030AF914",
        "description": "Demonstration mod: static ASCII string 'DP570UV' overwritten with "
                        "'DM32MOD' (same length, 6 bytes differ) at its single occurrence in "
                        "the image. No code/hook involved - a pure data-sector edit.",
        "hook_convention": "static-data overwrite only; no instruction or branch modified",
        "status": "qemu-only",
        "status_evidence": "'NOT yet flashed to hardware (user's call).' Validated via the "
                            "mod-validate harness under qemu-cskyv2 (fnverify): pointer table "
                            "intact, strlen/table lookups through the new string all correct.",
        "source": "tools/examples/ (model-name demo)",
    },
    {
        "id": "voice-encryption-route-c-isr-hook",
        "kind": "instruction-patch",
        "addr": None,
        "expected_resolution": True,
        "description": "PROPOSED (not built): intercept the 27-byte TX voice frame at SRAM/"
                        "MMIO 0x16000960-0x1600097A via an ISR hook on the TX-frame-ready "
                        "interrupt (irq27/irq28, EOI via MMIO 0x110003B0 bits 4/5).",
        "hook_convention": "ISR hook (not yet designed in instruction-level detail)",
        "status": "theoretical",
        "status_evidence": "docs/features/encryption-patch-feasibility.md explicitly: "
                            "'Needs the voice ISR located and its register conventions "
                            "nailed down first' - a located target, not an implemented patch",
        "source": "docs/features/encryption-patch-feasibility.md",
        "note": "addr is null: no single instruction-level hook address has been chosen yet, "
                "only the interrupt/data-region target. Leave addr null (not a placeholder "
                "address) until a real site is picked - this script skips corpus resolution "
                "entirely for any site with addr=null.",
    },
    {
        "id": "fhss-txslot-hook",
        "kind": "instruction-patch",
        "addr": "0x0002d604",
        "description": "PROPOSED (not built): extend the per-TX-slot-boundary task at IRAM "
                        "0x2d604 (the 'txslot' handler, already in the RTOS dispatch table) "
                        "to drive FHSS hop timing, or add a new task pending on the same "
                        "semaphore object (0x35f50) it already uses.",
        "hook_convention": "task-body extension or sibling task (not yet built)",
        "status": "theoretical",
        "status_evidence": "docs/features/FHSS-implementation-plan.md: 'the hook is "
                            "concrete: task 0x2d604 runs once per TX slot boundary - either "
                            "extend it or add a task pending on the same semaphore' - a "
                            "design conclusion, no handler file exists for it",
        "source": "docs/features/FHSS-implementation-plan.md",
    },
]


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--out", type=pathlib.Path, default=OUT_JSON)
    args = ap.parse_args()

    for site in PATCH_SITES:
        if site["status"] not in VALID_STATUSES:
            raise ValueError(f"{site['id']}: status {site['status']!r} not in {VALID_STATUSES}")
        if site["kind"] not in VALID_KINDS:
            raise ValueError(f"{site['id']}: kind {site['kind']!r} not in {VALID_KINDS}")

    functions = json.loads(FUNCTIONS_JSON.read_text())["functions"]
    functions_by_start = sorted(
        ((int(f["addr"], 16), int(f["addr"], 16) + f["size"], f) for f in functions),
        key=lambda t: t[0],
    )

    def containing_function(addr: int):
        # linear scan is fine at this scale (a few thousand functions, checked once per
        # patch site, of which there will never be more than a few dozen)
        for start, end, f in functions_by_start:
            if start <= addr < end:
                return f
        return None

    default_expected_resolution = {
        "instruction-patch": True,
        "third-party-finding": True,
        "data-patch": False,
        "handler": False,
    }

    drift = []
    out_sites = []
    for site in PATCH_SITES:
        if site["addr"] is None:
            # No address chosen yet (a theoretical site with only a data/interrupt target,
            # not an instruction-level hook site) - nothing to resolve against the corpus.
            entry = dict(site)
            entry["corpus_function"] = None
            entry["corpus_function_addr"] = None
            entry["resolves_in_corpus"] = None
            out_sites.append(entry)
            continue

        addr = int(site["addr"], 16)
        fn = containing_function(addr)
        resolved = fn is not None
        expected = site.get("expected_resolution", default_expected_resolution[site["kind"]])

        entry = dict(site)
        entry["corpus_function"] = fn["name"] if fn else None
        entry["corpus_function_addr"] = fn["addr_hex"] if fn else None
        entry["resolves_in_corpus"] = resolved
        out_sites.append(entry)

        if resolved != expected:
            if expected:
                entry["drift_reason"] = ("expected to resolve inside a corpus function (it "
                                          "edits what was existing stock code) but does not "
                                          "- the corpus moved under this file, or this "
                                          "address is wrong")
            else:
                entry["drift_reason"] = (f"expected NOT to resolve to any corpus function "
                                          f"but now resolves inside {fn['name']} - see the "
                                          f"site's own kind/expected_resolution reasoning")
            drift.append(site["id"])

    out = {
        "note": "Hand-curated, not derived - see this script's module docstring. "
                "corpus_function/resolves_in_corpus ARE derived fresh every run; what counts "
                "as drift depends on each site's 'kind' (see docstring) and is explained "
                "per-entry in 'drift_reason' when present.",
        "drift": drift,
        "sites": out_sites,
    }

    args.out.write_text(json.dumps(out, indent=1))

    print(f"wrote {len(out_sites)} patch site(s) to {args.out}")
    if drift:
        print(f"DRIFT DETECTED: {len(drift)} site(s): {drift}")
    else:
        print("no drift: every site's corpus-resolution status matches what its kind expects")


if __name__ == "__main__":
    main()
