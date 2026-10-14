/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: search_table_u16_for_value @ 030311b4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 80 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

byte search_table_u16_for_value(char param_1,short param_2)

{
  byte bVar1;
  undefined *puVar2;
  byte bVar3;
  short local_1e;
  
  if (param_1 == '\x01') {
    bVar3 = 0x32;
    puVar2 = PTR_LAB_030312b8;
  }
  else {
    bVar3 = 0x69;
    puVar2 = PTR_LAB_030312b4;
  }
  bVar1 = 0;
  do {
    memcpy_bytes_iram(&local_1e,puVar2,2);
    if (local_1e == param_2) {
      return bVar1;
    }
    bVar1 = bVar1 + 1;
    puVar2 = puVar2 + 2;
  } while (bVar1 < bVar3);
  return 0;
}

