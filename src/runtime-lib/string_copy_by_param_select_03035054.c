/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: string_copy_by_param_select @ 03035054 (file base 0x03000000; code starts at 0x03001000)
 * Size: 28 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: runtime-lib
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void string_copy_by_param_select(int param_1__w,undefined4 param_2)

{
  char param_1 = (char)param_1__w;
  if (param_1 == '\x01') {
    strcpy_ck803s(param_2,p_list_row_text_buffer);
  }
  else {
    strcpy_ck803s(param_2,DAT_030350c0);
  }
  return;
}

