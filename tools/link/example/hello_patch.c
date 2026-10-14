/*
 * hello_patch.c -- smallest proof that a DM-32UV patch is ordinary embedded C.
 *
 * No addresses appear in this file. The stock routine is called by NAME through a normal
 * prototype; tools/link/dm32_stock_symbols.ld (INCLUDEd by hello_patch.ld) supplies its address,
 * and tools/link/dm32_patch_memory.ld decides where this code and its state may live.
 *
 * This is a link demonstration, not a working patch: nothing hooks hello_entry into the stock
 * firmware (that is build_patch.py's / a hand-made splice's job, see tools/examples/snake/), and
 * it is never flashed. Build: `make -C tools link-example` (in the toolchain image).
 *
 * The prototype is declared here rather than taken from dm32_patch_api.h because that header
 * defines display_fill_rect as a cast-to-address MACRO, which would bypass the linker entirely.
 * Semantics per dm32_patch_api.h (CONFIRMED on hardware): RGB565 colour, x1/y1 EXCLUSIVE, takes
 * the LCD/keypad bus semaphore itself; colour is the 5th argument, so it travels on the stack
 * (C-SKY ABIv2: r0-r3, then stack), which a C call gets right automatically.
 */
typedef unsigned short u16;

void display_fill_rect(int x0, int y0, int x1, int y1, u16 color);

/* A RAM cell from dm32_patch_api.h, also resolved by the linker (the symbol IS the cell). */
extern volatile unsigned int KEYPAD_POLL_ENABLE;

/* Zero-initialised state -> .bss -> PATCH_SRAM. Nothing clears it at boot: the SRAM scratch
 * window has been observed to read zero after boot (docs/rtos-and-memory.md), but a real patch
 * should not rely on that for anything that matters. */
static unsigned int hello_calls;

#ifdef HELLO_OVERSIZE
/* Negative test: 128 KiB of constant data cannot fit any free flash region (largest is 88 KiB),
 * so the link must fail with "region `PATCH_FLASH_1' overflowed". */
const unsigned char hello_oversize_blob[0x20000] = { 1 };
#endif

__attribute__((section(".text.hello_entry")))
void hello_entry(void)
{
    display_fill_rect(0, 0, 10, 10, 0xF800);      /* 10x10 red square, top-left */
    hello_calls++;
    if (hello_calls > 3)
        KEYPAD_POLL_ENABLE = 1;
#ifdef HELLO_OVERSIZE
    hello_calls += hello_oversize_blob[hello_calls & 0x1ffff];
#endif
}
