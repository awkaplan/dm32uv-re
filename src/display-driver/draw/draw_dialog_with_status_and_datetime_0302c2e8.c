/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: draw_dialog_with_status_and_datetime @ 0302c2e8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 158 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: display-driver
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void draw_dialog_with_status_and_datetime(void)

{
  undefined1 *puVar1;
  undefined4 *puVar2;
  
  display_draw_dialog_panel();
  display_draw_status_bar();
  display_blit_image(0x60,0x56,0x30,0x30,PTR_DAT_0302c394);
  puVar2 = PTR_PTR_0302c3a4;
  puVar1 = p_dm32_settings_block04;
  if ((*(byte *)PTR_DAT_0302c398 & 2) == 0) {
    display_draw_number_centered
              (0x90,0,0xc618,*(uint *)PTR_PTR_0302c3a4[(byte)p_dm32_settings_block04[0x30] >> 6 & 1]
              );
    display_draw_number_centered(0xae,0,0xc618,*(uint *)(puVar2[(byte)puVar1[0x30] >> 6 & 1] + 4));
  }
  else {
    display_draw_number_centered
              (0x90,0,0xc618,PTR_PTR_0302c3a0[(byte)p_dm32_settings_block04[0x30] >> 6 & 1]);
  }
  display_fill_rect(0,0x122,0xf0,0x140,0);
  display_update_datetime(0);
  return;
}

