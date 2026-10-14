/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: protocol_frame_periodic_timer_state_machine @ 03024788 (file base 0x03000000; code starts at 0x03001000)
 * Size: 150 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: host-protocol
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void protocol_frame_periodic_timer_state_machine(void)

{
  undefined2 *puVar1;
  uint uVar2;
  ushort uVar3;
  
  if (*(char *)PTR_DAT_03024820 == '\x01') {
    uVar2 = ((ushort)PTR_DAT_03024820[4] + 1 & 0x7ff) % 0x21c;
    PTR_DAT_03024820[4] = PTR_DAT_03024820[4] & 0xf800 | (ushort)uVar2;
    if (uVar2 == 0) {
      dmr_rx_burst_timer_setup_and_start();
    }
  }
  else if (*(char *)PTR_DAT_03024820 == '\x02') {
    uVar3 = PTR_DAT_03024820[4] + 1 & 0x7ff;
    PTR_DAT_03024820[4] = PTR_DAT_03024820[4] & 0xf800 | uVar3;
    if (uVar3 < 0x4b0) {
      if (uVar3 < 0x438) {
        *(undefined1 *)((int)PTR_DAT_03024820 + 5) = 0;
      }
      else if (*(char *)((int)PTR_DAT_03024820 + 5) == '\0') {
        *(undefined1 *)((int)PTR_DAT_03024820 + 5) = 1;
        protocol_frame_field_copy_and_send();
      }
    }
    else {
      guarded_timer_config_apply_wrapper_a(270000);
      puVar1 = PTR_DAT_03024820;
      *(undefined1 *)PTR_DAT_03024820 = 3;
      *(undefined4 *)(puVar1 + 6) = 0;
      puVar1[4] = puVar1[4] & 0xf800;
      *(byte *)((int)puVar1 + 9) = *(byte *)((int)puVar1 + 9) & 7;
    }
  }
  return;
}

