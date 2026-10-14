/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_field_render_multibranch_dispatch @ 0304637c (file base 0x03000000; code starts at 0x03001000)
 * Size: 598 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void menu_field_render_multibranch_dispatch(void)

{
  undefined1 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined1 *puVar4;
  byte bVar5;
  char cVar6;
  short sVar7;
  uint uVar8;
  char *pcVar9;
  char *pcVar10;
  
  puVar4 = PTR_DAT_0304675c;
  puVar3 = PTR_DAT_030465c4;
  puVar1 = PTR_DAT_03046568;
  cVar6 = *(char *)((uint)p_menu_screen_state->index_0x2 + DAT_0304655c + 2);
  if (cVar6 == '\0') {
    menu_item_render_and_select_multibranch();
  }
  else if (cVar6 == '\x01') {
    cVar6 = *(char *)((uint)p_menu_screen_state->index_0x3 + DAT_03046560 + 2);
    if (cVar6 == '\x03') {
      vfo_display_step_index_compute();
    }
    else if (cVar6 == '\a') {
      cVar6 = *(char *)((uint)p_menu_screen_state->index_0x5 + DAT_03046564 + 2);
      if (cVar6 == '\x01') {
        *(undefined1 *)p_active_screen_option_count = PTR_DAT_03046568[4];
        *p_active_screen_option_ptr_array = *(undefined4 *)puVar1;
        *(undefined1 *)PTR_active_screen_subtype_03046574 = puVar1[5];
        p_radio_mode_state_0003e318->flags_0x4 =
             p_radio_mode_state_0003e318->flags_0x4 & 0x7f | 0x80;
        if (*(char *)PTR_DAT_0304657c == '\x01') {
          init_field_pair_0x20_5();
        }
        iVar2 = _DAT_03046580;
        number_to_string_format_2args(_DAT_03046580,PTR_s__d_030afae0_8_03046584,*PTR_DAT_03046588);
        *(undefined1 *)(iVar2 + 8) = 0;
        bVar5 = strlen_ck803s(iVar2);
        *(byte *)PTR_DAT_0304658c = bVar5;
        *(ushort *)p_text_entry_current_char =
             (ushort)bVar5 * 0xc + *(short *)p_text_entry_current_char;
      }
      else if (cVar6 == '\x02') {
        dialog_request_init(0xc);
        iVar2 = p_text_entry_buffer;
        if (*(char *)PTR_DAT_0304657c == '\x01') {
          strcpy_ck803s(p_text_entry_buffer,p_list_row_text_buffer);
          bVar5 = strlen_ck803s(iVar2);
          *(byte *)PTR_DAT_0304659c = bVar5 + 1;
          *(byte *)PTR_DAT_030465a0 = bVar5;
          *(ushort *)p_text_entry_current_char = (ushort)bVar5 * 0xc + 5;
          p_radio_mode_state_0003e318->flags_0x5 = p_radio_mode_state_0003e318->flags_0x5 & 0xf7 | 8
          ;
        }
        puVar3 = PTR_DAT_030465a4;
        *(undefined1 *)p_active_screen_option_count = *(undefined1 *)(PTR_DAT_030465a4 + 1);
        *p_active_screen_option_ptr_array = *puVar3;
        *(undefined1 *)PTR_active_screen_subtype_03046574 = *(undefined1 *)((int)puVar3 + 5);
      }
    }
    else if (cVar6 == '\f') {
      cVar6 = *(char *)((uint)p_menu_screen_state->index_0x5 + DAT_03046564 + 2);
      if (cVar6 == '\x01') {
        *(undefined1 *)PTR_DAT_030465a8 = 1;
        if (*(char *)PTR_DAT_0304657c == '\x01') {
          *(undefined1 *)p_active_screen_state_word = 0;
        }
        *(undefined1 *)PTR_active_screen_subtype_03046574 = 0x1f;
        sVar7 = flash_field_scan_until_invalid_or_32(*(undefined1 *)PTR_DAT_030465b0);
        *(char *)PTR_DAT_030465b4 = (char)sVar7;
        *(short *)p_active_screen_index_list = sVar7 + 1;
        cVar6 = *(char *)p_active_screen_state_word;
        *(char *)p_menu_selected_item_index = cVar6;
        bVar5 = cVar6 + 1;
        *(byte *)p_active_screen_flag_0003e5d5 = bVar5;
        if (8 < bVar5) {
          *(undefined1 *)p_active_screen_flag_0003e5d5 = 8;
        }
      }
      else if (cVar6 == '\x02') {
        *(undefined1 *)p_active_screen_option_count = *(undefined1 *)(PTR_DAT_030465c4 + 1);
        *p_active_screen_option_ptr_array = *puVar3;
        *(undefined1 *)PTR_active_screen_subtype_03046574 = *(undefined1 *)((int)puVar3 + 5);
        if (*(char *)PTR_DAT_0304657c == '\x01') {
          dialog_request_init(10);
          iVar2 = p_text_entry_buffer;
          flash_field_read_cached
                    (0xf,(*(byte *)PTR_DAT_030465b0 - 1) * 0x6d + 0x11,p_text_entry_buffer,10);
          cVar6 = strlen_ck803s(iVar2);
          *(byte *)PTR_DAT_0304659c = cVar6 + 1U;
          if (10 < (byte)(cVar6 + 1U)) {
            *(undefined1 *)(iVar2 + 10) = 0;
            *(undefined1 *)PTR_DAT_0304659c = 0xb;
          }
          *(char *)PTR_DAT_030465a0 = *(char *)PTR_DAT_0304659c + -1;
          *(undefined2 *)PTR_DAT_030465c8 = 0x20;
          *(undefined2 *)p_text_entry_current_char = 5;
          *(undefined1 *)p_text_entry_current_char_alias = 0;
          gb2312_text_wrap_calculate(p_text_entry_buffer);
          p_radio_mode_state_0003e318->flags_0x5 =
               p_radio_mode_state_0003e318->flags_0x5 & 0xdf | 0x20;
        }
      }
    }
    else if (cVar6 == '\r') {
      bVar5 = PTR_DAT_0304675c[4];
      *(byte *)p_active_screen_option_count = bVar5;
      *p_active_screen_option_ptr_array = *(undefined4 *)puVar4;
      *(undefined1 *)PTR_active_screen_subtype_03046768 = puVar4[5];
      if (*(char *)PTR_DAT_0304676c == '\x01') {
        build_sequential_index_list
                  ((ushort)bVar5,(ushort *)p_active_screen_index_list,
                   (byte *)((int)p_active_screen_index_list + 2));
      }
      init_field_pair_0x20_5();
      p_radio_mode_state_0003e318->flags_0x4 = p_radio_mode_state_0003e318->flags_0x4 & 0x9f | 0x20;
      uVar8 = DAT_03046784;
      if (*(char *)((uint)p_menu_screen_state->index_0x4 + DAT_0304677c + 2) == '\x04') {
        uVar8 = PTR_DAT_03046780[8];
      }
      pcVar10 = PTR_DAT_03046788 + -8;
      pcVar9 = PTR_DAT_03046788;
      do {
        *pcVar9 = (char)uVar8 + (char)(uVar8 / 10) * -10 + '0';
        pcVar9 = pcVar9 + -1;
        uVar8 = uVar8 / 10;
      } while (pcVar9 != pcVar10);
      *(undefined1 *)PTR_DAT_0304678c = 8;
      *(undefined2 *)p_text_entry_current_char = 0x48;
    }
  }
  return;
}

