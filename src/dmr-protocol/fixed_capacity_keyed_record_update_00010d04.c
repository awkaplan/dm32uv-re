/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: fixed_capacity_keyed_record_update @ 00010d04 (IRAM address; the boot stub copies these bytes from program flash 0x030c0924)
 * Size: 64 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: dmr-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void fixed_capacity_keyed_record_update
               (int param_1,int param_2,undefined4 param_3,undefined2 param_4,undefined4 param_5)

{
  int iVar1;
  short sVar2;
  int iVar3;
  
  sVar2 = *(short *)(param_2 + 0x3e);
  if (sVar2 != 0) {
    iVar3 = *(int *)(*(int *)(param_2 + 0x30) + 0xc);
    iVar1 = *(int *)(param_2 + 0x30);
    while (iVar3 != param_1) {
      sVar2 = sVar2 + -1;
      if (sVar2 == 0) {
        return;
      }
      iVar3 = *(int *)(iVar1 + 0x2c);
      iVar1 = iVar1 + 0x20;
    }
    *(int *)(iVar1 + 0x10) = param_1;
    *(undefined4 *)(iVar1 + 0x14) = param_3;
    *(undefined2 *)(iVar1 + 0x18) = param_4;
    *(undefined4 *)(iVar1 + 0x1c) = param_5;
  }
  return;
}

