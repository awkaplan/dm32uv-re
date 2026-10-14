/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: list_cursor_increment_then_group_member_list_screen @ 03055e24 (file base 0x03000000; code starts at 0x03001000)
 * Size: 38 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-menu
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void list_cursor_increment_then_group_member_list_screen(undefined1 *param_1,undefined1 *param_2)

{
  undefined4 *puVar1;
  
  puVar1 = PTR_DAT_03055e4c;
  list_cursor_increment(param_1,param_2,*(char *)PTR_DAT_03055e4c + '\x01');
  group_member_list_screen(*param_1,*param_2,*(byte *)puVar1 + 1,*(undefined1 *)PTR_DAT_03055e64);
  return;
}

