/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dmr_filter_block_init_defaults @ 030c9920 (file base 0x03000000; code starts at 0x03001000)
 * Size: 54 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: dmr-protocol
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void dmr_filter_block_init_defaults(undefined2 *param_1)

{
  param_1[6] = 0x4000;
  param_1[2] = 0xe;
  param_1[1] = 0xff;
  *param_1 = 2;
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  param_1[7] = 0;
  u16_buffer_fill_memset(param_1 + 8,0x6666,0x38);
  param_1[0x42] = 0xffee;
  return;
}

