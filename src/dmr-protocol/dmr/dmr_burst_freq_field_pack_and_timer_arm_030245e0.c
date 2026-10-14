/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dmr_burst_freq_field_pack_and_timer_arm @ 030245e0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 190 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: dmr-protocol
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void dmr_burst_freq_field_pack_and_timer_arm(int param_1)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  
  puVar1 = PTR_DAT_030246a0;
  *(undefined1 *)(PTR_DAT_030246a0 + 2) = 5;
  *(undefined1 *)(puVar1 + 3) = 3;
  puVar2 = PTR_DAT_030246a0;
  if (*(int *)(puVar1 + 8) == param_1) {
    *(undefined1 *)PTR_DAT_030246a0 = 1;
    puVar1 = PTR_DAT_030246a4;
    *(byte *)((int)PTR_DAT_030246a4 + 3) = *(byte *)((int)PTR_DAT_030246a4 + 3) & 7;
    *(char *)(puVar1 + 2) = (char)((ushort)puVar2[9] >> 4);
    *(uint *)(puVar1 + 4) = *(uint *)(puVar2 + 8) & 0xfffff;
  }
  else {
    *(undefined1 *)PTR_DAT_030246a0 = 2;
    puVar1 = PTR_DAT_030246a4;
    *(byte *)((int)PTR_DAT_030246a4 + 3) =
         *(byte *)((int)PTR_DAT_030246a4 + 3) & 7 | *(byte *)((int)puVar2 + 9) & 0xf8;
    *(char *)(puVar1 + 2) = (char)((ushort)puVar2[7] >> 4);
    *(uint *)(puVar1 + 4) = *(uint *)(puVar2 + 6) & 0xfffff;
  }
  puVar2 = PTR_DAT_030246a4;
  puVar1 = PTR_DAT_030246a0;
  PTR_DAT_030246a4[1] = PTR_DAT_030246a4[1] & 0xf800 | PTR_DAT_030246a0[4] & 0x7ff;
  *(char *)(puVar2 + 6) = (char)((ushort)puVar1[9] >> 4);
  *(uint *)(puVar2 + 8) = *(uint *)(puVar1 + 8) & 0xfffff;
  *(undefined1 *)puVar2 = 0;
  *(undefined1 *)((int)puVar2 + 1) = 2;
  scan_timer_apply_random_jitter(*(undefined1 *)(puVar1 + 1));
  guarded_timer_config_apply_wrapper_b(120000);
  return;
}

