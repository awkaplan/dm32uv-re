/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: ccitt_crc4_stream_update @ 030c5038 (file base 0x03000000; code starts at 0x03001000)
 * Size: 94 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void ccitt_crc4_stream_update(uint param_1,uint param_2,int param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  param_1 = param_1 & 0xf;
  if ((param_2 & 0xff) != 0) {
    uVar3 = 0;
    do {
      uVar4 = 0;
      if (param_1 >> 3 != 0) {
        uVar4 = 2;
      }
      uVar2 = uVar3 & 7;
      uVar1 = uVar3 >> 3;
      uVar3 = uVar3 + 1 & 0xff;
      if (uVar2 == 0) {
        param_4 = (uint)*(byte *)(param_3 + uVar1);
      }
      if ((param_4 << uVar2 & 0x80) == 0) {
        uVar1 = 0;
      }
      else {
        uVar1 = 3;
      }
      param_1 = uVar1 ^ uVar4 ^ (param_1 * 2 & 0xf | param_1 >> 3);
    } while (uVar3 < (param_2 & 0xff));
  }
  return;
}

