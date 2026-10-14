/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: memset_with_word_alignment @ 0306ba88 (file base 0x03000000; code starts at 0x03001000)
 * Size: 116 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: runtime-lib
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void memset_with_word_alignment(undefined1 *param_1,undefined1 param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  
  if ((param_3 != 0) && (param_1 != (undefined1 *)0x0)) {
    uVar1 = (uint)param_1 & 3;
    if (uVar1 != 0) {
      for (; uVar1 < 4; uVar1 = uVar1 + 1) {
        *param_1 = param_2;
        param_1 = param_1 + 1;
        param_3 = param_3 - 1;
        if (param_3 == 0) {
          return;
        }
      }
    }
    if (3 < param_3) {
      iVar2 = 0;
      do {
        *(uint *)(param_1 + iVar2) = CONCAT31(CONCAT21(CONCAT11(param_2,param_2),param_2),param_2);
        iVar2 = iVar2 + 4;
      } while (3 < param_3 - iVar2);
      param_1 = param_1 + (param_3 - 4 & 0xfffffffc) + 4;
      param_3 = param_3 - 4 & 3;
    }
    if (param_3 != 0) {
      uVar1 = 0;
      do {
        param_1[uVar1] = param_2;
        uVar1 = uVar1 + 1;
      } while (param_3 != uVar1);
    }
  }
  return;
}

