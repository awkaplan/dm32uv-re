/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: softdouble_to_int32 @ 0306f3a4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 132 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

uint softdouble_to_int32(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint local_24;
  int iStack_20;
  int iStack_1c;
  uint uStack_18;
  uint uStack_14;
  undefined4 local_10;
  undefined4 uStack_c;
  
  local_10 = param_1;
  uStack_c = param_2;
  soft_double_unpack(&local_10,&local_24);
  if ((local_24 == 2) || (local_24 < 2)) {
    return 0;
  }
  if (local_24 != 4) {
    if (iStack_1c < 0) {
      return 0;
    }
    if (iStack_1c < 0x1f) {
      uVar3 = -iStack_1c + 0x3c;
      uVar1 = -iStack_1c + 0x1c;
      uVar2 = uStack_14 >> (uVar1 & 0x3f);
      if ((uVar1 & 0x80000000) != 0) {
        uVar2 = uStack_18 >> (uVar3 & 0x3f) | (uStack_14 << 1) << (0x1f - uVar3 & 0x3f);
      }
      if (iStack_20 == 0) {
        return uVar2;
      }
      return -uVar2;
    }
  }
  uVar2 = 0x80000000;
  if (iStack_20 == 0) {
    uVar2 = 0x7fffffff;
  }
  return uVar2;
}

