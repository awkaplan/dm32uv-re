/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: struct_init_typetag_and_funcptr @ 0306b024 (file base 0x03000000; code starts at 0x03001000)
 * Size: 36 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void struct_init_typetag_and_funcptr(undefined4 *param_1)

{
  *(undefined1 *)((int)param_1 + 0x2a) = 0;
  *param_1 = DAT_0306b054;
  param_1[1] = PTR_LAB_0306b058;
  param_1[8] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[9] = 0;
  *(undefined2 *)(param_1 + 10) = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  return;
}

