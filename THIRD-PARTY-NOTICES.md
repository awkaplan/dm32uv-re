# Third-party notices

Material in this repository that follows a third-party work released under its own license. It is
not covered by this repository's `LICENSE.md`; its own terms, reproduced below, apply.

## infamy/DM32-Protocol-Spec (MIT)

Source: <https://github.com/infamy/DM32-Protocol-Spec>, commit `62b9b36` (2026-08-03).

The codeplug, data-chip region-map, contact-database, calibration-block, boot-image, asset and CPS
serial-protocol layouts in `specs/ksy/` and `specs/generated/python/` follow this specification
(files `02-CONNECTION-SEQUENCE.md`, `03-COMMANDS.md`, `04-MEMORY-LAYOUT.md`,
`05-DATA-STRUCTURES.md`, `06-ENCODING.md` and `07-BLOCK-INVENTORY.md`). Each affected file credits
it in its header. Field names, confidence tags and cross-checks against the stock firmware are this
project's own.

```
MIT License

Copyright (c) 2025 DM-32UV Protocol Documentation Contributors

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```

The upstream `LICENSE` file also carries a use-at-your-own-risk and no-affiliation disclaimer after
the MIT text; see the source repository for it.

## Referenced but not reproduced

These works were consulted to cross-check names or values. No code or text from them is included,
so their licenses impose nothing here; they are listed for provenance only.

- OpenRTX DM-32 port, `pinmap.h` (GPL-3.0-or-later) — cited in `specs/dts/dm32uv.dts`.
- serialDV (GPL-3.0), tcd (GPL-3.0) and zumspotpy (Apache-2.0) — cited in
  `specs/include/hr_v3000.h` and `specs/generated/python/hr_v3000.py`.
- DemoUV008 driver headers (OpenGD77-derived, non-commercial license) — cited in
  `data/registers/README.md`.
- github.com/rogerclarkmelbourne/DM32 and github.com/yo3hjv/Baofeng-DM32 (no license file) —
  protocol and layout facts only, cited in `specs/generated/python/`.
