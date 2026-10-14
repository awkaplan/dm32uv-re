/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_field_write_and_notify @ 030312fc (file base 0x03000000; code starts at 0x03001000)
 * Size: 154 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void channel_field_write_and_notify(int param_1__w,int param_2__w)

{
  char param_1 = (char)param_1__w;
  undefined2 param_2 = (undefined2)param_2__w;
  undefined4 uVar1;
  undefined2 local_18 [2];
  short local_14;
  undefined1 local_12 [2];
  undefined1 local_10;
  undefined1 uStack_f;
  undefined1 uStack_e;
  undefined1 uStack_d;
  
  local_18[0] = param_2;
  os_sem_pend_ms(p_ucos_mutex_0003e330,0);
  memcpy_bytes_iram(&local_10,local_18,2);
  uVar1 = channel_list_index_resolve(p_dm32_settings_block04[0x29],p_dm32_settings_block04[0x26]);
  channel_num_to_block_offset(uVar1,local_12,&local_14);
  if (param_1 == '\x02') {
    uStack_e = local_10;
    uStack_d = uStack_f;
    flash_block_write(local_12[0],local_14 + 0x11,&local_10,4);
  }
  else {
    if (param_1 == '\x01') {
      local_14 = local_14 + 0x13;
    }
    else {
      local_14 = local_14 + 0x11;
    }
    flash_block_write(local_12[0],local_14,&local_10,2);
  }
  os_sem_post(p_ucos_mutex_0003e330);
  if ((PTR_DAT_03031488[3] & 2) == 0) {
    ui_event_notify_alt(8);
  }
  return;
}

