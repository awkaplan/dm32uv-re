/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: status_message_save_on_confirm @ 03035b44 (file base 0x03000000; code starts at 0x03001000)
 * Size: 56 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-screen
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void status_message_save_on_confirm(void)

{
  undefined1 *puVar1;
  
  puVar1 = PTR_DAT_03035b7c;
  if (PTR_DAT_03035b7c[1] == '\x02') {
    PTR_DAT_03035b7c[1] = 0;
    *puVar1 = 0;
    p_radio_mode_state_0003e318->field_0x8 = p_radio_mode_state_0003e318->field_0x8 & 0xbf;
    format_and_write_status_field
              (0,10,**(undefined4 **)
                      (PTR_PTR_03035b9c + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
  }
  return;
}

