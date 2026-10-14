/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: protocol_state_write_and_apply_sequence @ 03024928 (file base 0x03000000; code starts at 0x03001000)
 * Size: 74 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: host-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void protocol_state_write_and_apply_sequence(undefined4 param_1,ushort param_2,char param_3)

{
  undefined4 *puVar1;
  
  if (*(char *)PTR_DAT_03024a84 == '\x03') {
    osmbox_post_candidate2_on_check_0300c768();
  }
  puVar1 = PTR_DAT_03024a84;
  *(undefined1 *)PTR_DAT_03024a84 = 2;
  puVar1[3] = param_1;
  *(ushort *)((int)puVar1 + 0x12) = *(ushort *)((int)puVar1 + 0x12) & 0xf;
  *(byte *)((int)puVar1 + 9) = *(byte *)((int)puVar1 + 9) & 7 | (param_3 + '\x01') * '\b';
  *(ushort *)(puVar1 + 2) = *(ushort *)(puVar1 + 2) & 0xf800 | param_2 & 0x7ff;
  osmbox_post_candidate2_on_check_0300c780();
  protocol_timer_ensure_valid_or_recreate_wrapper(500);
  dmr_rx_control_state_update_from_status();
  return;
}

