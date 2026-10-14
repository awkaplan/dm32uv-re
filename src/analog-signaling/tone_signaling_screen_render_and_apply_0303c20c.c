/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: tone_signaling_screen_render_and_apply @ 0303c20c (file base 0x03000000; code starts at 0x03001000)
 * Size: 138 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: analog-signaling
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Removing unreachable block (ram,0x0303c842) */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void tone_signaling_screen_render_and_apply(void)

{
  char cVar1;
  byte bVar2;
  
  display_fill_screen(0);
  display_draw_number_centered
            (0x28,0xffff,0,
             *(uint *)(PTR_PTR_0303c3cc[((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 2] +
                      (uint)*(byte *)((uint)p_menu_screen_state->index_0x2 + DAT_0303c3c8 + 2) * 4))
  ;
  display_blit_bitmap_1bpp(0x68,0x50,0x20,0x88);
  if ((PTR_DAT_0303c3d4[4] & 2) == 0) {
    ctcss_tone_freq_display(DAT_0303c3d8);
  }
  else {
    dcs_code_display_normal_invert(DAT_0303c3d8);
  }
  bVar2 = tone_signaling_type_classify(*(undefined2 *)&p_vfo_display_state->field_0x11_0);
  PTR_DAT_0303c3e0[0x35] = PTR_DAT_0303c3e0[0x35] & 0xf3 | (bVar2 & 3) << 2;
  rf_channel_mode_select_and_apply();
  cVar1 = *(char *)PTR_active_screen_subtype_0303c950;
  if (((((((cVar1 != '\b') && (cVar1 != '\x05')) && (cVar1 != '\x06')) &&
        ((cVar1 != '\x04' && (cVar1 != '\x18')))) &&
       ((cVar1 != '\x03' && ((cVar1 != '\n' && (cVar1 != '\x17')))))) && (cVar1 != '%')) &&
     ((cVar1 != '/' && ((cVar1 != '\x16' || (*(char *)PTR_DAT_0303c954 != '\x01')))))) {
    signal_level_bargraph_mode_select();
  }
  OSTmr_state_dispatch_callback(p_ucos_tmr_inputcursor,0,0,&stack0x00000020);
  return;
}

