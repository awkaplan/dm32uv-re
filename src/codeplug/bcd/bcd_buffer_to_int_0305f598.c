/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: bcd_buffer_to_int @ 0305f598 (file base 0x03000000; code starts at 0x03001000)
 * Size: 54 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

int bcd_buffer_to_int(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  
  if ((param_2 & 0xff) == 0) {
    iVar1 = 0;
  }
  else {
    uVar2 = 0;
    iVar1 = 0;
    do {
      iVar1 = (iVar1 * 10 + (uint)(*(byte *)(param_1 + uVar2) >> 4)) * 10 +
              (*(byte *)(param_1 + uVar2) & 0xf);
      uVar2 = uVar2 + 1;
    } while ((uVar2 & 0xff) < (param_2 & 0xff));
  }
  return iVar1;
}

