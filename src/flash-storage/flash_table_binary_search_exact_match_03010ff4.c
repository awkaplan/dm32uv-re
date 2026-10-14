/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flash_table_binary_search_exact_match @ 03010ff4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 86 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: flash-storage
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

uint flash_table_binary_search_exact_match(int param_1,uint param_2,uint param_3,byte param_4)

{
  byte bVar1;
  uint uVar2;
  
  param_2 = param_2 & 0xffff;
  param_3 = param_3 & 0xffff;
  if (param_2 <= param_3) {
    do {
      uVar2 = (int)(param_3 - param_2) / 2 + param_2 & 0xffff;
      bVar1 = *(byte *)(uVar2 * 3 + param_1);
      if (param_4 < bVar1) {
        param_3 = uVar2 - 1 & 0xffff;
      }
      else {
        if (param_4 <= bVar1) {
          return uVar2 * 3 & 0xffff;
        }
        param_2 = uVar2 + 1 & 0xffff;
      }
    } while (param_2 <= param_3);
  }
  return 0xffff;
}

