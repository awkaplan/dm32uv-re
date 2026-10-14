/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flag_byte_clear_and_gpio_reset @ 03029440 (file base 0x03000000; code starts at 0x03001000)
 * Size: 28 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void flag_byte_clear_and_gpio_reset(void)

{
  undefined4 *puVar1;
  
  puVar1 = PTR_DAT_030294bc;
  *(undefined1 *)PTR_DAT_030294bc = 0;
  *(undefined1 *)((int)puVar1 + 1) = 0;
  *(undefined1 *)((int)puVar1 + 2) = 0;
  *(undefined1 *)((int)puVar1 + 3) = 0;
  *(undefined1 *)(puVar1 + 1) = 0;
  gpio_clear_bit0_wrapper();
  set_flag_byte_03064328_call(PTR_gpio_clear_bit0_if_flag_clear_030294c0);
  return;
}

