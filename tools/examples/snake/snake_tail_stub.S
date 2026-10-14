/*
 * snake_tail_stub.S - a per-category jump-table entry of the shape the stock tables expect.
 *
 * Found 2026-10-09 under QEMU (exec-trace histogram of the "freeze"): the stock per-category
 * jump tables do NOT hold functions. Render path (table 0x030aff74, consumed by
 * menu_screen_render_entry_variant @0x0303d8c8) and item path (table 0x030aff18, consumed by
 * main_menu_render_and_field_edit_dispatch @0x0303cdf0) hold CASE BLOCKS inside those functions,
 * reached by `jmp16 a3` with the enclosing frame (push16 l0-l2,lr; subi16 sp,4) still live. Every
 * stock case ends in the enclosing function's tail:
 *     0x0303d872:  bsr main_menu_screen_dispatch ; addi16 sp,4 ; pop16 l0-l2,lr
 * (the item cases are literally `bsr <handler>; br32 0x0303d872`, and the render cases inline the
 * same three instructions). Both functions have the identical prologue, so one tail serves both.
 * v10 put plain C functions in those slots; their own `pop lr` returned to the enclosing
 * function's caller with 0x14 bytes of frame still on the stack, once per UI pass -- the livelock.
 *
 * This stub is that shape: run HANDLER (a normal C function), then tail-transfer to EPILOGUE.
 * br16/br32 cannot reach from ~0x030e9xxx (+/-1 KB / +/-64 KB), so an absolute lrw+jmp is used;
 * r3/a3 is free (the dispatcher's `jmp16 a3` has already consumed it). HANDLER and EPILOGUE are
 * supplied by build_snake_patch.py via ld --defsym; the same source builds the render-path stub
 * (HANDLER = snake_category_entry) and the item-path stub (HANDLER = snake_screen_handler).
 */
    .text
    .global snake_tail_stub

snake_tail_stub:
    bsr     HANDLER
    lrw     r3, EPILOGUE
    jmp     r3
