/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: tx_history_pop_release_b @ 030373cc (file base 0x03000000; code starts at 0x03001000)
 * Size: 84 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rf-frontend
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void tx_history_pop_release_b(void)

{
  undefined1 *puVar1;
  
  if ((PTR_DAT_030374fc[0x16] & 1) == 0) {
    write_status_mode_byte_pair(0x46,0);
  }
  else {
    history_queue_pop();
    PTR_DAT_030374fc[0x16] = PTR_DAT_030374fc[0x16] & 0xfe;
    puVar1 = PTR_DAT_03037500;
    PTR_DAT_03037500[1] = PTR_DAT_03037500[1] & 0xf7;
    puVar1[0x2d] = puVar1[0x2d] & 0xf3;
    *(byte *)PTR_DAT_03037504 = *(byte *)PTR_DAT_03037504 & 0x7f;
    tx_gate_write_call_record(1);
  }
  return;
}

