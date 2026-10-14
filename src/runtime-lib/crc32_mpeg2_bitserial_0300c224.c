/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: crc32_mpeg2_bitserial @ 0300c224 (file base 0x03000000; code starts at 0x03001000)
 * Size: 92 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: runtime-lib
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void crc32_mpeg2_bitserial(uint param_1,uint param_2,int param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  if ((param_2 & 0xffff) != 0) {
    uVar2 = 0;
    do {
      if ((uVar2 & 7) == 0) {
        param_4 = (uint)*(byte *)(param_3 + (uVar2 >> 3 & 0xff));
      }
      uVar1 = DAT_0300c2bc;
      if (-((int)param_1 >> 0x1f) == 0) {
        uVar1 = 0;
      }
      uVar3 = DAT_0300c2c0;
      if ((param_4 << (uVar2 & 7) & 0x80) == 0) {
        uVar3 = 0;
      }
      param_1 = (param_1 * 2 | -((int)param_1 >> 0x1f)) ^ uVar1 ^ uVar3;
      uVar2 = uVar2 + 1;
    } while (uVar2 < (param_2 & 0xffff));
  }
  return;
}

