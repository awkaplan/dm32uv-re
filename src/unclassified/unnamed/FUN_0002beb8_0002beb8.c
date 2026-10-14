/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: FUN_0002beb8 @ 0002beb8 (IRAM address; the boot stub copies these bytes from program flash 0x030dbad8)
 * Size: 200 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

int FUN_0002beb8(uint param_1,uint param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  if (*piRam0002bf8c == 1) {
    iVar2 = -1;
  }
  else if (param_3 == 0) {
    iVar2 = -1;
  }
  else if ((uint)piRam0002bf8c[4] < param_1) {
    iVar2 = -1;
  }
  else if (param_2 == 0) {
    iVar2 = -1;
  }
  else {
    iVar2 = func_0x0002bd9c(0xfffffff);
    func_0x0002bc38(0x14);
    piVar1 = piRam0002bf8c;
    while (iVar2 == 0) {
      iVar4 = piVar1[3];
      uVar3 = piVar1[1];
      iVar2 = func_0x0002bd9c(0xfffff);
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
      func_0x0002bca4(6,1,0,0);
      iVar2 = func_0x0002bca4(param_1 & 0xffffff | 0x2000000,4,uVar3,param_3);
      if (iVar2 != 0) {
        return iVar2;
      }
      param_2 = param_2 - uVar3;
      iVar2 = func_0x0002bd9c(0xfffffff);
      func_0x0002bc38(0x14);
      if (param_2 == 0) {
        return iVar2;
      }
      param_1 = param_1 + uVar3;
      param_3 = param_3 + uVar3;
    }
  }
  return iVar2;
}

