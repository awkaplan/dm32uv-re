#!/usr/bin/env python3
"""
lookup.py - answer "what is X?" for anyone building a patch against DM32.00.01.048.

X can be:
  * an address (hex, with or without 0x):
      - program flash   0x03000000-0x030fffff
      - IRAM            0x00010000-0x00057fff
      - SRAM / MMIO / boot ROM are classified too, with whatever globals.h knows
  * a function or global name (exact; falls back to case-insensitive, then a unique substring)
  * a substring, with --search (functions, globals, catalogued patch sites)

For an address inside a function you get the containing function + offset; for an address that
is data you get the global / data region / occupied region it belongs to, plus the raw bytes
from the stock image. Either way you get the 4 KB sector, its sensitivity flag, patch risk,
catalogued patch sites, callers/callees (by name), disassembly and (with --c) decompiled C.

Plain python3 (>=3.8), no dependencies. Everything is read from this repo's own committed data:
  meta/functions.json, meta/disasm.jsonl, meta/xrefs.json, meta/sectors.json,
  meta/patch_risk.json, meta/patch_sites.json, meta/data_regions.json,
  data/firmware/patching/occupied_regions.json, include/dm32/globals.h, include/dm32/structs.h,
  src/**/<function file>.c, data/firmware/patching/progmem_stock_DP570UV_20260926_FULL.bin,
  data/firmware/IRAM_dm32.00.01.048.bin
Each file is loaded at most once, and only when the query needs it (disasm.jsonl is scanned for
the one line wanted, never parsed whole).

IRAM <-> flash aliasing: the boot stub copies flash 0x030bfc20..0x030decb8 to IRAM
0x00010000..0x0002f098 (see data/firmware/patching/occupied_regions.json). So an IRAM function's
persistent bytes live in flash at 0x030bfc20 + (addr - 0x10000), and a flash address in that
range is reported together with its IRAM alias. The same holds for SRAM 0x18000800..0x18004bfc
(initialised from flash 0x03072000). meta/disasm.jsonl and meta/patch_risk.json only cover
flash-linked functions, so IRAM functions have no corpus disassembly or risk entry - use
cs_disasm.py --bin data/firmware/IRAM_dm32.00.01.048.bin --base 0x10000 --addr <addr>.

EXAMPLES (run from the repo root, or from tools/ with src/dm32_patch_tools/lookup.py)
  python3 tools/src/dm32_patch_tools/lookup.py 0x03012e14
  python3 tools/src/dm32_patch_tools/lookup.py keypad_scan_and_map_pressed_key --c
  python3 tools/src/dm32_patch_tools/lookup.py 0x03017c50 --full        # all instructions/xrefs
  python3 tools/src/dm32_patch_tools/lookup.py 0x0300b10c               # per-unit sector data
  python3 tools/src/dm32_patch_tools/lookup.py 0x0002c0f8               # IRAM
  python3 tools/src/dm32_patch_tools/lookup.py --search keypad
  python3 tools/src/dm32_patch_tools/lookup.py 0x03013660 --json | jq .function.risk
  python3 tools/src/dm32_patch_tools/lookup.py 0x03013660 0x03012e14 -n 10   # several at once
  (or, from tools/: make lookup Q=0x03012e14 ARGS=--c)

CAVEATS (read before trusting an answer)
  * Naming confidence (CONFIRMED/STRUCTURAL/RAW) and patch_risk are separate axes - see
    meta/patch_risk.json's own note. 'high' risk under-detects ISR/RTOS callbacks.
  * "inside data region X" for flash comes from meta/data_regions.json's static classification;
    a 'binary-blob' there means "not decoded", not "free". occupied_regions.json wins over it.
  * A global's extent is only known when globals.h gives a sized type; an address past a
    global's known size is reported as "after" it, not "in" it.
  * Bytes in the per-unit sector 0x0300b000-0x0300bfff are scrubbed (0xFF) in every image here;
    they are NOT erased flash on a real radio. Never write there.
"""

import argparse
import bisect
import json
import os
import re
import sys

REPO = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "..", ".."))

FLASH_BASE = 0x03000000
FLASH_END = 0x03100000  # 1 MB GD25Q80 program flash
SECTOR = 0x1000
IRAM_BASE, IRAM_END = 0x00010000, 0x00058000
IRAM_IMG_FLASH, IRAM_IMG_LEN = 0x030BFC20, 0x0002F098 - 0x00010000
SRAM_BASE, SRAM_END = 0x18000000, 0x18008000
SRAM_IMG_RAM, SRAM_IMG_FLASH, SRAM_IMG_LEN = 0x18000800, 0x03072000, 0x18004BFC - 0x18000800
PER_UNIT = (0x0300B000, 0x0300C000)

BASIC_SIZES = {
    "undefined1": 1, "byte": 1, "char": 1, "uchar": 1, "bool": 1, "sbyte": 1,
    "undefined2": 2, "short": 2, "ushort": 2, "word": 2,
    "undefined4": 4, "int": 4, "uint": 4, "dword": 4, "float": 4, "long": 4, "ulong": 4,
    "undefined8": 8, "longlong": 8, "ulonglong": 8, "double": 8, "qword": 8,
}


def h(a):
    return "0x%08x" % a


def parse_addr(s):
    """Return int if s looks like an address, else None."""
    t = s.strip().lower()
    if t.startswith("0x"):
        try:
            return int(t, 16)
        except ValueError:
            return None
    if re.fullmatch(r"[0-9a-f]{5,8}", t):
        return int(t, 16)
    return None


# ------------------------------------------------------------------------------------------
# corpus: everything loaded lazily, once
# ------------------------------------------------------------------------------------------
class Corpus:
    def __init__(self, repo):
        self.repo = repo
        self._cache = {}

    def path(self, *p):
        return os.path.join(self.repo, *p)

    def _json(self, rel):
        if rel not in self._cache:
            with open(self.path(rel)) as f:
                self._cache[rel] = json.load(f)
        return self._cache[rel]

    # --- functions -----------------------------------------------------------------------
    @property
    def functions(self):
        if "functions" not in self._cache:
            fl = self._json("meta/functions.json")["functions"]
            fl = sorted(fl, key=lambda f: int(f["addr"], 16))
            for f in fl:
                f["_a"] = int(f["addr"], 16)
            self._cache["functions"] = fl
            self._cache["fstarts"] = [f["_a"] for f in fl]
            self._cache["fbyname"] = {f["name"]: f for f in fl}
            self._cache["fbyaddr"] = {f["_a"]: f for f in fl}
        return self._cache["functions"]

    def func_at(self, a):
        """(containing_function_or_None, preceding_function_or_None, next_function_or_None)."""
        fl = self.functions
        st = self._cache["fstarts"]
        i = bisect.bisect_right(st, a) - 1
        prev = fl[i] if i >= 0 else None
        nxt = fl[i + 1] if i + 1 < len(fl) else None
        if prev is not None and a < prev["_a"] + max(prev["size"], 1):
            return prev, prev, nxt
        return None, prev, nxt

    def func_by_addr(self, a):
        self.functions
        return self._cache["fbyaddr"].get(a)

    def func_by_name(self, n):
        self.functions
        return self._cache["fbyname"].get(n)

    def name_of(self, a):
        f, _, _ = self.func_at(a)
        if f is None:
            return None
        return f["name"] if f["_a"] == a else "%s+0x%x" % (f["name"], a - f["_a"])

    # --- source files ----------------------------------------------------------------------
    def src_file(self, fname):
        if "srcidx" not in self._cache:
            idx = {}
            for root, _, files in os.walk(self.path("src")):
                for fn in files:
                    idx.setdefault(fn, os.path.join(root, fn))
            self._cache["srcidx"] = idx
        return self._cache["srcidx"].get(fname)

    # --- disasm (one line, scanned) --------------------------------------------------------
    def disasm(self, a):
        key = ('{"addr": "%s"' % h(a)).encode()
        p = self.path("meta/disasm.jsonl")
        if not os.path.exists(p):
            return None
        with open(p, "rb") as f:
            for line in f:
                if line.startswith(key):
                    return json.loads(line)
        # format drift fallback: unpadded / other spacing
        alt = re.compile(rb'^\{\s*"addr"\s*:\s*"0x0*%x"' % a)
        with open(p, "rb") as f:
            for line in f:
                if alt.match(line):
                    return json.loads(line)
        return None

    # --- xrefs / risk / sectors / sites ----------------------------------------------------
    def xrefs(self, a):
        fx = self._json("meta/xrefs.json")["functions"]
        return fx.get("0x%x" % a) or fx.get(h(a))

    def risk(self, a):
        fr = self._json("meta/patch_risk.json")["functions"]
        return fr.get(h(a)) or fr.get("0x%x" % a)

    def sector(self, a):
        if not (FLASH_BASE <= a < FLASH_END):
            return None
        idx = (a - FLASH_BASE) // SECTOR
        s = self._json("meta/sectors.json")["sectors"].get(str(idx))
        base = FLASH_BASE + idx * SECTOR
        out = {"index": idx, "base": h(base), "flash_offset": "0x%05x" % (base - FLASH_BASE),
               "known_sensitive": None, "function_count": 0, "in_sectors_json": s is not None}
        if s:
            out["known_sensitive"] = s.get("known_sensitive")
            out["function_count"] = s.get("function_count", 0)
        if PER_UNIT[0] <= a < PER_UNIT[1]:
            out["known_sensitive"] = (out["known_sensitive"] or "") + \
                "PER-UNIT sector (eFuse-derived binding record) - never write"
        return out

    @property
    def sites(self):
        if "sites" not in self._cache:
            ss = self._json("meta/patch_sites.json")["sites"]
            for s in ss:
                s["_a"] = int(s["addr"], 16) if s.get("addr") else None
                ca = s.get("corpus_function_addr")
                s["_fa"] = int(ca, 16) if ca else None
            self._cache["sites"] = ss
        return self._cache["sites"]

    # --- data ------------------------------------------------------------------------------
    @property
    def regions(self):
        if "regions" not in self._cache:
            rr = self._json("meta/data_regions.json")["regions"]
            rr = sorted(rr, key=lambda r: int(r["start"], 16))
            for r in rr:
                r["_s"], r["_e"] = int(r["start"], 16), int(r["end"], 16)
            self._cache["regions"] = rr
            self._cache["rstarts"] = [r["_s"] for r in rr]
        return self._cache["regions"]

    def regions_end(self):
        d = self._json("meta/data_regions.json")
        try:
            return int(d["load_base"], 16) + int(d["image_size"])
        except (KeyError, ValueError):
            return max(r["_e"] for r in self.regions)

    def region_at(self, a):
        rr = self.regions
        i = bisect.bisect_right(self._cache["rstarts"], a) - 1
        if i >= 0 and rr[i]["_s"] <= a < rr[i]["_e"]:
            return rr[i]
        return None

    def occupied_at(self, a):
        try:
            occ = self._json("data/firmware/patching/occupied_regions.json")["occupied"]
        except FileNotFoundError:
            return []
        out = []
        for r in occ:
            s, e = FLASH_BASE + int(r["start"], 16), FLASH_BASE + int(r["end"], 16)
            if s <= a < e:
                out.append({"start": h(s), "end": h(e), "offset": a - s, "what": r["what"]})
        return out

    @property
    def struct_sizes(self):
        if "ssz" not in self._cache:
            sz = {}
            try:
                with open(self.path("include/dm32/structs.h")) as f:
                    for line in f:
                        m = re.match(r"/\* (\w+) - (\d+) bytes", line)
                        if m:
                            sz[m.group(1)] = int(m.group(2))
            except FileNotFoundError:
                pass
            self._cache["ssz"] = sz
        return self._cache["ssz"]

    @property
    def globals(self):
        if "globals" not in self._cache:
            rx = re.compile(r"^extern\s+(.+?)\s*\b([A-Za-z_]\w*)\s*(?:\[(\d+)\])?\s*;\s*/\*\s*(0x[0-9a-fA-F]+)(.*?)\*/")
            gl = []
            with open(self.path("include/dm32/globals.h")) as f:
                for line in f:
                    m = rx.match(line)
                    if not m:
                        continue
                    typ, name, cnt, addr, rest = m.groups()
                    typ = typ.strip()
                    if typ.endswith("*"):
                        esz = 4
                    else:
                        esz = BASIC_SIZES.get(typ) or self.struct_sizes.get(typ)
                    size = esz * int(cnt) if (esz and cnt) else esz
                    gl.append({"_a": int(addr, 16), "addr": h(int(addr, 16)), "name": name,
                               "type": typ + ("[%s]" % cnt if cnt else ""), "size": size,
                               "note": rest.strip(" ;") or None})
            gl.sort(key=lambda g: g["_a"])
            self._cache["globals"] = gl
            self._cache["gstarts"] = [g["_a"] for g in gl]
        return self._cache["globals"]

    def global_at(self, a):
        """(exact_or_containing_global, nearest_preceding_global)."""
        gl = self.globals
        i = bisect.bisect_right(self._cache["gstarts"], a) - 1
        if i < 0:
            return None, None
        g = gl[i]
        if g["_a"] == a or (g["size"] and a < g["_a"] + g["size"]):
            return g, g
        return None, g

    def global_by_name(self, n):
        for g in self.globals:
            if g["name"] == n:
                return g
        return None

    # --- raw bytes ---------------------------------------------------------------------------
    def read_bytes(self, a, n):
        if FLASH_BASE <= a < FLASH_END:
            p, off = self.path("data/firmware/patching/progmem_stock_DP570UV_20260926_FULL.bin"), a - FLASH_BASE
            src = "progmem_stock_DP570UV_20260926_FULL.bin"
        elif IRAM_BASE <= a < IRAM_END:
            p, off = self.path("data/firmware/IRAM_dm32.00.01.048.bin"), a - IRAM_BASE
            src = "IRAM_dm32.00.01.048.bin (boot-time image; runtime state differs above 0x0002f098)"
        else:
            return None
        try:
            with open(p, "rb") as f:
                f.seek(off)
                return {"source": src, "hex": f.read(n).hex(" ")}
        except FileNotFoundError:
            return None


# ------------------------------------------------------------------------------------------
# address classification
# ------------------------------------------------------------------------------------------
def classify_space(a):
    """Return (space_description, alias_addr_or_None, alias_description)."""
    if FLASH_BASE <= a < FLASH_END:
        if IRAM_IMG_FLASH <= a < IRAM_IMG_FLASH + IRAM_IMG_LEN:
            al = IRAM_BASE + (a - IRAM_IMG_FLASH)
            return "program flash (inside the IRAM load image)", al, "runs from IRAM at %s" % h(al)
        if SRAM_IMG_FLASH <= a < SRAM_IMG_FLASH + SRAM_IMG_LEN:
            al = SRAM_IMG_RAM + (a - SRAM_IMG_FLASH)
            return "program flash (inside the SRAM initialised-data image)", al, "copied to SRAM %s at boot" % h(al)
        return "program flash (XIP)", None, None
    if IRAM_BASE <= a < IRAM_END:
        if a < IRAM_BASE + IRAM_IMG_LEN:
            al = IRAM_IMG_FLASH + (a - IRAM_BASE)
            return "IRAM (loaded from flash at boot)", al, "persistent bytes live in flash at %s" % h(al)
        return "IRAM (above the load image: zero-initialised / runtime state)", None, None
    if a < IRAM_BASE:
        return "boot ROM region (~2 KB mask ROM mirrored across 0x0-0xffff)", None, None
    if SRAM_BASE <= a < SRAM_END:
        if SRAM_IMG_RAM <= a < SRAM_IMG_RAM + SRAM_IMG_LEN:
            al = SRAM_IMG_FLASH + (a - SRAM_IMG_RAM)
            return "SRAM (initialised-data image)", al, "initial value lives in flash at %s" % h(al)
        return "SRAM (0x18000000-0x18007fff; 0x18000000-0x180007ff used by the modem)", None, None
    if a >= 0x10000000:
        return "MMIO / peripheral space", None, None
    return "unmapped / unknown", None, None


def function_info(c, f, a, opts):
    fa = f["_a"]
    end = fa + f["size"]
    flash_alias = None
    if IRAM_BASE <= fa < IRAM_BASE + IRAM_IMG_LEN:
        flash_alias = IRAM_IMG_FLASH + (fa - IRAM_BASE)
    info = {
        "name": f["name"], "addr": h(fa), "end": h(end), "size": f["size"], "offset": a - fa,
        "subsystem": f["subsystem"], "classified_by": f.get("classified_by"),
        "confidence": f["confidence"], "named": f.get("named"), "in_manifest": f.get("in_manifest"),
        "file": None, "flash_alias": h(flash_alias) if flash_alias else None,
    }
    p = c.src_file(f["file"]) if f.get("file") else None
    info["file"] = os.path.relpath(p, c.repo) if p else None

    # sector + risk (flash-resident; IRAM functions via their load-image alias)
    sa = flash_alias if flash_alias is not None else fa
    sec = c.sector(sa)
    if sec is not None:
        last = (sa + max(f["size"], 1) - 1 - FLASH_BASE) // SECTOR
        sec["function_spans_into_next_sector"] = last != sec["index"]
    info["sector"] = sec
    r = c.risk(fa)
    info["risk"] = {"patch_risk": r["patch_risk"], "reasons": r["reasons"]} if r else None
    if r is None and flash_alias is not None:
        tw, _, _ = c.func_at(flash_alias)
        tr = c.risk(tw["_a"]) if tw else None
        if tr:
            info["risk"] = {"patch_risk": tr["patch_risk"],
                            "reasons": ["(via flash-image twin %s @ %s) " % (tw["name"], h(tw["_a"]))
                                        + "; ".join(tr["reasons"])]}

    # patch sites touching this function or its sector
    sites = []
    for s in c.sites:
        rel = None
        if s["_a"] is not None and (fa <= s["_a"] < max(end, fa + 1) or (
                flash_alias is not None and flash_alias <= s["_a"] < flash_alias + max(f["size"], 1))):
            rel = "inside this function"
        elif s["_fa"] == fa:
            rel = "names this function"
        elif sec and s["_a"] is not None and (s["_a"] - FLASH_BASE) // SECTOR == sec["index"]:
            rel = "same 4 KB sector"
        if rel:
            sites.append({"id": s["id"], "kind": s["kind"], "addr": s.get("addr"),
                          "status": s.get("status"), "relation": rel})
    info["patch_sites"] = sites

    # xrefs
    x = c.xrefs(fa)
    if x:
        def named(lst):
            return [{"addr": h(int(v, 16)), "name": c.name_of(int(v, 16))} for v in lst]
        info["xrefs"] = {
            "callers": named(x.get("callers", [])),
            "callees": named(x.get("callees_resolved", [])),
            "callees_iram_uncatalogued": named(x.get("callees_iram_uncatalogued", [])),
            "callees_flash_unresolved": named(x.get("callees_flash_unresolved", [])),
            "indirect_calls_out": x.get("indirect_calls_out", 0),
        }
    else:
        info["xrefs"] = None
    info["caller_count"], info["callee_count"] = f.get("caller_count"), f.get("callee_count")

    # disasm
    d = c.disasm(fa) if fa >= FLASH_BASE else None
    if d:
        ins = d["instructions"]
        idx = None
        for i, it in enumerate(ins):
            ia = int(it["addr"], 16)
            if ia <= a < ia + it["length"]:
                idx = i
                break
        n = len(ins) if opts.full else opts.n
        lo = 0
        if idx is not None and idx >= n:
            lo = max(0, idx - n // 2)
        shown = ins[lo:lo + n]
        info["disasm"] = {
            "instruction_count": d["instruction_count"], "shown_from": lo,
            "target_index": idx,
            "undecoded_ranges": d.get("undecoded_ranges", []),
            "instructions": [{"addr": h(int(it["addr"], 16)), "text": it["text"], "length": it["length"]}
                             for it in shown],
        }
    else:
        info["disasm"] = None
    if opts.c and p:
        with open(p, errors="replace") as fh:
            info["c_source"] = fh.read()
    return info


def lookup_addr(c, a, opts):
    space, alias, alias_desc = classify_space(a)
    res = {"query": h(a), "kind": None, "space": space,
           "alias": {"addr": h(alias), "note": alias_desc} if alias is not None else None}

    f, prev, nxt = c.func_at(a)
    # flash address in the IRAM load image -> the IRAM function lives at the alias
    if f is None and alias is not None and IRAM_BASE <= alias < IRAM_END:
        f2, _, _ = c.func_at(alias)
        if f2 is not None:
            f, a_eff = f2, alias
            res["note"] = "flash address is the load image of IRAM function %s" % f2["name"]
        else:
            a_eff = a
    else:
        a_eff = a

    if f is not None:
        res["kind"] = "code"
        res["function"] = function_info(c, f, a_eff, opts)
        # the same bytes can be catalogued twice: once at the flash load-image address and
        # once at the IRAM run address, under different names - report the other copy
        other = alias if a_eff == a else a
        if other is not None and other != a_eff:
            of, _, _ = c.func_at(other)
            if of is not None and of is not f:
                res["alias_function"] = {"name": of["name"], "addr": h(of["_a"]), "offset": other - of["_a"],
                                         "confidence": of["confidence"], "subsystem": of["subsystem"],
                                         "at": h(other)}
    else:
        res["kind"] = "data"
        res["function"] = None
        same = lambda fn: fn is not None and abs(fn["_a"] - a) < 0x10000
        if same(prev):
            res["after_function"] = {"name": prev["name"], "addr": h(prev["_a"]),
                                     "end": h(prev["_a"] + prev["size"]),
                                     "bytes_past_end": a - (prev["_a"] + prev["size"])}
        if same(nxt):
            res["before_function"] = {"name": nxt["name"], "addr": h(nxt["_a"]),
                                      "bytes_before": nxt["_a"] - a}

    # data-side context (always; for code it is usually the literal pool / nothing)
    flash_a = a if FLASH_BASE <= a < FLASH_END else (alias if alias and FLASH_BASE <= alias < FLASH_END else None)
    if flash_a is not None:
        r = c.region_at(flash_a)
        dr_end = c.regions_end()
        res["data_regions_cover"] = flash_a < dr_end
        res["data_regions_end"] = h(dr_end)
        if r:
            rr = {k: v for k, v in r.items() if not k.startswith("_")}
            rr["offset"] = flash_a - r["_s"]
            res["data_region"] = rr
        else:
            res["data_region"] = None
        res["occupied"] = c.occupied_at(flash_a)
        if res["function"] is None:
            res["sector"] = c.sector(flash_a)
            res["patch_sites"] = [{"id": s["id"], "kind": s["kind"], "addr": s.get("addr"),
                                   "status": s.get("status"),
                                   "relation": "exact" if s["_a"] == flash_a else "same 4 KB sector"}
                                  for s in c.sites if s["_a"] is not None
                                  and (s["_a"] - FLASH_BASE) // SECTOR == (flash_a - FLASH_BASE) // SECTOR
                                  and FLASH_BASE <= s["_a"] < FLASH_END]
    g, gp = c.global_at(a)
    if g is not None:
        res["global"] = {k: v for k, v in g.items() if not k.startswith("_")}
        res["global"]["offset"] = a - g["_a"]
    else:
        res["global"] = None
        if gp is not None and res["function"] is None and a - gp["_a"] < 0x1000:
            res["nearest_preceding_global"] = {k: v for k, v in gp.items() if not k.startswith("_")}
            res["nearest_preceding_global"]["distance"] = a - gp["_a"]
    if res["function"] is None or opts.bytes_always:
        b = c.read_bytes(a, opts.bytes)
        if b is not None and PER_UNIT[0] <= a < PER_UNIT[1]:
            b["note"] = "SCRUBBED: per-unit sector is blanked to 0xFF in every image here; real radios differ"
        res["bytes"] = b
    return res


def lookup_name(c, name, opts):
    f = c.func_by_name(name)
    if f is None:
        g = c.global_by_name(name)
        if g is not None:
            res = lookup_addr(c, g["_a"], opts)
            res["query"] = "%s (%s)" % (name, g["addr"])
            return res
        low = name.lower()
        cands = [x for x in c.functions if x["name"].lower() == low]
        if not cands:
            cands = [x for x in c.functions if low in x["name"].lower()]
        if len(cands) == 1:
            f = cands[0]
        else:
            return {"query": name, "kind": "ambiguous" if cands else "not-found",
                    "candidates": [{"addr": x["addr_hex"], "name": x["name"]} for x in cands[:50]],
                    "candidate_count": len(cands)}
    res = lookup_addr(c, f["_a"], opts)
    res["query"] = "%s (%s)" % (name, h(f["_a"]))
    return res


def search(c, term, opts):
    t = term.lower()
    lim = None if opts.full else opts.limit
    funcs = [f for f in c.functions if t in f["name"].lower() or t == f["subsystem"].lower()]
    rk = c._json("meta/patch_risk.json")["functions"]

    def risk_of(f):
        r = rk.get(h(f["_a"]))
        if r is None and IRAM_BASE <= f["_a"] < IRAM_BASE + IRAM_IMG_LEN:  # IRAM: flash twin's risk
            tw, _, _ = c.func_at(IRAM_IMG_FLASH + f["_a"] - IRAM_BASE)
            r = rk.get(h(tw["_a"])) if tw else None
        return (r or {}).get("patch_risk")
    fo = [{"addr": f["addr_hex"], "name": f["name"], "subsystem": f["subsystem"],
           "confidence": f["confidence"], "size": f["size"], "risk": risk_of(f)} for f in funcs]
    gls = [{"addr": g["addr"], "name": g["name"], "type": g["type"]}
           for g in c.globals if t in g["name"].lower()]
    sts = [{"id": s["id"], "kind": s["kind"], "addr": s.get("addr"), "status": s.get("status")}
           for s in c.sites if t in s["id"].lower() or t in (s.get("description") or "").lower()]
    return {"query": term, "kind": "search",
            "functions": fo[:lim], "function_count": len(fo),
            "globals": gls[:lim], "global_count": len(gls),
            "patch_sites": sts, "patch_site_count": len(sts)}


# ------------------------------------------------------------------------------------------
# text rendering
# ------------------------------------------------------------------------------------------
def wrap(s, n=100):
    return s if len(s) <= n else s[:n - 3] + "..."


def render(res, opts):
    out = []
    w = out.append
    k = res["kind"]
    if k == "search":
        w("== search %r: %d functions, %d globals, %d patch sites" % (
            res["query"], res["function_count"], res["global_count"], res["patch_site_count"]))
        if res["functions"]:
            w("-- functions (addr  conf  risk  size  subsystem  name)")
            for f in res["functions"]:
                w("  %s  %-10s %-7s %5d  %-16s %s" % (f["addr"], f["confidence"], f["risk"] or "-",
                                                     f["size"], f["subsystem"], f["name"]))
            if res["function_count"] > len(res["functions"]):
                w("  ... %d more (--full or --limit N)" % (res["function_count"] - len(res["functions"])))
        if res["globals"]:
            w("-- globals")
            for g in res["globals"]:
                w("  %s  %-20s %s" % (g["addr"], g["type"], g["name"]))
            if res["global_count"] > len(res["globals"]):
                w("  ... %d more" % (res["global_count"] - len(res["globals"])))
        if res["patch_sites"]:
            w("-- patch sites")
            for s in res["patch_sites"]:
                w("  %-38s %-20s %-12s %s" % (s["id"], s["kind"], s["addr"], s["status"]))
        return "\n".join(out)
    if k in ("not-found", "ambiguous"):
        w("== %r: %s%s" % (res["query"], k, " - try --search" if k == "not-found" else ""))
        for cnd in res.get("candidates", []):
            w("  %s  %s" % (cnd["addr"], cnd["name"]))
        if res.get("candidate_count", 0) > len(res.get("candidates", [])):
            w("  ... %d total (use --search)" % res["candidate_count"])
        return "\n".join(out)

    f = res.get("function")
    head = "== %s: %s" % (res["query"], res["space"])
    w(head)
    if res.get("alias"):
        w("   alias: %s (%s)" % (res["alias"]["addr"], res["alias"]["note"]))
    if res.get("note"):
        w("   note: " + res["note"])
    if res.get("alias_function"):
        af = res["alias_function"]
        w("   SAME BYTES ALSO CATALOGUED AS: %s @ %s%s (%s, %s) - two names, one piece of code" % (
            af["name"], af["addr"], (" + 0x%x" % af["offset"]) if af["offset"] else "",
            af["confidence"], af["subsystem"]))
    if f:
        off = " + 0x%x" % f["offset"] if f["offset"] else " (function entry)"
        w("-- identity")
        w("  %s @ %s%s" % (f["name"], f["addr"], off))
        w("  size %d (ends %s)  confidence %s  subsystem %s (%s)" % (
            f["size"], f["end"], f["confidence"], f["subsystem"], f["classified_by"]))
        if f["file"]:
            w("  source: " + f["file"])
        if f["flash_alias"]:
            w("  IRAM function: persistent bytes at flash %s (patch there; RAM edits are lost at reboot)" % f["flash_alias"])
        w("-- sector / risk / patch sites")
        s = f["sector"]
        if s:
            w("  sector %d  base %s  (flash write offset %s, %d flash-linked corpus functions share it%s)" % (
                s["index"], s["base"], s["flash_offset"], s["function_count"],
                "; FUNCTION SPANS INTO NEXT SECTOR" if s.get("function_spans_into_next_sector") else ""))
            if s["known_sensitive"]:
                w("  !! SENSITIVE: " + wrap(s["known_sensitive"], 160))
        else:
            w("  sector: n/a")
        if f["risk"]:
            w("  patch_risk %s: %s" % (f["risk"]["patch_risk"], "; ".join(f["risk"]["reasons"])))
        else:
            w("  patch_risk: not assessed (meta/patch_risk.json covers flash functions only)")
        for st in f["patch_sites"]:
            w("  patch site %s (%s, %s, %s) - %s" % (st["id"], st["kind"], st["addr"], st["status"], st["relation"]))
        x = f["xrefs"]
        # functions.json's callee_count is 0 for every function (as of 2026-10-10) and its
        # caller_count does not match xrefs.json's distinct-caller count - so lists below come from xrefs.json
        w("-- xrefs (meta/xrefs.json; functions.json caller_count=%s, may differ)" % f["caller_count"])
        if x:
            cap = None if opts.full else 25

            def lst(label, items):
                if not items:
                    return
                shown = items[:cap]
                w("  %s (%d): %s%s" % (label, len(items),
                                       ", ".join("%s@%s" % (i["name"] or "?", i["addr"]) for i in shown),
                                       " ... (--full)" if len(items) > len(shown) else ""))
            lst("callers", x["callers"])
            lst("callees", x["callees"])
            lst("callees IRAM-uncatalogued", x["callees_iram_uncatalogued"])
            lst("callees flash-unresolved", x["callees_flash_unresolved"])
            if not (x["callers"] or x["callees"]):
                w("  (no direct bsr/jsr callers or callees found - may be reached indirectly)")
            if x["indirect_calls_out"]:
                w("  indirect calls out: %d" % x["indirect_calls_out"])
        else:
            w("  not in meta/xrefs.json")
        d = f["disasm"]
        if d:
            w("-- disassembly (%d instructions%s)" % (
                d["instruction_count"],
                "" if len(d["instructions"]) >= d["instruction_count"] else
                ", showing %d from #%d; --full for all" % (len(d["instructions"]), d["shown_from"])))
            for j, it in enumerate(d["instructions"]):
                mark = ">" if (f["offset"] and d["target_index"] == d["shown_from"] + j) else " "
                w("  %s%s  %s" % (mark, it["addr"], it["text"]))
            if d["target_index"] is None and f["offset"]:
                w("  (query address is not on an instruction boundary of this function's decode - "
                  "likely an inline literal pool or undecoded span)")
            if d["undecoded_ranges"]:
                w("  undecoded ranges: " + ", ".join("%s-%s" % tuple(r) for r in d["undecoded_ranges"]))
        elif f["flash_alias"]:
            w("-- disassembly: none in corpus for IRAM functions; try")
            w("  cs_disasm.py --bin data/firmware/IRAM_dm32.00.01.048.bin --base 0x10000 --addr %s" % f["addr"][2:])
        if f.get("c_source"):
            w("-- decompiled C (%s)" % f["file"])
            w(f["c_source"].rstrip())
    else:
        w("-- not inside any corpus function")
        if res.get("after_function"):
            af = res["after_function"]
            w("  after  %s @ %s (ends %s, query is 0x%x past its end)" % (
                af["name"], af["addr"], af["end"], af["bytes_past_end"]))
        if res.get("before_function"):
            bf = res["before_function"]
            w("  before %s @ %s (0x%x bytes ahead)" % (bf["name"], bf["addr"], bf["bytes_before"]))
        s = res.get("sector")
        if s:
            w("-- sector %d  base %s  (flash write offset %s, %d corpus functions)" % (
                s["index"], s["base"], s["flash_offset"], s["function_count"]))
            if s["known_sensitive"]:
                w("  !! SENSITIVE: " + wrap(s["known_sensitive"], 160))
        for st in res.get("patch_sites", []) or []:
            w("  patch site %s (%s, %s, %s) - %s" % (st["id"], st["kind"], st["addr"], st["status"], st["relation"]))
    # data context
    if (("data_region" in res and not f) or res.get("data_region") or res.get("occupied")
            or res.get("global") or res.get("nearest_preceding_global")):
        w("-- data")
    for o in res.get("occupied") or []:
        w("  OCCUPIED %s-%s (+0x%x): %s" % (o["start"], o["end"], o["offset"], wrap(o["what"], 220)))
    dr = res.get("data_region")
    if dr:
        extra = ", ".join("%s=%s" % (kk, dr[kk]) for kk in ("flash_ptrs", "iram_ptrs", "words", "w", "h",
                                                             "glyphs", "evidence", "extracted_file") if kk in dr)
        w("  data_regions: %s %s-%s (+0x%x, %d bytes)%s" % (
            dr["kind"], "0x" + dr["start"], "0x" + dr["end"], dr["offset"], dr["size"],
            ("  [" + extra + "]") if extra else ""))
        if dr["kind"] == "binary-blob":
            w("    ('binary-blob' = not decoded, NOT free space)")
    elif "data_region" in res and not f:
        w("  data_regions: no region covers this address%s" % (
            "" if res.get("data_regions_cover") else
            " (meta/data_regions.json only covers the vendor image, to %s)" % res.get("data_regions_end", "?")))
    g = res.get("global")
    if g:
        w("  global: %s %s @ %s +0x%x%s" % (g["type"], g["name"], g["addr"], g["offset"],
                                           (" size %d" % g["size"]) if g["size"] else " (size unknown)"))
        if g.get("note"):
            w("    " + wrap(g["note"], 160))
    elif res.get("nearest_preceding_global"):
        g = res["nearest_preceding_global"]
        w("  nearest preceding global: %s %s @ %s (query is +0x%x; %s)" % (
            g["type"], g["name"], g["addr"], g["distance"],
            ("its known size is %d, so NOT inside it" % g["size"]) if g["size"] else "size unknown"))
    b = res.get("bytes")
    if b:
        w("  bytes: %s   [%s]" % (b["hex"], b["source"]))
        if b.get("note"):
            w("  !! " + b["note"])
    return "\n".join(out)


def main(argv=None):
    ap = argparse.ArgumentParser(description="What is X? (address, function/global name, or --search substring)",
                                 formatter_class=argparse.RawDescriptionHelpFormatter, epilog=__doc__.split("EXAMPLES")[1].split("CAVEATS")[0])
    ap.add_argument("query", nargs="+", help="address (hex), name, or (with --search) substring")
    ap.add_argument("--search", "-s", action="store_true", help="substring search over names/sites")
    ap.add_argument("--full", action="store_true", help="all instructions / xrefs / search hits")
    ap.add_argument("--c", action="store_true", help="include decompiled C source")
    ap.add_argument("--json", action="store_true", help="machine-readable output")
    ap.add_argument("-n", type=int, default=40, help="instructions to show (default 40)")
    ap.add_argument("--limit", type=int, default=60, help="search hits per category (default 60)")
    ap.add_argument("--bytes", type=int, default=16, help="raw bytes to show for data addresses (default 16)")
    ap.add_argument("--bytes-always", action="store_true", help="show raw bytes for code addresses too")
    ap.add_argument("--repo", default=REPO, help="repo root (default: inferred from this file)")
    opts = ap.parse_args(argv)

    c = Corpus(opts.repo)
    results = []
    for q in opts.query:
        if opts.search:
            results.append(search(c, q, opts))
            continue
        a = parse_addr(q)
        if a is not None and c.func_by_name(q) is None:
            results.append(lookup_addr(c, a, opts))
        else:
            results.append(lookup_name(c, q, opts))

    if opts.json:
        json.dump(results[0] if len(results) == 1 else results, sys.stdout, indent=1)
        sys.stdout.write("\n")
    else:
        print("\n\n".join(render(r, opts) for r in results))
    return 0 if all(r["kind"] not in ("not-found", "ambiguous") for r in results) else 1


if __name__ == "__main__":
    try:
        sys.exit(main())
    except BrokenPipeError:
        sys.exit(0)
