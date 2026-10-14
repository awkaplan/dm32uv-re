/*
 * snake_menu_append_trampoline.S - splices a new top-level menu item (index 10, Snake's
 * category) onto the end of menu_option_gen_idx23's visibility-list construction.
 *
 * HOOK SITE: the unconditional `br 0x304a112` at 0x03049dcc, right after item 9's append
 * (`movi r2,9 ; str.b r2,(r5,r3<<0) ; addi r3,1 ; st.h r3,(r4,0)`). That `br` is a 16-bit
 * instruction; replaced with a 32-bit `bsr` here, then this trampoline appends item 10 the
 * same way and falls through to the SAME epilogue target (0x304a112) the original branch used.
 *
 * REGISTERS AT THE HOOK SITE (confirmed by reading the preceding real instructions, not
 * guessed): r4 = cursor pointer (*unaff_r4 in the decompiled C), r5 = list buffer base
 * (unaff_r5), r3 = current cursor value (just read via `ld.h r3,(r4,0)` two instructions
 * before the original branch). All three are still live and must be preserved exactly as the
 * stock append blocks use them, since this trampoline does the identical append idiom.
 */
    .text
    .global snake_menu_append

    .equ EPILOGUE, 0x0304a112

snake_menu_append:
    ld.h    r3, (r4, 0)      /* re-read the cursor -- same as every stock append block does */
    movi    r2, 10           /* Snake's new top-level item index */
    str.b   r2, (r5, r3 << 0)
    addi    r3, 1
    st.h    r3, (r4, 0)
    lrw     r3, EPILOGUE
    jmp     r3
