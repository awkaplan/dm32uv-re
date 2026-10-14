/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: display_draw_status_bar @ 03019434 (file base 0x03000000; code starts at 0x03001000)
 * Size: 338 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: display-driver
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void display_draw_status_bar(void)

{
  ushort uVar1;
  int iVar2;
  undefined1 auStack_3c [8];
  byte bStack_34;
  
  display_fill_rect(0,0,0xf0,0x1b,0);
  display_fill_rect(0,0x1a,0xf0,0x1b,0xffff);
  busy_wait_delay_loop_counted(auStack_3c);
  if (((*(byte *)PTR_DAT_03019598 & 4) != 0) && ((*(byte *)(PTR_DAT_0301959c + 0x36) & 1) != 0)) {
    if ((*(byte *)PTR_DAT_0301959c & 0x40) == 0) {
      display_blit_image(7,3,0x12,0x13,*PTR_DAT_030195a0);
    }
    else {
      display_blit_image(7,3,0x12,0x13,PTR_DAT_030195a0[1]);
    }
  }
  if ((PTR_DAT_030195a4[1] & 0x80) != 0) {
    display_blit_bitmap_1bpp
              (0x2c,3,0x11,0x33,PTR_LAB_030195a8,PTR_DAT_030195b0[(byte)p_dm32_settings_block04[99]]
              );
  }
  if (p_dm32_settings_block04[0x6e] != '\0') {
    display_blit_bitmap_1bpp(0x43,3,0x11,0x36,PTR_LAB_030195b4,0xf800);
  }
  if (p_dm32_settings_block04[0x6c] == '\x01') {
    display_blit_bitmap_1bpp
              (0x85,7,0x17,0x27,PTR_LAB_030195b8,PTR_DAT_030195b0[(byte)p_dm32_settings_block04[99]]
              );
  }
  SUBPIECE_SET(uVar1, 0, 1, p_radio_mode_state_0003e318[1].flags_0x2);
  SUBPIECE_SET(uVar1, 1, 1, p_radio_mode_state_0003e318[1].flags_0x3);
  if ((uVar1 & 0x2ff) != 0) {
    display_blit_image(0xa1,3,0x12,0x12,PTR_LAB_030195c0);
  }
  iVar2 = settings_read_dispatcher(0x10);
  if (iVar2 != 0) {
    display_blit_image(0xb8,3,0x10,0x10,PTR_LAB_030195c4);
  }
  if ((*(char *)PTR_DAT_030195c8 != '\0') &&
     (((bStack_34 & 0xf0) == 0x10 || ((bStack_34 & 0xf0) == 0x30)))) {
    display_mode_state_icon_blit_0x6b();
  }
  dialog_type_icon_draw_with_color();
  return;
}

