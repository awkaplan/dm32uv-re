/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: best_match_index_search_by_cost_metric @ 030c7d24 (file base 0x03000000; code starts at 0x03001000)
 * Size: 224 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

uint best_match_index_search_by_cost_metric(int *param_1,uint *param_2,int param_3__w,undefined4 param_4,int param_5__w,int param_6__w,uint param_7,uint param_8,int param_9__w)

{
  short param_3 = (short)param_3__w;
  short param_5 = (short)param_5__w;
  short param_6 = (short)param_6__w;
  short param_9 = (short)param_9__w;
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  short sVar6;
  int iVar7;
  int iVar8;
  uint uStack_30;
  
  iVar5 = (int)param_3;
  iVar7 = (int)param_6;
  iVar8 = (int)param_5;
  (*(code *)(param_7 & 0xfffffffe))(param_2,param_4,iVar8,iVar7,iVar5);
  uStack_30 = (*(code *)(param_8 & 0xfffffffe))((int)*param_2 >> ((int)param_9 & 0x3fU));
  if (param_9 != 0) {
    uVar3 = func_0x030c8614(uStack_30,(int)(short)(param_5 + -1));
    uStack_30 = uVar3 & 1 | uStack_30 * 2;
  }
  iVar1 = short_sample_vs_twolevel_pattern_sse_metric(uStack_30,param_4,iVar8,iVar7);
  if (((1 < iVar7) && (*param_2 != uStack_30)) && (1 < iVar5)) {
    sVar6 = 1;
    do {
      param_2 = param_2 + 1;
      uVar3 = (*(code *)(param_8 & 0xfffffffe))((int)*param_2 >> ((int)param_9 & 0x3fU));
      if (param_9 != 0) {
        uVar4 = FUN_030c8610(uVar3,(int)(short)(param_5 + -1));
        uVar3 = uVar3 * 2 | uVar4 & 1;
      }
      iVar2 = short_sample_vs_twolevel_pattern_sse_metric(uVar3,param_4,iVar8,iVar7);
      sVar6 = sVar6 + 1;
      if (iVar2 < iVar1) {
        iVar1 = iVar2;
        uStack_30 = uVar3;
      }
    } while (sVar6 < iVar5);
  }
  *param_1 = iVar1;
  return uStack_30;
}

