/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: keypad_gate_dispatch_mask04 @ 03014610 (file base 0x03000000; code starts at 0x03001000)
 * Size: 114 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: input-keypad
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void keypad_gate_dispatch_mask04(void)

{
  if (((*(byte *)PTR_DAT_0301472c & 0x12) == 0x10) && ((PTR_DAT_03014730[8] & 1) == 0)) {
    if ((*(byte *)PTR_DAT_03014734 & 4) == 0) {
      if ((*(byte *)PTR_DAT_0301473c & 4) == 0) {
        keypad_tmrkey_state_dispatch();
      }
      else {
        if ((*(byte *)((int)PTR_DAT_0301472c + 5) & 1) != 0) {
          refresh_display_or_call_03015b24(0);
        }
        *(byte *)PTR_DAT_0301472c = *(byte *)PTR_DAT_0301472c & 0x7f;
      }
    }
    else if ((PTR_DAT_03014738[0x10] & 0x10) != 0) {
      refresh_display_or_call_03015ad8(0);
    }
  }
  return;
}

