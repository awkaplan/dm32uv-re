/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: mmio_11000074_bits_7_8_set_clear @ 0301e578 (file base 0x03000000; code starts at 0x03001000)
 * Size: 32 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: peripheral-mmio
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void mmio_11000074_bits_7_8_set_clear(int param_1)

{
  dword dVar1;
  
  if (param_1 == 0) {
    dVar1 = SystemControl_Type_11000000.ADC_CONTROL;
    SystemControl_Type_11000000.ADC_CONTROL = dVar1 & 0xfffffe7f;
  }
  else {
    dVar1 = SystemControl_Type_11000000.ADC_CONTROL;
    SystemControl_Type_11000000.ADC_CONTROL = dVar1 | 0x180;
  }
  return;
}

