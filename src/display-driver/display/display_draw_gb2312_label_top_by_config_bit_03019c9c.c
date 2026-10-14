/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: display_draw_gb2312_label_top_by_config_bit @ 03019c9c (file base 0x03000000; code starts at 0x03001000)
 * Size: 44 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: display-driver
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void display_draw_gb2312_label_top_by_config_bit(ushort param_1)

{
  display_draw_string_gb2312
            (0x122,0xc,
             (byte *)**(undefined4 **)
                       (PTR_PTR_03019cf8 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8),
             0xffff,param_1);
  return;
}

