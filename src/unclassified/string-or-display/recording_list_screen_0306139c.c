/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: recording_list_screen @ 0306139c (file base 0x03000000; code starts at 0x03001000)
 * Size: 298 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void recording_list_screen(int param_1,uint param_2,uint param_3)

{
  ushort block_id;
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined1 auStack_6c [11];
  undefined1 uStack_61;
  undefined1 uStack_5f;
  undefined1 uStack_5e;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined1 uStack_28;
  
  uStack_38 = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_58 = 0;
  uStack_54 = 0;
  uStack_50 = 0;
  uStack_4c = 0;
  uStack_48 = 0;
  uStack_44 = 0;
  uStack_40 = 0;
  uStack_3c = 0;
  if (param_3 != 0) {
    uVar1 = recording_count_scan();
    if ((p_dm32_settings_block04[0x30] & 0x40) == 0) {
      number_to_string_format_2args(&uStack_58,PTR_LAB_030614b8,param_2 + 1,uVar1);
    }
    else {
      number_to_string_format_2args(&uStack_58,PTR_s_Record__d__d_030614bc,param_2 + 1,uVar1);
    }
    display_fill_rect(0,0,0xf0,0x1b,0);
    display_draw_number_centered(1,0xffff,0,(uint)&uStack_58);
    if (uVar1 != 0) {
      uVar2 = (param_2 - param_1) + 1;
      uVar5 = 1;
      uVar3 = 0;
      do {
        uVar3 = uVar3 + 1;
        uVar4 = uVar2 + 1;
        if (uVar4 == uVar3) {
          block_id = recording_index_lookup(uVar4);
          flash_block_read(block_id,0,auStack_6c,0x14);
          number_to_string_format_2args
                    (&uStack_38,PTR_s__d__0_2d__0_2d__0_2d_030614c0,uVar4,uStack_61,uStack_5f,
                     uStack_5e);
          if (uVar2 == param_2) {
            display_draw_list_row(uVar5 & 0xffff,&uStack_38,1);
            display_blit_bitmap_1bpp_clipped(8,uVar5 & 0xffff,0x18,0x18,PTR_DAT_030614c4);
          }
          else {
            display_draw_list_row(uVar5 & 0xffff,&uStack_38,0);
            display_blit_bitmap_1bpp_clipped(8,uVar5 & 0xffff,0x18,0x18,PTR_LAB_030616ec);
          }
          if (param_3 <= uVar4) {
            return;
          }
          uVar5 = uVar5 + 1;
          uVar2 = uVar4;
          if (8 < uVar5) {
            return;
          }
        }
      } while (uVar3 < uVar1);
    }
  }
  return;
}

