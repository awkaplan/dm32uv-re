/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: text_entry_status_glyph_set_by_settings_flags_a @ 030596d8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 54 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void text_entry_status_glyph_set_by_settings_flags_a(void)

{
  if ((p_dm32_settings_block04[0x2d] & 0x80) == 0) {
    *(undefined2 *)PTR_DAT_030597b4 = 0x3b;
  }
  else {
    *(undefined2 *)PTR_DAT_030597b4 = 0xb1;
  }
  if (p_dm32_settings_block04[0x6c] == '\0') {
    *(undefined2 *)PTR_DAT_030597b4 = 0x59;
  }
  *(undefined2 *)p_text_entry_current_char = 0x8a;
  return;
}

