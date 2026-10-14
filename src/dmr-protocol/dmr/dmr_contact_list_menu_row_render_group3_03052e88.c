/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dmr_contact_list_menu_row_render_group3 @ 03052e88 (file base 0x03000000; code starts at 0x03001000)
 * Size: 738 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: dmr-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void dmr_contact_list_menu_row_render_group3(void)

{
  byte bVar1;
  ushort block_id;
  uint uVar2;
  uint uVar3;
  char cVar4;
  char cVar5;
  ushort uVar6;
  char cVar7;
  ushort uStack_44;
  uint uStack_3c;
  byte bStack_37;
  byte bStack_36;
  undefined1 uStack_35;
  byte abStack_34 [16];
  
  block_id = flash_block_id_resolve_locked(9);
  uStack_3c = dmr_list_header_load(5);
  bVar1 = *(byte *)PTR_active_screen_option_count_0305304c;
  if (bVar1 < 2) {
    if (bVar1 == 1) {
      if (uStack_3c != 0) {
        do {
          flash_block_read(block_id,uStack_3c + 0x2f & 0xffff,&bStack_37,1);
          uVar3 = (uint)bStack_37;
          if (uVar3 < 0xe) {
            flash_block_read(block_id,(uVar3 - 1) * 0x110 + 0x130 & 0xfff0,abStack_34,1);
          }
          else {
            contact_char_index_to_display_code(uVar3,5,&uStack_35,&bStack_36);
            uStack_44 = flash_block_id_resolve_locked(uStack_35);
            flash_block_read(uStack_44,(bStack_36 - 1) * 0x110 & 0xfff0,abStack_34,1);
          }
          if ((abStack_34[0] & 1) != 0) {
            if (bStack_37 < 0xe) {
              flash_block_read(block_id,(bStack_37 - 1) * 0x110 + 0x140 & 0xfff0,DAT_03053278,0xe);
            }
            else {
              flash_block_read(uStack_44,(bStack_36 - 1) * 0x110 + 0x10 & 0xfff0,DAT_03053278,0xe);
            }
            *(undefined1 *)((int)DAT_03053278 + 0xe) = 0;
            break;
          }
          uStack_3c = uStack_3c - 1 & 0xff;
        } while (uStack_3c != 0);
      }
      menu_list_row_draw_with_icon(0,DAT_03053278,1,0);
    }
    else if (bVar1 == 0) {
      dialog_show_icon_and_number
                (0,**(undefined4 **)(PTR_PTR_03053280 + ((byte)PTR_DAT_0305327c[0x30] >> 6 & 1) * 8)
                );
      write_field_and_mbox_post(1,0x2b);
      return;
    }
  }
  else if (1 < *(byte *)PTR_active_screen_visible_rows_03053058 + 1) {
    cVar4 = (*(char *)PTR_active_screen_state_word_03053050 + '\x01') -
            *(char *)PTR_active_screen_flag_0003e5d5_03053054;
    uVar6 = 1;
    cVar7 = '\0';
    uVar3 = uStack_3c;
joined_r0x03052ff4:
    for (; uVar3 != 0; uVar3 = uVar3 - 1 & 0xff) {
      flash_block_read(block_id,uVar3 + 0x2f & 0xffff,&bStack_37,1);
      uVar2 = (uint)bStack_37;
      if (uVar2 < 0xe) {
        flash_block_read(block_id,(uVar2 - 1) * 0x110 + 0x130 & 0xfff0,abStack_34,1);
      }
      else {
        contact_char_index_to_display_code(uVar2,5,&uStack_35,&bStack_36);
        uStack_44 = flash_block_id_resolve_locked(uStack_35);
        flash_block_read(uStack_44,(bStack_36 - 1) * 0x110 & 0xfff0,abStack_34,1);
      }
      cVar5 = cVar7;
      if (((abStack_34[0] & 1) != 0) && (cVar5 = cVar7 + '\x01', cVar4 == cVar7)) {
        uStack_3c = uVar3 - 1 & 0xff;
        if (bStack_37 < 0xe) {
          flash_block_read(block_id,(bStack_37 - 1) * 0x110 + 0x140 & 0xfff0,DAT_0305305c,0xe);
        }
        else {
          flash_block_read(uStack_44,(bStack_36 - 1) * 0x110 + 0x10 & 0xfff0,DAT_0305305c,0xe);
        }
        *(undefined1 *)((int)DAT_0305305c + 0xe) = 0;
        cVar7 = cVar5;
        break;
      }
      cVar7 = cVar5;
    }
    if (*(byte *)PTR_active_screen_flag_0003e5d5_03053054 == uVar6) {
      menu_list_row_draw_with_icon(uVar6 - 1,DAT_0305305c,1,0);
    }
    else {
      menu_list_row_draw_with_icon(uVar6 - 1,DAT_0305305c,0,0);
    }
    uVar6 = uVar6 + 1 & 0xff;
    if (uVar6 < (ushort)(*(byte *)PTR_active_screen_visible_rows_03053058 + 1)) {
      cVar4 = cVar4 + '\x01';
      uVar3 = uStack_3c;
      goto joined_r0x03052ff4;
    }
  }
  if ((PTR_DAT_0305327c[0x30] & 0x40) == 0) {
    number_to_string_format_2args
              (abStack_34,PTR_DAT_03053288,*(byte *)PTR_active_screen_state_word_03053284 + 1,
               *(undefined1 *)PTR_active_screen_option_count_0305328c);
  }
  else {
    number_to_string_format_2args
              (abStack_34,PTR_s_Draft_Box__d__d_03053290,
               *(byte *)PTR_active_screen_state_word_03053284 + 1,
               *(undefined1 *)PTR_active_screen_option_count_0305328c);
  }
  display_fill_rect(0,0,0xf0,0x1b,0);
  display_draw_number_centered(1,0xffff,0,(uint)abStack_34);
  return;
}

