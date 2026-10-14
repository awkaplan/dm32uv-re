/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: freq_cal_interp_mode_select @ 0301b5a4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 78 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rf-frontend
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined1 freq_cal_interp_mode_select(undefined4 param_1)

{
  undefined1 uVar1;
  int iVar2;
  byte bStack_19;
  int iStack_18;
  
  if ((PTR_DAT_0301b6a0[3] & 0x10) == 0) {
    iVar2 = PTR_DAT_0301b6a4[6];
  }
  else {
    iVar2 = PTR_DAT_0301b6a4[4];
  }
  FUN_0301b558(param_1,&bStack_19,&iStack_18);
  uVar1 = linear_interpolate_freq_calibration
                    (param_1,iVar2 + (uint)bStack_19 * iStack_18,0,
                     iVar2 + iStack_18 * (bStack_19 + 1),0);
  return uVar1;
}

