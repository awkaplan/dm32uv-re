/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: format_computed_ratio_as_string @ 030114d4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 32 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: display-driver
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void format_computed_ratio_as_string(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 local_14;
  undefined4 uStack_10;
  
  nmea_latlon_pack_deg_1e5(param_2,&local_14);
  number_to_string_format_2args(param_3,PTR_LAB_03011618,local_14,uStack_10);
  return;
}

