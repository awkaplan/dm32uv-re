/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: tx_abort_check_and_report @ 03015cc8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 66 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rf-frontend
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void tx_abort_check_and_report(void)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((PTR_DAT_03015dd0[3] & 0x40) == 0) && (iVar1 = poll_condition_group(0x12), iVar1 != 0)) {
    if (*(byte *)PTR_DAT_03015dd4 < 3) {
      if (*(byte *)PTR_DAT_03015dd4 == 2) {
        uVar2 = 0x42;
      }
      else {
        uVar2 = 0x43;
      }
    }
    else {
      uVar2 = 0x41;
    }
    tx_abort_on_condition();
    write_event_record_and_notify(0x27,uVar2);
  }
  return;
}

