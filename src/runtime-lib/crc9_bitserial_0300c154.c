/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: crc9_bitserial @ 0300c154 (file base 0x03000000; code starts at 0x03001000)
 * Size: 102 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: runtime-lib
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void crc9_bitserial(uint param_1,uint param_2,int param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  param_1 = param_1 & 0x1ff;
  if ((param_2 & 0xff) != 0) {
    uVar2 = 0;
    do {
      if ((uVar2 & 7) == 0) {
        param_4 = (uint)*(byte *)(param_3 + (uVar2 >> 3 & 0xff));
      }
      if (param_1 >> 8 == 0) {
        uVar1 = 0;
      }
      else {
        uVar1 = 0x58;
      }
      if ((param_4 << (uVar2 & 7) & 0x80) == 0) {
        uVar3 = 0;
      }
      else {
        uVar3 = 0x59;
      }
      param_1 = (param_1 * 2 & 0x1ff | param_1 >> 8) ^ uVar1 ^ uVar3;
      uVar2 = uVar2 + 1 & 0xffff;
    } while (uVar2 < (param_2 & 0xff));
  }
  return;
}

