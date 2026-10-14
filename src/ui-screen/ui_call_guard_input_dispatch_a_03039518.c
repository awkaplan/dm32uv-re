/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: ui_call_guard_input_dispatch_a @ 03039518 (file base 0x03000000; code starts at 0x03001000)
 * Size: 160 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-screen
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void ui_call_guard_input_dispatch_a(void)

{
  byte bVar1;
  undefined1 *puVar2;
  int iVar3;
  
  if (((*(byte *)PTR_call_active_flag_03039668 & 8) == 0) ||
     ((iVar3 = bitwise_not_of_boolean_result(), iVar3 == 0 && ((PTR_DAT_0303966c[1] & 2) == 0)))) {
    write_status_mode_byte_pair(*(undefined1 *)((uint)(byte)PTR_DAT_03039660[2] + DAT_03039664),0);
    puVar2 = PTR_DAT_03039674;
    if ((PTR_DAT_03039674[3] & 2) == 0) {
      if ((((PTR_DAT_03039678[8] & 1) == 0) && (iVar3 = keypad_dispatch_not_inhibited(), iVar3 != 0)
          ) && ((*PTR_DAT_03039674 & 0x42) == 0)) {
        input_state_arm_if_not_busy();
      }
    }
    else {
      if ((PTR_DAT_03039674[3] & 8) != 0) {
        bVar1 = PTR_DAT_03039674[3];
        tx_abort_and_radio_state_reset();
        puVar2[3] = puVar2[3] & 0xef | (bVar1 >> 4 & 1) << 4;
      }
      dialog_header_status_bit4_toggle_and_draw();
    }
  }
  else {
    *(undefined1 *)PTR_DAT_03039670 = 0x41;
    write_status_mode_byte_pair(0x70,1);
  }
  return;
}

