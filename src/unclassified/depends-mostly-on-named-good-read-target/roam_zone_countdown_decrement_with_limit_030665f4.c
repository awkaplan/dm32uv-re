/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: roam_zone_countdown_decrement_with_limit @ 030665f4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 146 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void roam_zone_countdown_decrement_with_limit(uint param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_24 [16];
  
  param_2 = param_2 & 0xff;
  if (*(byte *)PTR_DAT_0306666c < 2) {
    dialog_show_icon_and_number(0,PTR_PTR_03066728[(byte)p_dm32_settings_block04[0x30] >> 6 & 1]);
  }
  else {
    iVar1 = (param_1 & 0xff) * 0x21;
    iVar2 = iVar1 + 0x21;
    flash_field_read_cached(0x65,iVar2,auStack_24,0x10);
    memcpy_bytes_iram(auStack_24 + param_2,auStack_24 + param_2 + 1,0xf - param_2);
    flash_block_write(0x65,iVar2,auStack_24,0x10);
    *(char *)PTR_DAT_0306666c = *(char *)PTR_DAT_0306666c + -1;
    flash_field_write_cached(0x65,iVar1 + 0x20);
    roam_zone_record_init();
    dialog_show_icon_and_number
              (1,**(undefined4 **)
                   (PTR_PTR_0306667c + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
  }
  return;
}

