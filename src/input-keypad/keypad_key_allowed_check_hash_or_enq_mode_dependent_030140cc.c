/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: keypad_key_allowed_check_hash_or_enq_mode_dependent @ 030140cc (file base 0x03000000; code starts at 0x03001000)
 * Size: 94 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: input-keypad
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

byte keypad_key_allowed_check_hash_or_enq_mode_dependent(char param_1)

{
  int iVar1;
  byte bVar2;
  
  bVar2 = p_vfo_display_state->flags_0x8 & 0xf0;
  if (bVar2 == 0x10) {
    if ((*(byte *)p_call_active_flag & 1) == 0) {
      iVar1 = read_byte_field_0302e120();
      if (iVar1 != 2) {
        return 1;
      }
      return ~(param_1 != '#');
    }
  }
  else {
    if (bVar2 != 0) {
      return 1;
    }
    if ((*(byte *)p_call_active_flag & 4) == 0) {
      return 1;
    }
  }
  if (param_1 == '#') {
    bVar2 = 1;
  }
  else {
    bVar2 = ~(param_1 != '\x05');
  }
  return bVar2;
}

