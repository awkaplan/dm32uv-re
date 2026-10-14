/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: audio_ctrl_ring_play_set @ 0301e598 (file base 0x03000000; code starts at 0x03001000)
 * Size: 36 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: audio
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void audio_ctrl_ring_play_set(int param_1)

{
  dword dVar1;
  
  if (param_1 == 0) {
    dVar1 = SystemControl_Type_11000000.AUDIO_CONTROL;
    SystemControl_Type_11000000.AUDIO_CONTROL = dVar1 & 0xffffff7f;
  }
  else {
    dVar1 = SystemControl_Type_11000000.AUDIO_CONTROL;
    SystemControl_Type_11000000.AUDIO_CONTROL = dVar1 | 0x80;
  }
  return;
}

