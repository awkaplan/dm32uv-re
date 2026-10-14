/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: protocol_frame_field_copy_and_send @ 0302470c (file base 0x03000000; code starts at 0x03001000)
 * Size: 124 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: host-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void protocol_frame_field_copy_and_send(void)

{
  undefined2 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  puVar1 = PTR_DAT_03024820;
  *(undefined1 *)(PTR_DAT_03024820 + 2) = 1;
  *(undefined1 *)(puVar1 + 3) = 3;
  puVar2 = PTR_DAT_03024824;
  *(byte *)((int)PTR_DAT_03024824 + 3) =
       *(byte *)((int)PTR_DAT_03024824 + 3) & 7 | *(byte *)((int)puVar1 + 9) & 0xf8;
  *(ushort *)((int)puVar2 + 2) = *(ushort *)((int)puVar2 + 2) & 0xf800 | puVar1[4] & 0x7ff;
  *(char *)(puVar2 + 1) = (char)((ushort)puVar1[7] >> 4);
  puVar2[2] = *(uint *)(puVar1 + 6) & 0xfffff;
  *(undefined1 *)(puVar2 + 3) = 0;
  uVar3 = *(uint *)(puVar1 + 8);
  puVar2[4] = uVar3 & 0xfffff;
  *(undefined1 *)puVar2 = 0;
  *(undefined1 *)((int)puVar2 + 1) = 2;
  scan_timer_apply_random_jitter(*(undefined1 *)(puVar1 + 1),uVar3 & 0xfffff,0);
  guarded_timer_config_apply_wrapper_b(120000);
  return;
}

