/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: radio_mode_enter_and_refresh @ 0306817c (file base 0x03000000; code starts at 0x03001000)
 * Size: 102 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: radio-state
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void radio_mode_enter_and_refresh(char param_1)

{
  undefined1 *puVar1;
  int iVar2;
  
  if (param_1 == '\0') {
    if ((p_radio_mode_state_0003e318[2].flags_0x2 & 8) == 0) {
      p_radio_mode_state_0003e318[2].flags_0x2 = p_radio_mode_state_0003e318[2].flags_0x2 & 0xf7 | 8
      ;
    }
  }
  else if ((p_radio_mode_state_0003e318[2].flags_0x2 & 0x10) == 0) {
    p_radio_mode_state_0003e318[2].flags_0x2 =
         p_radio_mode_state_0003e318[2].flags_0x2 & 0xef | 0x10;
  }
  puVar1 = PTR_DAT_030682a8;
  *PTR_DAT_030682a8 = *PTR_DAT_030682a8 & 0xf3 | 0xc;
  puVar1[4] = 0x32;
  backup_or_restore_slot_from_scratch();
  iVar2 = get_current_mode_state2();
  if (iVar2 != 0) {
    set_flag_byte_03064328(3);
  }
  return;
}

