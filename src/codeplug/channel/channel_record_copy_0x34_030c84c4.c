/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_record_copy_0x34 @ 030c84c4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 46 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined4 channel_record_copy_0x34(int param_1,int param_2)

{
  undefined2 uVar1;
  
  array_copy_u16(param_1,param_2,0xe);
  uVar1 = *(undefined2 *)(param_2 + 0x20);
  *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_2 + 0x1c);
  *(undefined2 *)(param_1 + 0x20) = uVar1;
  array_copy_u16(param_1 + 0x22,param_2 + 0x22,7);
  uVar1 = *(undefined2 *)(param_2 + 0x30);
  *(undefined2 *)(param_1 + 0x32) = *(undefined2 *)(param_2 + 0x32);
  *(undefined2 *)(param_1 + 0x30) = uVar1;
  return 0;
}

