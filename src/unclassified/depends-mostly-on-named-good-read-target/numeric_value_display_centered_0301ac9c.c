/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: numeric_value_display_centered @ 0301ac9c (file base 0x03000000; code starts at 0x03001000)
 * Size: 100 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void numeric_value_display_centered
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  byte abStack_34 [20];
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_c = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  number_to_string_format(abStack_34,param_1,&uStack_c);
  uVar1 = strlen_ck803s(abStack_34);
  display_fill_rect(0x14,0x82,0xdc,0x9a,0x7e0);
  display_draw_string_gb2312
            (0x82,(ushort)((int)((uVar1 & 0xff) * -0xc + 0xf0) >> 1),abStack_34,0,0x7e0);
  return;
}

