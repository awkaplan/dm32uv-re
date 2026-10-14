/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: event_flags_dispatch_bit8_group @ 0305e318 (file base 0x03000000; code starts at 0x03001000)
 * Size: 420 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rtos
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void event_flags_dispatch_bit8_group(void)

{
  undefined3 uVar1;
  dialog_flags_from_flash *pdVar2;
  byte bVar3;
  int iVar4;
  
  bVar3 = get_event_flags_byte_dispatch(8);
  if ((bVar3 & 1) == 0) {
    if ((bVar3 & 2) == 0) {
      if ((bVar3 & 4) != 0) {
        update_event_flags_byte_dispatch(8,4);
        p_call_active_flag[1] = p_call_active_flag[1] & 0xfe;
        if ((*pbRam0305e64c & 2) != 0) {
          format_and_write_status_field
                    (0x2c,10,*(undefined4 *)
                              (PTR_PTR_0305e654 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 4
                              ));
        }
      }
    }
    else {
      update_event_flags_byte_dispatch(8,2);
      tx_led_or_tone_on();
    }
  }
  else {
    _p_call_active_flag[1] = _p_call_active_flag[1] & 0xfe;
    PTR_DAT_0305e47c[1] = PTR_DAT_0305e47c[1] & 0xfd;
    update_event_flags_byte_dispatch(8,1);
    tx_led_or_tone_on();
    if ((*(byte *)p_dialog_flags_from_flash & 1) != 0) {
      dialog_leave_locked_state();
    }
    if ((((*(byte *)(_SUB_0305e484 + 4) & 4) == 0) && ((PTR_DAT_0305e488[5] & 4) == 0)) &&
       (iVar4 = dialog_flags_low2bits_read(), iVar4 == 0)) {
      if ((*(byte *)PTR_DAT_0305e48c & 2) == 0) {
        format_and_write_status_field
                  (0x2d,10,**(undefined4 **)
                             (_DAT_0305e498 +
                             (*(byte *)(_p_dm32_settings_block04 + 0x30) >> 6 & 1) * 4));
        ui_event_notify(0x1b);
      }
      else {
        format_and_write_status_field
                  (0x2d,10,PTR_PTR_0305e494[*(byte *)(_p_dm32_settings_block04 + 0x30) >> 6 & 1]);
      }
    }
    if (PTR_DAT_0305e49c[0x328] != '\0') {
      PTR_DAT_0305e49c[0x328] = 0;
    }
    if ((*_p_call_active_flag & 0x40) != 0) {
      *_p_call_active_flag = *_p_call_active_flag & 0xbf;
    }
    if ((p_dialog_flags_from_flash->flags_0x1d & 1) != 0) {
      p_dialog_flags_from_flash->flags_0x1d = p_dialog_flags_from_flash->flags_0x1d & 0xfe;
    }
    if ((p_dialog_flags_from_flash->flags_0x2f & 0x70) != 0) {
      if ((p_dialog_flags_from_flash->flags_0x1 & 3) == 1) {
        if ((p_dialog_flags_from_flash->flags_0x1f & 0x78) == 8) {
          p_dialog_flags_from_flash->flags_0x1f =
               p_dialog_flags_from_flash->flags_0x1f & 0x87 | 0x28;
        }
      }
      else {
        dialog_state_set_flag_0xc(1);
        pdVar2 = p_dialog_flags_from_flash;
        p_dialog_flags_from_flash->flags_0x1f = p_dialog_flags_from_flash->flags_0x1f & 0x87 | 0x28;
        pdVar2->flags_0x1 = pdVar2->flags_0x1 & 0xfc | 1;
        uVar1 = *(undefined3 *)&p_tx_ptt_ui_state->field_0x65;
        pdVar2->field_0x28_0 = p_tx_ptt_ui_state->field_0x64_0;
        *(undefined3 *)&pdVar2->field_0x29 = uVar1;
      }
    }
  }
  return;
}

