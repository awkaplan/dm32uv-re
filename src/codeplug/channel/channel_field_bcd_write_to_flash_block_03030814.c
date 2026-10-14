/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_field_bcd_write_to_flash_block @ 03030814 (file base 0x03000000; code starts at 0x03001000)
 * Size: 176 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void channel_field_bcd_write_to_flash_block(uint param_1,int param_2)

{
  undefined4 uVar1;
  uint uVar2;
  byte *pbVar3;
  short local_18;
  undefined1 local_16 [2];
  byte local_14 [4];
  
  os_sem_pend_ms(p_ucos_mutex_0003e330,0);
  pbVar3 = local_14;
  do {
    uVar2 = (param_1 % 100) / 10;
    *pbVar3 = (char)(param_1 % 100) + (char)uVar2 * -10 | (byte)(uVar2 << 4);
    pbVar3 = pbVar3 + 1;
    param_1 = param_1 / 100;
  } while (pbVar3 != &stack0xfffffff0);
  uVar1 = channel_list_index_resolve(p_dm32_settings_block04[0x29],p_dm32_settings_block04[0x26]);
  channel_num_to_block_offset(uVar1,local_16,&local_18);
  if (param_2 != 0) {
    local_18 = local_18 + 4;
  }
  flash_block_write(local_16[0],local_18,local_14,4);
  os_sem_post(p_ucos_mutex_0003e330);
  if ((PTR_DAT_030308d4[3] & 2) == 0) {
    ui_event_notify_alt(8);
  }
  return;
}

