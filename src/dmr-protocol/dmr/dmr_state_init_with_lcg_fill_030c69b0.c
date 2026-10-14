/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dmr_state_init_with_lcg_fill @ 030c69b0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 116 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: dmr-protocol
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void dmr_state_init_with_lcg_fill(int param_1,short param_2)

{
  short *psVar1;
  short sVar2;
  short sVar3;
  
  u16_buffer_fill_memset(param_1,0,0x3f4);
  *(undefined2 *)(param_1 + 0x7c2) = 0xffe2;
  *(undefined2 *)(param_1 + 0x7be) = 0x1c94;
  codec_level_id_store_and_scale(param_1,0x20,0xfffffff6);
  dmr_filter_block_init_defaults(param_1 + 0x470);
  dmr_filter_block_init_defaults(param_1 + 0x4f8);
  sVar3 = *(short *)(param_1 + 0x648);
  psVar1 = (short *)(param_1 + 0x64a);
  sVar2 = 0;
  do {
    sVar2 = sVar2 + 1;
    sVar3 = sVar3 * 0xad + 0x3619;
    *psVar1 = sVar3;
    psVar1 = psVar1 + 1;
  } while (sVar2 != 0x54);
  *(short *)(param_1 + 0x648) = sVar3;
  signaling_subblock_defaults_init((int)param_2,param_1 + 0x7a0,param_1 + 0x580);
  return;
}

