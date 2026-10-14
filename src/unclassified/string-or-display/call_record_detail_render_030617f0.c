/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: call_record_detail_render @ 030617f0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 538 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void call_record_detail_render(void)

{
  ushort block_id;
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  byte local_40 [20];
  byte local_2c;
  byte bStack_2b;
  byte bStack_27;
  byte bStack_26;
  byte bStack_25;
  undefined1 uStack_21;
  undefined1 uStack_1f;
  undefined1 uStack_1e;
  undefined1 uStack_1d;
  undefined1 uStack_1c;
  undefined1 uStack_1b;
  ushort uStack_1a;
  
  memset_bytes(local_40,0,0x14);
  display_fill_screen(0);
  block_id = recording_index_lookup(*PTR_DAT_03061928 + 1);
  flash_block_read(block_id,0,&local_2c,0x14);
  if ((local_2c & 0xf0) == 0x10) {
    uVar2 = *(undefined4 *)(PTR_PTR_0306192c[(byte)p_dm32_settings_block04[0x30] >> 6 & 1] + 4);
    uVar1 = strlen_ck803s(uVar2);
    uVar1 = uVar1 & 0xff;
    memcpy_bytes_iram(local_40,uVar2,uVar1);
  }
  else {
    uVar2 = *(undefined4 *)PTR_PTR_0306192c[(byte)p_dm32_settings_block04[0x30] >> 6 & 1];
    uVar1 = strlen_ck803s(uVar2);
    uVar1 = uVar1 & 0xff;
    memcpy_bytes_iram(local_40,uVar2,uVar1);
  }
  if ((local_2c & 0xf) == 0) {
    uVar3 = *(undefined4 *)PTR_PTR_03061930[((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 2];
    uVar2 = strlen_ck803s(uVar3);
    memcpy_bytes_iram(local_40 + uVar1,uVar3,uVar2);
  }
  else {
    uVar3 = *(undefined4 *)
             (PTR_PTR_03061930[((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 2] + 4);
    uVar2 = strlen_ck803s(uVar3);
    memcpy_bytes_iram(local_40 + uVar1,uVar3,uVar2);
  }
  display_draw_string_gb2312(0x28,5,local_40,0xffff,0);
  if ((local_2c & 0xf0) == 0x10) {
    if (bStack_2b >> 4 == 1) {
      display_blit_bitmap_1bpp_clipped(5,2,0x18,0x18,PTR_LAB_03061934);
      uVar2 = 3;
    }
    else if (bStack_2b >> 4 == 2) {
      display_blit_bitmap_1bpp_clipped(5,2,0x18,0x18,PTR_LAB_03061af4);
      uVar2 = 4;
    }
    else {
      display_blit_bitmap_1bpp_clipped(5,2,0x18,0x18,PTR_LAB_03061af8);
      uVar2 = 5;
    }
    contact_name_lookup_or_format
              (1,(uint)bStack_25 << 0x10 | (uint)bStack_27 | (uint)bStack_26 << 8,local_40,uVar2);
    display_draw_string_gb2312(0x46,0x28,local_40,0xffff,0);
  }
  uVar5 = ((uint)uStack_1a * 100) / 1000;
  uVar1 = uVar5 / 0xe10;
  local_40[2] = (byte)uVar1;
  uVar5 = uVar5 % 0xe10;
  uVar4 = uVar5 / 0x3c;
  local_40[1] = (byte)uVar4;
  uVar5 = uVar5 % 0x3c;
  local_40[0] = (byte)uVar5;
  number_to_string_format_2args
            (local_40,PTR_s__0_2d__0_2d__0_2d__d_03061afc,uVar1,uVar4,uVar5,
             ((uint)uStack_1a * 100) % 1000);
  display_draw_string_gb2312(100,5,local_40,0xffff,0);
  number_to_string_format_2args
            (local_40,PTR_s_20_0_2d__0_2d__0_2d_03061b00,uStack_21,uStack_1f,uStack_1e);
  display_draw_string_gb2312(0x82,5,local_40,0xffff,0);
  number_to_string_format_2args
            (local_40,PTR_s__0_2d__0_2d__0_2d_03061b04,uStack_1d,uStack_1c,uStack_1b);
  display_draw_string_gb2312(0xa0,5,local_40,0xffff,0);
  return;
}

