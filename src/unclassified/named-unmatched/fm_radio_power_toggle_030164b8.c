/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: fm_radio_power_toggle @ 030164b8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 124 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void fm_radio_power_toggle(void)

{
  int iVar1;
  byte bVar2;
  
  bVar2 = *(byte *)PTR_DAT_030165d8;
  iVar1 = poll_condition_group(0x1f);
  if (((*(char *)PTR_DAT_030165dc == '\0') && (PTR_DAT_030165e0[0xc] == '\0')) &&
     (iVar1 != 0 && (bVar2 & 1) != 0)) {
    bVar2 = (byte)PTR_DAT_030165e4[1] >> 7 ^ 1;
    PTR_DAT_030165e4[1] = PTR_DAT_030165e4[1] & 0x7f | bVar2 << 7;
    if (bVar2 == 0) {
      rda5807m_fm_off();
      ui_event_notify(0x19);
    }
    else {
      mode_transition_cleanup();
      ui_event_notify(0x18);
      rda5807m_fm_on();
    }
    write_field_and_mbox_post(1,100);
  }
  else {
    ui_event_notify(0x21);
  }
  return;
}

