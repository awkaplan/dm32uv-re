/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: count_table_entries_sharing_bit @ 03023d60 (file base 0x03000000; code starts at 0x03001000)
 * Size: 28 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: runtime-lib
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

char count_table_entries_sharing_bit(byte param_1)

{
  char cVar1;
  byte *pbVar2;
  
  cVar1 = '\0';
  pbVar2 = PTR_DAT_03023e5c;
  do {
    if ((*pbVar2 & param_1) != 0) {
      cVar1 = cVar1 + '\x01';
    }
    pbVar2 = pbVar2 + 1;
  } while (pbVar2 != PTR_DAT_03023e5c + 8);
  return cVar1;
}

