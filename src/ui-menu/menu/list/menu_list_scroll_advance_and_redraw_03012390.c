/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_list_scroll_advance_and_redraw @ 03012390 (file base 0x03000000; code starts at 0x03001000)
 * Size: 662 bytes
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

void menu_list_scroll_advance_and_redraw(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  byte *pbVar6;
  int *piVar7;
  short sVar8;
  uint uVar9;
  uint uVar10;
  byte *pbVar11;
  int iVar12;
  int iVar13;
  byte abStack_38 [20];
  
  pbVar11 = _p_active_screen_flag_0003e5d5;
  puVar5 = p_active_screen_option_ptr_array;
  puVar4 = p_active_screen_index_list;
  puVar3 = p_active_screen_state_word;
  puVar2 = p_active_screen_flag_0003e5d5;
  if ((*(ushort *)p_active_screen_index_list < 9) ||
     (*(char *)p_active_screen_flag_0003e5d5 != '\b')) {
    display_draw_list_row
              (*(undefined1 *)p_active_screen_flag_0003e5d5,
               *(undefined4 *)
                (*p_active_screen_option_ptr_array +
                (uint)*(byte *)((int)p_active_screen_index_list +
                               *(byte *)p_active_screen_state_word + 2) * 4),0);
    radio_telemetry_format_dispatch(*(undefined1 *)puVar3,abStack_38);
    sVar8 = strlen_ck803s(*(undefined4 *)
                           (*puVar5 + (uint)*(byte *)((int)puVar4 + *(byte *)puVar3 + 2) * 4));
    display_draw_string_gb2312
              ((ushort)(byte)PTR_DAT_03012494[*(byte *)puVar2],sVar8 * 0xc + 10U & 0xfe,abStack_38,
               0xffff,0);
    cVar1 = *(char *)puVar2;
    *(byte *)puVar2 = cVar1 + 1U;
    uVar9 = (uint)*(ushort *)puVar4;
    if ((uint)(byte)(cVar1 + 1U) == uVar9 + 1) {
      *(undefined1 *)puVar2 = 1;
    }
    puVar2 = p_active_screen_state_word;
    cVar1 = *(char *)p_active_screen_state_word;
    *(byte *)p_active_screen_state_word = cVar1 + 1U;
    if (uVar9 == (byte)(cVar1 + 1U)) {
      *(undefined1 *)puVar2 = 0;
    }
    puVar5 = p_active_screen_option_ptr_array;
    puVar4 = p_active_screen_index_list;
    puVar3 = p_active_screen_state_word;
    puVar2 = p_active_screen_flag_0003e5d5;
    display_draw_list_row
              (*(undefined1 *)p_active_screen_flag_0003e5d5,
               *(undefined4 *)
                (*p_active_screen_option_ptr_array +
                (uint)*(byte *)((int)p_active_screen_index_list +
                               *(byte *)p_active_screen_state_word + 2) * 4),1);
    radio_telemetry_format_dispatch(*(undefined1 *)puVar3,abStack_38);
    sVar8 = strlen_ck803s(*(undefined4 *)
                           (*puVar5 + (uint)*(byte *)((int)puVar4 + *(byte *)puVar3 + 2) * 4));
    display_draw_string_gb2312
              ((ushort)(byte)PTR_DAT_03012494[*(byte *)puVar2],sVar8 * 0xc + 10U & 0xfe,abStack_38,0
               ,0xc618);
  }
  else {
    uVar9 = (uint)*_p_active_screen_state_word;
    if (uVar9 == *(ushort *)p_active_screen_index_list - 1) {
      *_p_active_screen_flag_0003e5d5 = 1;
      pbVar6 = _p_active_screen_state_word;
      *_p_active_screen_state_word = 0;
      piVar7 = _p_active_screen_option_ptr_array;
      iVar12 = _p_active_screen_index_list;
      display_draw_list_row
                (1,*(undefined4 *)
                    (*_p_active_screen_option_ptr_array +
                    (uint)*(byte *)(_p_active_screen_index_list + 2) * 4),1);
      radio_telemetry_format_dispatch(*pbVar6,abStack_38);
      sVar8 = strlen_ck803s(*(undefined4 *)
                             (*piVar7 + (uint)*(byte *)(iVar12 + (uint)*pbVar6 + 2) * 4));
      display_draw_string_gb2312
                ((ushort)*(byte *)((uint)*pbVar11 + _LAB_03012650),sVar8 * 0xc + 10U & 0xfe,
                 abStack_38,0,0xc618);
      iVar12 = _LAB_03012654;
      piVar7 = _p_active_screen_option_ptr_array;
      uVar9 = (uint)(byte)(*pbVar11 + 1);
      if (uVar9 < 9) {
        iVar13 = 0;
        pbVar11 = _LAB_03012658;
        do {
          iVar13 = iVar13 + 1;
          display_draw_list_row(uVar9,*(undefined4 *)(*piVar7 + (uint)*pbVar11 * 4),0);
          radio_telemetry_format_dispatch(iVar13,abStack_38);
          sVar8 = strlen_ck803s(*(undefined4 *)(*piVar7 + (uint)*pbVar11 * 4));
          display_draw_string_gb2312
                    ((ushort)*(byte *)(iVar12 + uVar9 + -1),sVar8 * 0xc + 10U & 0xfe,abStack_38,
                     0xffff,0);
          uVar9 = uVar9 + 1 & 0xff;
          pbVar11 = pbVar11 + 1;
        } while (uVar9 < 9);
      }
    }
    else {
      uVar10 = uVar9 + 1 & 0xff;
      *_p_active_screen_state_word = (byte)(uVar9 + 1);
      piVar7 = _p_active_screen_option_ptr_array;
      iVar12 = _p_active_screen_index_list + uVar10;
      display_draw_list_row
                (8,*(undefined4 *)
                    (*_p_active_screen_option_ptr_array + (uint)*(byte *)(iVar12 + 2) * 4),1);
      radio_telemetry_format_dispatch(uVar10,abStack_38);
      sVar8 = strlen_ck803s(*(undefined4 *)(*piVar7 + (uint)*(byte *)(iVar12 + 2) * 4));
      pbVar11 = _p_active_screen_flag_0003e5d5;
      display_draw_string_gb2312
                ((ushort)*(byte *)((uint)*_p_active_screen_flag_0003e5d5 + _LAB_03012650),
                 sVar8 * 0xc + 10U & 0xfe,abStack_38,0,0xc618);
      iVar12 = _p_active_screen_index_list;
      uVar10 = *pbVar11 - 1 & 0xff;
      if (uVar10 != 0) {
        do {
          display_draw_list_row
                    (uVar10,*(undefined4 *)(*piVar7 + (uint)*(byte *)(iVar12 + uVar9 + 2) * 4),0);
          radio_telemetry_format_dispatch(uVar9,abStack_38);
          sVar8 = strlen_ck803s(*(undefined4 *)(*piVar7 + (uint)*(byte *)(iVar12 + uVar9 + 2) * 4));
          display_draw_string_gb2312
                    ((ushort)*(byte *)(_LAB_03012654 + uVar10 + -1),sVar8 * 0xc + 10U & 0xfe,
                     abStack_38,0xffff,0);
          uVar10 = uVar10 - 1 & 0xff;
          uVar9 = uVar9 - 1 & 0xff;
        } while (uVar10 != 0);
      }
    }
  }
  return;
}

