/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: gpio_clear_bit0_if_flag_clear @ 03029420 (file base 0x03000000; code starts at 0x03001000)
 * Size: 30 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: peripheral-gpio
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void gpio_clear_bit0_if_flag_clear(void)

{
  undefined4 *puVar1;
  
  if (*(char *)PTR_DAT_030294bc == '\0') {
    gpio_clear_bit0_wrapper();
    puVar1 = PTR_DAT_030294bc;
    *(undefined1 *)((int)PTR_DAT_030294bc + 1) = 0;
    *(undefined1 *)(puVar1 + 1) = 0;
  }
  else {
    ui_mode_noop_stub_variant_0300c85c();
  }
  return;
}

