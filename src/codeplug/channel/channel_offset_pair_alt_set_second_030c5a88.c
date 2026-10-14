/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_offset_pair_alt_set_second @ 030c5a88 (file base 0x03000000; code starts at 0x03001000)
 * Size: 26 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void channel_offset_pair_alt_set_second(short param_1)

{
  short *psVar1;
  undefined2 *puVar2;
  
  puVar2 = PTR_DAT_030c5b0c;
  psVar1 = PTR_DAT_030c5b0c + 0x8b5;
  PTR_DAT_030c5b0c[0x8b6] = param_1;
  codec_level_id_store_and_scale(puVar2,(int)*psVar1,(int)param_1);
  return;
}

