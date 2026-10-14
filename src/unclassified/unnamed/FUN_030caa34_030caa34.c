/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_030caa34 @ 030caa34 (file base 0x03000000; code starts at 0x03001000)
 * Size: 140 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Control flow encountered bad instruction data */

void FUN_030caa34(int param_1,short param_2,int *param_3,short param_4,ushort param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined2 uVar5;
  uint uVar6;
  
  if (0 < (short)param_5) {
    iVar2 = 0;
    iVar1 = ((param_5 - 1 & 0xffff) + 1) * 2;
    do {
      while (iVar3 = *param_3, iVar3 != 0) {
        if (-1 < (short)(param_4 - param_2)) {
          if (-1 < iVar3) {
                    /* WARNING: Bad instruction - Truncating control flow here */
            halt_baddata();
          }
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        }
        uVar4 = iVar3 >> ((int)(short)-(param_4 - param_2) & 0x3fU);
        uVar6 = uVar4 + 0x8000;
        if (-1 < (int)(uVar6 & ~uVar4)) goto LAB_030caa96;
        if ((uVar4 & 0x80000000) == 0) {
          uVar5 = 0x7fff;
        }
        else {
          uVar5 = 0x8000;
        }
        *(undefined2 *)(param_1 + iVar2) = uVar5;
        iVar2 = iVar2 + 2;
        param_3 = param_3 + 1;
        if (iVar2 == iVar1) {
          return;
        }
      }
      uVar6 = 0;
LAB_030caa96:
      *(short *)(param_1 + iVar2) = (short)(uVar6 >> 0x10);
      iVar2 = iVar2 + 2;
      param_3 = param_3 + 1;
    } while (iVar2 != iVar1);
  }
  return;
}

