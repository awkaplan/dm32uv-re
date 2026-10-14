/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: rx_voice_end_stop_rx_record @ 03021a14 (file base 0x03000000; code starts at 0x03001000)
 * Size: 92 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void rx_voice_end_stop_rx_record(void)

{
  int iVar1;
  
  if ((*(byte *)PTR_DAT_03021b0c & 2) != 0) {
    audio_pa_enable_gate(0);
    FUN_00016104();
    recording_stop_rx_finalize();
    iVar1 = bitwise_not_of_nonzero_check();
    if (iVar1 == 0) {
      FUN_00015ef0();
      FUN_00016000(0);
      FUN_00015f30(0,1);
      FUN_0001600c(1);
      PTR_DAT_03021b10[0x1f] = 0;
    }
    p_radio_mode_state_0003e318[1].flags_0x6 = p_radio_mode_state_0003e318[1].flags_0x6 & 0xfc;
    *(byte *)PTR_DAT_03021b0c = *(byte *)PTR_DAT_03021b0c & 0xfd;
  }
  return;
}

