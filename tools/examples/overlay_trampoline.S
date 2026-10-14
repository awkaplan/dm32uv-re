/*
 * overlay_trampoline.S - hook trampoline that draws an overlay banner over the running UI.
 *
 * HOOK SITE: display_draw_string_gb2312 @ 0x03018998. Its prologue is
 *     03018998:  d814   push  r4-r11, r15    <- NOT hooked (see below)
 *     0301899a:  3514   subi  r14, r14, 84   <- NOT hooked
 *     0301899c:  4b6d   mov   r5, r2         <- displaced (re-executed here)
 *     0301899e:  8175   zexth r6, r0         <- displaced (re-executed here)
 *     030189a0:  ...                          <- resume point (= r15 after our bsr)
 * The 4 bytes at 0x0301899c are replaced by one 32-bit `bsr` to this trampoline.
 *
 * WHY AFTER THE PROLOGUE, NOT AT THE ENTRY: a first attempt hooked the function's very first
 * instruction. That cannot work with `bsr`: at a function's entry the caller's return address
 * exists ONLY in r15 -- the `push ... r15` we would be displacing is what saves it -- and `bsr`
 * overwrites r15 before any trampoline code runs. The re-executed push then saved the
 * trampoline's return address instead of the caller's, and the function's epilogue "returned"
 * into its own body. (Under emulation this showed up as the boot stalling before the first
 * text draw.) Hooking AFTER the push means r15 is already safely on the stack; `bsr` may clobber
 * it freely and we simply `jmp r15` back to the resume point. This is also why the RAMDUMP
 * patch's mid-function `bsr` hook worked.
 *
 * WHY THIS FUNCTION: it is the text-drawing primitive the idle/standby screen actually calls
 * during boot (a `-d in_asm` trace shows display_update_datetime @0x0301b6a8, the more obvious
 * "redraw" hook, is never executed in the boot window). Hooking a primitive also means no
 * screen-mode ID has to be claimed -- see ../../docs/menu-system.md.
 *
 * RE-ENTRANCY: the overlay itself calls display_draw_string_gb2312, which re-enters this hook. A
 * guard word at SRAM 0x18007FE0 makes the nested call skip the overlay and run the function
 * normally. The guard is a MAGIC VALUE, not a zero/non-zero flag: take = store GUARD_MAGIC,
 * skip only while the word == GUARD_MAGIC, release = store 0. That makes it correct for ANY
 * initial contents of the word, which matters because nothing initialises it:
 *   - Provenance of the address: this trampoline's original comment recorded only
 *     "zero in sram.bin" -- i.e. zero in the zero-filled QEMU SRAM loader image, which proves
 *     nothing about a real radio. No live capture ever verified it as zero.
 *   - The one full live SRAM capture from a real radio (RAMDUMP
 *     2026-09-29; not shipped here, see ../../docs/live-ram-capture.md) shows 0x18004c00-0x18007fff as
 *     power-on noise (13,277 of 13,312 bytes non-zero), with 0x18007fe0 = 0x140b32b9. That is
 *     consistent with no stock code using the word, but it is NOT zero at boot.
 *   - The previous version skipped the overlay while the word was NON-ZERO and set it to 1, so on
 *     that radio it would most likely never have drawn the banner at all. With a magic value,
 *     noise only causes a skip if it happens to equal GUARD_MAGIC (~2^-32 for random bits), and
 *     the first completed overlay leaves the word at 0 regardless.
 * See ../../docs/patch-patterns.md (pattern 2; section 10 item 12) and ../../docs/rtos-and-memory.md.
 * If you place your own guard or state elsewhere, capture your own RAM to check the region is
 * unused (../../docs/live-ram-capture.md) -- and on hardware expect "unused" to look like
 * unchanging noise, not zeros, so never rely on a zero start value.
 * Residual limitation (unchanged from the old design): if the overlay is ever abandoned mid-draw
 * (fault, or a warm reset that preserves SRAM) the word stays == GUARD_MAGIC and the overlay
 * stays off until something stores 0 there.
 *
 * REGISTER SAFETY: r0-r3 are the hooked function's arguments and are still live (the displaced
 * `mov r5,r2` / `zexth r6,r0` read r2/r0; the body then reads r1 (`zexth r4,r1`) and r3
 * (`zexth r3,r3`), plus the 5th argument at its own (r14,0x78) once our frame is popped), and
 * the display primitives clobber them, so they are saved/restored around the overlay -- which is
 * also why the guard check may use r0 for GUARD_MAGIC and r3 for the loaded word: both are
 * restored at .Lskip on every path. r4-r11 are callee-saved (already pushed by the prologue,
 * every one of them is written before it is read in the body, and the primitives preserve them
 * per the ABI). r12 is a caller-saved temporary.
 */
    .text
    .global overlay_trampoline

    .equ GUARD,       0x18007FE0
    .equ GUARD_MAGIC, 0x4F564C59        /* "OVLY"; any value except 0 works */
    .equ FILL_RECT, 0x03017c50
    .equ DRAW_STR,  0x03018998

overlay_trampoline:
    subi    r14, r14, 24
    st.w    r15, (r14, 0)           /* = 0x030189a0, our resume point */
    st.w    r0,  (r14, 4)
    st.w    r1,  (r14, 8)
    st.w    r2,  (r14, 12)
    st.w    r3,  (r14, 16)

    /* --- re-entrancy guard: skip the overlay only if the word holds GUARD_MAGIC --- */
    /* (r0 and r3 are saved above and restored at .Lskip; arbitrary power-on contents != MAGIC
     *  just mean "not inside the overlay", see the header comment) */
    lrw     r12, GUARD
    lrw     r0, GUARD_MAGIC
    ld.w    r3, (r12, 0)
    cmpne   r3, r0
    bf      .Lskip                  /* word == MAGIC: we are already inside the overlay */
    st.w    r0, (r12, 0)            /* take the guard */

    /* --- overlay: display_fill_rect(30, 60, 210, 80, 0x001F) --- */
    /* 5th arg (color) on the stack per C-SKY ABIv2; args 1-4 in r0-r3. */
    subi    r14, r14, 8
    movi    r3, 0x1f                /* 0x001F = blue */
    st.w    r3, (r14, 0)
    movi    r0, 30
    movi    r1, 60
    movi    r2, 210
    movi    r3, 80
    lrw     r12, FILL_RECT
    jsr     r12
    addi    r14, r14, 8

    /* --- overlay: display_draw_string_gb2312(36, 64, "CLAUDE", 0, bg=0x001F) --- */
    /* FIVE args, not 3. Stock site 0x03012072 does `movi r3,0xC618 ; st.w r3,(r14,0)` (5th arg,
     * a colour, on the stack) then `movi r3,0` (4th arg) before the bsr, and the prologue spills
     * r3 (`zexth r3,r3 ; st.w r3,(r14,8)`). Leaving the stack slot unset made the routine read
     * this trampoline's saved r15 (0x030189a0) as the colour -- the brown band it painted was
     * exactly 0x89a0, the low half of that address. 32/40 literal stock sites pass r3 = 0. */
    subi    r14, r14, 8
    movi    r3, 0x1f                /* 5th arg: background colour = same blue as the banner */
    st.w    r3, (r14, 0)
    movi    r0, 36
    movi    r1, 64
    lrw     r2, ovl_msg
    movi    r3, 0
    lrw     r12, DRAW_STR
    jsr     r12
    addi    r14, r14, 8

    lrw     r12, GUARD
    movi    r3, 0
    st.w    r3, (r12, 0)            /* release the guard (0, i.e. anything but MAGIC) */

.Lskip:
    ld.w    r3,  (r14, 16)
    ld.w    r2,  (r14, 12)
    ld.w    r1,  (r14, 8)
    ld.w    r0,  (r14, 4)
    ld.w    r15, (r14, 0)
    addi    r14, r14, 24

    /* Re-execute the two displaced 16-bit instructions, copied byte-for-byte from the stock
     * image (build_overlay_image.py asserts these exact bytes are at the hook site). */
    .short  0x6d4b                  /* 0301899c: mov r5, r2 */
    .short  0x7581                  /* 0301899e: zexth r6, r0 */
    jmp     r15                     /* -> 0x030189a0 */

    .align 2
ovl_msg:
    .asciz  "CLAUDE"
