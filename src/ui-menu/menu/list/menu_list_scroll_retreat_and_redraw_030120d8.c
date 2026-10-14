/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_list_scroll_retreat_and_redraw @ 030120d8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 668 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void menu_list_scroll_retreat_and_redraw(void)

{
  char cVar1;
  ushort uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  short sVar8;
  uint uVar9;
  uint uVar10;
  byte abStack_38 [20];
  
  puVar7 = p_active_screen_flag_0003e5d5;
  puVar6 = p_active_screen_option_ptr_array;
  puVar5 = p_active_screen_state_word;
  puVar4 = p_active_screen_flag_0003e5d5;
  puVar3 = p_active_screen_index_list;
  uVar2 = *(ushort *)p_active_screen_index_list;
  if ((uVar2 < 9) || (*(char *)p_active_screen_flag_0003e5d5 != '\x01')) {
    display_draw_list_row
              (*(undefined1 *)p_active_screen_flag_0003e5d5,
               *(undefined4 *)
                (*p_active_screen_option_ptr_array +
                (uint)*(byte *)((int)p_active_screen_index_list +
                               *(byte *)p_active_screen_state_word + 2) * 4),0);
    radio_telemetry_format_dispatch(*(undefined1 *)puVar5,abStack_38);
    sVar8 = strlen_ck803s(*(undefined4 *)
                           (*puVar6 + (uint)*(byte *)((int)puVar3 + *(byte *)puVar5 + 2) * 4));
    display_draw_string_gb2312
              ((ushort)(byte)PTR_DAT_030122b4[*(byte *)puVar4],sVar8 * 0xc + 10U & 0xfe,abStack_38,
               0xffff,0);
    cVar1 = *(char *)puVar4;
    *(char *)puVar4 = cVar1 + -1;
    if ((char)(cVar1 + -1) == '\0') {
      *(char *)puVar4 = (char)*(undefined2 *)p_active_screen_index_list;
    }
    if (*(char *)p_active_screen_state_word == '\0') {
      *(char *)p_active_screen_state_word = *(char *)p_active_screen_index_list + -1;
    }
    else {
      *(char *)p_active_screen_state_word = *(char *)p_active_screen_state_word + -1;
    }
    puVar6 = p_active_screen_option_ptr_array;
    puVar5 = p_active_screen_state_word;
    puVar4 = p_active_screen_flag_0003e5d5;
    puVar3 = p_active_screen_index_list;
    display_draw_list_row
              (*(undefined1 *)p_active_screen_flag_0003e5d5,
               *(undefined4 *)
                (*p_active_screen_option_ptr_array +
                (uint)*(byte *)((int)p_active_screen_index_list +
                               *(byte *)p_active_screen_state_word + 2) * 4),1);
    radio_telemetry_format_dispatch(*(undefined1 *)puVar5,abStack_38);
    sVar8 = strlen_ck803s(*(undefined4 *)
                           (*puVar6 + (uint)*(byte *)((int)puVar3 + *(byte *)puVar5 + 2) * 4));
    display_draw_string_gb2312
              ((ushort)(byte)PTR_DAT_030122b4[*(byte *)puVar4],sVar8 * 0xc + 10U & 0xfe,abStack_38,0
               ,0xc618);
  }
  else {
    uVar10 = (uint)*(byte *)p_active_screen_state_word;
    if (uVar10 == 0) {
      *(undefined1 *)p_active_screen_flag_0003e5d5 = 8;
      uVar10 = uVar2 - 1;
      uVar9 = uVar10 & 0xff;
      *(char *)p_active_screen_state_word = (char)uVar10;
      puVar4 = p_active_screen_option_ptr_array;
      puVar3 = p_active_screen_index_list;
      display_draw_list_row
                (8,*(undefined4 *)
                    (*p_active_screen_option_ptr_array +
                    (uint)*(byte *)((int)p_active_screen_index_list + uVar9 + 2) * 4),1);
      radio_telemetry_format_dispatch(uVar9,abStack_38);
      sVar8 = strlen_ck803s(*(undefined4 *)(*puVar4 + (uint)*(byte *)((int)puVar3 + uVar9 + 2) * 4))
      ;
      display_draw_string_gb2312
                ((ushort)(byte)PTR_DAT_03012494[*(byte *)puVar7],sVar8 * 0xc + 10U & 0xfe,abStack_38
                 ,0,0xc618);
      puVar4 = p_active_screen_option_ptr_array;
      puVar3 = p_active_screen_index_list;
      uVar10 = *(byte *)puVar7 - 1 & 0xff;
      if (uVar10 != 0) {
        do {
          uVar9 = uVar9 - 1 & 0xff;
          display_draw_list_row
                    (uVar10,*(undefined4 *)(*puVar4 + (uint)*(byte *)((int)puVar3 + uVar9 + 2) * 4),
                     0);
          radio_telemetry_format_dispatch(uVar9,abStack_38);
          sVar8 = strlen_ck803s(*(undefined4 *)
                                 (*puVar4 + (uint)*(byte *)((int)puVar3 + uVar9 + 2) * 4));
          display_draw_string_gb2312
                    ((ushort)(byte)PTR_DAT_03012498[uVar10 - 1],sVar8 * 0xc + 10U & 0xfe,abStack_38,
                     0xffff,0);
          uVar10 = uVar10 - 1 & 0xff;
        } while (uVar10 != 0);
      }
    }
    else {
      uVar9 = uVar10 - 1 & 0xff;
      *(char *)p_active_screen_state_word = (char)(uVar10 - 1);
      puVar5 = p_active_screen_option_ptr_array;
      puVar3 = p_active_screen_index_list;
      display_draw_list_row
                (1,*(undefined4 *)
                    (*p_active_screen_option_ptr_array +
                    (uint)*(byte *)((int)p_active_screen_index_list + uVar9 + 2) * 4),1);
      radio_telemetry_format_dispatch(uVar9,abStack_38);
      sVar8 = strlen_ck803s(*(undefined4 *)(*puVar5 + (uint)*(byte *)((int)puVar3 + uVar9 + 2) * 4))
      ;
      puVar4 = p_active_screen_flag_0003e5d5;
      display_draw_string_gb2312
                ((ushort)(byte)PTR_DAT_030122b4[*(byte *)p_active_screen_flag_0003e5d5],
                 sVar8 * 0xc + 10U & 0xfe,abStack_38,0,0xc618);
      puVar3 = p_active_screen_index_list;
      uVar9 = (uint)(byte)(*(char *)puVar4 + 1);
      if (uVar9 < 9) {
        do {
          display_draw_list_row
                    (uVar9,*(undefined4 *)(*puVar5 + (uint)*(byte *)((int)puVar3 + uVar10 + 2) * 4),
                     0);
          radio_telemetry_format_dispatch(uVar10,abStack_38);
          sVar8 = strlen_ck803s(*(undefined4 *)
                                 (*puVar5 + (uint)*(byte *)((int)puVar3 + uVar10 + 2) * 4));
          display_draw_string_gb2312
                    ((ushort)(byte)PTR_DAT_030122b8[uVar9 - 1],sVar8 * 0xc + 10U & 0xfe,abStack_38,
                     0xffff,0);
          uVar9 = uVar9 + 1 & 0xff;
          uVar10 = uVar10 + 1 & 0xff;
        } while (uVar9 < 9);
      }
    }
  }
  return;
}

