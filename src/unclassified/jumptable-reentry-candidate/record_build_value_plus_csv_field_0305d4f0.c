/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: record_build_value_plus_csv_field @ 0305d4f0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 80 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

uint record_build_value_plus_csv_field
               (undefined4 param_1,char *param_2,undefined4 param_3,undefined1 *param_4)

{
  uint uVar1;
  uint unaff_r6;
  uint unaff_r7;
  
  *param_4 = (char)param_1;
  param_4[1] = (char)((uint)param_1 >> 8);
  param_4[2] = (char)((uint)param_1 >> 0x10);
  param_4[3] = 0;
  param_4[4] = 0;
  if ((*param_2 == '\'') && (param_2[1] == '~')) {
    uVar1 = string_find_nth_comma_index(param_2 + 4,1);
    unaff_r6 = uVar1 & 0xffff;
    uVar1 = string_find_nth_comma_index(param_2 + 4,10);
    unaff_r7 = uVar1 & 0xffff;
    memcpy_bytes_iram(param_4 + 3,param_2 + unaff_r6 + 4,unaff_r7 - unaff_r6);
  }
  return (unaff_r7 + 4) - unaff_r6 & 0xffff;
}

