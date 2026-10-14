/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: signaling_subblock_defaults_init @ 030cfc68 (file base 0x03000000; code starts at 0x03001000)
 * Size: 106 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined4 signaling_subblock_defaults_init(short param_1,undefined4 param_2,undefined2 *param_3)

{
  *param_3 = 1;
  param_3[1] = 0xff;
  param_3[2] = 0xf;
  param_3[6] = 0x4027;
  param_3[3] = 0;
  *(undefined4 *)(param_3 + 4) = 0;
  param_3[7] = 0;
  u16_buffer_fill_memset(param_3 + 8,0,0x38);
  param_3[0x40] = 0x3333;
  param_3[0x41] = 0x3800;
  param_3[0x42] = 0;
  param_3[0x43] = 0;
  param_3[0x44] = 0;
  param_3[0x45] = 0;
  u16_buffer_fill_memset(param_3 + 0x46,0,3);
  func_0x030cfbc4(param_2,(int)param_1,0);
  return 0;
}

