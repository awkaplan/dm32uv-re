/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: keypad_key_allowed_by_bitmask_mode_dependent @ 0301412c (file base 0x03000000; code starts at 0x03001000)
 * Size: 108 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: input-keypad
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined4 keypad_key_allowed_by_bitmask_mode_dependent(char param_1)

{
  int iVar1;
  undefined4 uVar2;
  byte bVar3;
  
  bVar3 = p_vfo_display_state->flags_0x8 & 0xf0;
  if (bVar3 == 0x10) {
    if ((*(byte *)p_call_active_flag & 2) == 0) {
      iVar1 = read_byte_field_0302e120();
      if (iVar1 == 3) {
        if (((byte)(param_1 - 10U) < 0x1a) &&
           ((1 << ((int)(char)(param_1 - 10U) & 0x3fU) & DAT_030141d8) != 0)) {
          uVar2 = 0;
        }
        else {
          uVar2 = 1;
        }
      }
      else {
        uVar2 = 1;
      }
    }
    else {
      uVar2 = 0;
    }
  }
  else if ((bVar3 == 0) && ((*(byte *)p_call_active_flag & 8) != 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}

