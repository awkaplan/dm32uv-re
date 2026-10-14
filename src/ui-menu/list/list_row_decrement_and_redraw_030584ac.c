/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: list_row_decrement_and_redraw @ 030584ac (file base 0x03000000; code starts at 0x03001000)
 * Size: 34 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-menu
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void list_row_decrement_and_redraw(undefined1 *param_1,undefined1 *param_2)

{
  undefined4 *puVar1;
  
  puVar1 = PTR_DAT_03058514;
  list_cursor_decrement(param_1,param_2,*(char *)PTR_DAT_03058514 + '\x01');
  list_row_draw_variant1(*param_1,*param_2,*(char *)puVar1 + '\x01');
  return;
}

