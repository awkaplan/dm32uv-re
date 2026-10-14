/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flash_field_scan_until_invalid_or_32 @ 030559f8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 76 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: flash-storage
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

char flash_field_scan_until_invalid_or_32(ushort param_1)

{
  char cVar1;
  short sVar2;
  int local_20;
  
  cVar1 = '\0';
  local_20 = 0;
  sVar2 = ((param_1 & 0xff) - 1) * 0x6d + 0x1c;
  do {
    flash_field_read_cached(0xf,sVar2,&local_20,3);
    if (0xfffcde < local_20 - 1U) {
      return cVar1;
    }
    cVar1 = cVar1 + '\x01';
    sVar2 = sVar2 + 3;
  } while (cVar1 != ' ');
  return ' ';
}

