/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: wlt_cmd_string_build @ 030543b4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 30 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void wlt_cmd_string_build(undefined1 param_1)

{
  undefined4 uVar1;
  
  uVar1 = p_text_entry_buffer;
  memset_bytes(p_text_entry_buffer,0,0x154);
  number_to_string_format_2args(uVar1,PTR_s_WLT_CMD__03d_03054458,param_1);
  return;
}

