/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dialog_history_pop_and_state_dispatch @ 03037020 (file base 0x03000000; code starts at 0x03001000)
 * Size: 80 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-dialog
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void dialog_history_pop_and_state_dispatch(void)

{
  undefined1 *puVar1;
  uint uVar2;
  
  if (PTR_DAT_030372d0[0x328] == '\x01') {
    PTR_DAT_030372d4[10] = PTR_DAT_030372d4[10] & 0xfe | 1;
    dialog_history_show_if_present();
    PTR_DAT_030372d0[0x328] = 0;
  }
  history_queue_pop();
  puVar1 = PTR_DAT_030372d8;
  uVar2 = PTR_PTR_030372dc[(uint)(byte)PTR_DAT_030372d8[3] * 3];
  *PTR_DAT_030372e0 = uVar2;
  (*(code *)(uVar2 & 0xfffffffe))();
  puVar1[4] = 0;
  return;
}

