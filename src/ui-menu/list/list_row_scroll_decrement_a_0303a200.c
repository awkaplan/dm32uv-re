/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: list_row_scroll_decrement_a @ 0303a200 (file base 0x03000000; code starts at 0x03001000)
 * Size: 594 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void list_row_scroll_decrement_a(void)

{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  dialog_history_ui_state *pdVar6;
  uint uVar7;
  uint uVar8;
  
  uVar3 = *(ushort *)p_active_screen_index_list;
  if ((uVar3 < 9) || (*(char *)p_active_screen_flag_0003e5d5 != '\x01')) {
    display_draw_list_row
              (*(undefined1 *)p_active_screen_flag_0003e5d5,
               *(undefined4 *)
                (*p_active_screen_option_ptr_array +
                (uint)*(byte *)((int)p_active_screen_index_list +
                               *(byte *)p_active_screen_state_word + 2) * 4),0);
    PTR_DAT_0303a33c[1] = PTR_DAT_0303a33c[1] & 0xbf;
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
    *(char *)p_active_screen_flag_0003e5d5 = cVar1 + -1;
    if ((char)(cVar1 + -1) == '\0') {
      *(char *)p_active_screen_flag_0003e5d5 = (char)*(undefined2 *)p_active_screen_index_list;
    }
    if (*(char *)p_active_screen_state_word == '\0') {
      *(char *)p_active_screen_state_word = *(char *)p_active_screen_index_list + -1;
    }
    else {
      *(char *)p_active_screen_state_word = *(char *)p_active_screen_state_word + -1;
    }
    display_draw_list_row
              (*(undefined1 *)p_active_screen_flag_0003e5d5,
               *(undefined4 *)
                (*p_active_screen_option_ptr_array +
                (uint)*(byte *)((int)p_active_screen_index_list +
                               *(byte *)p_active_screen_state_word + 2) * 4),1);
    PTR_DAT_0303a33c[1] = PTR_DAT_0303a33c[1] & 0xbf | 0x40;
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
    if (uVar8 == 0) {
      *(undefined1 *)p_active_screen_flag_0003e5d5 = 8;
      uVar7 = uVar3 - 1;
      uVar8 = uVar7 & 0xff;
      *(char *)p_active_screen_state_word = (char)uVar7;
      display_draw_list_row
                (8,*(undefined4 *)
                    (*p_active_screen_option_ptr_array +
                    (uint)(byte)p_active_screen_index_list[uVar8 + 2] * 4),1);
      PTR_DAT_0303a4bc[1] = PTR_DAT_0303a4bc[1] & 0xbf | 0x40;
      if (p_dialog_history_ui_state->field_0xa0a == 0) {
        menu_icon_draw_dispatch
                  (*(undefined1 *)p_active_screen_flag_0003e5d5,
                   p_active_screen_index_list[uVar8 + 2]);
      }
      else {
        menu_icon_draw_dispatch(*(undefined1 *)p_active_screen_flag_0003e5d5,uVar8);
      }
      PTR_DAT_0303a4bc[1] = PTR_DAT_0303a4bc[1] & 0xbf;
      pdVar6 = p_dialog_history_ui_state;
      puVar5 = p_active_screen_option_ptr_array;
      puVar4 = p_active_screen_index_list;
      cVar1 = *(char *)p_active_screen_flag_0003e5d5;
      while (cVar1 = cVar1 + -1, cVar1 != '\0') {
        uVar8 = uVar8 - 1 & 0xff;
        display_draw_list_row(cVar1,*(undefined4 *)(*puVar5 + (uint)(byte)puVar4[uVar8 + 2] * 4),0);
        if (pdVar6->field_0xa0a == 0) {
          menu_icon_draw_dispatch(cVar1,puVar4[uVar8 + 2]);
        }
        else {
          menu_icon_draw_dispatch(cVar1,uVar8);
        }
      }
    }
    else {
      uVar7 = uVar8 - 1 & 0xff;
      *(char *)p_active_screen_state_word = (char)(uVar8 - 1);
      display_draw_list_row
                (1,*(undefined4 *)
                    (*p_active_screen_option_ptr_array +
                    (uint)*(byte *)((int)p_active_screen_index_list + uVar7 + 2) * 4),1);
      PTR_DAT_0303a33c[1] = PTR_DAT_0303a33c[1] & 0xbf | 0x40;
      if (p_dialog_history_ui_state->field_0xa0a == 0) {
        menu_icon_draw_dispatch
                  (*(undefined1 *)p_active_screen_flag_0003e5d5,
                   *(undefined1 *)((int)p_active_screen_index_list + uVar7 + 2));
      }
      else {
        menu_icon_draw_dispatch(*(undefined1 *)p_active_screen_flag_0003e5d5,uVar7);
      }
      PTR_DAT_0303a4bc[1] = PTR_DAT_0303a4bc[1] & 0xbf;
      pdVar6 = p_dialog_history_ui_state;
      puVar5 = p_active_screen_option_ptr_array;
      puVar4 = p_active_screen_index_list;
      bVar2 = *(byte *)p_active_screen_flag_0003e5d5;
      while (bVar2 = bVar2 + 1, bVar2 < 9) {
        display_draw_list_row(bVar2,*(undefined4 *)(*puVar5 + (uint)(byte)puVar4[uVar8 + 2] * 4),0);
        if (pdVar6->field_0xa0a == 0) {
          menu_icon_draw_dispatch(bVar2,puVar4[uVar8 + 2]);
        }
        else {
          menu_icon_draw_dispatch(bVar2,uVar8);
        }
        uVar8 = uVar8 + 1 & 0xff;
      }
    }
  }
  return;
}

