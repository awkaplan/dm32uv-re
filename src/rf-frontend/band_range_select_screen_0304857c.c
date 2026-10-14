/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: band_range_select_screen @ 0304857c (file base 0x03000000; code starts at 0x03001000)
 * Size: 480 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rf-frontend
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void band_range_select_screen(void)

{
  char cVar1;
  int *piVar2;
  undefined4 *puVar3;
  
  if (*(char *)PTR_active_screen_subtype_030486b0 == '\x1b') {
    display_fill_screen(0);
    gps_position_display_screen();
  }
  else {
    display_draw_dialog_panel();
    cVar1 = *(char *)PTR_active_screen_subtype_030486b0;
    puVar3 = PTR_DAT_030486c4;
    if (((cVar1 != '\x1d') && (puVar3 = (undefined4 *)PTR_DAT_030486c8, cVar1 != ',')) &&
       (puVar3 = (undefined4 *)PTR_DAT_030486bc, cVar1 == '-')) {
      puVar3 = PTR_DAT_030486c0;
    }
    if ((p_radio_mode_state_0003e318->field_0x9 & 1) == 0) {
      display_blit_image(0x60,0x56,0x30,0x30,puVar3);
    }
    else {
      display_blit_image(0x60,0x38,0x30,0x30,puVar3);
    }
    piVar2 = p_active_screen_option_ptr_array;
    if ((p_radio_mode_state_0003e318->field_0x8 & 0x40) == 0) {
      if ((p_radio_mode_state_0003e318->field_0x9 & 1) == 0) {
        display_draw_number_centered(0x90,0,0xc618,DAT_030488a0);
      }
      else {
        display_draw_number_centered(0x6a,0xf800,0xc618,(uint)PTR_s__d__d_030486dc);
        display_draw_number_centered(0x88,0,0xc618,*(uint *)*p_active_screen_option_ptr_array);
        puVar3 = p_active_screen_option_ptr_array;
        cVar1 = *(char *)PTR_DAT_030486e0;
        if (cVar1 == '\x01') {
          display_draw_number_centered(0xa1,0,0xc618,(uint)PTR_s_144_148_03048880);
          display_draw_number_centered(0xba,0,0xc618,(uint)PTR_s_430_450_03048888);
        }
        else if (cVar1 == '\0') {
          display_draw_number_centered(0xa1,0,0xc618,(uint)PTR_s_144_148_03048880);
          display_draw_number_centered(0xba,0,0xc618,(uint)PTR_s_420_450_03048884);
        }
        else if (cVar1 == '\x02') {
          display_draw_number_centered(0xa1,0,0xc618,(uint)PTR_s_144_146_0304888c);
          display_draw_number_centered(0xba,0,0xc618,(uint)PTR_s_430_440_03048890);
        }
        else if (cVar1 == '\x03') {
          display_draw_number_centered(0xa1,0,0xc618,(uint)PTR_s_144_148_03048880);
          display_draw_number_centered(0xba,0,0xc618,(uint)PTR_s_420_440_03048894);
        }
        else {
          display_draw_number_centered
                    (0xa1,0,0xc618,*(uint *)(*p_active_screen_option_ptr_array + 4));
          display_draw_number_centered(0xba,0,0xc618,*(uint *)(*puVar3 + 8));
        }
        p_radio_mode_state_0003e318->field_0x9 = p_radio_mode_state_0003e318->field_0x9 & 0xfe;
      }
    }
    else if (*(char *)p_active_screen_option_count == '\x01') {
      display_draw_number_centered(0x90,0,0xc618,*(uint *)*p_active_screen_option_ptr_array);
    }
    else {
      display_draw_number_centered(0x90,0,0xc618,*(uint *)*p_active_screen_option_ptr_array);
      display_draw_number_centered(0xae,0,0xc618,*(uint *)(*piVar2 + 4));
    }
  }
  return;
}

