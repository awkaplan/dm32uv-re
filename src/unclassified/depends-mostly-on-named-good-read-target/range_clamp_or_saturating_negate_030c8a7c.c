/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: range_clamp_or_saturating_negate @ 030c8a7c (file base 0x03000000; code starts at 0x03001000)
 * Size: 126 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Control flow encountered bad instruction data */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

ushort range_clamp_or_saturating_negate
                 (ushort param_1,int param_2,ushort param_3,int param_4,undefined2 *param_5)

{
  int iVar1;
  
  if ((param_1 == 0) || (0x1f < param_4 - param_2)) {
    if (param_3 == 0) {
      *param_5 = 0;
      return 0;
    }
    *param_5 = (short)param_4;
    return param_3;
  }
  if ((param_3 != 0) && (param_2 - param_4 < 0x20)) {
    iVar1 = param_2;
    if (param_2 <= param_4) {
      iVar1 = param_4;
    }
    if ((int)((uint)param_3 << 0x10) >> ((iVar1 + 1) - param_4 & 0x3fU) !=
        (int)((uint)param_1 << 0x10) >> ((iVar1 + 1) - param_2 & 0x3fU)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    *param_5 = 0;
    return 0;
  }
  if (param_1 == 0x8000) {
    param_1 = 0x7fff;
    *param_5 = (short)param_2;
  }
  else {
    param_1 = -param_1;
    *param_5 = (short)param_2;
  }
  return param_1;
}

