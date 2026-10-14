/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: battery_percentage_display_update @ 0301ba34 (file base 0x03000000; code starts at 0x03001000)
 * Size: 104 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: peripheral-adc
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void battery_percentage_display_update(void)

{
  int iVar1;
  uint uVar2;
  undefined1 auStack_10 [8];
  
  display_draw_number_centered
            (100,0xffff,0,
             *(uint *)(PTR_PTR_0301bb20[((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 2] + 8));
  iVar1 = adc_read_channel_dispatch(2);
  uVar2 = (iVar1 * 100) / (int)(((uint)(ushort)PTR_DAT_0301bb24[0x17] * 10) / 0x4b) & 0xffff;
  number_to_string_format_2args(auStack_10,_DAT_0301bb28,uVar2 / 100,uVar2 % 100);
  display_draw_number_centered(0x82,0xffff,0,(uint)auStack_10);
  return;
}

