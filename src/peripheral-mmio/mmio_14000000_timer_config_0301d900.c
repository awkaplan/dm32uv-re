/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: mmio_14000000_timer_config @ 0301d900 (file base 0x03000000; code starts at 0x03001000)
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

void mmio_14000000_timer_config(int param_1)

{
  dword dVar1;
  
  TIMER_Type_14000000.CH[1].CurrentValue = 0;
  TIMER_Type_14000000.CH[1].LoadCount = (uint)(param_1 * *PTR_DAT_0301d964) / 1000;
  dVar1 = TIMER_Type_14000000.CH[1].ControlReg;
  TIMER_Type_14000000.CH[1].ControlReg = dVar1 | 1;
  return;
}

