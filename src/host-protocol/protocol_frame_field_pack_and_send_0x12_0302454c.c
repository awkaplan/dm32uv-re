/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: protocol_frame_field_pack_and_send_0x12 @ 0302454c (file base 0x03000000; code starts at 0x03001000)
 * Size: 148 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: host-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void protocol_frame_field_pack_and_send_0x12(uint param_1,ushort param_2,uint param_3)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  uint uVar3;
  
  if (*(char *)PTR_DAT_030246a0 == '\x03') {
    osmbox_post_candidate2_on_check_0300c768();
  }
  puVar1 = PTR_DAT_030246a0;
  *(undefined1 *)(PTR_DAT_030246a0 + 2) = 4;
  *(undefined1 *)(puVar1 + 3) = 10;
  *(uint *)(puVar1 + 6) = param_1;
  puVar1[4] = puVar1[4] & 0xf800 | param_2 & 0x7ff;
  uVar3 = (param_3 & 0xff) + 1 & 0x1f;
  *(byte *)((int)puVar1 + 9) = *(byte *)((int)puVar1 + 9) & 7 | (byte)(uVar3 << 3);
  puVar2 = PTR_DAT_030246a4;
  *(byte *)((int)PTR_DAT_030246a4 + 3) =
       *(byte *)((int)PTR_DAT_030246a4 + 3) & 7 | (byte)(uVar3 << 3);
  puVar2[1] = puVar2[1] & 0xf800 | param_2 & 0x7ff;
  *(char *)(puVar2 + 2) = (char)((ushort)puVar1[7] >> 4);
  *(uint *)(puVar2 + 4) = param_1 & 0xfffff;
  *(char *)(puVar2 + 6) = (char)((ushort)puVar1[9] >> 4);
  *(uint *)(puVar2 + 8) = *(uint *)(puVar1 + 8) & 0xfffff;
  *(undefined1 *)puVar2 = 0;
  *(undefined1 *)((int)puVar2 + 1) = 3;
  *(undefined1 *)(puVar1 + 1) = 0x12;
  scan_timer_apply_random_jitter(0x12);
  guarded_timer_config_apply_wrapper_b(120000);
  return;
}

