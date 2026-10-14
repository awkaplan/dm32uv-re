/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: zone_up_down_toggle_handler @ 030171f0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 186 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4 zone_up_down_toggle_handler(char param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  mode_transition_cleanup();
  iVar1 = poll_condition_group(0xd);
  if (iVar1 != 0) {
    tx_timeout_cleanup();
    uVar2 = get_zone_count();
    uVar3 = (uint)(byte)p_dm32_settings_block04[0x29];
    if ((1 < uVar2) && ((p_dm32_settings_block04[0x2d] & 4) != 0)) {
      dtmf_inject_digits_2_0();
      rx_forbid_flag_conditional_clear();
      if (param_1 == '\0') {
        if (uVar3 < uVar2) {
          uVar3 = uVar3 + 1 & 0xff;
        }
        else {
          uVar3 = 1;
        }
        ui_event_notify(0x1d);
      }
      else if (param_1 == '\x01') {
        if (1 < uVar3) {
          uVar2 = uVar3 - 1 & 0xff;
        }
        uVar3 = uVar2;
        ui_event_notify(0x1e);
      }
      else if (param_1 == '\x02') {
        if (uVar3 == 1) {
          ui_event_notify(0x1e);
          uVar3 = 2;
        }
        else {
          ui_event_notify(0x1d);
          uVar3 = 1;
        }
      }
      settings_write_dispatcher(6,uVar3);
      ui_event_notify_alt(9);
      return 1;
    }
  }
  if ((p_radio_mode_state_0003e318->flags_0x3 & 0x40) == 0) {
    ui_event_notify(0x21);
  }
  return 0;
}

