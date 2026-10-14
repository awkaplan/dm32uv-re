/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: frequency_to_step_index_resolve @ 0301af74 (file base 0x03000000; code starts at 0x03001000)
 * Size: 134 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rf-frontend
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

char frequency_to_step_index_resolve(uint param_1,char param_2,char param_3)

{
  uint uVar1;
  byte bVar2;
  short sVar3;
  undefined1 auStack_20 [4];
  
  flash_block_id_resolve_locked(2);
  if (param_2 == '\x01') {
    sVar3 = 0x314;
    if (param_3 == '\0') {
      sVar3 = 0x300;
    }
  }
  else {
    sVar3 = 0x33c;
    if (param_3 == '\0') {
      sVar3 = 0x328;
    }
  }
  bVar2 = 0;
  do {
    flash_field_read_cached(2,sVar3,auStack_20,4);
    uVar1 = bcd_frequency_decode(auStack_20,4);
    if (param_1 <= uVar1) {
      if (bVar2 < 5) {
        if (bVar2 == 0) {
          bVar2 = 1;
        }
      }
      else {
        bVar2 = 4;
      }
      goto LAB_0301aff2;
    }
    bVar2 = bVar2 + 1;
    sVar3 = sVar3 + 4;
  } while (bVar2 != 5);
  bVar2 = 4;
LAB_0301aff2:
  return bVar2 - 1;
}

