/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: timer_ch0_configure_periodic @ 0306cef4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 26 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rtos
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void timer_ch0_configure_periodic(undefined4 param_1,uint param_2)

{
  dword dVar1;
  
  TIMER_Type_14000000.CH[0].ControlReg = 2;
  TIMER_Type_14000000.CH[0].LoadCount = (uint)*PTR_DAT_0306cf30 / param_2;
  dVar1 = TIMER_Type_14000000.CH[0].ControlReg;
  TIMER_Type_14000000.CH[0].ControlReg = dVar1 | 1;
  return;
}

