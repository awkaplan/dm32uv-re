/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dmr_privacy_mi_embedded_encode @ 030c5790 (file base 0x03000000; code starts at 0x03001000)
 * Size: 100 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: dmr-protocol
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void dmr_privacy_mi_embedded_encode(uint param_1,uint *param_2)

{
  uint uVar1;
  uint uStack_2c;
  uint uStack_28;
  uint uStack_24;
  undefined1 uStack_20;
  undefined1 uStack_1f;
  undefined1 uStack_1e;
  undefined1 uStack_1d;
  
  uStack_2c = param_1 >> 0x14;
  uStack_1d = (undefined1)param_1;
  uStack_28 = param_1 >> 8 & 0xfff;
  uStack_20 = (undefined1)(param_1 >> 0x18);
  uStack_1f = (undefined1)(param_1 >> 0x10);
  uStack_1e = (undefined1)(param_1 >> 8);
  uVar1 = ccitt_crc4_stream_update(0,0x20,&uStack_20);
  uStack_24 = (param_1 & 0xff) << 4 | uVar1 & 0xf ^ 0xf;
  dmr_type_s_scramble_permute_block(&uStack_2c);
  *param_2 = uStack_2c;
  param_2[1] = uStack_28;
  param_2[2] = uStack_24;
  return;
}

