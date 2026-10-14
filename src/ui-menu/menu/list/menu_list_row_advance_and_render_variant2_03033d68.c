/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_list_row_advance_and_render_variant2 @ 03033d68 (file base 0x03000000; code starts at 0x03001000)
 * Size: 650 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void menu_list_row_advance_and_render_variant2(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined1 *puVar7;
  short sVar8;
  uint uVar9;
  uint uVar10;
  byte *pbVar11;
  int iVar12;
  byte abStack_38 [20];
  
  puVar6 = p_active_screen_flag_0003e5d5;
  puVar5 = p_active_screen_option_ptr_array;
  puVar4 = p_active_screen_state_word;
  puVar3 = p_active_screen_flag_0003e5d5;
  puVar2 = p_active_screen_index_list;
  if ((*(ushort *)p_active_screen_index_list < 9) ||
     (*(char *)p_active_screen_flag_0003e5d5 != '\b')) {
    display_draw_list_row
              (*(undefined1 *)p_active_screen_flag_0003e5d5,
               *(undefined4 *)
                (*p_active_screen_option_ptr_array +
                (uint)*(byte *)((int)p_active_screen_index_list +
                               *(byte *)p_active_screen_state_word + 2) * 4),0);
    fixed_field_copy_and_format_dispatch(*(undefined1 *)puVar4,abStack_38);
    sVar8 = strlen_ck803s(*(undefined4 *)
                           (*puVar5 + (uint)*(byte *)((int)puVar2 + *(byte *)puVar4 + 2) * 4));
    display_draw_string_gb2312
              ((ushort)(byte)PTR_DAT_03033f34[*(byte *)puVar3],sVar8 * 0xc + 5U & 0xff,abStack_38,
               0xffff,0);
    cVar1 = *(char *)puVar3;
    *(byte *)puVar3 = cVar1 + 1U;
    uVar9 = (uint)*(ushort *)puVar2;
    if ((uint)(byte)(cVar1 + 1U) == uVar9 + 1) {
      *(undefined1 *)puVar3 = 1;
    }
    puVar2 = p_active_screen_state_word;
    cVar1 = *(char *)p_active_screen_state_word;
    *(byte *)p_active_screen_state_word = cVar1 + 1U;
    if (uVar9 == (byte)(cVar1 + 1U)) {
      *(undefined1 *)puVar2 = 0;
    }
    puVar5 = p_active_screen_option_ptr_array;
    puVar4 = p_active_screen_state_word;
    puVar3 = p_active_screen_flag_0003e5d5;
    puVar2 = p_active_screen_index_list;
    display_draw_list_row
              (*(undefined1 *)p_active_screen_flag_0003e5d5,
               *(undefined4 *)
                (*p_active_screen_option_ptr_array +
                (uint)*(byte *)((int)p_active_screen_index_list +
                               *(byte *)p_active_screen_state_word + 2) * 4),1);
    fixed_field_copy_and_format_dispatch(*(undefined1 *)puVar4,abStack_38);
    sVar8 = strlen_ck803s(*(undefined4 *)
                           (*puVar5 + (uint)*(byte *)((int)puVar2 + *(byte *)puVar4 + 2) * 4));
    display_draw_string_gb2312
              ((ushort)(byte)PTR_DAT_03033f34[*(byte *)puVar3],sVar8 * 0xc + 5U & 0xff,abStack_38,0,
               0xc618);
  }
  else {
    uVar9 = (uint)*(byte *)p_active_screen_state_word;
    if (uVar9 == *(ushort *)p_active_screen_index_list - 1) {
      *(undefined1 *)p_active_screen_flag_0003e5d5 = 1;
      puVar2 = p_active_screen_state_word;
      *(undefined1 *)p_active_screen_state_word = 0;
      puVar3 = p_active_screen_option_ptr_array;
      puVar7 = p_active_screen_index_list;
      display_draw_list_row
                (1,*(undefined4 *)
                    (*p_active_screen_option_ptr_array +
                    (uint)(byte)p_active_screen_index_list[2] * 4),1);
      fixed_field_copy_and_format_dispatch(*(undefined1 *)puVar2,abStack_38);
      sVar8 = strlen_ck803s(*(undefined4 *)(*puVar3 + (uint)(byte)puVar7[*(byte *)puVar2 + 2] * 4));
      display_draw_string_gb2312
                ((ushort)(byte)PTR_DAT_03034104[*(byte *)puVar6],sVar8 * 0xc + 5U & 0xff,abStack_38,
                 0,0xc618);
      puVar3 = PTR_DAT_0303410c;
      puVar2 = p_active_screen_option_ptr_array;
      uVar9 = (uint)(byte)(*(char *)puVar6 + 1);
      if (uVar9 < 9) {
        iVar12 = 0;
        pbVar11 = PTR_DAT_03034108;
        do {
          iVar12 = iVar12 + 1;
          display_draw_list_row(uVar9,*(undefined4 *)(*puVar2 + (uint)*pbVar11 * 4),0);
          fixed_field_copy_and_format_dispatch(iVar12,abStack_38);
          sVar8 = strlen_ck803s(*(undefined4 *)(*puVar2 + (uint)*pbVar11 * 4));
          display_draw_string_gb2312
                    ((ushort)*(byte *)((int)puVar3 + (uVar9 - 1)),sVar8 * 0xc + 5U & 0xff,abStack_38
                     ,0xffff,0);
          uVar9 = uVar9 + 1 & 0xff;
          pbVar11 = pbVar11 + 1;
        } while (uVar9 < 9);
      }
    }
    else {
      uVar10 = uVar9 + 1 & 0xff;
      *(char *)p_active_screen_state_word = (char)(uVar9 + 1);
      puVar4 = p_active_screen_option_ptr_array;
      puVar2 = p_active_screen_index_list;
      display_draw_list_row
                (8,*(undefined4 *)
                    (*p_active_screen_option_ptr_array +
                    (uint)*(byte *)((int)p_active_screen_index_list + uVar10 + 2) * 4),1);
      fixed_field_copy_and_format_dispatch(uVar10,abStack_38);
      sVar8 = strlen_ck803s(*(undefined4 *)(*puVar4 + (uint)*(byte *)((int)puVar2 + uVar10 + 2) * 4)
                           );
      puVar3 = p_active_screen_flag_0003e5d5;
      display_draw_string_gb2312
                ((ushort)(byte)PTR_DAT_03033f34[*(byte *)p_active_screen_flag_0003e5d5],
                 sVar8 * 0xc + 5U & 0xff,abStack_38,0,0xc618);
      puVar2 = p_active_screen_index_list;
      uVar10 = *(byte *)puVar3 - 1 & 0xff;
      if (uVar10 != 0) {
        do {
          display_draw_list_row
                    (uVar10,*(undefined4 *)(*puVar4 + (uint)*(byte *)((int)puVar2 + uVar9 + 2) * 4),
                     0);
          fixed_field_copy_and_format_dispatch(uVar9,abStack_38);
          sVar8 = strlen_ck803s(*(undefined4 *)
                                 (*puVar4 + (uint)*(byte *)((int)puVar2 + uVar9 + 2) * 4));
          display_draw_string_gb2312
                    ((ushort)(byte)PTR_DAT_03033f38[uVar10 - 1],sVar8 * 0xc + 5U & 0xff,abStack_38,
                     0xffff,0);
          uVar10 = uVar10 - 1 & 0xff;
          uVar9 = uVar9 - 1 & 0xff;
        } while (uVar10 != 0);
      }
    }
  }
  return;
}

