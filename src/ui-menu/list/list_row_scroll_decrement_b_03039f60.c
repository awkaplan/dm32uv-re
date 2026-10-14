/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: list_row_scroll_decrement_b @ 03039f60 (file base 0x03000000; code starts at 0x03001000)
 * Size: 592 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void list_row_scroll_decrement_b(void)

{
  char cVar1;
  ushort uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  dialog_history_ui_state *pdVar5;
  byte bVar6;
  uint uVar7;
  uint uVar8;
  byte *pbVar9;
  int iVar10;
  
  if ((*(ushort *)p_active_screen_index_list < 9) ||
     (*(char *)p_active_screen_flag_0003e5d5 != '\b')) {
    display_draw_list_row
              (*(undefined1 *)p_active_screen_flag_0003e5d5,
               *(undefined4 *)
                (*p_active_screen_option_ptr_array +
                (uint)*(byte *)((int)p_active_screen_index_list +
                               *(byte *)p_active_screen_state_word + 2) * 4),0);
    PTR_DAT_03039fc4[1] = PTR_DAT_03039fc4[1] & 0xbf;
    if (p_dialog_history_ui_state->field_0xa0a == 0) {
      menu_icon_draw_dispatch
                (*(undefined1 *)p_active_screen_flag_0003e5d5,
                 *(undefined1 *)
                  ((int)p_active_screen_index_list + *(byte *)p_active_screen_state_word + 2));
    }
    else {
      menu_icon_draw_dispatch
                (*(undefined1 *)p_active_screen_flag_0003e5d5,
                 *(undefined1 *)p_active_screen_state_word);
    }
    cVar1 = *(char *)p_active_screen_flag_0003e5d5;
    *(byte *)p_active_screen_flag_0003e5d5 = cVar1 + 1U;
    uVar2 = *(ushort *)p_active_screen_index_list;
    if ((uint)(byte)(cVar1 + 1U) == uVar2 + 1) {
      *(undefined1 *)p_active_screen_flag_0003e5d5 = 1;
    }
    puVar3 = p_active_screen_state_word;
    cVar1 = *(char *)p_active_screen_state_word;
    *(byte *)p_active_screen_state_word = cVar1 + 1U;
    if ((uint)uVar2 == (uint)(byte)(cVar1 + 1U)) {
      *(undefined1 *)puVar3 = 0;
    }
    display_draw_list_row
              (*(undefined1 *)p_active_screen_flag_0003e5d5,
               *(undefined4 *)
                (*p_active_screen_option_ptr_array +
                (uint)*(byte *)((int)p_active_screen_index_list +
                               *(byte *)p_active_screen_state_word + 2) * 4),1);
    PTR_DAT_0303a18c[1] = PTR_DAT_0303a18c[1] & 0xbf | 0x40;
    if (p_dialog_history_ui_state->field_0xa0a == 0) {
      menu_icon_draw_dispatch
                (*(undefined1 *)p_active_screen_flag_0003e5d5,
                 *(undefined1 *)
                  ((int)p_active_screen_index_list + *(byte *)p_active_screen_state_word + 2));
    }
    else {
      menu_icon_draw_dispatch
                (*(undefined1 *)p_active_screen_flag_0003e5d5,
                 *(undefined1 *)p_active_screen_state_word);
    }
  }
  else {
    uVar8 = (uint)*(byte *)p_active_screen_state_word;
    if (uVar8 == *(ushort *)p_active_screen_index_list - 1) {
      *(undefined1 *)p_active_screen_flag_0003e5d5 = 1;
      *(undefined1 *)p_active_screen_state_word = 0;
      display_draw_list_row
                (1,*(undefined4 *)
                    (*p_active_screen_option_ptr_array +
                    (uint)*(byte *)((int)p_active_screen_index_list + 2) * 4),1);
      PTR_DAT_0303a18c[1] = PTR_DAT_0303a18c[1] & 0xbf | 0x40;
      if (p_dialog_history_ui_state->field_0xa0a == 0) {
        menu_icon_draw_dispatch
                  (*(undefined1 *)p_active_screen_flag_0003e5d5,
                   *(undefined1 *)
                    ((int)p_active_screen_index_list + *(byte *)p_active_screen_state_word + 2));
      }
      else {
        menu_icon_draw_dispatch
                  (*(undefined1 *)p_active_screen_flag_0003e5d5,
                   *(undefined1 *)p_active_screen_state_word);
      }
      PTR_DAT_0303a33c[1] = PTR_DAT_0303a33c[1] & 0xbf;
      pdVar5 = p_dialog_history_ui_state;
      puVar3 = p_active_screen_option_ptr_array;
      bVar6 = *(char *)p_active_screen_flag_0003e5d5 + 1;
      if (bVar6 < 9) {
        iVar10 = 0;
        pbVar9 = PTR_DAT_0303a340;
        do {
          iVar10 = iVar10 + 1;
          display_draw_list_row(bVar6,*(undefined4 *)(*puVar3 + (uint)*pbVar9 * 4),0);
          if (pdVar5->field_0xa0a == 0) {
            menu_icon_draw_dispatch(bVar6,*pbVar9);
          }
          else {
            menu_icon_draw_dispatch(bVar6,iVar10);
          }
          bVar6 = bVar6 + 1;
          pbVar9 = pbVar9 + 1;
        } while (bVar6 < 9);
      }
    }
    else {
      uVar7 = uVar8 + 1 & 0xff;
      *(char *)p_active_screen_state_word = (char)(uVar8 + 1);
      display_draw_list_row
                (8,*(undefined4 *)
                    (*p_active_screen_option_ptr_array +
                    (uint)*(byte *)((int)p_active_screen_index_list + uVar7 + 2) * 4),1);
      PTR_DAT_0303a18c[1] = PTR_DAT_0303a18c[1] & 0xbf | 0x40;
      if (p_dialog_history_ui_state->field_0xa0a == 0) {
        menu_icon_draw_dispatch
                  (*(undefined1 *)p_active_screen_flag_0003e5d5,
                   *(undefined1 *)((int)p_active_screen_index_list + uVar7 + 2));
      }
      else {
        menu_icon_draw_dispatch(*(undefined1 *)p_active_screen_flag_0003e5d5,uVar7);
      }
      PTR_DAT_0303a18c[1] = PTR_DAT_0303a18c[1] & 0xbf;
      pdVar5 = p_dialog_history_ui_state;
      puVar4 = p_active_screen_option_ptr_array;
      puVar3 = p_active_screen_index_list;
      cVar1 = *(char *)p_active_screen_flag_0003e5d5;
      while (cVar1 = cVar1 + -1, cVar1 != '\0') {
        display_draw_list_row
                  (cVar1,*(undefined4 *)(*puVar4 + (uint)*(byte *)((int)puVar3 + uVar8 + 2) * 4),0);
        if (pdVar5->field_0xa0a == 0) {
          menu_icon_draw_dispatch(cVar1,*(undefined1 *)((int)puVar3 + uVar8 + 2));
        }
        else {
          menu_icon_draw_dispatch(cVar1,uVar8);
        }
        uVar8 = uVar8 - 1 & 0xff;
      }
    }
  }
  return;
}

