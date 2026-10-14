/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: load_tag_string_0x52_and_set_len4 @ 03042090 (file base 0x03000000; code starts at 0x03001000)
 * Size: 30 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void load_tag_string_0x52_and_set_len4(void)

{
  memcpy_bytes_iram(_DAT_0304218c,DAT_03042190,4);
  *(undefined1 *)PTR_active_screen_subtype_0304216c = 4;
  *(undefined1 *)PTR_DAT_03042194 = 0x52;
  *(undefined1 *)PTR_DAT_03042198 = 0;
  return;
}

