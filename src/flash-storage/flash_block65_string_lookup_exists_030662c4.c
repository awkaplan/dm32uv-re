/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flash_block65_string_lookup_exists @ 030662c4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 82 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: flash-storage
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4 flash_block65_string_lookup_exists(undefined4 param_1)

{
  char cVar1;
  uint uVar2;
  short sVar3;
  uint uVar4;
  undefined1 auStack_34 [20];
  
  uVar2 = read_byte_field_03065e34();
  if (uVar2 != 0) {
    sVar3 = 0x10;
    uVar4 = 0;
    do {
      flash_field_read_cached(0x65,sVar3,auStack_34,0x10);
      cVar1 = strncmp_ck803s(param_1,auStack_34,0x10);
      if (cVar1 == '\0') {
        return 1;
      }
      uVar4 = uVar4 + 1 & 0xffff;
      sVar3 = sVar3 + 0x21;
    } while (uVar4 < uVar2);
  }
  return 0;
}

