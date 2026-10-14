/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: character_input_event_dispatcher @ 03039810 (file base 0x03000000; code starts at 0x03001000)
 * Size: 186 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: input-keypad
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void character_input_event_dispatcher(char param_1)

{
  int iVar1;
  
  iVar1 = settings_read_dispatcher(param_1);
  if (param_1 == '!') {
    if ((p_dm32_settings_block04[0x43] & 1) != 0) {
      write_event_record_and_notify(iVar1 + 5U & 0xff,p_dm32_settings_block04[0x49]);
    }
  }
  else if (param_1 == '#') {
    if ((p_dm32_settings_block04[0x43] & 2) != 0) {
      write_event_record_and_notify(iVar1,p_dm32_settings_block04[0x4b]);
    }
  }
  else if (param_1 == '%') {
    if ((p_dm32_settings_block04[0x43] & 4) != 0) {
      write_event_record_and_notify(iVar1,p_dm32_settings_block04[0x4d]);
    }
  }
  else if (param_1 == '\'') {
    if ((p_dm32_settings_block04[0x43] & 8) != 0) {
      write_event_record_and_notify(iVar1,p_dm32_settings_block04[0x4f]);
    }
  }
  else if ((param_1 == ')') && ((p_dm32_settings_block04[0x43] & 0x10) != 0)) {
    write_event_record_and_notify(iVar1 + 10U & 0xff,p_dm32_settings_block04[0x51]);
  }
  return;
}

