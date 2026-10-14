/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: radio_state_reinit_and_120s_timer_start @ 03024434 (file base 0x03000000; code starts at 0x03001000)
 * Size: 108 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: radio-state
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void radio_state_reinit_and_120s_timer_start(void)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  
  puVar1 = PTR_DAT_030244a0;
  PTR_DAT_030244a0[9] = PTR_DAT_030244a0[9] & 0xf | 0x20;
  *(undefined1 *)(puVar1 + 2) = 1;
  *(undefined1 *)(puVar1 + 3) = 3;
  puVar2 = PTR_DAT_030244a4;
  *(byte *)((int)PTR_DAT_030244a4 + 3) = *(byte *)((int)PTR_DAT_030244a4 + 3) & 7;
  puVar2[1] = puVar2[1] & 0xf800;
  *(undefined1 *)(puVar2 + 2) = 0;
  *(undefined4 *)(puVar2 + 4) = 0;
  *(undefined1 *)(puVar2 + 6) = 2;
  *(uint *)(puVar2 + 8) = *(uint *)(puVar1 + 8) & 0xfffff;
  *(undefined1 *)puVar2 = 0;
  *(undefined1 *)((int)puVar2 + 1) = 0;
  scan_timer_apply_random_jitter(*(undefined1 *)(puVar1 + 1));
  guarded_timer_config_apply_wrapper_b(120000);
  return;
}

