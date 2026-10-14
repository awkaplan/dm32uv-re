/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_change_apply_with_zone_and_flash_validate @ 03058180 (file base 0x03000000; code starts at 0x03001000)
 * Size: 308 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void channel_change_apply_with_zone_and_flash_validate(void)

{
  radio_mode_state_0003e318 *prVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  ushort uVar4;
  int iVar5;
  undefined2 local_12;
  undefined1 auStack_10 [4];
  
  local_12 = 1;
  uVar4 = flash_block_id_resolve_locked(0x12);
  puVar2 = PTR_DAT_030582b8;
  flash_block_read(uVar4,0,PTR_DAT_030582b8,2);
  if (4000 < *(ushort *)puVar2) {
    prVar1 = p_radio_mode_state_0003e318;
    prVar1[1].field_0x8 = 0xa0;
    prVar1[1].field_0x9 = 0xf;
  }
  if ((p_dm32_settings_block04[0x2d] & 4) != 0) {
    iVar5 = keypad_dispatch_not_inhibited();
    if (iVar5 == 0) {
      uVar4 = flash_block_id_resolve_locked(4);
      flash_block_read(uVar4,0xf01,auStack_10,1);
      flash_block_read(uVar4,0xf02,&local_12,2);
      puVar3 = p_dm32_settings_block04;
      p_dm32_settings_block04[0x60] = (undefined1)local_12;
      puVar3[0x61] = SUBPIECE(local_12, 1, 1);
      PTR_DAT_030582c4[8] = PTR_DAT_030582c4[8] & 0xfe;
    }
    else {
      local_12 = channel_list_index_resolve
                           (p_dm32_settings_block04[0x29],p_dm32_settings_block04[0x26]);
    }
  }
  if (((PTR_DAT_030582c4[8] & 1) == 0) || (iVar5 = keypad_dispatch_not_inhibited(), iVar5 == 0)) {
    channel_change_apply_dispatcher(local_12,1);
    mmio_11000074_bits78_set_from_status_nibble();
    if ((p_radio_mode_state_0003e318->flags_0x3 & 0x40) == 0) {
      radio_mode_dispatcher_char(1,0);
      iVar5 = keypad_dispatch_not_inhibited();
      if (((iVar5 != 0) && (zone_change_key_handler(0), (p_dm32_settings_block04[0x43] & 0x20) != 0)
          ) && ((p_dm32_settings_block04[0x2d] & 4) != 0)) {
        write_event_record_and_notify(0x27,p_dm32_settings_block04[0x26]);
      }
    }
    else if (((p_dm32_settings_block04[0x5d] & 1) != 0) &&
            (iVar5 = keypad_dispatch_not_inhibited(), iVar5 != 0)) {
      ui_event_notify(0x20);
    }
  }
  return;
}

