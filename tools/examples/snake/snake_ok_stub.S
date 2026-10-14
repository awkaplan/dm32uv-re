/*
 * snake_ok_stub.S - the 11th entry in the top menu's OK-dispatch jump table (0x030afef0).
 *
 * The ten stock entries are 6-byte stubs packed at 0x0303cdac + i*6:
 *     bsr   <per-category OK handler>     (4 bytes)
 *     br16  0x0303cde6                    (2 bytes, the shared epilogue all ten reach)
 * The dispatch is `ldr32.w a3,(a3,a2<<2)` then `jmp16 a3` -- a TAIL JUMP, so r15 still holds the
 * dispatching function's own return address and that epilogue is what unwinds it. This stub must
 * honour the same contract: run Snake's category handler, then transfer to the stock epilogue
 * rather than returning on its own.
 *
 * WHY NOT A LITERAL 6-BYTE COPY: this stub lives in free flash at ~0x030e9xxx, about 350 KB from
 * the epilogue. br16 reaches +/-1 KB and br32 +/-64 KB, so neither can encode the branch (the
 * build script's own range assertion caught this). An absolute `lrw` + `jmp` is used instead,
 * which is distance-independent. r3/a3 is free here: the dispatcher's `jmp16 a3` has already
 * consumed it, and the stock stubs' own `bsr` clobbers r15 the same way this does.
 *
 * SNAKE_CATENTRY and OK_EPILOGUE are supplied by build_snake_patch.py via ld --defsym, so the
 * addresses are written down in exactly one place.
 */
    .text
    .global snake_ok_stub

snake_ok_stub:
    bsr     SNAKE_CATENTRY          /* Snake's category OK handler (opens the sub-list) */
    lrw     r3, OK_EPILOGUE         /* absolute: too far for br16/br32 */
    jmp     r3                      /* tail-transfer into the stock shared epilogue */
