/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: datetime_display_gb2312 @ 03058d78 (file base 0x03000000; code starts at 0x03001000)
 * Size: 190 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void datetime_display_gb2312(char param_1,undefined1 param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined1 local_2c [2];
  undefined1 uStack_2a;
  undefined1 uStack_29;
  undefined1 uStack_28;
  undefined1 uStack_27;
  undefined1 uStack_26;
  ushort uStack_25;
  byte local_20;
  undefined1 uStack_1f;
  undefined1 uStack_1e;
  
  flash_record_read_with_block_skip(param_1,param_2,local_2c);
  number_to_string_format_2args
            (&local_20,PTR_s_20_0_2d__0_2d__0_2d_03058e3c,local_2c[0],uStack_2a,uStack_29);
  display_draw_string_gb2312(0x82,5,&local_20,0xffff,0);
  number_to_string_format_2args
            (&local_20,PTR_s__0_2d__0_2d__0_2d_03058e40,uStack_28,uStack_27,uStack_26);
  display_draw_string_gb2312(0xa0,5,&local_20,0xffff,0);
  if (param_1 != '\x01') {
    uVar2 = ((uint)uStack_25 * 1000) / 1000 & 0xffff;
    uVar1 = uVar2 / 0xe10;
    uStack_1e = (undefined1)uVar1;
    uVar2 = uVar2 % 0xe10;
    uVar3 = uVar2 / 0x3c;
    uStack_1f = (undefined1)uVar3;
    uVar2 = uVar2 % 0x3c;
    local_20 = (byte)uVar2;
    number_to_string_format_2args(&local_20,PTR_s__0_2d__0_2d__0_2d_03058e40,uVar1,uVar3,uVar2);
    display_draw_string_gb2312(100,5,&local_20,0xffff,0);
  }
  return;
}

