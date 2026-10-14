/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: strcmp_byte_ordinal @ 0305f8cc (file base 0x03000000; code starts at 0x03001000)
 * Size: 80 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: runtime-lib
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Removing unreachable block (ram,0x0305f912) */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4 strcmp_byte_ordinal(byte *param_1,byte *param_2)

{
  undefined4 uVar1;
  byte bVar2;
  byte bVar3;
  
  bVar3 = *param_1;
  if (bVar3 == 0) {
LAB_0305f900:
    if (*param_2 == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = 0xffffffff;
    }
  }
  else {
    bVar2 = *param_2;
    if (bVar3 == bVar2) {
      do {
        param_1 = param_1 + 1;
        param_2 = param_2 + 1;
        bVar3 = *param_1;
        if (bVar3 == 0) goto LAB_0305f900;
        bVar2 = *param_2;
      } while (bVar3 == bVar2);
    }
    uVar1 = 0xffffffff;
    if (bVar2 < bVar3) {
      uVar1 = 1;
    }
  }
  return uVar1;
}

