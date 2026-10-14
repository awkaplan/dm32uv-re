/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: tx_disable_mode_gate_check @ 03017040 (file base 0x03000000; code starts at 0x03001000)
 * Size: 156 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rf-frontend
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined4 tx_disable_mode_gate_check(char param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar2 = scan_entry_get_mode_bits(0xc);
  if ((p_radio_mode_state_0003e318->flags_0x3 & 0x40) == 0) {
    iVar3 = poll_condition_group(0xc);
    bVar1 = iVar3 != 0;
    if (((param_1 == '\0') &&
        (*(char *)((uint)p_menu_screen_state->index_0x1 + DAT_03017170 + 2) == '\0')) &&
       (*(char *)PTR_DAT_03017174 == '\x04')) {
      bVar1 = false;
    }
    if (iVar2 != 1) {
      if (iVar2 == 0) {
        bVar1 = false;
      }
      else if (iVar2 == 2) {
        bVar1 = false;
      }
    }
    if ((PTR_DAT_03017178[1] == '\0') && (bVar1)) {
      if ((PTR_DAT_0301717c[1] & 0x80) != 0) {
        rda5807m_fm_off();
      }
      *(undefined1 *)PTR_active_screen_subtype_03017180 = 2;
      PTR_DAT_03017178[1] = 1;
      write_field_and_mbox_post(1,0x18);
      uVar4 = 1;
    }
    else {
      ui_event_notify(0x21);
      uVar4 = 0;
    }
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}

