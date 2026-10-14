/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: FUN_00013a84 @ 00013a84 (IRAM address; the boot stub copies these bytes from program flash 0x030c36a4)
 * Size: 28 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

void FUN_00013a84(void)

{
  ushort uVar1;
  undefined2 *puVar2;
  ushort uVar3;
  
  uVar1 = *puRam00013bb8;
  if (uVar1 != 0) {
    uVar3 = 0;
    puVar2 = (undefined2 *)PTR_DAT_00013bbc;
    do {
      *puVar2 = 0;
      uVar3 = uVar3 + 1;
      puVar2 = puVar2 + 4;
    } while (uVar3 < uVar1);
  }
  return;
}

