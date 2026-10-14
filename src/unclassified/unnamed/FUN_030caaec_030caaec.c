/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_030caaec @ 030caaec (file base 0x03000000; code starts at 0x03001000)
 * Size: 126 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Control flow encountered bad instruction data */

void FUN_030caaec(undefined4 param_1,int param_2,short param_3,undefined2 *param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = (int)param_3;
  if (iVar5 < 1) {
    FUN_030caa34(param_1,0,param_2,0,iVar5);
    *param_4 = *param_4;
    return;
  }
  iVar2 = 0;
  iVar4 = ((ushort)(param_3 - 1) + 1) * 4;
  uVar3 = 0;
  do {
    while (uVar1 = *(uint *)(param_2 + iVar2), uVar1 != 0x80000000) {
      if ((int)uVar1 < 0) {
        uVar1 = ~uVar1 + 1;
      }
      iVar2 = iVar2 + 4;
      if ((int)uVar3 < (int)uVar1) {
        uVar3 = uVar1;
      }
      if (iVar2 == iVar4) goto LAB_030cab36;
    }
    iVar2 = iVar2 + 4;
    uVar3 = 0x7fffffff;
  } while (iVar2 != iVar4);
LAB_030cab36:
  if (uVar3 == 0) {
    FUN_030caa34(param_1,0,param_2,0,iVar5);
    *param_4 = *param_4;
    return;
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

