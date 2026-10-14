/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: history_record_push_typed @ 03025e40 (file base 0x03000000; code starts at 0x03001000)
 * Size: 80 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-screen
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined4 history_record_push_typed(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = history_slot_allocate();
  if (iVar1 == 0) {
    OSTimeDly_ms_wrapper(0x3c);
    iVar1 = history_slot_allocate();
    if (iVar1 == 0) {
      return 1;
    }
  }
  *(undefined1 *)(iVar1 + 2) = 0;
  *(undefined1 *)(iVar1 + 3) = 6;
  memset_bytes(iVar1 + 5,0,0x18);
  if (0xf < *(byte *)(param_1 + 4)) {
    history_slot_link_append(iVar1);
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x03025e80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*(code *)(PTR_PTR_03025e84[*(byte *)(param_1 + 4)] & 0xfffffffe))();
  return uVar2;
}

