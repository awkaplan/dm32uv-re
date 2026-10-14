/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flash_region_write_chunked @ 03003f60 (file base 0x03000000; code starts at 0x03001000)
 * Size: 200 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: flash-storage
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

int flash_region_write_chunked(uint param_1,uint param_2,int param_3)

{
  undefined1 *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  if (*PTR_LAB_03003ff4 == 0) {
    iVar2 = -1;
  }
  else if (param_3 == 0) {
    iVar2 = -1;
  }
  else if ((uint)PTR_LAB_03003ff4[4] < param_1) {
    iVar2 = -1;
  }
  else if (param_2 == 0) {
    iVar2 = -1;
  }
  else {
    iVar2 = modem_wait_ready_then_proceed(0xfffffff);
    FUN_03003cc4(0x14);
    puVar1 = PTR_LAB_030040d0;
    while (iVar2 == 0) {
      iVar4 = *(int *)(puVar1 + 0xc);
      uVar3 = *(uint *)(puVar1 + 4);
      iVar2 = modem_wait_ready_then_proceed(0xfffff);
      if (iVar2 != 0) {
        return iVar2;
      }
      if (param_2 <= uVar3) {
        uVar3 = param_2;
      }
      uVar5 = iVar4 - (iVar4 - 1U & param_1);
      if (uVar5 < uVar3) {
        uVar3 = uVar5;
      }
      FUN_03003d5c(6,1,0,0);
      iVar2 = FUN_03003d5c(param_1 & 0xffffff | 0x2000000,4,uVar3,param_3);
      if (iVar2 != 0) {
        return iVar2;
      }
      param_2 = param_2 - uVar3;
      iVar2 = modem_wait_ready_then_proceed(0xfffffff);
      FUN_03003cc4(0x14);
      if (param_2 == 0) {
        return iVar2;
      }
      param_1 = param_1 + uVar3;
      param_3 = param_3 + uVar3;
    }
  }
  return iVar2;
}

