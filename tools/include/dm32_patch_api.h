/*
 * dm32_patch_api.h - the stock-firmware primitives a DM-32UV patch can call, with the
 * RAM/SRAM cells it must know about. DM32.00.01.048 only (load base 0x03000000; every address
 * here is absolute into that one image, see ../../PROVENANCE.md).
 *
 * Supersedes dm32_ui.h (kept for the overlay example). Everything below was exercised by the
 * Snake example (tools/examples/snake/) under this repo's QEMU model AND on a real radio
 * (2026-10-09/10); the confidence tag on each entry says which. Calling convention is C-SKY
 * ABIv2 (r0-r3 arguments, 5th+ on the stack, r0 return, r15 return address): a plain C call
 * through a typed function pointer is correct, no assembly shim needed.
 *
 * READ FIRST: docs/keypad-input.md (the LCD/keypad pin-mux trap and the shared bus semaphore),
 * docs/menu-system.md (jump tables hold case blocks, how to add a category), and
 * docs/rtos-and-memory.md (where patch data may live).
 */
#ifndef DM32_PATCH_API_H
#define DM32_PATCH_API_H

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

/* ------------------------------------------------------------------------------------------
 * Display primitives (CONFIRMED on hardware). Colours are RGB565 (0x0000 black, 0xFFFF white,
 * 0x07E0 green, 0xF800 red). Every one of these takes the LCD/keypad bus semaphore itself
 * (see LCD_KEYPAD_BUS_SEM below) -- never call them while you hold it.
 * ------------------------------------------------------------------------------------------ */
#define display_set_window \
    ((void (*)(int x0, int y0, int x1, int y1))0x03017c38)
/* x1/y1 are EXCLUSIVE. */
#define display_fill_rect \
    ((void (*)(int x0, int y0, int x1, int y1, u16 color))0x03017c50)
/* Fills rows 0x1b..0x121 (the area between the title bar and the soft-key bar). */
#define display_fill_screen \
    ((void (*)(u16 color))0x03017f54)
/* FIVE arguments: the background colour travels on the stack. Omitting it paints the
 * background with whatever word sits at (sp,0).
 * ARGUMENT ORDER IS (ROW, COLUMN), unlike display_fill_rect's (x, y): the first argument steps
 * by 24 when the text wraps and the second by 12 per ASCII glyph, wrapping past 228 (decompiled
 * body; QEMU-confirmed 2026-10-15 by dm32uv-unleashed's About screen). ASCII glyphs are 12x24. */
#define display_draw_string_gb2312 \
    ((void (*)(int row, int col, const char *s, u16 fg, u16 bg))0x03018998)
#define display_draw_number_centered \
    ((void (*)(int x, int y, int value))0x03018b5c)
#define display_draw_string_wrapped2 \
    ((void (*)(int x, int y, const char *s))0x03019ff4)

/* ------------------------------------------------------------------------------------------
 * Keypad (CONFIRMED on hardware, scan codes MEASURED under QEMU run r37 against the OpenRTX
 * port's hardware keymap). Returns a raw scan code:
 *   0x00 nothing pressed (fast exit), 0x65 scan found no closure,
 *   0x02 Up   0x05 Down   0x03 Ok/Menu   0x06 Back   0x09 P1   0x0c P2
 *   0x10..0x18 '1'..'9'   0x0f '0'   0x0d '*'   0x0e '#'
 *   7 / 4 = the two dedicated-pin early exits (GPIOB bit 20 / 19 low): NOT the arrows.
 * ------------------------------------------------------------------------------------------ */
#define keypad_scan_and_map_pressed_key \
    ((u8 (*)(void))0x03013660)

#define SCAN_NONE    0x00
#define SCAN_TIMEOUT 0x65
#define SCAN_UP      0x02
#define SCAN_DOWN    0x05
#define SCAN_OK      0x03
#define SCAN_BACK    0x06
#define SCAN_P1      0x09
#define SCAN_P2      0x0c
#define SCAN_STAR    0x0d
#define SCAN_HASH    0x0e
#define SCAN_0       0x0f
#define SCAN_1       0x10   /* SCAN_1 + (n-1) for '1'..'9' */

/* HARDWARE TRAP. The keypad rows ROW0..ROW4 are the LCD data-bus pads DB0..DB4. Every call to
 * keypad_scan_and_map_pressed_key hands them to GPIO (keypad_scan_begin_mux_rows_drive_low
 * @0x03012e14: IO_DIPLEX2 |= 0xfe00). The stock poll gives them back immediately afterwards
 * with this function (IO_DIPLEX2 &= 0xffff01ff). Call it after EVERY scan, before the next LCD
 * write, or the panel goes white/frozen until the next power cycle (Snake v21 on hardware,
 * 2026-10-10). The QEMU model now forces pixel data to 0xFF while the mux is wrong, so a
 * forgotten restore shows up under emulation too. */
#define lcd_bus_restore_after_keypad_scan \
    ((void (*)(void))0x0301cad0)

/* The LCD/keypad bus semaphore (uC/OS-III OS_SEM at 0x00039344). The wrappers are OSSemPend
 * with a millisecond timeout (0 = forever) and OSSemPost. Pass 0: every stock pend on this
 * semaphore does, and the pend wrapper's OS error code (returned in r0, not declared below) is
 * the only way to tell a timeout from success. Hold it only around your own scan:
 *     os_sem_pend_ms(LCD_KEYPAD_BUS_SEM, 0);
 *     scan = keypad_scan_and_map_pressed_key();
 *     lcd_bus_restore_after_keypad_scan();
 *     os_sem_post(LCD_KEYPAD_BUS_SEM);
 * Never hold it across a display_* call: those pend it again and the semaphore is not
 * recursive (self-deadlock, QEMU run r36). */
#define os_sem_pend_ms \
    ((void (*)(void *sem, int timeout_ms))0x0300c500)   /* corpus name: OSMutexPend_wrapper2 */
#define os_sem_post \
    ((void (*)(void *sem))0x0300c53c)                   /* corpus name: OSMutexPost_wrapper2 */
#define LCD_KEYPAD_BUS_SEM ((void *)0x00039344)

/* Parking the STOCK keypad poll (keypad_poll_and_dispatch_key_event @0x03013744, which runs in
 * main_ui_background_task_loop in the task "task init", a different task from "task menu", where
 * a menu screen handler runs -- measured under QEMU 2026-10-10).
 * Its first test is `if (*KEYPAD_POLL_ENABLE == 0)`: when the word is 0 it does not scan and
 * runs the blanking stub @0x03013494 instead. That stub only counts (KEYPAD_BLANK_COUNTER; on
 * the 21st blank poll, counter > 0x14, it clears the counter, CLEARS KEYPAD_BLANK_REARM and
 * writes KEYPAD_POLL_ENABLE = 1) while KEYPAD_BLANK_REARM is non-zero; otherwise it returns
 * immediately and the keypad stays disabled until someone writes the enable word. So
 * KEYPAD_BLANK_REARM is a one-shot "re-enable later" request. Stock parks the poll the same way
 * (0x03059550 and 0x03022fac write ENABLE = 0, then REARM = 1).
 *   while you own the keypad:   *KEYPAD_POLL_ENABLE = 0; *KEYPAD_BLANK_COUNTER = 0;   each frame
 *   on exit (the only exit tested to work, Snake v21/v22):
 *                               *KEYPAD_BLANK_REARM = 1; *KEYPAD_BLANK_COUNTER = 0;
 *                               *KEYPAD_POLL_ENABLE = 0;   (re-enables ~20 polls later)
 * Writing *KEYPAD_POLL_ENABLE = 1 directly on exit is NOT a safe alternative from the item-OK
 * path: Snake v17/v20 did that and needed extra Backs / lost the Back (HISTORY.md). Stock never
 * does it outside the blanking stub. */
#define KEYPAD_POLL_ENABLE   ((volatile u32 *)0x18000800)
#define KEYPAD_BLANK_COUNTER ((volatile u8  *)0x0003e395)
#define KEYPAD_BLANK_REARM   ((volatile u32 *)0x00030790)

/* The stock poll's confirmed-key cells and dispatch rule: when cur != prev and cur != 0 it
 * calls KEYPAD_HANDLER_TABLE[cur]() (SRAM table of function pointers indexed by scan code,
 * filled at boot) and then sets prev = cur. Leaving cur = SCAN_BACK, prev = 0 and arming the
 * deferred re-arm above makes the stock process a Back for you after your handler has
 * returned -- the only way found to hand a key to the stock UI from inside a screen handler
 * (events posted directly from there are discarded; Snake v19/v20). */
#define STOCK_KEY_CUR         ((volatile u8 *)0x000392c4)
#define STOCK_KEY_PREV        ((volatile u8 *)0x000392c5)
#define KEYPAD_HANDLER_TABLE  ((void (**)(void))0x18000834)

/* ------------------------------------------------------------------------------------------
 * RTOS (uC/OS-III; CONFIRMED against the DemoUV008 port sources)
 * ------------------------------------------------------------------------------------------ */
#define os_time_dly_ms \
    ((void (*)(int ms))0x0300c4bc)
/* Post a key/UI event to the UI task's mailbox. field 1 or 3 = unconditional; field 2 is
 * dropped unless the byte at 0x0003078c is 1 (menu context). Events posted from inside a
 * screen handler are discarded before the UI task sees them -- see STOCK_KEY_CUR. */
#define write_field_and_mbox_post \
    ((void (*)(int field, int value))0x03013178)
#define event_queue_reset \
    ((void (*)(void))0x03054d80)

/* ------------------------------------------------------------------------------------------
 * Menu / sub-list cells (CONFIRMED; see docs/menu-system.md). A category's entry case fills
 * these, then calls build_sequential_index_list(count, ACTIVE_INDEX_LIST, ACTIVE_INDEX_LIST+2).
 * The stock item-OK path zeroes ACTIVE_VISIBLE_ROWS on the way into an item; re-run your
 * category entry on the way out so the list redraws.
 * ------------------------------------------------------------------------------------------ */
#define ACTIVE_ITEM_COUNT        ((volatile u8  *)0x0003e8f8)
#define ACTIVE_OPTION_PTR_ARRAY  ((volatile u32 *)0x0003e904)
#define ACTIVE_SCREEN_SUBTYPE    ((volatile u8  *)0x18000a90)
#define ACTIVE_VISIBLE_ROWS      ((volatile u8  *)0x0003e8f4)
#define ACTIVE_INDEX_LIST        ((u8 *)0x0003e5f8)
#define MENU_MAX_VISIBLE_ROWS    8
#define build_sequential_index_list \
    ((void (*)(u8 count, volatile void *out_count, volatile void *out_list))0x0304a118)
/* Where the stock category/item case blocks return to (docs/menu-system.md). */
#define STOCK_CASE_TAIL   0x0303d872
#define STOCK_OK_EPILOGUE 0x0303cde6

/* UI language bit (0 = Chinese, 1 = English) used to pick the string-array half. */
#define UI_LANG_IS_ENGLISH() ((((volatile u8 *)0x0003e9b4)[0x30] >> 6) & 1)

/* ------------------------------------------------------------------------------------------
 * Patch scratch RAM. The only region that passed the three checks in docs/rtos-and-memory.md.
 * ------------------------------------------------------------------------------------------ */
#define PATCH_SRAM_SCRATCH_LO 0x18004c00
#define PATCH_SRAM_SCRATCH_HI 0x18008000
/* Already taken inside it: Snake state 0x18007000-0x1800730f, overlay GUARD 0x18007FE0,
 * RAMDUMP cursor 0x18007FF0. The machine-readable copy of that list is
 * data/allocations.json, which placement_scan.py and the linker-script generator both enforce -
 * declare any range you claim there, or the next patch's scan will call it free.
 * Nothing initialises this window: it reads zero under QEMU (zero-filled sram.bin) but holds
 * power-on noise on a real radio (a live capture read 0x140b32b9 at 0x18007FE0). Set every
 * variable you keep here before you read it. */

#endif /* DM32_PATCH_API_H */
