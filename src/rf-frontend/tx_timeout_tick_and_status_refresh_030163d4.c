/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: tx_timeout_tick_and_status_refresh @ 030163d4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 72 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rf-frontend
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void tx_timeout_tick_and_status_refresh(void)

{
  int iVar1;
  
  iVar1 = poll_condition_group(5);
  if (iVar1 != 0) {
    tx_timeout_cleanup();
    iVar1 = settings_read_dispatcher(0x10);
    if (~(iVar1 != 0) == 0) {
      ui_event_notify(0x18);
    }
    settings_write_dispatcher(0x10,~(iVar1 != 0));
    if ((*(char *)PTR_DAT_030164a0 == '\0') || (*(char *)PTR_DAT_030164a0 == '[')) {
      display_draw_status_bar();
    }
  }
  return;
}

