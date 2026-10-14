/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: delta_encode_adjacent_xor @ 03024138 (file base 0x03000000; code starts at 0x03001000)
 * Size: 54 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: runtime-lib
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void delta_encode_adjacent_xor(byte *param_1,int param_2,int param_3__w)

{
  byte param_3 = (byte)param_3__w;
  byte *pbVar1;
  byte *pbVar2;
  
  memcpy_bytes_iram(param_2,param_1,4);
  if (4 < param_3) {
    pbVar2 = (byte *)(param_2 + 4);
    pbVar1 = param_1 + (byte)(param_3 - 5) + 1;
    do {
      *pbVar2 = *param_1 ^ param_1[1];
      param_1 = param_1 + 1;
      pbVar2 = pbVar2 + 1;
    } while (param_1 != pbVar1);
  }
  return;
}

