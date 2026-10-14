/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: text_entry_field_init_and_wrap_calc @ 0305ba00 (file base 0x03000000; code starts at 0x03001000)
 * Size: 72 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void text_entry_field_init_and_wrap_calc(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  if ((*(char *)((int)PTR_DAT_0305ba58 + 3) == '\0') && (*(char *)PTR_DAT_0305ba58 != '\x03')) {
    *(undefined1 *)PTR_DAT_0305ba58 = 3;
  }
  puVar2 = PTR_DAT_0305ba50;
  *(undefined2 *)PTR_DAT_0305ba50 = 0x20;
  puVar1 = p_text_entry_current_char;
  *(undefined2 *)p_text_entry_current_char = 5;
  *(undefined1 *)p_text_entry_current_char_alias = 0;
  gb2312_text_wrap_calculate(p_text_entry_buffer);
  *(char *)PTR_DAT_0305ba64 = *(char *)PTR_DAT_0305ba60 + -1;
  *(undefined2 *)PTR_DAT_0305ba68 = *(undefined2 *)puVar1;
  *(undefined2 *)p_text_entry_buffer_alias = *(undefined2 *)puVar2;
  return;
}

