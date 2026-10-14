/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_freq_step_adjust_b @ 0305b950 (file base 0x03000000; code starts at 0x03001000)
 * Size: 50 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void channel_freq_step_adjust_b(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = PTR_DAT_0305ba48;
  uVar2 = channel_frequency_step_clamp(*PTR_DAT_0305ba48,0);
  *(char *)puVar1 = (char)uVar2;
  *(char *)((int)puVar1 + 1) = (char)((uint)uVar2 >> 8);
  *(char *)((int)puVar1 + 2) = (char)((uint)uVar2 >> 0x10);
  *(char *)((int)puVar1 + 3) = (char)((uint)uVar2 >> 0x18);
  return;
}

