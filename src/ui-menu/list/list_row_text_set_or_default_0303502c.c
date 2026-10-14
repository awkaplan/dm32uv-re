/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: list_row_text_set_or_default @ 0303502c (file base 0x03000000; code starts at 0x03001000)
 * Size: 38 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-menu
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void list_row_text_set_or_default(char param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = p_list_row_text_buffer;
  if (param_1 == '\x01') {
    strcpy_ck803s(p_list_row_text_buffer);
    strcpy_ck803s((int)puVar1 + 0x1a,param_2);
  }
  else {
    strcpy_ck803s(DAT_030350c0);
  }
  return;
}

