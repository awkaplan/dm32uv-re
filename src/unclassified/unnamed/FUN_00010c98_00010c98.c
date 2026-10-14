/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: FUN_00010c98 @ 00010c98 (IRAM address; the boot stub copies these bytes from program flash 0x030c08b8)
 * Size: 52 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

void FUN_00010c98(int param_1,int param_2__w)

{
  undefined1 param_2 = (undefined1)param_2__w;
  int iVar1;
  int iVar2;
  short sVar3;
  
  *(undefined1 *)(param_1 + 0x37) = param_2;
  iVar1 = *(int *)(param_1 + 0x30);
  sVar3 = *(short *)(param_1 + 0x3e);
  if (sVar3 != 0) {
    while( true ) {
      if (1 < *(ushort *)(*(int *)(iVar1 + 0xc) + 0x10)) {
        iVar2 = *(int *)(iVar1 + 0xc) + 8;
        list_node_unlink_a(iVar2,iVar1);
        func_0x00010bb8(iVar2,iVar1);
      }
      sVar3 = sVar3 + -1;
      if (sVar3 == 0) break;
      iVar1 = iVar1 + 0x20;
    }
  }
  return;
}

