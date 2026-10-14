/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: FUN_00010b58 @ 00010b58 (IRAM address; the boot stub copies these bytes from program flash 0x030c0778)
 * Size: 90 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

void FUN_00010b58(undefined4 *param_1,int *param_2,undefined4 param_3,undefined4 *param_4)

{
  byte bVar1;
  int iVar2;
  int *piVar3;
  uint in_r12;
  undefined4 in_PSR;
  
  bVar1 = (byte)((uint)in_PSR >> 0x18);
  if ((bool)(bVar1 >> 7)) {
    if (!(bool)(bVar1 >> 7)) {
      param_4 = param_1;
    }
    param_2[0x31] = (int)param_4;
    return;
  }
  piVar3 = (int *)*param_1;
  if (piVar3 == (int *)0x0) {
LAB_00010c16:
    param_2[1] = 0;
    iVar2 = param_1[1];
    *param_2 = iVar2;
    *(int **)(iVar2 + 4) = param_2;
    param_1[1] = param_2;
  }
  else {
    bVar1 = *(byte *)(piVar3[2] + 0x37);
    while (bVar1 <= in_r12) {
      piVar3 = (int *)piVar3[1];
      if (piVar3 == (int *)0x0) goto LAB_00010c16;
      bVar1 = *(byte *)(piVar3[2] + 0x37);
    }
    iVar2 = *piVar3;
    if (iVar2 == 0) {
      *piVar3 = (int)param_2;
      *param_2 = 0;
      param_2[1] = (int)piVar3;
      *param_1 = param_2;
    }
    else {
      *param_2 = iVar2;
      param_2[1] = (int)piVar3;
      *(int **)(iVar2 + 4) = param_2;
      *piVar3 = (int)param_2;
    }
  }
  return;
}

