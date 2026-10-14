/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: alpu_nonce_byte_next @ 00016b60 (IRAM address; the boot stub copies these bytes from program flash 0x030c6780)
 * Size: 110 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: alpu-anticlone
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

uint alpu_nonce_byte_next(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  
  iVar3 = func_0x0306fea4();
  iVar2 = iRam1100011c;
  iVar1 = iRam00016bd0;
  iVar7 = *(int *)(iRam00016bd0 + 0x20);
  iVar4 = bytes_to_u32_be();
  iVar5 = FUN_000172b0();
  uVar6 = iRam00016bd8 *
          (iVar2 + iVar7 + (uint)bRam16000233 +
           ((uint)bRam16000232 + ((uint)bRam16000032 * 0x100 + (uint)bRam16000033) * 0x100) * 0x100
           + iVar4 + iVar5 + iVar3) + 0x3039;
  *(uint *)(iVar1 + 0x20) = uVar6;
  return uVar6 >> 0x10 & 0xff;
}

