/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: scan_list_activation_commit @ 03016f4c (file base 0x03000000; code starts at 0x03001000)
 * Size: 182 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void scan_list_activation_commit(char param_1)

{
  int iVar1;
  
  scan_entry_get_mode_bits(0x13);
  if ((p_radio_mode_state_0003e318->flags_0x3 & 0x40) == 0) {
    tx_timeout_cleanup();
    iVar1 = poll_condition_group(0x13);
    if ((*(char *)PTR_DAT_03016ff8 == '\0') && (iVar1 != 0)) {
      iVar1 = get_current_mode_state1();
      if (iVar1 == 0) {
        iVar1 = zone_change_key_handler(1);
        if (iVar1 == 0) {
          ui_event_notify(0x1b);
        }
        else {
          if ((PTR_DAT_03016ffc[1] & 0x80) != 0) {
            rda5807m_fm_off();
          }
          if (*(char *)PTR_DAT_03016ff8 == '\0') {
            reentrant_state_reset_sequence();
          }
          else {
            write_field_and_mbox_post(1,100);
          }
          if (param_1 == '\x01') {
            flash_field_write_cached(0x11,0xf00,0xa5);
          }
        }
      }
      else {
        dtmf_inject_digits_2_0();
        ui_event_notify(0x19);
        if (param_1 == '\x01') {
          flash_field_write_cached(0x11,0xf00,0);
        }
        p_vfo_freq_display_state->flags_0x10 = p_vfo_freq_display_state->flags_0x10 & 0x7f;
      }
    }
    else {
      ui_event_notify(0x21);
    }
  }
  return;
}

