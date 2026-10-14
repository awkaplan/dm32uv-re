/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: audio_pa_enable_gate @ 0301d6cc (file base 0x03000000; code starts at 0x03001000)
 * Size: 96 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: audio
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void audio_pa_enable_gate(int param_1)

{
  if (param_1 == 0) {
    if ((*(byte *)((int)PTR_DAT_0301d738 + 1) & 2) != 0) {
      if (((*(byte *)((int)PTR_DAT_0301d738 + 1) & 0x80) != 0) &&
         ((*PTR_DAT_0301d738 & 0x18000) != 0x18000)) {
        return;
      }
      gpio_clear_output_bit(0x35);
      *(byte *)((int)PTR_DAT_0301d738 + 1) = *(byte *)((int)PTR_DAT_0301d738 + 1) & 0xfd;
    }
  }
  else if ((*(byte *)((int)PTR_DAT_0301d738 + 1) & 2) == 0) {
    gpio_set_output_bit(0x35);
    *(byte *)((int)PTR_DAT_0301d738 + 1) = *(byte *)((int)PTR_DAT_0301d738 + 1) & 0xfd | 2;
  }
  return;
}

