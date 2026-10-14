/* Memory layout for the Baofeng DM-32UV (HR_C7000 SoC, C-SKY CK803S core).
 *
 * GENERATED FILE - do not edit by hand.
 *
 * WHAT THIS IS FOR
 * ----------------
 * This script exists so the decompiled corpus can be COMPILED AND LINKED for the real target,
 * which is how a caller's expectations about a function are checked against the machine the code
 * actually runs on. It is NOT a script for producing a replacement firmware image, and linking
 * this corpus will not yield one - see build/README.md for exactly why not.
 *
 * REGION VALUES AND WHERE THEY COME FROM
 * --------------------------------------
 * FLASH/IRAM/SRAM bases and lengths are the vendor SoC documentation's memory map for this part,
 * independently corroborated by a shipped linker script for a different product built on the same
 * SoC. The DM-32UV's own image was separately confirmed to place its application region at
 * 0x03001000 (the 0x1000 header holds the boot magic), matching FLASH below.
 *
 * The program flash is 1 MB, mapped at 0x03000000..0x030FFFFF. The application region starts
 * 0x1000 into it, so its length is 0x100000 - 0x1000 = 0xFF000 and it ends at 0x030FFFFF. (A
 * length of 0x100000 from 0x03001000 would run 4 KB past the end of the part.)
 *
 *   FLASH 0x03001000 len 0x0FF000  - execute-in-place NOR flash, application region
 *   IRAM  0x00010000 len 0x048000  - 288KB on-chip instruction RAM; flash code calls into it
 *   SRAM  0x18000800 len 0x007800  - 30KB data SRAM; 0x18000000..0x180007FF is modem-owned
 *
 * The modem reservation at the bottom of SRAM is a real hardware constraint, not padding: that
 * window belongs to the DMR modem block, so the usable region starts at 0x18000800.
 */

ENTRY(_dm32_corpus_entry)

MEMORY
{
    FLASH (rx)  : ORIGIN = 0x03001000, LENGTH = 0x0FF000
    IRAM  (xrw) : ORIGIN = 0x00010000, LENGTH = 0x048000
    SRAM  (rw)  : ORIGIN = 0x18000800, LENGTH = 0x007800
}

SECTIONS
{
    .text : {
        . = ALIGN(4);
        __stext = .;
        *(.text .text.* .gnu.linkonce.t.*)
        . = ALIGN(4);
        __etext = .;
    } > FLASH

    .rodata : {
        . = ALIGN(4);
        *(.rodata .rodata.* .gnu.linkonce.r.*)
        . = ALIGN(4);
    } > FLASH

    .data : {
        . = ALIGN(4);
        __sdata = .;
        *(.data .data.* .sdata .sdata.*)
        . = ALIGN(4);
        __edata = .;
    } > SRAM

    .bss (NOLOAD) : {
        . = ALIGN(4);
        __sbss = .;
        *(.bss .bss.* .sbss .sbss.* COMMON)
        . = ALIGN(4);
        __ebss = .;
    } > IRAM

    /* Decompiled code references thousands of absolute addresses as `extern` globals. Nothing
     * defines them, so a full link cannot resolve them; see build/README.md. Discarding the
     * debug sections keeps per-object link probes readable. */
    /DISCARD/ : { *(.comment) *(.note.*) }
}
