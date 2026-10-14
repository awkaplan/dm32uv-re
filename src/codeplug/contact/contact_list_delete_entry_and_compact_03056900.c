/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: contact_list_delete_entry_and_compact @ 03056900 (file base 0x03000000; code starts at 0x03001000)
 * Size: 190 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void contact_list_delete_entry_and_compact(char param_1,uint param_2)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  undefined1 auStack_98 [128];
  short local_18;
  undefined1 local_16 [2];
  
  param_2 = param_2 & 0xff;
  if (*(byte *)PTR_DAT_030569c4 < 2) {
    dialog_show_icon_and_number(0,PTR_PTR_030569d0[(byte)p_dm32_settings_block04[0x30] >> 6 & 1]);
  }
  else {
    channel_offset_minus_0x10(param_1 + '\x01',local_16,&local_18);
    flash_field_read_cached(local_16[0],local_18 + 0x11,auStack_98,0x80);
    memcpy_bytes_iram(auStack_98 + param_2 * 2,auStack_98 + (param_2 + 1) * 2,(0x3f - param_2) * 2);
    flash_block_write(local_16[0],local_18 + 0x11,auStack_98,0x80);
    puVar1 = PTR_DAT_030569c4;
    *(char *)PTR_DAT_030569c4 = *(char *)PTR_DAT_030569c4 + -1;
    flash_block_write(local_16[0],local_18 + 0x10,puVar1,1);
    puVar2 = p_dm32_settings_block04;
    p_dm32_settings_block04[0x27] = 1;
    puVar2[0x28] = 1;
    contact_record_copy_with_limit((byte)puVar2[0x2d] >> 7);
    vfo_load_side_config();
    dialog_show_icon_and_number
              (1,**(undefined4 **)(PTR_PTR_030569cc + ((byte)puVar2[0x30] >> 6 & 1) * 8));
  }
  return;
}

