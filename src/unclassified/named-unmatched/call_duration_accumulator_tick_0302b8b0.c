/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: call_duration_accumulator_tick @ 0302b8b0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 110 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void call_duration_accumulator_tick(void)

{
  char cVar1;
  byte bVar2;
  
  if (((*(byte *)PTR_DAT_0302b9f0 & 0x40) == 0) &&
     (cVar1 = *(char *)PTR_DAT_0302b9f4, *(byte *)PTR_DAT_0302b9f4 = cVar1 + 1U,
     9 < (byte)(cVar1 + 1U))) {
    bVar2 = *(byte *)PTR_call_active_flag_0302b9f8;
    if ((((bVar2 & 8) != 0) || (((bVar2 & 4) != 0 && (PTR_DAT_0302b9fc[0xc] == '\0')))) ||
       (((bVar2 & 2) != 0 && ((*(byte *)PTR_DAT_0302ba00 & 1) != 0)))) {
      PTR_DAT_0302b9f4[0x30] = PTR_DAT_0302b9f4[0x30] + 1;
    }
    *(undefined1 *)PTR_DAT_0302b9f4 = 0;
    call_duration_post_flag_0x1000();
  }
  return;
}

