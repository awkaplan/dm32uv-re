/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: keypad_key_allowed_by_bitmask_a @ 03014060 (file base 0x03000000; code starts at 0x03001000)
 * Size: 48 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: input-keypad
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined4 keypad_key_allowed_by_bitmask_a(char param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = get_current_mode_state1();
  if (iVar1 == 0) {
    uVar2 = 1;
  }
  else if (((byte)(param_1 - 5U) < 0x1f) &&
          ((1 << ((int)(char)(param_1 - 5U) & 0x3fU) & DAT_030140a4) != 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}

