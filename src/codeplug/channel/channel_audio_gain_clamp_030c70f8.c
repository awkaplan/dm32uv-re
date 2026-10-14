/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_audio_gain_clamp @ 030c70f8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 76 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

short channel_audio_gain_clamp(short param_1,int param_2,short param_3)

{
  short sVar1;
  
  if ((-0x3c < param_2) && (param_1 != 0)) {
    sVar1 = FUN_030c8ce0((int)param_1,(int)(short)((short)param_2 + 0x1e),5);
    param_3 = param_3 + sVar1;
    if (0x7800 < param_3) {
      return 0x7800;
    }
    if (param_3 < -0x1400) {
      param_3 = -0x1400;
    }
    return param_3;
  }
  return -0x1400;
}

