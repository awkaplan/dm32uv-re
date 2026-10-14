/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: scrollable_list_menu_render_8row @ 0302e86c (file base 0x03000000; code starts at 0x03001000)
 * Size: 298 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-menu
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void scrollable_list_menu_render_8row(ushort param_1,ushort param_2,ushort param_3)

{
  undefined1 *puVar1;
  vfo_display_state *pvVar2;
  ushort uVar3;
  ushort uVar4;
  uint uVar5;
  uint3 uStack_30;
  undefined1 uStack_2d;
  uint uStack_2c;
  undefined4 uStack_28;
  
  pvVar2 = p_vfo_display_state;
  puVar1 = p_dm32_settings_block04;
  param_2 = param_2 & 0xff;
  param_3 = param_3 & 0xff;
  _uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  if (param_3 != 0) {
    uVar4 = (param_2 - (param_1 & 0xff)) + 1 & 0xff;
    uVar3 = 1;
    uVar5 = 1;
    do {
      if ((ushort)(uVar4 + 1) == uVar3) {
        if (uVar3 == 1) {
          if ((puVar1[0x30] & 0x40) == 0) {
            memcpy_bytes_iram(&uStack_30,PTR_LAB_0302e930,2);
            uStack_30 = (uint3)(ushort)uStack_30;
          }
          else {
            memcpy_bytes_iram(&uStack_30,PTR_LAB_0302e934,4);
            uStack_2c = uStack_2c & 0xffffff00;
          }
          if (uVar4 == param_2) {
            display_draw_list_row(uVar5,&uStack_30,1);
          }
          else {
            display_draw_list_row(uVar5,&uStack_30,0);
          }
          if ((pvVar2->flags_0x9 & 0x3f) == 0) {
            display_blit_bitmap_1bpp
                      (8,PTR_DAT_0302e938[uVar5 - 1],0x18,0x48,PTR_LAB_0302e93c,0xffff);
          }
        }
        else {
          flash_field_read_cached(0x11,uVar3 * 0x39 + -0x71,&uStack_30,0xb);
          if (uVar4 == param_2) {
            display_draw_list_row(uVar5,&uStack_30,1);
            memcpy_bytes_iram(p_list_row_text_buffer,&uStack_30,0xc);
          }
          else {
            display_draw_list_row(uVar5,&uStack_30,0);
          }
          if ((pvVar2->flags_0x9 & 0x3f) == uVar4) {
            display_blit_bitmap_1bpp
                      (8,PTR_DAT_0302eb04[uVar5 - 1],0x18,0x48,PTR_LAB_0302eb08,0xffff);
          }
        }
        uVar4 = uVar4 + 1 & 0xff;
        if (param_3 <= uVar4) {
          return;
        }
        uVar5 = uVar5 + 1 & 0xff;
        if (8 < uVar5) {
          return;
        }
      }
      uVar3 = uVar3 + 1 & 0xff;
    } while (uVar3 <= param_3);
  }
  return;
}

