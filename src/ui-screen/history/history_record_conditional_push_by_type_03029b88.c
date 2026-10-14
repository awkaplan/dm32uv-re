/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: history_record_conditional_push_by_type @ 03029b88 (file base 0x03000000; code starts at 0x03001000)
 * Size: 68 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-screen
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined4 history_record_conditional_push_by_type(void)

{
  char cVar1;
  char *unaff_r5;
  
  history_slot_link_append();
  if ((p_call_setup_sm_state_aux->mode_0x1 == 4) &&
     ((((cVar1 = *unaff_r5, cVar1 == '\x04' || (cVar1 == '\'')) || (cVar1 == '\x1f')) ||
      ((cVar1 == '\x1d' || ((cVar1 == '$' && (-1 < unaff_r5[7])))))))) {
    history_record_push();
  }
  return 0;
}

