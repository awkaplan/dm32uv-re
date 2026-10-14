/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: codeplug_bitfield_unpack_3byte @ 030c518c (file base 0x03000000; code starts at 0x03001000)
 * Size: 444 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void codeplug_bitfield_unpack_3byte(uint *param_1,int param_2,byte param_3)

{
  byte bVar1;
  byte bVar2;
  uint *puVar3;
  
  if (param_3 < 5) {
    if (param_3 == 0) {
      *param_1 = *(byte *)(param_2 + 7) >> 4 & 1 |
                 (*(byte *)(param_2 + 7) & 1) * 2 |
                 (*(byte *)(param_2 + 8) & 1) << 3 | (int)(*(byte *)(param_2 + 8) & 0x10) >> 2;
      puVar3 = param_1 + 1;
      *puVar3 = (*(byte *)(param_2 + 0x10) & 1) * 2 |
                (*(byte *)(param_2 + 0x11) & 1) << 3 | (int)(*(byte *)(param_2 + 0x11) & 0x10) >> 2
                | *(byte *)(param_2 + 0x10) >> 4 & 1;
      bVar2 = *(byte *)(param_2 + 0x1a);
      bVar1 = *(byte *)(param_2 + 0x19);
      *param_1 = *param_1 << 4;
      *puVar3 = *puVar3 << 4;
      param_1[2] = (bVar1 >> 4 & 1 | (bVar1 & 1) * 2 | (int)(bVar2 & 0x10) >> 2 | (bVar2 & 1) << 3)
                   << 4;
      return;
    }
    *param_1 = *(byte *)(param_2 + 7) >> 4 & 1 |
               (*(byte *)(param_2 + 7) & 1) * 2 |
               (*(byte *)(param_2 + 8) & 1) << 3 | (int)(*(byte *)(param_2 + 8) & 0x10) >> 2 |
               *param_1;
    puVar3 = param_1 + 1;
    *puVar3 = *(byte *)(param_2 + 0x10) >> 4 & 1 |
              (int)(*(byte *)(param_2 + 0x11) & 0x10) >> 2 | (*(byte *)(param_2 + 0x11) & 1) << 3 |
              (*(byte *)(param_2 + 0x10) & 1) * 2 | *puVar3;
    bVar1 = *(byte *)(param_2 + 0x1a);
    bVar2 = *(byte *)(param_2 + 0x19);
    *param_1 = *param_1 << 4;
    *puVar3 = *puVar3 << 4;
    param_1[2] = (bVar2 >> 4 & 1 | (bVar2 & 1) * 2 | (int)(bVar1 & 0x10) >> 2 | (bVar1 & 1) << 3 |
                 param_1[2]) << 4;
  }
  else if (param_3 == 5) {
    *param_1 = *(byte *)(param_2 + 7) >> 4 & 1 |
               (*(byte *)(param_2 + 7) & 1) * 2 |
               (*(byte *)(param_2 + 8) & 1) << 3 | (int)(*(byte *)(param_2 + 8) & 0x10) >> 2 |
               *param_1;
    param_1[1] = *(byte *)(param_2 + 0x10) >> 4 & 1 |
                 (int)(*(byte *)(param_2 + 0x11) & 0x10) >> 2 | (*(byte *)(param_2 + 0x11) & 1) << 3
                 | (*(byte *)(param_2 + 0x10) & 1) * 2 | param_1[1];
    param_1[2] = *(byte *)(param_2 + 0x19) >> 4 & 1 |
                 (*(byte *)(param_2 + 0x19) & 1) * 2 |
                 (*(byte *)(param_2 + 0x1a) & 1) << 3 | (int)(*(byte *)(param_2 + 0x1a) & 0x10) >> 2
                 | param_1[2];
    return;
  }
  return;
}

