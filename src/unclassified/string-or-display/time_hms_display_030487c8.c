/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: time_hms_display @ 030487c8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 90 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void time_hms_display(void)

{
  undefined4 local_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined2 uStack_10;
  
  local_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  uStack_10 = 0;
  number_to_string_format_2args
            (&local_2c,PTR_s__0_2d__0_2d__0_2d_030488a8,
             *(char *)PTR_DAT_030488a4 * '\n' + *(char *)((int)PTR_DAT_030488a4 + 1),
             *(char *)((int)PTR_DAT_030488a4 + 2) * '\n' + *(char *)((int)PTR_DAT_030488a4 + 3),
             *(char *)(PTR_DAT_030488a4 + 1) * '\n' + *(char *)((int)PTR_DAT_030488a4 + 5));
  display_draw_number_centered(100,0,0x7e0,(uint)&local_2c);
  return;
}

