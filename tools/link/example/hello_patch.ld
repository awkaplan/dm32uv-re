/*
 * hello_patch.ld -- linker script for tools/link/example/hello_patch.c, and the template for a
 * real patch: two INCLUDEs and three output sections. Run ld with `-L tools/link` so the
 * INCLUDEs resolve (see the link-example target in tools/Makefile).
 *
 * A real patch first claims its own range in data/allocations.json, regenerates the .ld files
 * (gen_link_artifacts.py), and places its sections in the PATCH_FLASH_<n>/PATCH_SRAM_<n> region
 * that claim produced. This example uses the PATCH_FLASH / PATCH_SRAM aliases (largest free
 * region of each) because it is never flashed.
 */
INCLUDE dm32_patch_memory.ld
INCLUDE dm32_stock_symbols.ld

ENTRY(hello_entry)

SECTIONS
{
    /* Entry point first, by name: GCC's emission order is not source order (snake_game.ld's
     * mode-126 freeze). Needs -ffunction-sections. KEEP survives --gc-sections. */
    .text : {
        KEEP(*(.text.hello_entry))
        *(.text .text.*)
        *(.rodata .rodata.*)
    } > PATCH_FLASH

    .bss (NOLOAD) : {
        *(.bss .bss.*)
        *(COMMON)
    } > PATCH_SRAM

    /* Nothing copies initialised RAM data from flash at boot, so a patch cannot have any. */
    .data : { *(.data .data.*) } > PATCH_SRAM
    ASSERT(SIZEOF(.data) == 0, "patch has initialised writable data (.data): nothing copies it to RAM; make it const or zero-initialised")
}
