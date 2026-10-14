/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dmr_burst_assemble_and_dispatch @ 030244ac (file base 0x03000000; code starts at 0x03001000)
 * Size: 158 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: dmr-protocol
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void dmr_burst_assemble_and_dispatch(byte param_1,uint param_2)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  
  if (*(char *)PTR_DAT_030246a0 == '\x03') {
    osmbox_post_candidate2_on_check_0300c768();
  }
  puVar1 = PTR_DAT_030246a0;
  *(undefined1 *)PTR_DAT_030246a0 = 2;
  puVar1[7] = puVar1[7] & 0xf | (ushort)param_1 << 4;
  *(uint *)(puVar1 + 6) = *(uint *)(puVar1 + 6) & 0xfff00000 | param_2 & 0xfffff;
  puVar1[9] = puVar1[9] & 0xf;
  *(undefined1 *)(puVar1 + 2) = 2;
  *(undefined1 *)(puVar1 + 3) = 3;
  *(byte *)((int)puVar1 + 9) = *(byte *)((int)puVar1 + 9) & 7 | 8;
  osmbox_post_candidate2_on_check_0300c780();
  protocol_timer_ensure_valid_or_recreate_wrapper(500);
  puVar2 = PTR_DAT_030246a4;
  *(byte *)((int)PTR_DAT_030246a4 + 3) =
       *(byte *)((int)PTR_DAT_030246a4 + 3) & 7 | *(byte *)((int)puVar1 + 9) & 0xf8;
  puVar2[1] = puVar2[1] & 0xf800 | puVar1[4] & 0x7ff;
  *(byte *)(puVar2 + 2) = param_1;
  *(uint *)(puVar2 + 4) = param_2;
  *(char *)(puVar2 + 6) = (char)((ushort)puVar1[9] >> 4);
  *(uint *)(puVar2 + 8) = *(uint *)(puVar1 + 8) & 0xfffff;
  *(undefined1 *)((int)puVar2 + 1) = 2;
  *(undefined1 *)puVar2 = 1;
  scan_timer_apply_random_jitter(*(undefined1 *)(puVar1 + 1));
  guarded_timer_config_apply_wrapper_b(120000);
  return;
}

