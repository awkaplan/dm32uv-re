/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: tick_counter_and_event_log @ 0301b9dc (file base 0x03000000; code starts at 0x03001000)
 * Size: 88 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rtos
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void tick_counter_and_event_log(void)

{
  char cVar1;
  
  if ((((p_radio_mode_state_0003e318->flags_0x7 & 4) != 0) &&
      (cVar1 = *(char *)PTR_DAT_0301bb18, *(byte *)PTR_DAT_0301bb18 = cVar1 + 1U,
      9 < (byte)(cVar1 + 1U))) &&
     (*(undefined1 *)PTR_DAT_0301bb18 = 0, (p_dm32_settings_block04[0x44] & 1) != 0)) {
    if ((p_dm32_settings_block04[0x43] & 0x20) == 0) {
      write_event_record_and_notify(0x26,0);
    }
    else {
      write_event_record_and_notify(0x27,0x4c);
    }
  }
  return;
}

