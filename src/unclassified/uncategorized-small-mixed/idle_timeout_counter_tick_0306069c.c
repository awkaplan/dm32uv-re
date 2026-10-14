/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: idle_timeout_counter_tick @ 0306069c (file base 0x03000000; code starts at 0x03001000)
 * Size: 98 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void idle_timeout_counter_tick(void)

{
  char cVar1;
  
  if ((*(byte *)PTR_DAT_03060850 & 0x20) == 0) {
    PTR_DAT_03060858[0x1c] = 0;
  }
  else if ((PTR_DAT_03060858[0x1d] & 4) == 0) {
    cVar1 = PTR_DAT_03060858[0x1c];
    PTR_DAT_03060858[0x1c] = cVar1 + 1U;
    if (0x1e < (byte)(cVar1 + 1U)) {
      *(byte *)PTR_DAT_03060850 = *(byte *)PTR_DAT_03060850 & 0xdf;
      menu_highlight_position_update(0);
    }
  }
  else {
    PTR_DAT_03060858[0x1c] = 0;
    *(undefined1 *)PTR_DAT_0306085c = 0;
  }
  write_byte_field_0300c3bc(*(byte *)PTR_DAT_03060850 >> 5 & 1);
  return;
}

