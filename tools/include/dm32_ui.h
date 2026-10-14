/*
 * dm32_ui.h - call the DM-32 stock firmware's own UI primitives from patch code.
 *
 * WHY THIS EXISTS
 *   Ghidra's decompiled C for this firmware is NOT recompilable (undefined4/CONCAT/uRam
 *   artifacts, Ghidra-specific memory-layout assumptions). New UI features are therefore built
 *   the md380tools/OpenGD77 way: write fresh C, and CALL the stock firmware's existing,
 *   already-reverse-engineered routines at their known flash addresses.
 *
 *   Every address below is taken from this project's naming manifest for
 *   DM32.00.01.048 (sha256 0791558d...6147, load base 0x03000000) and is marked with the
 *   confidence level recorded there. Re-check them before targeting any other firmware build:
 *   these are absolute addresses into ONE specific image.
 *
 * CALLING CONVENTION
 *   C-SKY ABIv2: arguments in r0..r3, return in r0, return address in r15. This matches the
 *   compiler's own convention for -mcpu=ck803s, so a plain function-pointer call through these
 *   addresses is correct and needs no assembly shim.
 *
 * COLOR FORMAT
 *   RGB565, big-endian on the wire (display_lcd driver writes pixel>>8 then pixel&0xff).
 *   Observed stock values: 0xFFFF white, 0xF800 red, 0x0304 dark green text, 0x0000 black.
 *   See docs/subsystems/display-lcd-driver.md.
 */
#ifndef DM32_UI_H
#define DM32_UI_H

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

/* --- display primitives (docs/subsystems/display-lcd-driver.md) ------------------------- */

/* CONFIRMED. Set the LCD address window (CASET+RASET) to the inclusive rect. */
#define display_set_window \
    ((void (*)(int x0, int y0, int x1, int y1))0x03017c38)

/* CONFIRMED. The workhorse fill (112 stock callers): window + stream pixels of `color`.
 * x1/y1 are EXCLUSIVE (emulator-observed 2026-09-28: fill_rect(30,60,210,80) painted
 * x 30..209, y 60..79). */
#define display_fill_rect \
    ((void (*)(int x0, int y0, int x1, int y1, u16 color))0x03017c50)

/* CONFIRMED. Clear the whole panel to one color. */
#define display_fill_screen \
    ((void (*)(u16 color))0x03017f54)

/* CONFIRMED. Draw a GB2312/ASCII mixed string. FIVE arguments (emulator-verified 2026-09-28):
 *   r0=x, r1=y, r2=string, r3=attr (32/40 literal stock sites pass 0; meaning not yet pinned),
 *   stack=background colour (stock site 0x03012072 passes 0xC618).
 * The prologue spills r3 (`zexth r3,r3 ; st.w r3,(r14,8)`). Omitting the stack argument made the
 * routine paint its background with whatever word sat at (r14,0) -- a return address, which
 * showed up as a 0x89a0 band. Always pass all five. */
#define display_draw_string_gb2312 \
    ((void (*)(int x, int y, const char *s, u16 attr, u16 bg))0x03018998)

/* CONFIRMED. Draw a right-aligned/centered number (129 stock callers). */
#define display_draw_number_centered \
    ((void (*)(int x, int y, int value))0x03018b5c)

/* CONFIRMED. Word-wrapped string draw. */
#define display_draw_string_wrapped2 \
    ((void (*)(int x, int y, const char *s))0x03019ff4)

/* STRUCTURAL. Draw one menu/list row; `selected` highlights it. */
#define display_draw_list_row \
    ((void (*)(int row, const void *rec, int selected))0x03018cd8)

/* --- screen-mode state (docs/subsystems/ui-screen-state-machine.md) ---------------------- */

/*
 * STRUCTURAL. write_status_mode_byte_pair(mode, redraw):
 *     ui_state->field_0x3 = mode;
 *     if (redraw) ui_state->field_0x4 = redraw;
 * `mode` is a screen-mode ID; `redraw` is the refresh request byte (0x0b = request redraw,
 * 0 = leave the current redraw state alone). The struct lives at RAM 0x000320ac.
 */
#define ui_set_screen_mode \
    ((void (*)(u8 mode, u8 redraw))0x03035ec4)

#define UI_REDRAW_NONE     0x00
#define UI_REDRAW_REQUEST  0x0b
/* field_0x4 == 1 is a sticky/locked state that back-navigation refuses to override. */
#define UI_REDRAW_STICKY   0x01

/*
 * Screen-mode IDs, recovered by scanning all 319 call
 * sites of write_status_mode_byte_pair. The stock screens occupy a CONTIGUOUS 7-byte-strided
 * run 0,7,14,...,119 (k=0..17) with no gaps -- see docs/subsystems/ui-screen-mode-enum.md.
 *
 * A NEW screen must therefore NOT reuse any of these. The first free 7-strided slot is 126.
 * Read the enum doc's "allocating a new mode ID" section before picking one: mode IDs are used
 * as raw BYTE OFFSETS into runtime tables, so an out-of-range value reads past a table end.
 */
#define UI_MODE_FIRST_FREE_7STRIDE  126

#endif /* DM32_UI_H */
