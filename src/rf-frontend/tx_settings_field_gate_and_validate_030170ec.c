/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: tx_settings_field_gate_and_validate @ 030170ec (file base 0x03000000; code starts at 0x03001000)
 * Size: 146 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rf-frontend
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void tx_settings_field_gate_and_validate(undefined1 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  mode_transition_cleanup();
  vfo_active_side_mode_nibble();
  if ((p_radio_mode_state_0003e318->flags_0x3 & 0x40) == 0) {
    iVar2 = poll_condition_group(10);
    if ((*(char *)PTR_DAT_03017184 == '\0') && (iVar2 != 0)) {
      if ((PTR_DAT_0301717c[1] & 0x80) != 0) {
        rda5807m_fm_off();
      }
      puVar1 = PTR_DAT_03017188;
      settings_block4_5byte_array_read(param_1,PTR_DAT_03017188);
      iVar2 = protocol_command_byte_dispatch(*puVar1,*(undefined1 *)(puVar1 + 1));
      if (iVar2 == 0) {
        ui_event_notify(0x21);
      }
      else if ((byte)(PTR_DAT_030172d0[3] - 1) < 2) {
        ui_event_notify(0x18);
        write_field_and_mbox_post(1,0x2b);
      }
    }
    else {
      ui_event_notify(0x21);
    }
  }
  return;
}

