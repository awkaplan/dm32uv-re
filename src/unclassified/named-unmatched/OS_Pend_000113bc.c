/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: OS_Pend @ 000113bc (IRAM address; the boot stub copies these bytes from program flash 0x030c0fdc)
 * Size: 78 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void OS_Pend(int param_1,int param_2,undefined1 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = *piRam00011568;
  *(undefined1 *)(iVar1 + 0x34) = param_3;
  *(undefined1 *)(iVar1 + 0x35) = 0;
  func_0x00011368(iVar1,param_4);
  if (param_2 == 0) {
    iVar1 = *piRam00011568;
    *(undefined2 *)(iVar1 + 0x3e) = 0;
    *(undefined4 *)(iVar1 + 0x30) = 0;
  }
  else {
    *(int *)(param_1 + 0xc) = param_2;
    func_0x00010ac4(*piRam00011568,param_1,1);
    func_0x00010bb8(param_2 + 8,param_1);
  }
  func_0x00010b34(param_2,*piRam00011568);
  return;
}

