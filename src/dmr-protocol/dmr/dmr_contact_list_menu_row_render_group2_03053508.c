/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dmr_contact_list_menu_row_render_group2 @ 03053508 (file base 0x03000000; code starts at 0x03001000)
 * Size: 856 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: dmr-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void dmr_contact_list_menu_row_render_group2(void)

{
  byte bVar1;
  ushort block_id;
  uint uVar2;
  uint uVar3;
  char cVar4;
  char cVar5;
  ushort uVar6;
  char cVar7;
  ushort uStack_58;
  uint uStack_50;
  uint uStack_4c;
  int iStack_48;
  byte bStack_3f;
  byte bStack_3e;
  undefined1 uStack_3d;
  byte abStack_3c [4];
  uint uStack_38;
  uint uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined1 uStack_28;
  
  uStack_50 = dmr_list_header_load(1);
  uStack_38 = DAT_0305363c;
  uStack_34 = DAT_0305363c;
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  bVar1 = PTR_DAT_03053640[8];
  block_id = flash_block_id_resolve_locked(7);
  if (*(byte *)PTR_active_screen_option_count_03053634 < 2) {
    if (*(byte *)PTR_active_screen_option_count_03053634 != 1) {
      dialog_show_icon_and_number
                (0,**(undefined4 **)(PTR_PTR_03053864 + ((byte)PTR_DAT_03053860[0x30] >> 6 & 1) * 8)
                );
      write_field_and_mbox_post(1,0x2b);
      return;
    }
    if (uStack_50 != 0) {
      do {
        flash_block_read(block_id,uStack_50 + 0x2f & 0xffff,&bStack_3f,1);
        uVar3 = (uint)bStack_3f;
        if (uVar3 < 0xe) {
          flash_block_read(block_id,(uVar3 - 1) * 0x110 + 0x130 & 0xfff0,abStack_3c,1);
        }
        else {
          contact_char_index_to_display_code(uVar3,1,&uStack_3d,&bStack_3e);
          uStack_58 = flash_block_id_resolve_locked(uStack_3d);
          flash_block_read(uStack_58,(bStack_3e - 1) * 0x110 & 0xfff0,abStack_3c,1);
        }
        if ((abStack_3c[0] & 1) != 0) {
          if (bStack_3f < 0xe) {
            flash_block_read(block_id,(bStack_3f - 1) * 0x110 + 0x13d & 0xffff,&uStack_38,3);
          }
          else {
            flash_block_read(uStack_58,(bStack_3e - 1) * 0x110 + 0xd & 0xffff,&uStack_38,3);
          }
          iStack_48 = ((uStack_38 >> 0x10 & 0xff) * 0x100 + (uStack_38 >> 8 & 0xff)) * 0x100 +
                      (uStack_38 & 0xff);
          uStack_4c = (uint)(byte)~((abStack_3c[0] & 2) != 0);
          contact_name_lookup_or_format(bVar1 >> 4,iStack_48,&uStack_38,3);
          break;
        }
        uStack_50 = uStack_50 - 1 & 0xff;
      } while (uStack_50 != 0);
    }
    menu_list_row_draw_with_icon(0,&uStack_38,1,uStack_4c);
    *PTR_text_entry_current_char_minus_6_03053858 = iStack_48;
  }
  else if (1 < *(byte *)PTR_active_screen_visible_rows_03053648 + 1) {
    cVar4 = (*(char *)PTR_active_screen_state_word_0305362c + '\x01') -
            *(char *)PTR_active_screen_flag_0003e5d5_03053644;
    uVar6 = 1;
    cVar7 = '\0';
    uVar3 = uStack_50;
joined_r0x030536f2:
    for (; uVar3 != 0; uVar3 = uVar3 - 1 & 0xff) {
      flash_block_read(block_id,uVar3 + 0x2f & 0xffff,&bStack_3f,1);
      uVar2 = (uint)bStack_3f;
      if (uVar2 < 0xe) {
        flash_block_read(block_id,(uVar2 - 1) * 0x110 + 0x130 & 0xfff0,abStack_3c,1);
      }
      else {
        contact_char_index_to_display_code(uVar2,1,&uStack_3d,&bStack_3e);
        uStack_58 = flash_block_id_resolve_locked(uStack_3d);
        flash_block_read(uStack_58,(bStack_3e - 1) * 0x110 & 0xfff0,abStack_3c,1);
      }
      cVar5 = cVar7;
      if (((abStack_3c[0] & 1) != 0) && (cVar5 = cVar7 + '\x01', cVar4 == cVar7)) {
        uStack_50 = uVar3 - 1 & 0xff;
        if (bStack_3f < 0xe) {
          flash_block_read(block_id,(bStack_3f - 1) * 0x110 + 0x13d & 0xffff,&uStack_38,3);
        }
        else {
          flash_block_read(uStack_58,(bStack_3e - 1) * 0x110 + 0xd & 0xffff,&uStack_38,3);
        }
        iStack_48 = ((uStack_38 >> 0x10 & 0xff) * 0x100 + (uStack_38 >> 8 & 0xff)) * 0x100 +
                    (uStack_38 & 0xff);
        uStack_4c = (uint)(byte)~((abStack_3c[0] & 2) != 0);
        contact_name_lookup_or_format(bVar1 >> 4,iStack_48,&uStack_38,3);
        cVar7 = cVar5;
        break;
      }
      cVar7 = cVar5;
    }
    if (*(byte *)PTR_active_screen_flag_0003e5d5_03053854 == uVar6) {
      menu_list_row_draw_with_icon(uVar6 - 1,&uStack_38,1,uStack_4c);
      *PTR_text_entry_current_char_minus_6_03053858 = iStack_48;
    }
    else {
      menu_list_row_draw_with_icon(uVar6 - 1,&uStack_38,0,uStack_4c);
    }
    uVar6 = uVar6 + 1 & 0xff;
    if (uVar6 < (ushort)(*(byte *)PTR_active_screen_visible_rows_0305385c + 1)) {
      cVar4 = cVar4 + '\x01';
      uVar3 = uStack_50;
      goto joined_r0x030536f2;
    }
  }
  if ((PTR_DAT_03053860[0x30] & 0x40) == 0) {
    number_to_string_format_2args
              (&uStack_38,PTR_DAT_0305386c,*(byte *)PTR_active_screen_state_word_03053868 + 1,
               *(undefined1 *)PTR_active_screen_option_count_03053870);
  }
  else {
    number_to_string_format_2args
              (&uStack_38,PTR_s_Inbox__d__d_03053ae8,
               *(byte *)PTR_active_screen_state_word_03053ae4 + 1,
               *(undefined1 *)PTR_active_screen_option_count_03053aec);
  }
  display_fill_rect(0,0,0xf0,0x1b,0);
  display_draw_number_centered(1,0xffff,0,(uint)&uStack_38);
  return;
}

