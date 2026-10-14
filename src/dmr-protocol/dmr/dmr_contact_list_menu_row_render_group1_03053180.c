/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dmr_contact_list_menu_row_render_group1 @ 03053180 (file base 0x03000000; code starts at 0x03001000)
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

void dmr_contact_list_menu_row_render_group1(void)

{
  byte bVar1;
  char cVar2;
  undefined4 *puVar3;
  ushort block_id;
  uint uVar4;
  uint uVar5;
  char cVar6;
  char cVar7;
  ushort uVar8;
  ushort uStack_4c;
  uint uStack_40;
  byte bStack_3b;
  byte bStack_3a;
  undefined1 uStack_39;
  byte abStack_38 [16];
  undefined4 uStack_28;
  
  uStack_40 = dmr_list_header_load(3);
  block_id = flash_block_id_resolve_locked(8);
  bVar1 = *(byte *)PTR_active_screen_option_count_0305328c;
  if (bVar1 < 2) {
    if (bVar1 == 1) {
      if (uStack_40 != 0) {
        do {
          flash_block_read(block_id,uStack_40 + 0x2f & 0xffff,&bStack_3b,1);
          uVar5 = (uint)bStack_3b;
          if (uVar5 < 0xe) {
            flash_block_read(block_id,(uVar5 - 1) * 0x110 + 0x130 & 0xfff0,abStack_38,1);
          }
          else {
            contact_char_index_to_display_code(uVar5,3,&uStack_39,&bStack_3a);
            uStack_4c = flash_block_id_resolve_locked(uStack_39);
            flash_block_read(uStack_4c,(bStack_3a - 1) * 0x110 & 0xfff0,abStack_38,1);
          }
          if ((abStack_38[0] & 1) != 0) {
            if (bStack_3b < 0xe) {
              flash_block_read(block_id,(bStack_3b - 1) * 0x110 + 0x13d & 0xffff,
                               PTR_text_entry_buffer_03053444,3);
            }
            else {
              flash_block_read(uStack_4c,(bStack_3a - 1) * 0x110 + 0xd & 0xffff,
                               PTR_text_entry_buffer_03053444,3);
            }
            puVar3 = PTR_text_entry_buffer_03053444;
            *(undefined1 *)((int)PTR_text_entry_buffer_03053444 + 3) = 0;
            uStack_28 = 0;
            memcpy_bytes_iram(&uStack_28,puVar3,3);
            if ((abStack_38[0] & 0xc) == 8) {
              abStack_38[0] = 5;
            }
            else if ((abStack_38[0] & 0xc) == 4) {
              abStack_38[0] = 4;
            }
            else {
              abStack_38[0] = 3;
            }
            contact_name_lookup_or_format(1,uStack_28,DAT_03053620,abStack_38[0]);
            break;
          }
          uStack_40 = uStack_40 - 1 & 0xff;
        } while (uStack_40 != 0);
      }
      menu_list_row_draw_with_icon(0,DAT_03053620,1,0);
    }
    else if (bVar1 == 0) {
      dialog_show_icon_and_number
                (0,**(undefined4 **)(PTR_PTR_03053628 + ((byte)PTR_DAT_03053624[0x30] >> 6 & 1) * 8)
                );
      write_field_and_mbox_post(1,0x2b);
      return;
    }
  }
  else if (1 < *(byte *)PTR_active_screen_visible_rows_03053298 + 1) {
    cVar6 = (*(char *)PTR_active_screen_state_word_03053284 + '\x01') -
            *(char *)PTR_active_screen_flag_0003e5d5_03053294;
    uVar8 = 1;
    cVar2 = '\0';
    uVar5 = uStack_40;
joined_r0x0305334a:
    for (; uVar5 != 0; uVar5 = uVar5 - 1 & 0xff) {
      flash_block_read(block_id,uVar5 + 0x2f & 0xffff,&bStack_3b,1);
      uVar4 = (uint)bStack_3b;
      if (uVar4 < 0xe) {
        flash_block_read(block_id,(uVar4 - 1) * 0x110 + 0x130 & 0xfff0,abStack_38,1);
      }
      else {
        contact_char_index_to_display_code(uVar4,3,&uStack_39,&bStack_3a);
        uStack_4c = flash_block_id_resolve_locked(uStack_39);
        flash_block_read(uStack_4c,(bStack_3a - 1) * 0x110 & 0xfff0,abStack_38,1);
      }
      cVar7 = cVar2;
      if (((abStack_38[0] & 9) == 1) && (cVar7 = cVar2 + '\x01', cVar6 == cVar2)) {
        uStack_40 = uVar5 - 1 & 0xff;
        if (bStack_3b < 0xe) {
          flash_block_read(block_id,(bStack_3b - 1) * 0x110 + 0x13d & 0xffff,DAT_03053278,3);
        }
        else {
          flash_block_read(uStack_4c,(bStack_3a - 1) * 0x110 + 0xd & 0xffff,
                           PTR_text_entry_buffer_03053444,3);
        }
        puVar3 = PTR_text_entry_buffer_03053444;
        *(undefined1 *)((int)PTR_text_entry_buffer_03053444 + 3) = 0;
        uStack_28 = 0;
        memcpy_bytes_iram(&uStack_28,puVar3,3);
        if ((abStack_38[0] & 0xc) == 8) {
          abStack_38[0] = 5;
        }
        else if ((abStack_38[0] & 0xc) == 4) {
          abStack_38[0] = 4;
        }
        else {
          abStack_38[0] = 3;
        }
        contact_name_lookup_or_format(1,uStack_28,PTR_text_entry_buffer_03053444,abStack_38[0]);
        cVar2 = cVar7;
        break;
      }
      cVar2 = cVar7;
    }
    if (*(byte *)PTR_active_screen_flag_0003e5d5_03053448 == uVar8) {
      menu_list_row_draw_with_icon(uVar8 - 1,PTR_text_entry_buffer_03053444,1,0);
    }
    else {
      menu_list_row_draw_with_icon(uVar8 - 1,PTR_text_entry_buffer_03053444,0,0);
    }
    uVar8 = uVar8 + 1 & 0xff;
    if (uVar8 < (ushort)(*(byte *)PTR_active_screen_visible_rows_0305344c + 1)) {
      cVar6 = cVar6 + '\x01';
      uVar5 = uStack_40;
      goto joined_r0x0305334a;
    }
  }
  if ((PTR_DAT_03053624[0x30] & 0x40) == 0) {
    number_to_string_format_2args
              (abStack_38,PTR_LAB_03053630,*(byte *)PTR_active_screen_state_word_0305362c + 1,
               *(undefined1 *)PTR_active_screen_option_count_03053634);
  }
  else {
    number_to_string_format_2args
              (abStack_38,PTR_s_Outbox__d__d_03053638,
               *(byte *)PTR_active_screen_state_word_0305362c + 1,
               *(undefined1 *)PTR_active_screen_option_count_03053634);
  }
  display_fill_rect(0,0,0xf0,0x1b,0);
  display_draw_number_centered(1,0xffff,0,(uint)abStack_38);
  return;
}

