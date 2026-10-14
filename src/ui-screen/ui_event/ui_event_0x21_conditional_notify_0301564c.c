/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: ui_event_0x21_conditional_notify @ 0301564c (file base 0x03000000; code starts at 0x03001000)
 * Size: 44 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-screen
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void ui_event_0x21_conditional_notify(void)

{
  if ((PTR_DAT_0301579c[3] & 2) != 0) {
    ui_event_notify(0x21);
  }
  if ((*(byte *)PTR_call_active_flag_030157a0 & 10) == 0) {
    write_field_and_mbox_post(1,0x17);
  }
  return;
}

