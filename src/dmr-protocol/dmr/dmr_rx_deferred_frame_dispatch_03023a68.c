/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dmr_rx_deferred_frame_dispatch @ 03023a68 (file base 0x03000000; code starts at 0x03001000)
 * Size: 112 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: dmr-protocol
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void dmr_rx_deferred_frame_dispatch(void)

{
  uint uVar1;
  
  uVar1 = *PTR_DAT_03023ad8;
  if ((PTR_DAT_03023adc[1] != '\x02') && (PTR_DAT_03023adc[1] != '\x04')) {
    if ((uVar1 & 0x40) != 0) {
      FUN_03023914();
    }
    if ((uVar1 & 0x10) != 0) {
      dmr_incoming_call_setup_conflict_resolve();
    }
    if ((uVar1 & 8) != 0) {
      FUN_0300c0e8();
      FUN_0300c0e4(*(undefined1 *)PTR_DAT_03023ae0);
      dmr_call_state_machine_step();
    }
    if ((uVar1 & 4) != 0) {
      dmr_embedded_lc_superframe_process();
    }
    if ((uVar1 & 2) != 0) {
      FUN_0002d6a4();
    }
    if ((uVar1 & 0x800) != 0) {
      FUN_03023a58();
      FUN_0300c0e4(*(undefined1 *)PTR_DAT_03023ae0);
    }
  }
  return;
}

