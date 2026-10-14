/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: saturating_sub_or_full_and_stamp_0x27d8 @ 0306c12c (file base 0x03000000; code starts at 0x03001000)
 * Size: 48 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void saturating_sub_or_full_and_stamp_0x27d8(void)

{
  uint uVar1;
  undefined4 *unaff_r4;
  uint unaff_r6;
  uint *unaff_r11;
  undefined4 in_stack_00000004;
  
  cpu_sr_restore_irq_iram(in_stack_00000004);
  uVar1 = padded_block_total_size_with_overflow_guard();
  if (unaff_r6 < uVar1) {
    *unaff_r11 = uVar1 - unaff_r6;
  }
  else {
    *unaff_r11 = uVar1;
  }
  *unaff_r4 = 0x27d8;
  return;
}

