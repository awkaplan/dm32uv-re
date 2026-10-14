/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: ring_half_block_dequeue_fallback_post @ 0002e238 (IRAM address; the boot stub copies these bytes from program flash 0x030dde58)
 * Size: 190 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void ring_half_block_dequeue_fallback_post(void)

{
  short *psVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  undefined2 *puVar5;
  int iVar6;
  undefined2 auStack_b0 [80];
  undefined1 auStack_10 [4];
  
  mmio_110003b0_bit5_set();
  puVar2 = PTR_DAT_0002e308;
  if (PTR_DAT_0002e308[0x1150] != '\0') {
    if (*(short *)(PTR_DAT_0002e308 + 0x1352) < 1) {
      func_0x030703bc(auStack_b0,PTR_DAT_0002e308 + 0x12ae,0xa0);
      func_0x03021b50(auStack_b0,0x50);
      iVar6 = *(int *)PTR_DAT_0002e2fc;
      iVar4 = 0;
      do {
        *(undefined2 *)(iVar6 + iVar4) = *(undefined2 *)((int)auStack_b0 + iVar4);
        iVar4 = iVar4 + 2;
      } while (iVar4 != 0xa0);
    }
    else {
      func_0x03021b50(PTR_DAT_0002e308 + *(short *)(PTR_DAT_0002e308 + 0x1350) * 2 + 0x116e,0x50);
      puVar5 = *(undefined2 **)PTR_DAT_0002e2fc;
      iVar6 = 0;
      do {
        iVar4 = iVar6 + *(short *)(puVar2 + 0x1350);
        iVar6 = iVar6 + 1;
        *puVar5 = *(undefined2 *)(puVar2 + (iVar4 + 0x8b6) * 2 + 2);
        puVar3 = PTR_DAT_0002e308;
        puVar5 = puVar5 + 1;
      } while (iVar6 != 0x50);
      psVar1 = (short *)(PTR_DAT_0002e308 + 0x1352);
      *(short *)(PTR_DAT_0002e308 + 0x1350) =
           (short)(*(short *)(PTR_DAT_0002e308 + 0x1350) + 0x50) % 0xa0;
      *(short *)(puVar3 + 0x1352) = *psVar1 + -0x50;
    }
    OSTaskSemPost(PTR_DAT_0002e30c,0,auStack_10);
  }
  return;
}

