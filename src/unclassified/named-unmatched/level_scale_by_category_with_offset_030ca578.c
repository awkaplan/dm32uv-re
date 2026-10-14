/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: level_scale_by_category_with_offset @ 030ca578 (file base 0x03000000; code starts at 0x03001000)
 * Size: 142 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Removing unreachable block (ram,0x030ca604) */
/* WARNING: Removing unreachable block (ram,0x030ca5fa) */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined4 level_scale_by_category_with_offset(short *param_1,short param_2,ushort param_3)

{
  short sVar1;
  ushort uVar2;
  
  sVar1 = classify_id_into_range_bucket((int)param_2);
  if (sVar1 == 0) {
    uVar2 = 0xffc4;
    if ((-0x3d < (short)param_3) && (uVar2 = param_3, 3 < (short)param_3)) {
      uVar2 = 3;
    }
    *param_1 = (short)((uint)uVar2 * 0x1542c00 + 0x6bca0000 >> 0x10);
    return 1;
  }
  if ((-1 < sVar1) && (sVar1 < 4)) {
    uVar2 = 0xffc4;
    if ((-0x3d < (short)param_3) && (uVar2 = param_3, 3 < (short)param_3)) {
      uVar2 = 3;
    }
    *param_1 = (short)((uint)uVar2 * 0x1542c00 + 0x6bca0000 >> 0x10) + -0x800;
    return 1;
  }
  *param_1 = 0;
  return 0;
}

