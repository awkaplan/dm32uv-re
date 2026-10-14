/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: codec_level_id_store_and_scale @ 030c6980 (file base 0x03000000; code starts at 0x03001000)
 * Size: 46 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: audio
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined4 codec_level_id_store_and_scale(int param_1,short param_2,short param_3)

{
  short sVar1;
  
  sVar1 = classify_id_into_range_bucket((int)param_2);
  if (sVar1 == 4) {
    param_2 = 0x20;
  }
  *(short *)(param_1 + 0x79c) = param_2;
  level_scale_by_category_with_offset(param_1 + 0x79e,(int)param_2,(int)param_3);
  return 0x4000;
}

