/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: hw_status_debounce_and_alarm_poll @ 0300e530 (file base 0x03000000; code starts at 0x03001000)
 * Size: 266 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: radio-state
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void hw_status_debounce_and_alarm_poll(void)

{
  undefined2 *puVar1;
  int iVar2;
  
  if ((*(byte *)((int)PTR_DAT_0300e5d0 + 0x1d) & 5) == 4) {
    if ((((byte)PTR_DAT_0300e5c0[0x35] >> 2 & 3) == 0) &&
       (((p_dm32_settings_block04[0x6d] & 4) == 0 ||
        ((p_radio_mode_state_0003e318[2].field_0x1 & 0x24) != 4)))) {
      if ((PTR_DAT_0300e664[3] & 2) == 0) {
        *(byte *)((int)PTR_DAT_0300e660 + 0x1d) = *(byte *)((int)PTR_DAT_0300e660 + 0x1d) & 0xfd | 2
        ;
      }
    }
    else {
      iVar2 = hw_status_bit_select_by_config_field();
      puVar1 = PTR_DAT_0300e5d0;
      if (iVar2 == 0) {
        if ((p_radio_mode_state_0003e318[2].field_0x1 & 0x20) == 0) {
          if ((ushort)PTR_DAT_0300e660[1] < 300) {
            PTR_DAT_0300e660[1] = PTR_DAT_0300e660[1] + 1;
          }
          else {
            *(byte *)((int)PTR_DAT_0300e660 + 0x1d) = *(byte *)((int)PTR_DAT_0300e660 + 0x1d) & 0xfd
            ;
          }
        }
      }
      else {
        PTR_DAT_0300e5d0[1] = 0;
        *(byte *)((int)puVar1 + 0x1d) = *(byte *)((int)puVar1 + 0x1d) & 0xfd | 2;
        if (((p_dm32_settings_block04[0x6d] & 4) != 0) &&
           ((p_radio_mode_state_0003e318[2].field_0x1 & 4) != 0)) {
          p_radio_mode_state_0003e318[2].field_0x1 =
               p_radio_mode_state_0003e318[2].field_0x1 & 0xdf | 0x20;
          alarm_banner_draw(PTR_DAT_0300e5d8[1] & 1);
          ui_event_notify(0x15);
        }
      }
    }
    iVar2 = hw_status_bit_check_by_radio_mode();
    puVar1 = PTR_DAT_0300e660;
    if (iVar2 != 0) {
      *(byte *)((int)PTR_DAT_0300e660 + 0x1d) = *(byte *)((int)PTR_DAT_0300e660 + 0x1d) & 0xfc | 1;
      *(undefined1 *)(puVar1 + 0xb) = 0;
      return;
    }
  }
  puVar1 = PTR_DAT_0300e660;
  if (99 < *(byte *)(PTR_DAT_0300e660 + 0xb)) {
    *(byte *)((int)PTR_DAT_0300e660 + 0x1d) = *(byte *)((int)PTR_DAT_0300e660 + 0x1d) & 0xfe;
    *(undefined1 *)(puVar1 + 0xb) = 0;
  }
  return;
}

