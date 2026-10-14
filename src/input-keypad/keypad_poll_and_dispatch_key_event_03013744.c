/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: keypad_poll_and_dispatch_key_event @ 03013744 (file base 0x03000000; code starts at 0x03001000)
 * Size: 540 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: input-keypad
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void keypad_poll_and_dispatch_key_event(void)

{
  byte bVar1;
  char cVar2;
  undefined1 *puVar3;
  byte *pbVar4;
  uint uVar5;
  int iVar6;
  
  os_sem_pend_ms(_p_ucos_mutex_00039344,0);
  if (*PTR_keypad_poll_enable_word_03013834 == 0) {
    func_0x03013494();
  }
  else {
    uVar5 = keypad_scan_and_map_pressed_key();
    lcd_bus_pads_restore_after_keypad_scan();
    if (((byte)PTR_DAT_03013838[0x40c] == uVar5) || (uVar5 == 0x65)) {
      PTR_DAT_03013838[0x40d] = 0;
    }
    else {
      cVar2 = PTR_DAT_03013838[0x40d];
      PTR_DAT_03013838[0x40d] = cVar2 + 1U;
      puVar3 = PTR_DAT_03013838;
      if (1 < (byte)(cVar2 + 1U)) {
        PTR_DAT_03013838[0x40d] = 0;
        *(char *)PTR_keypad_confirmed_key_cur_0301383c = (char)uVar5;
        puVar3[0x40c] = (char)uVar5;
        key_event_state_clear_preserve_bit0();
        if ((PTR_DAT_03013840[2] & 0x10) == 0) {
          settings_set_menu_hold_interval(PTR_DAT_03013844[0x3a]);
        }
      }
    }
    cVar2 = *(char *)PTR_keypad_confirmed_key_cur_0301383c;
    if (((cVar2 == *(char *)((int)PTR_keypad_confirmed_key_cur_0301383c + 1)) &&
        ((PTR_DAT_03013840[2] & 4) == 0)) && ((PTR_DAT_03013848[0x2b] & 8) == 0)) {
      iVar6 = read_byte_field_0302e118();
      if (((iVar6 == 0) && ((*_p_call_active_flag & 8) == 0)) &&
         (uVar5 = (uint)*(byte *)PTR_keypad_confirmed_key_cur_0301383c, uVar5 != 0)) {
        bVar1 = *(byte *)PTR_DAT_03013850;
        if (bVar1 < 200) {
          *(byte *)PTR_DAT_03013850 = bVar1 + 1;
        }
        else if ((uVar5 == 2) || (uVar5 == 5)) {
          if (bVar1 < 0xcd) {
            *(byte *)PTR_DAT_03013850 = bVar1 + 1;
          }
          else {
            *_LAB_03013994 = 200;
            (*(code *)(*(uint *)(_LAB_03013998 + uVar5 * 4) & 0xfffffffe))();
          }
        }
        else if (bVar1 == 200) {
          *_LAB_03013994 = 0xc9;
          if (uVar5 == 0xd) {
            if (*_LAB_0301399c == '\x01') {
              *(byte *)(_LAB_030139a0 + 3) = *(byte *)(_LAB_030139a0 + 3) & 0xfe | 1;
              (*(code *)(*(uint *)(_LAB_03013998 + 0x34) & 0xfffffffe))();
            }
          }
          else if (uVar5 == 6) {
            if (*_LAB_0301399c == '\x01') {
              p_radio_mode_state_0003e318->flags_0x4 =
                   p_radio_mode_state_0003e318->flags_0x4 & 0xfe | 1;
              (*(code *)(*(uint *)(_LAB_03013998 + 0x18) & 0xfffffffe))();
            }
          }
          else if (uVar5 == 0xe) {
            (*(code *)(*(uint *)(_LAB_03013998 + 0x38) & 0xfffffffe))();
          }
        }
      }
    }
    else if (cVar2 == '\0') {
      if (((*(char *)((int)PTR_keypad_confirmed_key_cur_0301383c + 1) != '\0') &&
          ((*(byte *)(_DAT_030139a8 + 2) & 4) == 0)) && ((*(byte *)(_DAT_030139ac + 0x2b) & 8) == 0)
         ) {
        event_queue_reset();
        *(byte *)(_DAT_030139a8 + 4) = *(byte *)(_DAT_030139a8 + 4) & 0xf7 | 8;
        pbVar4 = _DAT_030139b4;
        (*(code *)(*(uint *)(_LAB_03013998 + (_DAT_030139b4[1] + 0x1b) * 4) & 0xfffffffe))();
        pbVar4[1] = *pbVar4;
        *_LAB_03013994 = 0;
        *(undefined1 *)(_LAB_030139a0 + 2) = 0;
      }
    }
    else if (((((*(byte *)(_DAT_030139a8 + 2) & 4) == 0) || (cVar2 == '\x03')) || (cVar2 == '\x06'))
            && (((*(byte *)(_DAT_030139ac + 0x2b) & 8) == 0 || (cVar2 == '\x06')))) {
      event_queue_reset();
      iVar6 = _DAT_030139a8;
      *(byte *)(_DAT_030139a8 + 4) = *(byte *)(_DAT_030139a8 + 4) & 0xf7 | 8;
      if ((*(byte *)(iVar6 + 2) & 0x10) == 0) {
        (*(code *)(*(uint *)(_LAB_03013998 + (uint)*_DAT_030139b4 * 4) & 0xfffffffe))();
      }
      else {
        settings_set_menu_hold_interval(*(undefined1 *)(_DAT_030139b0 + 0x3a));
        tx_gate_write_call_record(1);
      }
      _DAT_030139b4[1] = *_DAT_030139b4;
      *(undefined1 *)(_DAT_030139b8 + 9) = 0;
    }
  }
  os_sem_post(_p_ucos_mutex_00039344);
  return;
}

