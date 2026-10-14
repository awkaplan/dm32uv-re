/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: sysctl_0x384_bit8_toggle_with_companion_byte @ 0301ece8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 58 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void sysctl_0x384_bit8_toggle_with_companion_byte(int param_1__w)

{
  byte param_1 = (byte)param_1__w;
  dword dVar1;
  
  p_call_setup_sm_state->flags_0x18 = p_call_setup_sm_state->flags_0x18 & 0xf7 | (param_1 & 1) << 3;
  dVar1 = SystemControl_Type_11000000.LOCAL_CC;
  dVar1 = dVar1 & 0xfffffcff;
  if ((param_1 & 1) == 0) {
    PTR_DAT_0301ed64[7] = 0;
  }
  else {
    PTR_DAT_0301ed64[7] = 8;
    dVar1 = dVar1 | 0x100;
  }
  SystemControl_Type_11000000.LOCAL_CC = dVar1;
  return;
}

