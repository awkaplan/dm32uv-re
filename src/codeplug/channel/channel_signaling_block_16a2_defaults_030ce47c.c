/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_signaling_block_16a2_defaults @ 030ce47c (file base 0x03000000; code starts at 0x03001000)
 * Size: 96 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void channel_signaling_block_16a2_defaults(int param_1,short param_2,short param_3,short param_4)

{
  short sVar1;
  
  *(short *)(param_1 + 0x16a8) = param_4 << 8;
  *(undefined2 *)(param_1 + 0x16aa) = 0xd800;
  sVar1 = (param_2 + 4) * 0x100;
  *(undefined2 *)(param_1 + 0x16ae) = 0xccc;
  *(undefined2 *)(param_1 + 0x16b0) = 0x333;
  *(short *)(param_1 + 0x16a2) = sVar1;
  *(short *)(param_1 + 0x16a4) = sVar1;
  *(short *)(param_1 + 0x16a6) = param_3 << 8;
  *(undefined2 *)(param_1 + 0x16ac) = 0x4000;
  *(undefined2 *)(param_1 + 0x16b2) = 0xa3;
  *(undefined2 *)(param_1 + 0x16b4) = 0xa00;
  *(undefined2 *)(param_1 + 0x16b6) = 0x1900;
  return;
}

