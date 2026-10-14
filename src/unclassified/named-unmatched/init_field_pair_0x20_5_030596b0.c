/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: init_field_pair_0x20_5 @ 030596b0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 32 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void init_field_pair_0x20_5(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  *(undefined1 *)PTR_DAT_030597b0 = 0;
  puVar1 = PTR_DAT_030597b4;
  *(undefined2 *)p_text_entry_buffer_alias = *(undefined2 *)PTR_DAT_030597b4;
  puVar2 = p_text_entry_current_char;
  *(undefined2 *)PTR_DAT_030597c0 = *(undefined2 *)p_text_entry_current_char;
  *(undefined2 *)puVar1 = 0x20;
  *(undefined2 *)puVar2 = 5;
  return;
}

