/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: number_list_display_update @ 03058b18 (file base 0x03000000; code starts at 0x03001000)
 * Size: 340 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined4 number_list_display_update(uint param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  char cVar6;
  undefined1 auStack_34 [16];
  
  puVar1 = p_active_screen_flag_0003e5d5;
  param_1 = param_1 & 0xff;
  iVar3 = *(int *)(PTR_LAB_03058c70 + param_1 * 4);
  if (*(char *)(iVar3 + 4) == '\0') {
    display_draw_string_gb2312
              (0x3b,0x2c,
               (byte *)**(undefined4 **)
                         (PTR_PTR_03058ca0 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8),0,
               0xffff);
    uVar4 = 0;
  }
  else {
    if (1 < *(byte *)PTR_active_screen_visible_rows_03058c7c + 1) {
      cVar6 = (*(char *)p_active_screen_state_word + '\x01') -
              *(char *)p_active_screen_flag_0003e5d5;
      uVar5 = 1;
      do {
        cVar6 = cVar6 + '\x01';
        contact_name_lookup_by_offset_walk(param_1,cVar6,auStack_34);
        if (*(byte *)puVar1 == uVar5) {
          display_draw_list_row(uVar5,auStack_34,1);
          uVar2 = strlen_ck803s(auStack_34);
          memcpy_bytes_iram(PTR_DAT_03058c80,auStack_34,uVar2 & 0xff);
          PTR_DAT_03058c80[uVar2 & 0xff] = 0;
          display_blit_bitmap_1bpp_clipped(8,uVar5,0x18,0x18,PTR_DAT_03058c84[param_1 - 1]);
        }
        else {
          display_draw_list_row(uVar5,auStack_34,0);
          display_blit_bitmap_1bpp_clipped(8,uVar5,0x18,0x18,PTR_DAT_03058c88[param_1 - 1]);
        }
        uVar5 = uVar5 + 1 & 0xff;
      } while (uVar5 < *(byte *)PTR_active_screen_visible_rows_03058c7c + 1);
    }
    uVar4 = *(undefined4 *)
             (PTR_PTR_03058c98[((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 2] +
             (uint)*(byte *)((uint)p_menu_screen_state->index_0x2 + DAT_03058c94 + 2) * 4);
    uVar5 = strlen_ck803s(uVar4);
    memcpy_bytes_iram(auStack_34,uVar4,uVar5 & 0xff);
    number_to_string_format_2args
              (auStack_34 + (uVar5 & 0xff),PTR_s__d__d_030afcac_8_03058c9c,
               *(byte *)p_active_screen_state_word + 1,*(undefined1 *)(iVar3 + 4));
    display_fill_rect(0,0,0xf0,0x1b,0);
    display_draw_number_centered(1,0xffff,0,(uint)auStack_34);
    uVar4 = 1;
  }
  return uVar4;
}

