/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: zone_list_cursor_increment @ 030565c4 (file base 0x03000000; code starts at 0x03001000)
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

void zone_list_cursor_increment(undefined1 *param_1,undefined1 *param_2)

{
  char cVar1;
  
  cVar1 = get_zone_count();
  cVar1 = cVar1 + '\x01';
  if (cVar1 != '\x01') {
    list_cursor_increment(param_1,param_2,cVar1);
    zone_list_screen(*param_1,*param_2,cVar1);
  }
  return;
}

