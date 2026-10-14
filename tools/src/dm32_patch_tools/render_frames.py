"""Render DM32_GRAMDUMP raw GRAM captures (from qemu_run.py's rundir) into viewable PNGs.

WHY THIS EXISTS: `qemu_run.py` (and the `-M dm32` board model underneath it) writes raw GRAM
dumps, not images - `<rundir>/gram.raw.NNN`, one per settled frame when DM32_GRAMSEQ=1. Looking
at a KEYSEQ-driven UI-navigation run means turning a handful of those into something a human (or
an agent via the Read tool's image support) can actually look at, ideally several at once so a
whole navigation sequence is visible in one picture. vendor/dm32uv-qemu/scripts/gram2png.py
already renders a single such frame; this script adds picking frames by number, cropping to the
panel's visible region, and tiling many into one labeled montage - the thing actually needed when
reviewing a 12-step KEYSEQ run.

FRAME FORMAT (same as vendor/dm32uv-qemu/scripts/gram2png.py and the DM32 LCD controller model):
320 rows, 256 pixels per row STRIDE (the controller's native GRAM width), of which only the
first 240 pixels per row are the panel's VISIBLE columns - the remaining 16 are off-panel GRAM
and must be cropped, not just left in. Each pixel is one RGB565 little-endian halfword.

Requires Pillow (not a dependency of any other script in this family - this is the one place
it's allowed, per this submodule's own conventions). If it's missing, this script prints an
install hint and exits rather than crashing with an ImportError traceback.
"""
from __future__ import annotations

import argparse
import pathlib
import sys

try:
    from PIL import Image, ImageDraw
    HAVE_PIL = True
except ImportError:
    # Dependency-free fallback (used inside this repo's Docker image, which ships no Pillow):
    # a tiny RGB canvas with the four methods this script uses and a zlib-based PNG writer.
    # Labels are not drawn in this mode; everything else renders identically.
    import struct as _struct
    import zlib as _zlib

    HAVE_PIL = False

    class _Px:
        def __init__(self, img): self.img = img
        def __setitem__(self, xy, rgb):
            x, y = xy; i = (y * self.img.w + x) * 3
            self.img.buf[i:i + 3] = bytes(rgb)

    class _RawImage:
        def __init__(self, w, h, fill=(0, 0, 0)):
            self.w, self.h = w, h
            self.buf = bytearray(bytes(fill) * (w * h))
        @staticmethod
        def new(mode, size, color=(0, 0, 0)): return _RawImage(size[0], size[1], color)
        def load(self): return _Px(self)
        def paste(self, other, xy):
            x0, y0 = xy
            for y in range(other.h):
                src = other.buf[y * other.w * 3:(y + 1) * other.w * 3]
                dst = ((y0 + y) * self.w + x0) * 3
                self.buf[dst:dst + len(src)] = src
        def save(self, path):
            raw = b"".join(b"\x00" + bytes(self.buf[y * self.w * 3:(y + 1) * self.w * 3]) for y in range(self.h))
            def chunk(tag, data):
                return _struct.pack(">I", len(data)) + tag + data + _struct.pack(">I", _zlib.crc32(tag + data) & 0xffffffff)
            png = b"\x89PNG\r\n\x1a\n" + chunk(b"IHDR", _struct.pack(">IIBBBBB", self.w, self.h, 8, 2, 0, 0, 0))
            png += chunk(b"IDAT", _zlib.compress(raw, 6)) + chunk(b"IEND", b"")
            pathlib.Path(path).write_bytes(png)

    class _NoDraw:
        def __init__(self, img): pass
        def text(self, *a, **k): pass

    class Image:  # noqa: N801 - mimic the two PIL entry points used below
        Image = _RawImage
        new = staticmethod(_RawImage.new)

    class ImageDraw:  # noqa: N801
        Draw = _NoDraw

ROWS = 320
STRIDE = 256
VISIBLE_COLS = 240
GRID_COLS = 6
LABEL_HEIGHT = 16


def load_frame(path: pathlib.Path) -> "Image.Image":
    data = path.read_bytes()
    expected = ROWS * STRIDE * 2
    if len(data) != expected:
        print(f"warning: {path} is {len(data)} bytes, expected {expected} "
              f"({ROWS} rows x {STRIDE} px x 2 bytes) - rendering what's there, padded/truncated",
              file=sys.stderr)
        if len(data) < expected:
            data = data + b"\x00" * (expected - len(data))
        else:
            data = data[:expected]

    img = Image.new("RGB", (VISIBLE_COLS, ROWS))
    px = img.load()
    for row in range(ROWS):
        row_off = row * STRIDE * 2
        for col in range(VISIBLE_COLS):
            off = row_off + col * 2
            halfword = data[off] | (data[off + 1] << 8)
            r5 = (halfword >> 11) & 0x1F
            g6 = (halfword >> 5) & 0x3F
            b5 = halfword & 0x1F
            r = (r5 * 255) // 31
            g = (g6 * 255) // 63
            b = (b5 * 255) // 31
            px[col, row] = (r, g, b)
    return img


def frame_path(rundir: pathlib.Path, n: int) -> pathlib.Path:
    return rundir / f"gram.raw.{n:03d}"


def montage(rundir: pathlib.Path, frame_nums: list[int]) -> "Image.Image":
    tiles = []
    for n in frame_nums:
        p = frame_path(rundir, n)
        if not p.exists():
            print(f"warning: {p} not found, skipping frame {n}", file=sys.stderr)
            continue
        tiles.append((n, load_frame(p)))

    if not tiles:
        raise SystemExit("no frames found to render")

    cols = min(GRID_COLS, len(tiles))
    rows = (len(tiles) + cols - 1) // cols
    tile_w, tile_h = VISIBLE_COLS, ROWS
    cell_w, cell_h = tile_w, tile_h + LABEL_HEIGHT

    out = Image.new("RGB", (cols * cell_w, rows * cell_h), (32, 32, 32))
    draw = ImageDraw.Draw(out)
    for i, (n, img) in enumerate(tiles):
        cx = (i % cols) * cell_w
        cy = (i // cols) * cell_h
        draw.text((cx + 4, cy + 1), f"#{n}", fill=(255, 255, 0))
        out.paste(img, (cx, cy + LABEL_HEIGHT))
    return out


def parse_frame_list(spec: str) -> list[int]:
    try:
        return [int(x) for x in spec.split(",") if x.strip() != ""]
    except ValueError:
        raise SystemExit(f"--frames must be a comma-separated list of integers, got {spec!r}")


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--rundir", type=pathlib.Path, required=True,
                     help="qemu_run.py run directory containing gram.raw.NNN files")
    ap.add_argument("--frames", default=None, help="comma-separated frame numbers, e.g. 12,25,40")
    ap.add_argument("--last", type=int, default=None, help="render the last N frames found in --rundir")
    ap.add_argument("--single", type=int, default=None, metavar="N",
                     help="render exactly one frame number (use with --out as the single image path)")
    ap.add_argument("--out", type=pathlib.Path, required=True, help="output PNG path")
    args = ap.parse_args()

    if args.single is not None:
        p = frame_path(args.rundir, args.single)
        if not p.exists():
            raise SystemExit(f"{p} not found")
        img = load_frame(p)
        img.save(args.out)
        print(f"wrote {args.out} (frame #{args.single})")
        return

    if args.frames is not None:
        frame_nums = parse_frame_list(args.frames)
    elif args.last is not None:
        existing = sorted(
            int(p.suffix.lstrip(".")) for p in args.rundir.glob("gram.raw.*")
            if p.suffix.lstrip(".").isdigit()
        )
        frame_nums = existing[-args.last:]
        if not frame_nums:
            raise SystemExit(f"no gram.raw.NNN frames found under {args.rundir}")
    else:
        raise SystemExit("specify --frames, --last, or --single")

    img = montage(args.rundir, frame_nums)
    img.save(args.out)
    print(f"wrote {args.out} ({len(frame_nums)} frame(s) requested)")


if __name__ == "__main__":
    main()
