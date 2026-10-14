/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: key_shortcut_dispatch_gate_list @ 030413c8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 54 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: input-keypad
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void key_shortcut_dispatch_gate_list(void)

{
  if (*(char *)PTR_active_screen_subtype_0304141c == '/') {
    PTR_DAT_03041420[0x5d] = PTR_DAT_03041420[0x5d] & 0xfe | 1;
    write_status_mode_byte_pair(*(undefined1 *)((uint)(byte)PTR_DAT_03041424[2] + DAT_03041428),0);
  }
  else {
    key_shortcut_dispatch_table_list_screens();
  }
  return;
}

