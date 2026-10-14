/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: calibration_table_interp_block2 @ 0301b5f4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 102 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined1 calibration_table_interp_block2(undefined4 param_1)

{
  undefined1 uVar1;
  int iVar2;
  byte bStack_21;
  int iStack_20;
  undefined1 uStack_1c;
  undefined1 uStack_1b;
  
  if ((PTR_DAT_0301b6a0[3] & 0x10) == 0) {
    iVar2 = PTR_DAT_0301b6a4[6];
  }
  else {
    iVar2 = PTR_DAT_0301b6a4[4];
  }
  FUN_0301b558(param_1,&bStack_21,&iStack_20);
  flash_field_read_cached(2,bStack_21 + 0x96,&uStack_1c,2);
  uVar1 = linear_interpolate_freq_calibration
                    (param_1,(uint)bStack_21 * iStack_20 + iVar2,uStack_1c,
                     iStack_20 * (bStack_21 + 1) + iVar2,uStack_1b);
  return uVar1;
}

