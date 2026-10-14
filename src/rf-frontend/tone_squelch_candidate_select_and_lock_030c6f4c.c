/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: tone_squelch_candidate_select_and_lock @ 030c6f4c (file base 0x03000000; code starts at 0x03001000)
 * Size: 258 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rf-frontend
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void tone_squelch_candidate_select_and_lock
               (int param_1,undefined4 param_2,short param_3,uint param_4,short param_5,
               short param_6)

{
  short sVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined2 uStack_28;
  undefined2 uStack_26;
  
  if ((param_4 & 0x1000) == 0) {
    iVar3 = param_1 + param_5 * 4;
    *(undefined2 *)(iVar3 + 0xe) = 0;
    *(undefined2 *)(param_1 + (param_5 + 4) * 2 + 2) = 0xff;
    *(undefined2 *)(iVar3 + 0x10) = 0;
    return;
  }
  iVar3 = (int)param_5;
  iVar5 = param_1 + (iVar3 + 3) * 4;
  iVar4 = param_1 + iVar3 * 4;
  uStack_28 = *(undefined2 *)(iVar5 + 2);
  uStack_26 = *(undefined2 *)(iVar4 + 0x10);
  sVar2 = tone_squelch_code_match_search(&uStack_28,param_2,(int)param_3,0,param_1,(int)param_6);
  if (sVar2 == 0xff) {
    sVar2 = *(short *)(param_1 + 8);
    if (sVar2 < 0x80) {
      if (((sVar2 == 0x13) || (sVar2 == 0x3a)) && (sVar1 = *(short *)(param_1 + 6), 0 < sVar1)) {
        *(short *)(param_1 + (iVar3 + 4) * 2 + 2) = sVar2;
        *(short *)(param_1 + 6) = sVar1 + -1;
        *(short *)(param_1 + 8) = sVar2;
        return;
      }
    }
    else {
      sVar1 = *(short *)(param_1 + 6);
      if (0 < sVar1) {
        *(undefined2 *)(iVar5 + 2) = 0xb001;
        *(short *)(param_1 + (iVar3 + 4) * 2 + 2) = sVar2;
        *(short *)(param_1 + 6) = sVar1 + -1;
        *(undefined2 *)(iVar4 + 0x10) = 0xb001;
        *(short *)(param_1 + 8) = sVar2;
        return;
      }
    }
    *(undefined2 *)(param_1 + (iVar3 + 3) * 4 + 2) = 0;
    *(undefined2 *)(param_1 + (iVar3 + 4) * 2 + 2) = 0xff;
    *(undefined2 *)(iVar3 * 4 + param_1 + 0x10) = 0;
    *(undefined2 *)(param_1 + 8) = 0xff;
  }
  else {
    *(undefined2 *)(iVar5 + 2) = uStack_28;
    *(undefined2 *)(iVar4 + 0x10) = uStack_26;
    *(short *)(param_1 + (iVar3 + 4) * 2 + 2) = sVar2;
    *(undefined2 *)(param_1 + 6) = 2;
    *(short *)(param_1 + 8) = sVar2;
  }
  return;
}

