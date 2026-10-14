# DMR voice encryption (ARC4 / DES / AES-128 / AES-256)

How the stock firmware (DM32.00.01.048) implements DMR privacy, how to turn on AES-256, and what
was found when the implementation was audited (2026-10-13).

**Verdict:**
- The AES-256 cipher itself is correct: the firmware's own code was run under QEMU against FIPS-197.
- The way the firmware picks the message indicator (MI, the per-call IV seed) is broken. It
  comes from an **unseeded libc `rand()`** and keeps only the low byte of each output.
- So **only 512 distinct initial MIs can ever occur**, and the sequence restarts from the same
  point on every power-up.
- AES-OFB with a repeated IV is a two-time pad. As shipped, AES-256 on this radio does not give
  confidentiality against someone recording traffic over time.
- No setting in the CPS fixes this. A firmware patch to the MI source is required; one is built and QEMU-verified (§6).

---

## 1. Enabling AES-256 (codeplug side)

Field layout is from infamy's codeplug protocol spec (`05-DATA-STRUCTURES.md`,
github.com/infamy/DM32-Protocol-Spec). The firmware-side reads below confirm it.

| What | Where | Value for AES-256 |
|---|---|---|
| Key slot (8 of them) | block `0x10`, `0x300 + (n-1)*0x2C`, 44 bytes each | |
| ↳ +0x00 ID | 1 byte | slot number 1–8. **Sent over the air as the Key ID**, so it must match on every radio |
| ↳ +0x01 name | 10 bytes ASCII | anything |
| ↳ +0x0B type | 1 byte | **4 = AES256** (0 None, 1 "Custom", 2 ARC4, 3 AES128) |
| ↳ +0x0C key | 32 bytes | the full 256-bit key. AES-256 uses all 32 bytes verbatim; **AES-128 uses only the first 16** (`aes_key_schedule_expand` reads `4*Nk` bytes from the field start) |
| Channel: encryption on | channel byte `0x1D` bit 7 (digital channels) | 1 |
| Channel: key slot | channel byte `0x2A` | 1–8 |

In the CPS: add a key under the encryption key list with type AES256 and enter **all 64 hex digits**
from a real random source. On each digital channel, turn Encryption on and pick that key. The
programmable-key function "Digital Encrypt" (side-key list item 4) and the menu entries
"Encrypt Switch" / "Encrypt List" control it at runtime.

Interop: the radio sends DMRA-standard privacy signalling. The PI header has FID `0x10` and
algorithm ID `0x25` for AES-256, plus the Key ID and the MI. A receiver only turns decryption on
when **both** the algorithm ID and the Key ID match its own channel key (see §2).

Gotchas:
- The key bytes in the spec's hardware capture are right-aligned and zero-padded (8 real bytes
  out of 32). The firmware does **no** length or content check on the key (the load path copies a
  fixed 32 bytes; the key expansion reads them as they are). Whether the CPS forces a full
  64-digit entry is not documented anywhere in this project's sources (checked 2026-10-14: the
  spec, the forum notes and the vendor-manual notes say nothing about the entry dialog). A short
  entry gives an AES-256 key with only that much entropy. The forum notes also record a
  *contradiction* for ARC4 padding (leading `0` per one user, left-aligned per the spec's
  capture) — unresolved.
- **CPS type 1 "Custom" is not a cipher in this firmware** (§2, "Algorithm IDs"). Do not use it
  expecting privacy.
- Factory defaults (`codeplug_factory_defaults_write` @0x03032434) create one key, slot 1 "Privacy 1",
  type 1 (Custom/DES), key `12 34 56 78 90 AB CD`. That is a published constant, so never use it.
- Keys are stored in plaintext on the data chip and **come back in a normal CPS read**. The infamy
  read capture contains them. Anyone with the radio and a cable has the key.
- Legal: on US amateur frequencies, encryption is prohibited by 47 CFR 97.113(a)(4). This
  feature is for licensed commercial/Part 90-style use.

## 2. Firmware mechanism

The crypto code is in the **IRAM load image**: flash `0x030bfc20..0x030decb8` is copied to IRAM
`0x00010000`. A flash-view corpus address runs at `addr - 0x030afc20`. The routines therefore have
no direct callers in the flash-view corpus, and their real callers branch to IRAM addresses.

### Key load: `dmr_privacy_key_load_and_mi_draw` @0x0305ca48 (called by `channel_change_apply_dispatcher`)

- Runs on every channel load or change.
- If the channel has a key slot (`vfo.field_0xe`), encryption enabled (`vfo.field_0xf & 0x40`) and is
  digital (`(vfo.flags_0x8 & 0xf0) == 0x10`), it reads the 44-byte key record from block `0x10`.
- Copies the record ID into both contexts' `[1]` (Key ID).
- Copies the 32 key bytes into the **TX context** (IRAM `0x3f338`, key at `+0x02`) and the **RX
  context** (IRAM `0x3f700`, key at `+0x03`).
- Then fills the TX MI (`0x3f338 + 0x22`, 4 bytes plus 2 spare) with **six calls to
  `lcg_rand_next`**, storing the low byte of each (`bsr 0x306fea4; st16.b a0` at 0x0305caec).

### Algorithm IDs

Internal IDs are what the setup and apply routines switch on. The PI header sends `id | 0x20`.

| internal | over the air | cipher | key bytes used | keystream |
|---|---|---|---|---|
| 1 | 0x21 | ARC4 (DMRA Enhanced Privacy) | 5 (40-bit) ‖ 4-byte MI | RC4, first 256 bytes dropped, 126 bytes |
| 2 | 0x22 | **none — stubbed.** The three block routines (`FUN_030cd0d8`/`dc`/`e4`) are single `rts` instructions (bytes `3c 78` at `0x030cd0d8..e6`, no DES tables anywhere in the image). The apply loop XORs the stale 8 bytes at ctx`+0x340` into the data, so with a fresh context **ciphertext == plaintext**. KAT-confirmed under QEMU (`crypto_kat.py`, check 4). | 7 copied, never used | 8 stale bytes, repeated |
| 4 | 0x24 | AES-128 | 16 | AES-OFB, 128 bytes |
| 5 | 0x25 | AES-256 | 32 | AES-OFB, 128 bytes |

**CPS type → internal ID (located 2026-10-14):** `dmr_privacy_alg_select_from_cps_type` @0x0301f074,
called from `dmr_privacy_type_apply` with the raw type byte (global `0x33824`, written by
`dmr_privacy_key_load_and_mi_draw`). It stores into both contexts' `[0]` (`0x3f338` and `0x3f700`):

| CPS type | internal `ctx[0]` | where |
|---|---|---|
| 2 ARC4 | 1 | `0x0301f0ca` |
| 3 AES128 | 4 | `0x0301f0e0` |
| 4 AES256 | 5 | `0x0301f0f8` |
| 1 Custom | **not written** — instead it zeroes a 10-byte buffer at `0x33825`, runs `delta_encode_adjacent_xor` over 7 key bytes from `0x3f33a` (the TX key), and hands the 7 bytes to IRAM `0x16064` and `0x16040`, which bit-copy them (via `0x2e3f0`) into tables at IRAM `0x46aa4` and `0x49a88` | `0x0301f0a2..0x0301f0c8` |
| 0 / other | clears `0x33824` and a flag at `0x33cac+0xb` | `0x0301f110` |

So internal ID 2 is reachable only if `ctx[0]` already held 2, which nothing in this build
writes; and even then the cipher is a stub. What the two IRAM key tables feed (plausibly the
HR_C7000 modem's own privacy scrambler — the datasheet's Appendix D) is **not traced**; type 1
may therefore be a hardware-side scrambler, or nothing. Either way it is not the 7-byte
"DES-style" software cipher this doc previously described. The `uStack_31`/`auStack_30` names in
the decompiled seed loader are wrong (type at `sp+0xb`, key at `sp+0xc`); the disassembly is
authoritative.

### PI header: `dmr_lc_call_setup_header_build` @0x0302417c (name correct)

`[0] = algid | 0x20, [1] = 0x10 (FID, DMRA), [2] = Key ID, [3..6] = MI, [7..9] = destination ID`.
The MI is sent in the clear, as DMR requires.

### TX keystream: IRAM `0x15bd4` (corpus: `dmr_privacy_tx_keystream_setup` @0x030c57f4, **misnamed**)

- Called with the TX context at call setup (`call_setup_or_teardown_handler`, from task
  **"CclTraffic"**, TCB `0x36f58`, created at `0x0300cb40`; and `dmr_call_setup_event_dispatch`,
  whose dispatcher is unresolved) and again for each superframe from an **IRAM function at
  `0x2d7ac`** (call site `0x2dbc0`: `movi r0,1; lrw r1,0x3f338; bsr 0x15bd4`). (Corrected
  2026-10-14: this was previously attributed to IRAM `0x2d6a4`, which does not call it.)
- For AES it expands the key, expands the MI to an IV, and generates 128 bytes of OFB keystream.
- It then **advances the MI in place** (32 steps of the same LFSR) for the next superframe and
  encodes it for embedded signalling.
- Within one channel session the MI therefore follows an LFSR chain. It is re-drawn from `rand()`
  only when the channel is loaded again.

### RX: IRAM `0x2b320` (a 10-byte wrapper around IRAM `0x15728` = corpus `dmr_privacy_rx_keystream_setup` @0x030c5348, misnamed)

- Called from `rxvoice_task_entry` @0x03020778 (despite the name, this is the PI-header
  RX path; it is task **"rxvoice"**, TCB `0x364a8`, created at `0x0300caaa`) and from
  `deferred_task_dispatch_on_timer_match` @0x030276bc (root unresolved: `FUN_03023a68` has no
  static reference).
- **Context note for patch authors:** TX and RX keystream setup run in different tasks, stock takes
  no lock around them, and the block encrypt works in a global buffer (IRAM `0x33c88`), so the
  uC/OS-III scheduler is the only thing keeping them apart. No AES use from ISR context was found
  (all registered handlers were walked; ~14 vectors' subgraphs only partly resolved).
- Both first check the received algorithm ID and Key ID against the RX context (HR_C7000
  `RX_INFO[2:0]` / `RX_INFO[10:3]`), copy the received MI, and build the same keystream.

### Corpus names (renamed 2026-10-14)

These were misnamed in the corpus; the upstream naming manifest was corrected and the corpus
regenerated on 2026-10-14. Old name → new name:

| old corpus name → new | address | actually |
|---|---|---|
| `crc32_block_append` → `dmr_privacy_mi_expand_lfsr` | 0x030cd000 | MI→IV expansion: `MI ‖ L(MI) ‖ L²(MI) ‖ L³(MI)`, L = 32 steps of the LFSR with taps 32,22,2,1 |
| `crc32_compute_and_log` → `dmr_privacy_mi_advance` | 0x030c4480 | MI advance (one L step; ARC4 uses a different LFSR). The "log" calls are empty stubs, and the gate at 0x03021b58 is `movi a0,1; rts` |
| `copy_and_checksum_blocks` → `dmr_privacy_aes_ofb_keystream_128` | 0x030cd08c | AES-OFB keystream: `t=E(IV)`, then 8 blocks `E(t), E²(t), …` (first OFB block skipped) |
| `firmware_command_buffer_encode_and_checksum` → `dmr_privacy_tx_keystream_setup` | 0x030c57f4 | TX privacy keystream setup (above) |
| `dmr_record_field_type_dispatcher` → `dmr_privacy_rx_keystream_setup` | 0x030c5348 | RX privacy keystream setup |
| `firmware_image_decrypt_by_mode` / `packet_payload_decrypt_by_mode` | 0x030c5538 / 0x030c5664 | keystream apply (XOR) per algorithm, for data payloads |
| `dmr_channel_scramble_seed_load` → `dmr_privacy_key_load_and_mi_draw` | 0x0305ca48 | privacy key load + TX MI draw |
| `u32_field_split_with_xor_table_lookup` → `dmr_privacy_mi_embedded_encode` | 0x030c5790 | MI + CRC4 encode for embedded signalling |

## 3. What was verified, and how

| Property | Result | Evidence |
|---|---|---|
| AES S-box and Rcon | correct | SRAM-init table at SRAM `0x1800119c` (flash `0x0307299c`) equals the FIPS-197 S-box byte for byte |
| AES-128 / AES-256 encryption | **correct** | `tools/src/dm32_patch_tools/crypto_kat.py`: the firmware's own code run under QEMU passes FIPS-197 C.1 and C.3 and an OpenSSL cross-check |
| MI→IV expansion | matches model | same script |
| Keystream construction | AES-OFB, first block skipped, 128 bytes | same script, compared against OpenSSL |
| TX setup + apply, id 5 | matches model | same script, check 4: scratch context, `0x15bd4` then `0x15918`; setup advances the MI once (`L(MI)`), apply XORs `E²(IV)` of the advanced MI |
| TX setup + apply, id 2 | **no cipher** | same script, check 4: keystream region untouched, output = input ⊕ stale `ctx+0x340` |
| RNG seeding | **never seeded** | static: `srand` (0x0306fec0) has zero callers in flash or IRAM, by `bsr` sweep and pointer search. The state at SRAM `0x18000c2c` starts at 1 (SRAM-init image). Dynamic: `rng_seed_probe.py` shows the state at standby is exactly `LCG^672(1)` and identical across boots |
| RNG algorithm | `s = s*1103515245 + 12345; return s>>1` | `lcg_rand_next` @0x0306fea4 |

## 4. The flaw: predictable, tiny MI space, so keystream reuse

1. Each MI byte is `(rand() & 0xff)`, i.e. bits 1..8 of the LCG state. For a power-of-two LCG,
   the low *n* bits are a self-contained LCG mod 2ⁿ. Bits 0..8 have period 512, so **the 4-byte
   initial MI depends only on `state mod 512`. At most 512 initial MIs exist, ever, for every radio
   running this firmware.** This was checked exhaustively.
2. The state starts at 1 on every boot and is never seeded. Other consumers are the ALPU exchange
   at boot and the scan-jitter and back-off timers (`scan_timer_apply_random_jitter`, the routine
   at 0x030241b4). These only move it along the same fixed sequence. With the same steps after
   power-up, the radio draws the **same MI every time**. Successive channel loads cycle with
   period 256 when nothing else consumes `rand()`.
3. After the draw, MIs follow a deterministic LFSR chain per superframe. Two sessions that start
   from the same initial MI produce **identical keystreams**, superframe for superframe.
4. The MI is sent in the clear in every PI header. A passive listener can therefore *see* when
   reuse happens and line up the matching superframes. XORing two such transmissions cancels the
   keystream and leaves `voice₁ ⊕ voice₂`. Where either side is a known AMBE+2 frame (silence
   frames are fixed patterns and speech is full of pauses), the keystream itself drops out. It
   can then be stored, indexed by MI, and reused against every later session from that MI.

The AES-256 key is never recovered; it doesn't need to be. Steps 1–3 are proven from code and
emulation. Step 4 is standard OFB/stream-cipher cryptanalysis and has **not** been demonstrated
over the air against this radio.

ARC4 and AES-128 draw their MI from the same code, so they share this flaw. ARC4 is also weak in
its own right (40-bit key).

## 5. Limits of DMRA privacy even with a perfect RNG

These are properties of the protocol, not of this firmware. Fixing §4 does not remove them.

- **32-bit MI.** The 128-bit IV is a fixed function of 32 bits. Every radio sharing a key draws
  from the same 2³² IV space, and each session consumes a chain of them. Collisions become likely
  after on the order of 2¹⁶ sessions per key. Rotate keys.
- **No integrity.** OFB is malleable, and voice frames have no MAC. An attacker can flip bits in
  ciphertext undetected, which garbles audio rather than producing chosen speech.
- **Metadata in the clear.** Source and destination IDs, algorithm, Key ID and MI are all
  unencrypted (HR_C7000 datasheet v2.7 Appendix D says the same).
- **Key custody.** Plaintext keys in the codeplug, readable with a cable (§1).

## 6. Notes for anyone patching the MI source

The HR_C7000 datasheet (v2.7) documents no hardware RNG, and its Appendix D leaves IV generation to
the integrator. Fixing §4 means replacing the `bsr lcg_rand_next` at **0x0305caec** (inside the
6-iteration fill loop of `dmr_privacy_key_load_and_mi_draw`) with a real random source. A patch that
does so exists outside this repository; this file
only records the stock facts such a patch has to respect:

- **The firmware's AES block encrypt is not reentrant.** `aes_block_encrypt` copies its input into a
  global buffer (IRAM `0x33c88`, from the literal pool at flash `0x030ccff0`). The TX and RX
  keystream code use the same buffer from two different tasks ("CclTraffic", "rxvoice") with no
  stock lock. Anything else that calls it must serialise against both, e.g. with IRQs off
  (`cpu_sr_save_and_disable_irq_iram` at `0x1018c` returns the old PSR in r0;
  `cpu_sr_restore_irq_iram` at `0x1019c` takes it in r0). The key schedule writes only to the
  caller's buffer. One block is 1221 instructions (QEMU exec trace), ~6 µs at 192 MHz.
- **Three tasks reach the MI draw**, none from ISR context (all registered IRQ handlers walked):
  "task init" (boot initial channel load, and keypad handler index 79 → `dtmf_key_poll_tick` →
  `channel_load_synchronized`), "task menu" (screen-mode row 5 → `channel_vfo_commit_with_
  password_and_flash_write` → `channel_change_apply_with_zone_and_flash_validate`) and "task
  CodeSw" (prio 28, `task_codesw_entry`, created at `0x03030360` → `channel_switch_and_screen_refresh`
  → `channel_load_synchronized`). `channel_load_synchronized` is an event-flag gate (group
  `0x0003fd90`, bit `0x20`), not a mutex, and the zone path has no lock at all: static state in a
  replacement needs its own lock.
- **The S-box is SRAM init data.** It lives at SRAM `0x1800119c`, copied from flash `0x0307299c`
  by the boot stub. `compose_qemu_image.py --iram-out` writes an all-zero `sram.bin`, under which
  AES silently returns key bytes instead of ciphertext. Build the SRAM image from flash
  `0x72000..0x763fc` at `0x800`, as `crypto_kat.py` and `rng_seed_probe.py` do.
- **The MI draw only runs on an encrypted digital channel** (key slot set, encryption bit set). A
  boot with no codeplug never reaches `0x0305caec`, so a hook there cannot be shown by booting
  alone; call it over the gdb stub (see `crypto_kat.py` for the pattern).
- **Noise sources available at that point:** only ADC channels 1 and 2 are muxed to the ADC on stock
  (`adc_stop_and_reset` @0x0301caec clears IO_DIPLEX2 bits 20/21; nothing clears 19 or 22–26, so
  other channels read a GPIO constant); TIMER0 (`CurrentValue` at `0x14000004`, 84 MHz) is free-
  running; the per-unit sector at `0x0300b000` is readable (XIP) and unique but neither secret nor
  random. Stock reads the ADC (`0x0305f3e2`) and starts the timers (`0x0305f2e0`) before the
  initial channel load (`0x0305f436`), so both are live by the first draw.
- Storage for a persistent counter is **not** available (no free data-chip space; see the
  blank-check notes in the research project).

## 7. Open items

- ~~Locate the CPS-type → internal-algorithm-ID conversion~~ — found (§2): 2→1, 3→4, 4→5; type 1
  takes a separate IRAM key-table path and never sets a software ID.
- ~~Decode the 8-byte-block cipher~~ — there is none (§2): the routines are `rts` stubs. **Open
  instead:** what consumes the IRAM key tables at `0x46aa4` / `0x49a88` that CPS type 1 fills
  (modem-side scrambler?). If nothing does, "Custom" sends voice in the clear while advertising
  encryption.
- ~~Check whether the CPS enforces a full-length AES key~~ — the firmware does not; the CPS
  dialog is undocumented in this project's sources (§1). Needs a look at the CPS itself.
- Measure the real radio's `rand()` count at standby (emulator count is 672 with the ALPU bypass).
- Over-the-air confirmation: capture the PI headers from two power-cycles on an encrypted channel
  and check the MI repeats (predicted from the emulator count: `c3 23 3a ce` if no other
  `rand()` consumer runs first; real hardware will differ but should repeat).
