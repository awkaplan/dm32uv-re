/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: ring_half_block_enqueue_post @ 0002e1d4 (IRAM address; the boot stub copies these bytes from program flash 0x030dddf4)
 * Size: 98 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void ring_half_block_enqueue_post(void)

{
  int iVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  undefined2 *puVar6;
  undefined1 auStack_c [4];
  
  mmio_110003b0_bit4_set();
  puVar2 = PTR_DAT_0002e2f8;
  iVar1 = *(short *)(PTR_DAT_0002e2f8 + 0x1894) * 2;
  puVar4 = *(undefined2 **)(PTR_DAT_0002e2fc + 4);
  puVar5 = (undefined2 *)(PTR_DAT_0002e2f8 + (*(short *)(PTR_DAT_0002e2f8 + 0x1894) + 0xbaa) * 2);
  puVar6 = (undefined2 *)(PTR_DAT_0002e2f8 + iVar1 + 0x17f4);
  do {
    *puVar5 = *puVar4;
    puVar5 = puVar5 + 1;
    puVar4 = puVar4 + 1;
  } while (puVar5 != puVar6);
  func_0x03021b4c(PTR_DAT_0002e300 + iVar1,0x50);
  puVar3 = PTR_DAT_0002e304;
  *(short *)(puVar2 + 0x1894) = (short)(*(short *)(puVar2 + 0x1894) + 0x50) % 0xa0;
  OSTaskSemPost(puVar3,0,auStack_c);
  return;
}

