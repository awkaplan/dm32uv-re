/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: vfo_ab_display_redraw_dispatch @ 030154a0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 336 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-screen
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void vfo_ab_display_redraw_dispatch(int param_1__w)

{
  char param_1 = (char)param_1__w;
  int iVar1;
  short y0;
  
  if (param_1 == '\0') {
    p_radio_mode_state_0003e318[2].field_0x1 = p_radio_mode_state_0003e318[2].field_0x1 & 0xfb;
    if ((p_dm32_settings_block04[0x2d] & 0x80) == 0) {
      p_radio_mode_state_0003e318[2].field_0x1 = p_radio_mode_state_0003e318[2].field_0x1 & 0xfe;
      p_dm32_settings_block04[0x26] = p_dm32_settings_block04[0x27];
    }
    else {
      p_radio_mode_state_0003e318[2].field_0x1 = p_radio_mode_state_0003e318[2].field_0x1 & 0xfd;
      p_dm32_settings_block04[0x26] = p_dm32_settings_block04[0x28];
    }
    p_radio_mode_state_0003e318[2].field_0x1 = p_radio_mode_state_0003e318[2].field_0x1 & 199;
    ui_event_notify(0x19);
    ui_event_notify_alt(0x1b);
  }
  else {
    p_radio_mode_state_0003e318[2].field_0x1 = p_radio_mode_state_0003e318[2].field_0x1 & 0xf3 | 4;
    if ((p_dm32_settings_block04[0x2d] & 0x80) == 0) {
      p_radio_mode_state_0003e318[2].field_0x1 = p_radio_mode_state_0003e318[2].field_0x1 & 0xfe | 1
      ;
      if (p_dm32_settings_block04[0x2a] == '\0') {
        p_dm32_settings_block04[0x2a] = 1;
      }
      p_dm32_settings_block04[0x26] = p_dm32_settings_block04[0x2a];
      y0 = 0x62;
    }
    else {
      p_radio_mode_state_0003e318[2].field_0x1 = p_radio_mode_state_0003e318[2].field_0x1 & 0xfd | 2
      ;
      if (*(char *)(_p_dm32_settings_block04 + 0x2b) == '\0') {
        *(undefined1 *)(_p_dm32_settings_block04 + 0x2b) = 1;
      }
      *(undefined1 *)(_p_dm32_settings_block04 + 0x26) =
           *(undefined1 *)(_p_dm32_settings_block04 + 0x2b);
      y0 = 0xd8;
    }
    if (*(char *)(_p_dm32_settings_block04 + 0x6c) == '\0') {
      display_fill_rect(10,0x81,0xe6,0x99,0);
      display_fill_rect(10,0x3b,0xe6,0x53,0);
    }
    else {
      display_fill_rect(0,y0,0xaa,y0 + 0x10,0);
    }
    iVar1 = _p_dm32_settings_block04;
    status_field_glyph_or_ascii_render
              (*(byte *)(_p_dm32_settings_block04 + 0x2d) >> 7,_LAB_03015608,0xffff,0);
    ui_event_notify(0x18);
    *(ushort *)&p_vfo_freq_display_state->field_0x14_0 = (ushort)*(byte *)(iVar1 + 0x26);
    ui_event_notify_alt(0x1a);
  }
  return;
}

