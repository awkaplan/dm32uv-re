/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: scan_list_cursor_next_if_present @ 03055e90 (file base 0x03000000; code starts at 0x03001000)
 * Size: 40 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void scan_list_cursor_next_if_present(undefined1 *param_1,undefined1 *param_2)

{
  if (*(char *)PTR_DAT_03056020 != '\0') {
    list_cursor_increment(param_1,param_2,*(char *)PTR_DAT_03056020 + '\x02');
    scan_list_screen_with_add(*param_1,*param_2,*(byte *)PTR_DAT_03056020 + 2);
  }
  return;
}

