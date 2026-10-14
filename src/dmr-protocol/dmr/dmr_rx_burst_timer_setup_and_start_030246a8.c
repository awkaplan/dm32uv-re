/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dmr_rx_burst_timer_setup_and_start @ 030246a8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 98 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: dmr-protocol
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void dmr_rx_burst_timer_setup_and_start(void)

{
  undefined2 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined1 uVar4;
  
  puVar1 = PTR_DAT_03024820;
  *(undefined1 *)(PTR_DAT_03024820 + 2) = 3;
  *(undefined1 *)(puVar1 + 3) = 10;
  puVar2 = PTR_DAT_03024824;
  *(byte *)((int)PTR_DAT_03024824 + 3) = *(byte *)((int)PTR_DAT_03024824 + 3) & 7;
  *(ushort *)((int)puVar2 + 2) = *(ushort *)((int)puVar2 + 2) & 0xf800 | puVar1[4] & 0x7ff;
  uVar4 = (undefined1)((ushort)puVar1[9] >> 4);
  *(undefined1 *)(puVar2 + 1) = uVar4;
  uVar3 = *(uint *)(puVar1 + 8);
  puVar2[2] = uVar3 & 0xfffff;
  *(undefined1 *)(puVar2 + 3) = uVar4;
  puVar2[4] = uVar3 & 0xfffff;
  *(undefined1 *)puVar2 = 0;
  *(undefined1 *)((int)puVar2 + 1) = 3;
  scan_timer_apply_random_jitter(*(undefined1 *)(puVar1 + 1));
  guarded_timer_config_apply_wrapper_b(120000);
  return;
}

