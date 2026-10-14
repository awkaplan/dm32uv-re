# /// script
# requires-python = ">=3.9"
# dependencies = []
# ///
"""
Fast CK803S disassembly via a capstone build with C-SKY support - a lightweight alternative to
export_disasm.py's pyghidra round trip for the "what does this ONE call site actually do" spot
checks that come up constantly while tracing a mechanism (resolving a literal-pool table base,
confirming a bit-field width, checking what a splice site's neighboring bytes really are).
export_disasm.py is the right tool for a whole-corpus regen; this is the right tool for the dozen
quick re-checks a single patch-authoring session needs in between.

PREREQUISITE: a capstone build with CSKY architecture support compiled in - stock capstone
(pip/apt/brew) does not have it. Source: github.com/awkaplan/capstone, branch `csky` (capstone
`next` plus an arch/CSKY module), pinned to commit 1c7f705409870ee816d8842193daeeb0cd1f2f50 in
docker/Dockerfile. The Docker image (docker/) builds it and sets DM32_CAPSTONE_LIB /
DM32_CAPSTONE_HDR, so inside the image this just works. On a host, build it yourself:

  git clone -b csky https://github.com/awkaplan/capstone.git capstone-csky
  cmake -S capstone-csky -B capstone-csky/build -G Ninja -DCMAKE_BUILD_TYPE=Release \
        -DCAPSTONE_ARCHITECTURE_DEFAULT=OFF -DCAPSTONE_CSKY_SUPPORT=ON \
        -DCAPSTONE_BUILD_SHARED_LIBS=ON
        # macOS: if cmake can't find the SDK, add -DCMAKE_OSX_SYSROOT="$(xcrun --show-sdk-path)"
  ninja -C capstone-csky/build

LIBRARY LOOKUP ORDER (first hit wins; the header is needed too - CS_ARCH_CSKY's enum value is
read from it rather than hardcoded):
  1. --lib / --header
  2. $DM32_CAPSTONE_LIB / $DM32_CAPSTONE_HDR
  3. $DM32_CAPSTONE_PREFIX (a checkout with build/, or an install prefix with lib/ + include/)
  4. generic candidates: /opt/capstone-csky (the Docker image's prefix), ./capstone-csky and
     ../capstone-csky relative to this repo's root, ~/workspace/capstone-csky - each probed as
     both a build tree and an install prefix. These are EXAMPLE locations only; the portable,
     documented way to point at your own build is $DM32_CAPSTONE_PREFIX (or --lib/--header).
A candidate is only accepted if its header actually defines CS_ARCH_CSKY, so a stock capstone
that happens to be installed is skipped rather than half-working.

FALLBACK: if no capstone-csky is found, `--backend auto` (default) falls back to
csky-abiv2-elf-objdump (on PATH in the Docker image) over the raw image. Same instructions, but
objdump's spelling (register names, width suffixes) can differ from capstone's, so --sweep
mnemonic matching is only guaranteed against capstone output. Force one with --backend.

VALIDATED (upstream, before this repo existed) against csky-elfabiv2-objdump on 3,316
boundary-aligned instructions of real DM-32 firmware at 100% mnemonic agreement. Output uses ABI
register names (a0/l1/sp/lr) and width-suffixed mnemonics (andn32, ld32.b), so it reads differently
from Ghidra's r0/rts style - same instructions.

CAVEAT - literal pools: CK803S puts lrw constant pools inline, right after the
function body. Disassembly does not stop at a function's real end unless you tell
it to, so trailing "instructions" after a pop/jmp are usually pool DATA being
decoded as code. --stop-at-return (default) breaks at the first return-shaped
instruction; pass --no-stop-at-return to see raw decoding, and treat anything
past the return as suspect. This is the same gotcha recorded in the project's
FHSS notes.

USAGE
  # one function, by address
  cs_disasm.py --addr 0305dbe4

  # one function, by decompiled .c filename (address parsed from the name)
  cs_disasm.py --file firmware/DM32.00.01.048/decompiled/batch/is_dialog_open_0305dbe4.c

  # sweep: every batch function whose real instruction stream contains these
  cs_disasm.py --sweep andn,mvcv,movih --batch firmware/DM32.00.01.048/decompiled/batch

  # live-in register summary (the disasm_context.py question, but sweepable)
  cs_disasm.py --addr 03001920 --regs
"""

import argparse
import ctypes
import glob
import os
import re
import shutil
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))))

# Default: the full 1MB stock image (see data/firmware/patching/README.md for why the full image,
# not data/firmware/DM32.00.01.048.bin, is the right default for patch-authoring work - the
# truncated file can make free-flash regions look like end-of-file instead of confirmed-erased).
DEFAULT_BIN = os.path.join(ROOT, "data/firmware/patching/progmem_stock_DP570UV_20260926_FULL.bin")
DEFAULT_BASE = 0x03000000
# Probed in order after --lib/--header and the DM32_CAPSTONE_* env vars - see the docstring.
CAPSTONE_PREFIXES = [
    "/opt/capstone-csky",                                    # docker/Dockerfile's install prefix
    os.path.join(ROOT, "capstone-csky"),
    os.path.join(os.path.dirname(ROOT), "capstone-csky"),
    os.path.expanduser("~/workspace/capstone-csky"),         # example location; prefer DM32_CAPSTONE_PREFIX
]
LIB_NAMES = ("libcapstone.so", "libcapstone.dylib", "capstone.dll")
OBJDUMP = "csky-abiv2-elf-objdump"



class CsInsn(ctypes.Structure):
    _fields_ = [
        ("id", ctypes.c_uint),
        ("alias_id", ctypes.c_uint64),
        ("address", ctypes.c_uint64),
        ("size", ctypes.c_uint16),
        ("bytes", ctypes.c_ubyte * 24),
        ("mnemonic", ctypes.c_char * 32),
        ("op_str", ctypes.c_char * 160),
        ("is_alias", ctypes.c_bool),
        ("usesAliasDetails", ctypes.c_bool),
        ("detail", ctypes.c_void_p),
    ]


def arch_id(header):
    """CS_ARCH_CSKY's value, read from the header rather than hardcoded - it
    shifts whenever capstone adds an architecture ahead of it in the enum."""
    src = open(header).read()
    body = src[src.index("CS_ARCH_ARM = 0"):src.index("CS_ARCH_MAX")]
    idx, vals = 0, {}
    for name, explicit in re.findall(r"CS_ARCH_(\w+)(?:\s*=\s*(\d+))?", body):
        if explicit != "":
            idx = int(explicit)
        vals.setdefault(name, idx)
        idx += 1
    return vals["CSKY"]


def has_csky(header):
    try:
        return "CS_ARCH_CSKY" in open(header).read()
    except OSError:
        return False


def prefix_candidates(prefix):
    """(lib, header) pairs for one prefix, as a build tree and as an install prefix."""
    hdr = os.path.join(prefix, "include", "capstone", "capstone.h")
    for libdir in ("build", "lib", "lib64"):
        for name in LIB_NAMES:
            yield os.path.join(prefix, libdir, name), hdr


def find_capstone(lib_arg=None, hdr_arg=None):
    """Resolve (lib, header) per the docstring's lookup order. Returns (lib, hdr, tried) with
    lib/hdr None if nothing usable was found."""
    tried = []
    explicit = [(lib_arg, hdr_arg, "--lib/--header"),
                (os.environ.get("DM32_CAPSTONE_LIB"), os.environ.get("DM32_CAPSTONE_HDR"),
                 "DM32_CAPSTONE_LIB/HDR")]
    for lib, hdr, why in explicit:
        if not lib and not hdr:
            continue
        if not (lib and hdr):
            sys.exit("%s: set both the library and the header (got lib=%r header=%r)"
                     % (why, lib, hdr))
        if os.path.exists(lib) and has_csky(hdr):
            return lib, hdr, tried
        tried.append("%s (%s): %s / %s" % (why, "missing" if not os.path.exists(lib)
                                           else "header has no CS_ARCH_CSKY", lib, hdr))
    prefixes = ([os.environ["DM32_CAPSTONE_PREFIX"]] if os.environ.get("DM32_CAPSTONE_PREFIX")
                else []) + CAPSTONE_PREFIXES
    for prefix in prefixes:
        for lib, hdr in prefix_candidates(prefix):
            if os.path.exists(lib) and has_csky(hdr):
                return lib, hdr, tried
        tried.append(prefix)
    return None, None, tried


NOT_BUILT = """capstone-csky not found. Looked in:
  %s
Build it (see this script's docstring for details), then either put it at one of the paths
above or point DM32_CAPSTONE_LIB / DM32_CAPSTONE_HDR at it:
  git clone -b csky https://github.com/awkaplan/capstone.git capstone-csky
  cmake -S capstone-csky -B capstone-csky/build -G Ninja -DCMAKE_BUILD_TYPE=Release \\
        -DCAPSTONE_ARCHITECTURE_DEFAULT=OFF -DCAPSTONE_CSKY_SUPPORT=ON \\
        -DCAPSTONE_BUILD_SHARED_LIBS=ON   # macOS: -DCMAKE_OSX_SYSROOT="$(xcrun --show-sdk-path)"
  ninja -C capstone-csky/build
(or run inside the docker/ image, which has it prebuilt; --backend objdump also works there)"""


class Disassembler:
    name = "capstone-csky"

    def __init__(self, lib_path, header, bin_path, base):
        self.lib = ctypes.CDLL(lib_path)
        self.lib.cs_disasm.restype = ctypes.c_size_t
        self.fw = open(bin_path, "rb").read()
        self.base = base
        self.h = ctypes.c_size_t()
        err = self.lib.cs_open(arch_id(header), 0, ctypes.byref(self.h))
        if err != 0:
            sys.exit("cs_open failed: %d" % err)

    def at(self, addr, window=4096, stop_at_return=True):
        """Decode forward from addr. Returns [(addr, mnemonic, operands, bytes)]."""
        off = addr - self.base
        if off < 0 or off >= len(self.fw):
            return []
        window = min(window, len(self.fw) - off)
        insn = ctypes.POINTER(CsInsn)()
        n = self.lib.cs_disasm(
            self.h, self.fw[off:off + window], ctypes.c_size_t(window),
            ctypes.c_uint64(addr), ctypes.c_size_t(0), ctypes.byref(insn),
        )
        out = []
        for i in range(n):
            ins = insn[i]
            mnem = ins.mnemonic.decode()
            out.append((ins.address, mnem, ins.op_str.decode(),
                        bytes(ins.bytes[:ins.size]).hex()))
            if stop_at_return and is_return(mnem):
                break
        return out


class ObjdumpDisassembler:
    """Fallback backend: csky-abiv2-elf-objdump over the raw image. Same interface as
    Disassembler.at(); instruction bytes are taken from the image itself (objdump prints
    halfword-swapped hex for 32-bit C-SKY instructions), sized from objdump's own decode."""
    name = "csky-abiv2-elf-objdump (fallback)"
    # " 3012e1c:\tec42fe00 \tori      \tr2, r2, 65024" - one 4- or 8-digit hex field per insn
    LINE = re.compile(r"^\s*([0-9a-f]+):\s+([0-9a-f]{4}(?:[0-9a-f]{4})?)\s+(\S+)\s*(.*)$")

    def __init__(self, objdump, bin_path, base):
        self.objdump = objdump
        self.bin_path = bin_path
        self.fw = open(bin_path, "rb").read()
        self.base = base

    def at(self, addr, window=4096, stop_at_return=True):
        off = addr - self.base
        if off < 0 or off >= len(self.fw):
            return []
        window = min(window, len(self.fw) - off)
        cmd = [self.objdump, "-D", "-b", "binary", "-m", "csky", "-EL",
               "--adjust-vma=0x%x" % self.base,
               "--start-address=0x%x" % addr, "--stop-address=0x%x" % (addr + window),
               self.bin_path]
        res = subprocess.run(cmd, capture_output=True, text=True)
        if res.returncode != 0:
            sys.exit("%s failed (%d): %s" % (self.objdump, res.returncode, res.stderr.strip()))
        out = []
        for line in res.stdout.splitlines():
            m = self.LINE.match(line)
            if not m:
                continue
            ia = int(m.group(1), 16)
            size = len(m.group(2)) // 2
            raw = self.fw[ia - self.base:ia - self.base + size].hex()
            mnem, ops = m.group(3), m.group(4).split("//")[0].strip()
            out.append((ia, mnem, ops, raw))
            if stop_at_return and is_return(mnem):
                break
        return out


def make_disassembler(args):
    base = int(args.base, 16)
    if args.backend in ("auto", "capstone"):
        lib, hdr, tried = find_capstone(args.lib, args.header)
        if lib:
            return Disassembler(lib, hdr, args.bin, base)
        if args.backend == "capstone":
            sys.exit(NOT_BUILT % "\n  ".join(tried))
    objdump = shutil.which(OBJDUMP)
    if objdump:
        if args.backend == "auto":
            print("# note: capstone-csky not found, falling back to %s" % OBJDUMP,
                  file=sys.stderr)
        return ObjdumpDisassembler(objdump, args.bin, base)
    if args.backend == "objdump":
        sys.exit("%s not on PATH (it is inside the docker/ image)" % OBJDUMP)
    sys.exit(NOT_BUILT % "\n  ".join(tried) + "\n%s is not on PATH either." % OBJDUMP)


def strip_width(mnemonic):
    """andn32 -> andn, ld32.b -> ld.b, br16 -> br. Lets a sweep name an
    instruction the way objdump and the ISA docs do."""
    return re.sub(r"(?<=[a-z0-9])(16|32)(?=\.|$)", "", mnemonic)


def is_return(mnemonic):
    """The return-shaped instructions --stop-at-return breaks on: jmp/rts (any width) and
    pop (any width) - CK803S `pop16 l0-l3, lr` restores the listed registers AND returns
    (implicit `jmp lr`), and it is how most compiled functions in this firmware end, so
    without it a single --addr decode ran through the literal pool into the next function."""
    return strip_width(mnemonic) in ("jmp", "rts", "pop")


def addr_from_name(path):
    m = re.search(r"_([0-9a-f]{8})\.c$", os.path.basename(path))
    return int(m.group(1), 16) if m else None


def live_in_registers(insns):
    """Registers read before ever being written - the real parameter list,
    independent of whatever unaff_rN locals the decompiler invented. Same
    first-operand-is-destination heuristic disasm_context.py uses, and the same
    caveat applies: stores and branches do not write their first operand."""
    read_first, written = [], set()
    for _, mnem, ops, _ in insns:
        regs = re.findall(r"\b(?:a[0-3]|l[0-7]|t[01]|sp|lr|r\d+)\b", ops)
        if not regs:
            continue
        writes_first = not (mnem.startswith("st") or mnem.startswith("b")
                            or mnem.startswith("cmp") or mnem.startswith("jmp"))
        srcs = regs[1:] if writes_first else regs
        for r in srcs:
            if r not in written and r not in read_first:
                read_first.append(r)
        if writes_first:
            written.add(regs[0])
    return read_first, written


def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--addr", help="function address, hex (e.g. 0305dbe4)")
    ap.add_argument("--file", help="decompiled .c file; address parsed from its name")
    ap.add_argument("--sweep", help="comma-separated mnemonics to hunt across --batch "
                                    "(width suffixes optional: 'andn' matches andn16/andn32)")
    ap.add_argument("--batch", help="decompiled batch dir to sweep")
    ap.add_argument("--regs", action="store_true", help="show live-in register summary")
    ap.add_argument("--bin", default=DEFAULT_BIN, help="firmware image (default: 00.01.048)")
    ap.add_argument("--base", default=hex(DEFAULT_BASE), help="load base (default 0x03000000)")
    ap.add_argument("--window", type=int, default=4096, help="max bytes to decode per function")
    ap.add_argument("--no-stop-at-return", action="store_true",
                    help="keep decoding past the first return (shows literal pools as 'code')")
    ap.add_argument("--lib", help="libcapstone with CSKY support (default: see LIBRARY "
                                  "LOOKUP ORDER above)")
    ap.add_argument("--header", help="matching include/capstone/capstone.h")
    ap.add_argument("--backend", choices=("auto", "capstone", "objdump"), default="auto",
                    help="auto (default) = capstone-csky if found, else %s" % OBJDUMP)
    args = ap.parse_args()

    dis = make_disassembler(args)
    stop = not args.no_stop_at_return

    if args.sweep:
        if not args.batch:
            sys.exit("--sweep needs --batch <decompiled batch dir>")
        wanted = {w.strip() for w in args.sweep.split(",") if w.strip()}
        hits = {w: [] for w in wanted}
        scanned = 0
        for path in sorted(glob.glob(os.path.join(args.batch, "*.c"))):
            addr = addr_from_name(path)
            if addr is None:
                continue
            insns = dis.at(addr, args.window, stop)
            if not insns:
                continue
            scanned += 1
            for ia, mnem, ops, _ in insns:
                base = strip_width(mnem)
                for w in wanted:
                    if base == w or mnem == w:
                        hits[w].append((os.path.basename(path), ia, mnem, ops))
        print("swept %d functions in %s\n" % (scanned, args.batch))
        for w in sorted(wanted):
            fns = {h[0] for h in hits[w]}
            print("=== %s: %d occurrence(s) in %d function(s) ===" % (w, len(hits[w]), len(fns)))
            for fn, ia, mnem, ops in hits[w][:20]:
                print("  %08x  %-10s %-24s %s" % (ia, mnem, ops, fn))
            if len(hits[w]) > 20:
                print("  ... %d more" % (len(hits[w]) - 20))
            print()
        return

    if args.file:
        addr = addr_from_name(args.file)
        if addr is None:
            sys.exit("could not parse an address out of %s" % args.file)
    elif args.addr:
        addr = int(args.addr, 16)
    else:
        ap.error("need --addr, --file or --sweep")

    insns = dis.at(addr, args.window, stop)
    if not insns:
        sys.exit("nothing decoded at %08x (wrong --bin or --base?)" % addr)

    print("# %s disassembly @ %08x  (%s)\n" % (dis.name, addr, os.path.basename(args.bin)))
    for ia, mnem, ops, raw in insns:
        print("  %08x  [%-8s]  %-10s %s" % (ia, raw, mnem, ops))
    if stop and is_return(insns[-1][1]):
        print("\n  (stopped at %s - anything after this is likely the literal pool, not code)"
              % insns[-1][1])

    if args.regs:
        read_first, written = live_in_registers(insns)
        print("\n# Register usage")
        print("  Read before written (real live-in / likely PARAMETERS): %s"
              % (", ".join(read_first) or "(none)"))
        print("  Written at some point (locals, or params reused as scratch): %s"
              % (", ".join(sorted(written)) or "(none)"))
        print("\n  Heuristic: first operand is the destination except for st*/b*/cmp*/jmp*.")
        print("  Cross-check against any unaff_rN names in the decompiled C - a match")
        print("  confirms genuine jump-table re-entry, not a decompiler bug.")


if __name__ == "__main__":
    main()
