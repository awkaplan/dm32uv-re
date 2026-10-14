/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: tone_squelch_detection_frame_dispatch @ 030c6a24 (file base 0x03000000; code starts at 0x03001000)
 * Size: 308 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rf-frontend
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void tone_squelch_detection_frame_dispatch
               (int param_1,undefined4 param_2,int param_3,ushort param_4,short param_5)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 auStack_22c [516];
  undefined4 uStack_28;
  
  uStack_28 = 0;
  iVar4 = param_1 + 0x13a4;
  array_copy_u16(iVar4,param_1 + (param_3 + 0x9d2) * 2,-param_3 + 0x17f);
  iVar2 = -param_3 + 0xb51;
  if (((int)(short)param_4 & 0x100U) == 0) {
    FUN_030c87ec(param_1,param_1 + iVar2 * 2,param_2,param_3);
  }
  else {
    array_copy_u16(param_1 + iVar2 * 2,param_2,param_3);
  }
  array_copy_u16(param_1 + 0x420,param_1 + 0x21c,0x102);
  iVar2 = param_1 + 0x18;
  *(undefined2 *)(param_1 + 0x628) = *(undefined2 *)(param_1 + 0x626);
  array_copy_u16(param_1 + 0x21c,iVar2,0x102);
  *(undefined2 *)(param_1 + 0x626) = *(undefined2 *)(param_1 + 0x624);
  uVar1 = fixed_point_windowed_correlation_or_convolution
                    (iVar2,param_1 + 0x13dc,_DAT_030c6b58,0xfffffff9,199,0,auStack_22c,8,1);
  iVar3 = (int)param_5;
  *(undefined2 *)(param_1 + 0x624) = uVar1;
  tone_squelch_detection_frame_process
            (param_1 + 0xb50,iVar2,iVar3,iVar4,param_3,param_1 + 0x938,param_4 & 0x80,&uStack_28,
             param_1 + 0x16b8);
  tone_squelch_state_history_update
            (iVar2,iVar3,iVar4,auStack_22c,param_3,param_1 + 0x938,(int)(short)uStack_28);
  tone_squelch_candidate_select_and_lock
            (param_1 + 0x1370,iVar2,(int)*(short *)(param_1 + 0x624),(int)(short)param_4,iVar3,
             (int)*(short *)(param_1 + 0xab8));
  return;
}

