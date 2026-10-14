/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: ptt_id_status_screen_render @ 0301ad00 (file base 0x03000000; code starts at 0x03001000)
 * Size: 480 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: input-keypad
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void ptt_id_status_screen_render(void)

{
  char cVar1;
  int iVar2;
  byte bVar3;
  undefined1 auStack_1c [15];
  undefined1 uStack_d;
  undefined2 auStack_c [2];
  
  display_fill_rect(0x17,0x32,0xd9,0xd2,0);
  draw_rect_outline_mutex_guarded(0x17,0xd9,0x32,0xd2,0xffff);
  cVar1 = *(char *)(PTR_DAT_0301adf8 + 1);
  if ((cVar1 == '\0') || (cVar1 == '\x03')) {
    display_blit_image(0x41,0x47,0x30,0x30,PTR_LAB_0301adfc);
  }
  else if (cVar1 == '\x01') {
    display_blit_image(0x41,0x47,0x30,0x30,PTR_LAB_0301ae00);
  }
  else {
    display_blit_image(0x41,0x47,0x30,0x30,PTR_LAB_0301ae04);
  }
  display_blit_image(0x70,0x37,0x40,0x40,PTR_LAB_0301ae08);
  display_blit_image(0x90,0x3f,0x17,0x17,PTR_LAB_0301ae0c);
  if ((*(byte *)PTR_DAT_0301adf8 & 0x40) == 0) {
    bVar3 = p_vfo_display_state->field_0x16 & 0xe;
    if (bVar3 == 8) {
      iVar2 = bdc_table_lookup_by_id(*_LAB_0301af1c,auStack_c);
      if (iVar2 == 0) {
        number_to_string_format_2args(auStack_1c,_LAB_0301af20,*_LAB_0301af1c);
      }
      else {
        bdc_table_read_by_index(auStack_c[0],auStack_1c);
        uStack_d = 0;
      }
      display_draw_number_centered(0x81,0xffff,0,_LAB_0301af24);
      display_draw_number_centered(0x9f,0xffff,0,(uint)auStack_1c);
    }
    else if (bVar3 == 4) {
      p_radio_mode_state_0003e318[2].flags_0x2 = p_radio_mode_state_0003e318[2].flags_0x2 & 0xfe | 1
      ;
      p_dialog_flags_from_flash->flags_0x2d = p_dialog_flags_from_flash->flags_0x2d & 0xf3 | 0xc;
      *_DAT_0301af30 = *_DAT_0301af30 & 0x7f | 0x80;
      display_draw_number_centered
                (0x9f,0xffff,0,
                 *(uint *)(*(int *)(_DAT_0301af38 +
                                   (*(byte *)(_p_dm32_settings_block04 + 0x30) >> 6 & 1) * 4) + 0x28
                          ));
    }
    else {
      if (_DAT_0301af30[4] < 3) {
        display_draw_number_centered
                  (0x81,0xffff,0,
                   *(uint *)(*(int *)(_DAT_0301af3c +
                                     (*(byte *)(_p_dm32_settings_block04 + 0x30) >> 6 & 1) * 4) +
                            (uint)_DAT_0301af30[4] * 4));
      }
      else {
        display_draw_number_centered(0x81,0xffff,0,_LAB_0301af24);
      }
      display_draw_number_centered(0x9f,0xffff,0,_DAT_0301af40);
    }
  }
  else {
    if ((p_dialog_flags_from_flash->flags_0x1 & 8) == 0) {
      p_dialog_flags_from_flash->flags_0x1 = p_dialog_flags_from_flash->flags_0x1 & 0xf7 | 8;
      ui_event_notify(0x16);
      display_draw_number_centered
                (0x9f,0xffff,0,PTR_PTR_0301ae14[(byte)p_dm32_settings_block04[0x30] >> 6 & 1]);
    }
    *(byte *)PTR_DAT_0301adf8 = *(byte *)PTR_DAT_0301adf8 & 0xbf;
  }
  _DAT_0301af30[5] = 0;
  p_radio_mode_state_0003e318[2].flags_0x2 = p_radio_mode_state_0003e318[2].flags_0x2 & 0xfe | 1;
  return;
}

