/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: call_setup_mode_flag_dispatch @ 03014d34 (file base 0x03000000; code starts at 0x03001000)
 * Size: 110 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: dmr-protocol
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void call_setup_mode_flag_dispatch(void)

{
  int iVar1;
  
  if ((*(byte *)PTR_DAT_03014e58 & 2) == 0) {
    if ((*(byte *)((int)PTR_DAT_03014e58 + 5) & 1) == 0) {
      OSFlagPost_wrapper_set(p_ucos_flaggrp_0003a4f0,8);
    }
    else {
      iVar1 = get_current_mode_state1();
      if (iVar1 == 0) {
        if (*(char *)PTR_DAT_03014e5c == '\0') {
          OSFlagPost_wrapper_set(p_ucos_flaggrp_0003a4f0,8);
        }
        else {
          *(byte *)((int)PTR_DAT_03014e58 + 5) = *(byte *)((int)PTR_DAT_03014e58 + 5) & 0xfe;
          ui_event_notify(0x21);
          dialog_show_number_or_alt();
        }
      }
      else {
        *(byte *)((int)PTR_DAT_03014e58 + 5) = *(byte *)((int)PTR_DAT_03014e58 + 5) & 0xfe;
        ui_event_notify(0x1b);
      }
    }
  }
  return;
}

