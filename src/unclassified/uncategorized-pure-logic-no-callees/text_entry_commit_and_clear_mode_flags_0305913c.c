/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: text_entry_commit_and_clear_mode_flags @ 0305913c (file base 0x03000000; code starts at 0x03001000)
 * Size: 74 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void text_entry_commit_and_clear_mode_flags(void)

{
  radio_mode_state_0003e318 *prVar1;
  
  *(undefined2 *)PTR_DAT_030592d0 = *(undefined2 *)p_text_entry_buffer_alias;
  *(undefined2 *)p_text_entry_current_char = *(undefined2 *)PTR_DAT_030592d4;
  prVar1 = p_radio_mode_state_0003e318;
  p_radio_mode_state_0003e318->flags_0x4 = p_radio_mode_state_0003e318->flags_0x4 & 0xf;
  prVar1->flags_0x5 = prVar1->flags_0x5 & 0x3a;
  prVar1->flags_0x6 = prVar1->flags_0x6 & 0x9b;
  return;
}

