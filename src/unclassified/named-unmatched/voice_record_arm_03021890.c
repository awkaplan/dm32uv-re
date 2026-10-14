/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: voice_record_arm @ 03021890 (file base 0x03000000; code starts at 0x03001000)
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

void voice_record_arm(void)

{
  dword dVar1;
  
  if ((*(byte *)PTR_DAT_030219f4 & 1) == 0) {
    dVar1 = SystemControl_Type_11000000.AUDIO_BUFFER_CLR;
    SystemControl_Type_11000000.AUDIO_BUFFER_CLR = dVar1 | 1;
    if ((*(byte *)PTR_DAT_030219fc & 0x10) != 0) {
      voice_record_direction_select(1);
      write_byte_field_030212e4(2);
      PTR_DAT_03021a00[5] = 0;
    }
    FUN_00016088();
    *(byte *)PTR_DAT_030219f4 = *(byte *)PTR_DAT_030219f4 | 1;
  }
  return;
}

