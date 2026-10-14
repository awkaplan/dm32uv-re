/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: standby_screen_refresh @ 03018e64 (file base 0x03000000; code starts at 0x03001000)
 * Size: 106 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void standby_screen_refresh(void)

{
  undefined1 *puVar1;
  undefined2 *puVar2;
  
  display_fill_rect(0,0x122,0xf0,0x140,0);
  puVar2 = PTR_DAT_03019058;
  puVar1 = p_dm32_settings_block04;
  display_draw_string_gb2312
            (0x122,0xc,
             (byte *)**(undefined4 **)
                       (PTR_PTR_03019054 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8),
             PTR_DAT_03019058[(byte)p_dm32_settings_block04[99]],0);
  display_blit_bitmap_1bpp(200,0x125,0x1c,0x44,PTR_LAB_0301905c,puVar2[(byte)puVar1[99]]);
  display_update_datetime(1);
  return;
}

