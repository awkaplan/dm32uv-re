/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: vfo_scan_add_toggle_on_poll_change @ 030161fc (file base 0x03000000; code starts at 0x03001000)
 * Size: 132 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-screen
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void vfo_scan_add_toggle_on_poll_change(void)

{
  int iVar1;
  byte bVar2;
  int iStack_40;
  int iStack_3c;
  byte bStack_36;
  
  busy_wait_delay_loop_counted(&iStack_40);
  bVar2 = bStack_36 & 8;
  iVar1 = poll_condition_group(0x1a);
  if (((bStack_36 & 0x80) == 0) && (iVar1 != 0 && (iStack_40 != iStack_3c || bVar2 != 0))) {
    mode_transition_cleanup();
    if ((bStack_36 & 8) == 0) {
      vfo_scan_add_toggle(1);
      ui_event_notify_alt(0x10);
      ui_event_notify(0x18);
    }
    else {
      vfo_scan_add_toggle(0);
      ui_event_notify_alt(0x11);
      ui_event_notify(0x19);
    }
  }
  else {
    ui_event_notify(0x21);
  }
  return;
}

