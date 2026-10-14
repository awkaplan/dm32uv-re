/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: event_record_guarded_by_state_flags @ 03013568 (file base 0x03000000; code starts at 0x03001000)
 * Size: 112 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void event_record_guarded_by_state_flags(void)

{
  int iVar1;
  
  if (((((*(byte *)PTR_DAT_03013600 & 2) == 0) &&
       ((p_radio_mode_state_0003e318->field_0x8 & 4) == 0)) &&
      ((p_radio_mode_state_0003e318->flags_0x7 & 0x80) == 0)) &&
     ((((p_radio_mode_state_0003e318->field_0x8 & 0x1b) == 0 &&
       (*(char *)PTR_DAT_03013608 == '\x02')) &&
      (iVar1 = settings_read_dispatcher(0x11), iVar1 == 1)))) {
    if (*(char *)((int)PTR_DAT_03013608 + 1) == '\x01') {
      write_event_record_and_notify
                (p_dm32_settings_block04[0x48] + '\x10',p_dm32_settings_block04[0x47]);
    }
    else {
      write_event_record_and_notify(0x21,p_dm32_settings_block04[0x47]);
    }
  }
  return;
}

