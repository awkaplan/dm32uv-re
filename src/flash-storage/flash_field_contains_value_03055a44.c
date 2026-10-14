/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flash_field_contains_value @ 03055a44 (file base 0x03000000; code starts at 0x03001000)
 * Size: 94 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: flash-storage
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4 flash_field_contains_value(ushort param_1,int param_2)

{
  short sVar1;
  short sVar2;
  int local_24;
  
  local_24 = 0;
  sVar2 = ((param_1 & 0xff) - 1) * 0x6d;
  sVar1 = sVar2 + 0x1c;
  while( true ) {
    flash_field_read_cached(0xf,sVar1,&local_24,3);
    if (0xfffcde < local_24 - 1U) {
      return 0;
    }
    if (local_24 == param_2) break;
    sVar1 = sVar1 + 3;
    if (sVar1 == (short)(sVar2 + 0x7c)) {
      return 0;
    }
  }
  return 1;
}

