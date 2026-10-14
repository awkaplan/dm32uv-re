/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: ctcss_dcs_list_row_render @ 03031204 (file base 0x03000000; code starts at 0x03001000)
 * Size: 214 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: analog-signaling
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void ctcss_dcs_list_row_render(uint param_1,uint param_2,uint param_3)

{
  int iVar1;
  undefined2 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  byte bVar7;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined2 uStack_28;
  undefined1 uStack_26;
  
  iVar1 = p_active_screen_index_list;
  param_3 = param_3 & 0xff;
  local_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_26 = 0;
  if (param_3 != 0) {
    uVar5 = ((param_2 & 0xff) - (param_1 & 0xff)) + 1 & 0xff;
    iVar6 = 0;
    uVar4 = 0;
    bVar7 = 1;
    do {
      uVar4 = uVar4 + 1 & 0xff;
      if (uVar5 + 1 == uVar4) {
        if (*(char *)((uint)p_menu_screen_state->index_0x5 + iVar1 + 0xd5) == '\x01') {
          uVar3 = bcd_frequency_decode(PTR_LAB_030312b8 + iVar6,2);
          number_to_string_format_2args
                    (&local_30,PTR_s__d__d_030312c4,(uVar3 & 0xffff) / 10,(uVar3 & 0xffff) % 10);
        }
        else {
          uVar2 = bcd_frequency_decode(PTR_LAB_030312b4 + iVar6,2);
          if (*(char *)((uint)p_menu_screen_state->index_0x5 + iVar1 + 0xd5) == '\x02') {
            number_to_string_format_2args(&local_30,PTR_s_D_03dN_030312c8,uVar2);
          }
          else {
            number_to_string_format_2args(&local_30,PTR_s_D_03dI_030312cc,uVar2);
          }
        }
        if (uVar5 == (param_2 & 0xff)) {
          display_draw_list_row(bVar7,&local_30,1);
        }
        else {
          display_draw_list_row(bVar7,&local_30,0);
        }
        menu_icon_draw_dispatch(bVar7,uVar5);
        uVar5 = uVar5 + 1 & 0xff;
        if (param_3 <= uVar5) {
          return;
        }
        bVar7 = bVar7 + 1;
        if (8 < bVar7) {
          return;
        }
      }
      iVar6 = iVar6 + 2;
    } while (uVar4 < param_3);
  }
  return;
}

