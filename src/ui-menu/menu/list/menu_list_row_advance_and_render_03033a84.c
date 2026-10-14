/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_list_row_advance_and_render @ 03033a84 (file base 0x03000000; code starts at 0x03001000)
 * Size: 656 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void menu_list_row_advance_and_render(void)

{
  char cVar1;
  ushort uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined1 *puVar8;
  short sVar9;
  uint uVar10;
  uint uVar11;
  byte abStack_38 [20];
  
  puVar7 = p_active_screen_flag_0003e5d5;
  puVar6 = p_active_screen_option_ptr_array;
  puVar5 = p_active_screen_index_list;
  puVar4 = p_active_screen_flag_0003e5d5;
  puVar3 = p_active_screen_state_word;
  uVar2 = *(ushort *)p_active_screen_index_list;
  if ((uVar2 < 9) || (*(char *)p_active_screen_flag_0003e5d5 != '\x01')) {
    display_draw_list_row
              (*(undefined1 *)p_active_screen_flag_0003e5d5,
               *(undefined4 *)
                (*p_active_screen_option_ptr_array +
                (uint)*(byte *)((int)p_active_screen_index_list +
                               *(byte *)p_active_screen_state_word + 2) * 4),0);
    fixed_field_copy_and_format_dispatch(*(undefined1 *)puVar3,abStack_38);
    sVar9 = strlen_ck803s(*(undefined4 *)
                           (*puVar6 + (uint)*(byte *)((int)puVar5 + *(byte *)puVar3 + 2) * 4));
    display_draw_string_gb2312
              ((ushort)(byte)PTR_DAT_03033b50[*(byte *)puVar4],sVar9 * 0xc + 5U & 0xff,abStack_38,
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
    puVar5 = p_active_screen_option_ptr_array;
    puVar8 = p_active_screen_index_list;
    puVar4 = p_active_screen_flag_0003e5d5;
    puVar3 = p_active_screen_state_word;
    display_draw_list_row
              (*(undefined1 *)p_active_screen_flag_0003e5d5,
               *(undefined4 *)
                (*p_active_screen_option_ptr_array +
                (uint)(byte)p_active_screen_index_list[*(byte *)p_active_screen_state_word + 2] * 4)
               ,1);
    fixed_field_copy_and_format_dispatch(*(undefined1 *)puVar3,abStack_38);
    sVar9 = strlen_ck803s(*(undefined4 *)(*puVar5 + (uint)(byte)puVar8[*(byte *)puVar3 + 2] * 4));
    display_draw_string_gb2312
              ((ushort)(byte)PTR_DAT_03033d60[*(byte *)puVar4],sVar9 * 0xc + 5U & 0xff,abStack_38,0,
               0xc618);
  }
  else {
    uVar11 = (uint)*(byte *)p_active_screen_state_word;
    if (uVar11 == 0) {
      *(undefined1 *)p_active_screen_flag_0003e5d5 = 8;
      uVar11 = uVar2 - 1;
      uVar10 = uVar11 & 0xff;
      *(char *)p_active_screen_state_word = (char)uVar11;
      puVar3 = p_active_screen_option_ptr_array;
      puVar8 = p_active_screen_index_list;
      display_draw_list_row
                (8,*(undefined4 *)
                    (*p_active_screen_option_ptr_array +
                    (uint)(byte)p_active_screen_index_list[uVar10 + 2] * 4),1);
      fixed_field_copy_and_format_dispatch(uVar10,abStack_38);
      sVar9 = strlen_ck803s(*(undefined4 *)(*puVar3 + (uint)(byte)puVar8[uVar10 + 2] * 4));
      display_draw_string_gb2312
                ((ushort)(byte)PTR_DAT_03033d60[*(byte *)puVar7],sVar9 * 0xc + 5U & 0xff,abStack_38,
                 0,0xc618);
      puVar3 = p_active_screen_option_ptr_array;
      puVar8 = p_active_screen_index_list;
      uVar11 = *(byte *)puVar7 - 1 & 0xff;
      if (uVar11 != 0) {
        do {
          uVar10 = uVar10 - 1 & 0xff;
          display_draw_list_row
                    (uVar11,*(undefined4 *)(*puVar3 + (uint)(byte)puVar8[uVar10 + 2] * 4),0);
          fixed_field_copy_and_format_dispatch(uVar10,abStack_38);
          sVar9 = strlen_ck803s(*(undefined4 *)(*puVar3 + (uint)(byte)puVar8[uVar10 + 2] * 4));
          display_draw_string_gb2312
                    ((ushort)(byte)PTR_DAT_03033d64[uVar11 - 1],sVar9 * 0xc + 5U & 0xff,abStack_38,
                     0xffff,0);
          uVar11 = uVar11 - 1 & 0xff;
        } while (uVar11 != 0);
      }
    }
    else {
      uVar10 = uVar11 - 1 & 0xff;
      *(char *)p_active_screen_state_word = (char)(uVar11 - 1);
      puVar4 = p_active_screen_option_ptr_array;
      puVar8 = p_active_screen_index_list;
      display_draw_list_row
                (1,*(undefined4 *)
                    (*p_active_screen_option_ptr_array +
                    (uint)(byte)p_active_screen_index_list[uVar10 + 2] * 4),1);
      fixed_field_copy_and_format_dispatch(uVar10,abStack_38);
      sVar9 = strlen_ck803s(*(undefined4 *)(*puVar4 + (uint)(byte)puVar8[uVar10 + 2] * 4));
      puVar3 = p_active_screen_flag_0003e5d5;
      display_draw_string_gb2312
                ((ushort)(byte)PTR_DAT_03033d60[*(byte *)p_active_screen_flag_0003e5d5],
                 sVar9 * 0xc + 5U & 0xff,abStack_38,0,0xc618);
      puVar8 = p_active_screen_index_list;
      uVar10 = (uint)(byte)(*(char *)puVar3 + 1);
      if (uVar10 < 9) {
        do {
          display_draw_list_row
                    (uVar10,*(undefined4 *)(*puVar4 + (uint)(byte)puVar8[uVar11 + 2] * 4),0);
          fixed_field_copy_and_format_dispatch(uVar11,abStack_38);
          sVar9 = strlen_ck803s(*(undefined4 *)(*puVar4 + (uint)(byte)puVar8[uVar11 + 2] * 4));
          display_draw_string_gb2312
                    ((ushort)(byte)PTR_DAT_03033d64[uVar10 - 1],sVar9 * 0xc + 5U & 0xff,abStack_38,
                     0xffff,0);
          uVar10 = uVar10 + 1 & 0xff;
          uVar11 = uVar11 + 1 & 0xff;
        } while (uVar10 < 9);
      }
    }
  }
  return;
}

