/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: list_row_draw_variant1 @ 03058360 (file base 0x03000000; code starts at 0x03001000)
 * Size: 330 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void list_row_draw_variant1(uint param_1,uint param_2,uint param_3)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 local_38;
  uint uStack_34;
  undefined4 uStack_30;
  uint uStack_2c;
  undefined1 uStack_28;
  
  param_2 = param_2 & 0xff;
  param_3 = param_3 & 0xff;
  local_38 = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  if (param_3 != 0) {
    uVar3 = (param_2 - (param_1 & 0xff)) + 1 & 0xff;
    iVar4 = 0x13;
    uVar2 = 0;
    do {
      if ((int)uVar3 < (int)(param_3 - 1)) {
        flash_field_read_cached(0x67,iVar4,&local_38,0xc);
        uStack_2c = uStack_2c & 0xffffff00;
      }
      else if ((p_dm32_settings_block04[0x30] & 0x40) == 0) {
        memcpy_bytes_iram(&local_38,PTR_LAB_030584f8,4);
        uStack_34 = uStack_34 & 0xffffff00;
      }
      else {
        local_38 = 0x646441;
      }
      if (uVar3 == param_2) {
        display_draw_list_row(uVar2 + 1,&local_38,1);
      }
      else {
        display_draw_list_row(uVar2 + 1,&local_38,0);
      }
      if ((int)uVar3 < (int)(param_3 - 1)) {
        *(undefined1 *)PTR_DAT_030584fc = 2;
        menu_icon_draw_dispatch(uVar2 + 1,uVar3);
      }
      else {
        bVar1 = PTR_DAT_03058500[uVar2];
        if (uVar3 == param_2) {
          display_draw_list_row(uVar2 + 1,&local_38,1);
          display_blit_image(0xc,bVar1 + 4,0x11,0x11,PTR_LAB_03058504);
        }
        else {
          display_draw_list_row(uVar2 + 1,&local_38,0);
          display_blit_image(0xc,bVar1 + 4,0x11,0x11,PTR_LAB_03058508);
        }
      }
      uVar3 = uVar3 + 1 & 0xff;
      if ((param_3 <= uVar3) || (uVar2 == 7)) {
        if ((p_dm32_settings_block04[0x30] & 0x40) == 0) {
          number_to_string_format_2args(&local_38,PTR_LAB_0305850c,param_2 + 1,param_3);
        }
        else {
          number_to_string_format_2args
                    (&local_38,PTR_s_DMR_ID_List__d__d_03058510,param_2 + 1,param_3);
        }
        display_clear_status_row(0,0);
        display_draw_number_centered(1,0xffff,0,(uint)&local_38);
        return;
      }
      uVar2 = uVar2 + 1;
      iVar4 = iVar4 + 0x10;
    } while ((uVar2 & 0xff) < param_3);
  }
  return;
}

