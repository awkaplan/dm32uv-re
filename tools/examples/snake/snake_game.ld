/* Linker script: places .text/.rodata at the chosen free-flash offset (see README.md for how
 * that offset was verified against the full stock backup) and .bss in the top page of SRAM.
 *
 * .bss PLACEMENT, CORRECTED 2026-10-09 (QEMU r38, "snake freezes after a few ticks, CPU at
 * pc=0 sp=0xfffffffc"). The previous address, IRAM 0x00042cb1, was chosen because it is zero in
 * the live IRAM dump. It is zero because it is the uC/OS-III ready-list / scheduler area: flash
 * literals 0x0306ab04/0x0306ad90/0x0306aed0 point at 0x42cb4, 0x0306ab38/0x0306aedc at 0x42cb8,
 * 0x03069518/0x0306953c at 0x42cbc, a dozen kernel functions at 0x42cc0..0x42cc8, and the IRAM
 * context-switch code around 0x10934 indexes a 12-byte-stride table from there (OS_RDY_LIST is
 * 12 bytes). Zero ready-list slots look exactly like free memory. Writing the game state there
 * corrupted the scheduler, which eventually loaded sp/pc from a null TCB.
 *
 * REVIEWED 2026-10-10: the collision is real, the causal claim above is NOT proven. The linker
 * put `s` at 0x00042cb4, over kernel words 0x42cb4..0x42cc8 (read by
 * cpu_and_channel_load_statistics_task etc. in flash and, for 0x42cc0, by IRAM scheduler code at
 * 0x10b08); OSPrioHighRdy/OSTCBHighRdyPtr sit just below, at 0x42ca8/0x42cac, and were not
 * overlapped. Rebuilt with this placement and run under the FIXED emulator, the game ran 260 s
 * (27 direction changes) and, with len forced to 12 over 0x42cc0.., another 120 s, with no crash.
 * HISTORY.md v16(c) attributes r38 to the since-fixed emulator PSR bug, which produces the same
 * pc=0/sp=0xfffffffc signature; that is the better-supported cause. The move to SRAM stands.
 *
 * SRAM 0x18004c00-0x18008000 (13 KB) is referenced by NO literal in the flash image or the IRAM
 * dump (highest SRAM reference is 0x18004bfc, from 0x0300c0c8) and read back all-zero over the gdb
 * stub after a full QEMU boot + menu + game session (r39) -- zero only because QEMU loads a
 * zero-filled sram.bin; on hardware the window holds power-on noise. It also hosts two scratch
 * words: the RAMDUMP cursor 0x18007FF0 (used on hardware) and overlay_trampoline.S's GUARD
 * 0x18007FE0 (emulator-only so far; it was never verified against a live capture). The game's
 * 0x30f-byte state goes at 0x18007000, well clear of both. */
/* CORRECTED 2026-10-08, live hardware freeze #2: build_snake_patch.py's SNAKE_HANDLER_ADDR
 * constant (0x030e8000) assumes snake_screen_handler is the FIRST function GCC emits -- it
 * is NOT. `*(.text)` links in whatever order the compiler happened to emit place_food,
 * reset_game, draw_frame, snake_screen_handler (in that order), so the mode-126 table row
 * was pointing at place_food, not the real entry point -- place_food has a different
 * calling convention (no display calls, a bounded retry loop, no screen-mode awareness),
 * so mode 126 silently ran the wrong function and returned without ever drawing anything,
 * which is exactly what a "screen never transitions, then freezes" symptom looks like from
 * the user's side. Fixed by forcing the real entry point into its own named section and
 * placing that section explicitly first -- requires -ffunction-sections at compile time (see
 * build_snake_patch.py) so each function gets its own `.text.<name>` section to select by name. */
SECTIONS
{
    .text 0x030e8000 : {
        *(.text.snake_screen_handler)
        *(.text*)
    }
    .rodata : { *(.rodata*) }
    .bss 0x18007000 : { *(.bss) *(COMMON) }
}
