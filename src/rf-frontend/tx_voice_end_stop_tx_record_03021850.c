/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: tx_voice_end_stop_tx_record @ 03021850 (file base 0x03000000; code starts at 0x03001000)
 * Size: 64 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rf-frontend
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void tx_voice_end_stop_tx_record(void)

{
  int iVar1;
  
  if ((*(byte *)PTR_DAT_030219f4 & 1) != 0) {
    FUN_000160b0();
    recording_stop_tx_finalize();
    iVar1 = bitwise_not_of_nonzero_check();
    if (iVar1 == 0) {
      FUN_00015eb0();
      FUN_00015f30(0,1);
      audio_ctrl_bit0_tx_voice_source_set(0);
      *PTR_DAT_030219f8 = 0;
    }
    *(byte *)PTR_DAT_030219f4 = *(byte *)PTR_DAT_030219f4 & 0xfe;
  }
  return;
}

