/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: tx_voice_start_begin_record @ 03021a70 (file base 0x03000000; code starts at 0x03001000)
 * Size: 154 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: audio
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void tx_voice_start_begin_record(void)

{
  dword dVar1;
  int iVar2;
  
  if ((*(byte *)PTR_DAT_03021b0c & 1) == 0) {
    if ((*(byte *)PTR_DAT_03021b0c & 2) != 0) {
      rx_voice_end_stop_rx_record();
    }
    dVar1 = SystemControl_Type_11000000.AUDIO_BUFFER_CLR;
    SystemControl_Type_11000000.AUDIO_BUFFER_CLR = dVar1 | 1;
    if ((((*(byte *)PTR_DAT_03021b18 & 0x10) != 0) && ((PTR_DAT_03021b1c[3] & 1) != 0)) &&
       ((byte)(PTR_DAT_03021b1c[2] - 1) < 2)) {
      voice_record_direction_select(1);
      write_byte_field_030212e4(2);
      PTR_DAT_03021b20[5] = 0;
    }
    iVar2 = bitwise_not_of_nonzero_check();
    if (iVar2 == 0) {
      audio_ctrl_bit0_tx_voice_source_set(1);
      FUN_00015f30(4,1);
      FUN_00015f00();
      FUN_00015ea0();
      *PTR_DAT_03021b10 = 1;
    }
    else {
      audio_ctrl_bit0_tx_voice_source_set(0);
    }
    FUN_00016088();
    *(byte *)PTR_DAT_03021b0c = *(byte *)PTR_DAT_03021b0c | 1;
  }
  return;
}

