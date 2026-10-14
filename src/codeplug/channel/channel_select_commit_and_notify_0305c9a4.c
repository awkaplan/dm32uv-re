/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_select_commit_and_notify @ 0305c9a4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 104 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void channel_select_commit_and_notify(int param_1__w,undefined4 param_2,undefined4 param_3,int param_4__w,int param_5__w)

{
  undefined1 param_1 = (undefined1)param_1__w;
  undefined1 param_4 = (undefined1)param_4__w;
  undefined1 param_5 = (undefined1)param_5__w;
  if ((p_radio_mode_state_0003e318->flags_0x7 & 0x18) == 0) {
    p_radio_mode_state_0003e318[1].flags_0x6 = p_radio_mode_state_0003e318[1].flags_0x6 & 0x3f;
    channel_select_type_dispatch(param_1,param_2,param_3,param_4,param_5);
    write_status_mode_byte_pair(*(undefined1 *)((uint)*DAT_0305ca40 + DAT_0305ca44),0);
  }
  else {
    write_status_mode_byte_pair(*(undefined1 *)((uint)*DAT_0305ca40 + DAT_0305ca44),0);
    ui_event_notify(0x1b);
  }
  return;
}

