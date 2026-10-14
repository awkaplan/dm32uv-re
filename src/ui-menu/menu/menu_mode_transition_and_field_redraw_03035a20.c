/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_mode_transition_and_field_redraw @ 03035a20 (file base 0x03000000; code starts at 0x03001000)
 * Size: 290 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-menu
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void menu_mode_transition_and_field_redraw(char param_1)

{
  undefined1 *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  puVar1 = PTR_DAT_03035b7c;
  if ((*(byte *)PTR_DAT_03035b80 & 2) == 0) {
    if (param_1 == '\x02') {
      if (PTR_DAT_03035b7c[1] != '\x02') {
        PTR_DAT_03035b7c[1] = 2;
        *puVar1 = 0;
        p_radio_mode_state_0003e318->field_0x8 =
             p_radio_mode_state_0003e318->field_0x8 & 0xbf | 0x40;
        puVar3 = PTR_PTR_03035b8c;
        uVar2 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
        *(undefined1 *)p_active_screen_option_count =
             *(undefined1 *)(PTR_PTR_03035b8c + uVar2 * 2 + 1);
        puVar3 = (undefined4 *)puVar3[uVar2 * 2];
        *p_active_screen_option_ptr_array = puVar3;
        format_and_write_status_field(2,0x14,*puVar3);
      }
    }
    else if (param_1 == '\x04') {
      if (PTR_DAT_03035b7c[1] == '\x01') {
        PTR_DAT_03035b7c[1] = 4;
        *puVar1 = 0;
        p_radio_mode_state_0003e318->field_0x8 =
             p_radio_mode_state_0003e318->field_0x8 & 0xbf | 0x40;
        puVar3 = PTR_PTR_03035b98;
        uVar2 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
        *(undefined1 *)p_active_screen_option_count =
             *(undefined1 *)(PTR_PTR_03035b98 + uVar2 * 2 + 1);
        puVar3 = (undefined4 *)puVar3[uVar2 * 2];
        *p_active_screen_option_ptr_array = puVar3;
        format_and_write_status_field(0,0x14,*puVar3);
      }
    }
    else if ((param_1 == '\0') || (param_1 == '\x03')) {
      PTR_DAT_03035b7c[1] = 0;
      *puVar1 = 0;
    }
    else if ((param_1 == '\x01') && (PTR_DAT_03035b7c[1] == '\x02')) {
      PTR_DAT_03035b7c[1] = 1;
      p_radio_mode_state_0003e318->field_0x8 = p_radio_mode_state_0003e318->field_0x8 & 0xbf | 0x40;
      puVar3 = PTR_PTR_03035b8c;
      uVar2 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
      *(undefined1 *)p_active_screen_option_count =
           *(undefined1 *)(PTR_PTR_03035b8c + uVar2 * 2 + 1);
      puVar3 = (undefined4 *)puVar3[uVar2 * 2];
      *p_active_screen_option_ptr_array = puVar3;
      format_and_write_status_field(0,0x14,*puVar3);
      display_fill_rect(0,0x122,0xf0,0x140,0);
    }
  }
  else {
    PTR_DAT_03035b7c[1] = 0;
  }
  return;
}

