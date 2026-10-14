/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: tx_gate_write_call_record @ 030134c4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 124 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: dmr-protocol
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void tx_gate_write_call_record(int param_1__w)

{
  char param_1 = (char)param_1__w;
  int iVar1;
  
  if (((((*(byte *)PTR_DAT_03013558 & 2) == 0) &&
       ((p_radio_mode_state_0003e318->field_0x8 & 4) == 0)) &&
      ((p_radio_mode_state_0003e318->flags_0x7 & 0x80) == 0)) &&
     ((p_radio_mode_state_0003e318->field_0x8 & 0x1b) == 0)) {
    *(undefined1 *)PTR_DAT_03013560 = 2;
    settings_read_dispatcher(0x1e);
    iVar1 = settings_read_dispatcher(0x11);
    if (iVar1 == 1) {
      if (param_1 == '\x01') {
        write_event_record_and_notify
                  (p_dm32_settings_block04[0x48] + '\x10',p_dm32_settings_block04[0x47]);
      }
      else {
        write_event_record_and_notify(0x21,p_dm32_settings_block04[0x47]);
      }
      *(char *)((int)PTR_DAT_03013560 + 1) = param_1;
    }
    *(undefined1 *)PTR_DAT_03013560 = 1;
  }
  return;
}

