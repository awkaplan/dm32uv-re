/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: FUN_00010ccc @ 00010ccc (IRAM address; the boot stub copies these bytes from program flash 0x030c08ec)
 * Size: 4 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

void FUN_00010ccc(void)

{
  int unaff_r4;
  int iVar1;
  short unaff_r6;
  uint unaff_r7;
  
  while( true ) {
    if (unaff_r7 < *(ushort *)(*(int *)(unaff_r4 + 0xc) + 0x10)) {
      iVar1 = *(int *)(unaff_r4 + 0xc) + 8;
      list_node_unlink_a(iVar1,unaff_r4);
      func_0x00010bb8(iVar1,unaff_r4);
    }
    unaff_r6 = unaff_r6 + -1;
    if (unaff_r6 == 0) break;
    unaff_r4 = unaff_r4 + 0x20;
  }
  return;
}

