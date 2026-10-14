/*
 * snake_category_entry.c - the 11th top-menu category's OK handler.
 *
 * REWRITTEN 2026-10-08 (v7). History of what this file got wrong, because each wrong turn cost a
 * full restore/flash/freeze/RAMDUMP cycle on real hardware:
 *
 *   v1-v5 tried to skip the sub-list and jump straight into a screen-mode-table handler via
 *   ui_set_screen_mode(). That is architecturally wrong here. Screens are not polled per tick:
 *   screen_mode_static_table_dispatch (0x0305279c) is reached from exactly one site (a bf16 at
 *   0x0304073e) and only when the UI event dispatcher's event code is 0x2a. Setting the mode byte
 *   never generates that event. Proof: a live RAMDUMP at the freeze point showed mode = 126 with
 *   all three of that dispatcher's gates satisfied, yet its arm byte 0x0003ea30 still read 1 --
 *   the dispatcher clears that byte as its first action once the gates pass, so it had not run at
 *   all. The three gate pokes v3-v5 added (0x3ea30 == 1, a sequence byte vs cursor_struct+2, and a
 *   2-byte memcmp of gate_struct+3 vs 0x0003e4e8) all ended up passing and it still froze: they
 *   were never the blocker.
 *
 *   v6 modeled the stock *render* path (category 9's entry @0x0303dd40) instead. Closer, but still
 *   the wrong path for an OK press.
 *
 * THE RIGHT TEMPLATE, traced from the top menu's real OK dispatch: the event path reaches a
 * category-indexed jump table at 0x030afef0 (bound-checked cmphsi 0xa at 0x0303cd8e, reached via
 * the same remap table at 0x0003e63f the render path uses). Its ten 6-byte stubs each `bsr` a
 * per-category OK handler. Category 8's (0x03043624) and category 9's (0x030436c0) are the same
 * shape; category 8 is the one to copy because its descriptor lives in FLASH, like Snake's:
 *
 *     lang = (cursor_struct[0x30] >> 6) & 1        // zext32 a1,a1,6,6 -- ONE bit (bit 6)
 *     desc = flash_descriptor + lang * 8           // {u32 array_ptr, u8 count, u8 subtype, u16 pad}
 *     *(u8  *)0x0003e8f8  = desc[4]                // item count
 *     *(u32 *)0x0003e904  = *(u32 *)desc           // string-pointer array base
 *     *(u8  *)0x18000a90  = desc[5]                // screen subtype; 2 = generic icon list
 *     if (*(u8 *)0x0003e9b4 == 1) {
 *         build_sequential_index_list(count, 0x0003e5f8, 0x0003e5f8 + 2);
 *         screen_build_and_repaint();              // 0x03012b0c -- THE missing piece in v1-v6
 *     }
 *
 * The 0x03012b0c call is what v1-v6 never had in any form: the routine that actually rebuilds and
 * repaints the screen. Nothing here claims a screen-mode ID, relocates the screen-mode table, or
 * pokes a dispatcher gate. The descriptor layout is confirmed against three independent stock
 * instances (GNSS 0x030b7e28, APRS 0x030ba924, Contacts 0x030b94a4), all subtype 2. The three
 * destination cells are the same ones this patch's own label-array fix was already grounded in.
 *
 * Snake therefore gets a normal one-item sub-list ("Play"), exactly like every other category.
 */
#include "../../include/dm32_patch_api.h"

/* Two 8-byte entries (lang0 = GB2312, lang1 = English), built and placed by
 * build_snake_patch.py and resolved here via ld --defsym. */
extern const unsigned char snake_submenu_descriptor[];

/* The language bit's base. Category 8 reads (lang_struct[0x30] >> 6) & 1 with this base, i.e.
 * 0x0003e9e4; a live capture read 0x40 there -> bit 6 set -> lang 1 (English), which matches the
 * radio's actual setting, so this base is confirmed correct. */
#define lang_struct              ((volatile unsigned char *)0x0003e9b4)
#define active_item_count        (*(volatile unsigned char *)0x0003e8f8)
#define active_option_ptr_array  (*(volatile unsigned int  *)0x0003e904)
#define active_screen_subtype    (*(volatile unsigned char *)0x18000a90)
#define active_index_list        ((volatile unsigned char *)0x0003e5f8)

/* THE ACTUAL FREEZE CAUSE, found 2026-10-08 by instrumenting this function with trace markers
 * and reading them back over RAMDUMP (every marker set -> this function always ran to completion,
 * so the bug was never in the code here).
 *
 * display_list_with_icons_renderer (0x03041644) bounds its row loop on *(u8*)0x0003e8f4, NOT on
 * the item count at 0x0003e8f8 that this handler and every stock handler write. The loop runs
 * l0 = 1..*(u8*)0x0003e8f4, drawing index_list[l1 + 2] each pass. Stock derives 0x0003e8f4 inside
 * menu_field_value_screen_render_and_key_dispatch (0x0303b720) as min(index_list_count, 8) -- but
 * that clamp runs on the render pass, which is too late: this handler returns first, and the
 * renderer then runs with whatever 0x0003e8f4 held from the PREVIOUS screen.
 *
 * Measured on hardware (RAMDUMP at the freeze, with l1 start = (scroll+1) - cursor = 0): coming
 * from the 8-item APRS list, 0x0003e8f4 was still 8, so the loop ran 8 passes against Snake's
 * 1-entry array. Pass 1 fetched array[0] = "Play" correctly; pass 2 fetched array[1] =
 * 0xFFFFFFFF and the string routine dereferenced that unmapped address -> hard hang mid-draw,
 * which is exactly why no list was ever visible. Stock categories never hit this because their
 * item arrays are at least as long as any stale bound they can inherit.
 *
 * So this handler must set the bound itself, applying the same clamp the renderer's own dispatch
 * would: min(count, 8). With count = 1 the loop runs exactly one pass and draws only "Play".
 */
#define active_visible_rows      (*(volatile unsigned char *)0x0003e8f4)
#define MAX_VISIBLE_ROWS 8

/* CORRECTED (v8): v7 gated the list build on *(u8*)0x0003e9b4 == 1, conflating TWO different
 * literal-pool bases in category 8's handler -- 0x0303_43 6c -> 0x0003e9b4 is the LANG base, but
 * the guard at 0x03043654 uses 0x0303_4374 -> 0x000320b0, a different cell entirely. 0x000320b0
 * is cursor_struct+4, the "redraw pending" flag: screen_mode_static_table_dispatch CLEARS it to 0
 * after dispatching (0x030527e4), and 56 stock action handlers read it. A live capture read 0xb
 * there, not 1, so v7's guard was false and snake_category_entry stored the three cells then
 * returned without ever building the list or repainting -- exactly the observed "no Play list".
 * Snake does not want that guard: it should always build and repaint, so the condition is gone. */

#define screen_build_and_repaint \
    ((void (*)(void))0x03012b0c)

/* DIAGNOSTIC TRACE (v9). Eight builds have now each fixed a real, independently-verified bug and
 * still frozen, and the one thing never actually confirmed on hardware is whether this function
 * runs AT ALL -- every capture has shown Snake's .bss entirely zero, which is equally consistent
 * with "never called" and "called but hung on the first instruction". These markers settle it: a
 * single RAMDUMP of the already-captured window (Snake's .bss at 0x00042cb1, in range, and zero
 * in every prior capture so any nonzero byte is unambiguously ours) shows exactly how far
 * execution reached. 0xA1..0xA6 are arbitrary distinct sentinels.
 *
 * trace[0] = entered the function
 * trace[1] = read the language bit            (value = lang + 0x10, so 0x10 or 0x11)
 * trace[2] = read the descriptor's count      (value = count)
 * trace[3] = stored all three active_* cells
 * trace[4] = returned from build_sequential_index_list
 * trace[5] = returned from screen_build_and_repaint  <- if this is set, the whole path ran
 */
/* (2026-10-09) The trace[] marker stores were REMOVED after the v15 QEMU freeze showed that
 * 0x42cxx is the uC/OS-III scheduler's area (see snake_game.ld); the comment above is kept as the
 * record of how the v11 root cause was found. */

void snake_category_entry(void)
{
    const unsigned char *desc;
    unsigned char count;
    unsigned int lang;


    lang = (lang_struct[0x30] >> 6) & 1;

    desc = snake_submenu_descriptor + lang * 8;
    count = desc[4];

    active_item_count = count;
    active_option_ptr_array = *(const unsigned int *)desc;
    active_screen_subtype = desc[5];
    /* Same clamp the renderer's own dispatch applies; see active_visible_rows above. Without
     * this the stale bound from the previous screen drives the row loop off the end of the
     * item array and the renderer hangs dereferencing 0xFFFFFFFF as a string. */
    active_visible_rows = (count < MAX_VISIBLE_ROWS) ? count : MAX_VISIBLE_ROWS;

    build_sequential_index_list(count, active_index_list, active_index_list + 2);

    /*
     * v11 (2026-10-09, root cause found under QEMU, no flash needed): the 0x03012b0c call that
     * v7-v10 made here is NOT "screen_build_and_repaint". It is device_telemetry_report_build --
     * category 8's contact/device-info TEXT builder (memset of a 0x154-byte buffer, strlen/memcpy,
     * radio_telemetry_format_dispatch, vfprintf) -- which stock category 8 runs only under its
     * `*(u8*)0x000320b0 == 1` guard, and no other category runs at all. Worse, this function was
     * also installed as the RENDER-path jump-table entry for category 10, and that table does not
     * hold functions: it holds case blocks INSIDE menu_screen_render_entry_variant that end with
     * `bsr main_menu_screen_dispatch; addi sp,4; pop l0-l2,lr` -- the enclosing function's own
     * epilogue. Returning from here with a plain `pop lr` left that frame unpopped on every UI
     * pass, and the exec-trace histogram showed the result: this function + the telemetry builder
     * re-entered ~1,300 times a second forever (8.4M TBs of memset per 10 s), i.e. the "freeze".
     * The render-path slot now points at a stub that calls this function and tail-jumps into the
     * stock tail at 0x0303d872 (see snake_tail_stub.S); this function does only what the stock
     * render cases do: fill the three cells and build the index list.
     */
}
