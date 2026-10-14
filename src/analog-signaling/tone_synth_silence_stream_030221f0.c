/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: tone_synth_silence_stream @ 030221f0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 50 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: analog-signaling
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void tone_synth_silence_stream(ushort param_1)

{
  dword dVar1;
  undefined1 *puVar2;
  ushort uVar3;
  
  puVar2 = PTR_DAT_030223e4;
  if (param_1 != 0) {
    uVar3 = 0;
    do {
      do {
        dVar1 = SystemControl_Type_11000000.AUDIO_CONTROL;
      } while ((int)dVar1 < 0);
      memset_bytes(puVar2,0,0x40);
      uVar3 = uVar3 + 0x20;
    } while (uVar3 < param_1);
  }
  return;
}

