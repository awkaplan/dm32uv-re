/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: history_event_record_build_type0xbd @ 03029a4e (file base 0x03000000; code starts at 0x03001000)
 * Size: 60 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-screen
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined4 history_event_record_build_type0xbd(void)

{
  char cVar1;
  int unaff_r4;
  char *unaff_r5;
  
  *(undefined1 *)(unaff_r4 + 5) = 0xbd;
  *(char *)(unaff_r4 + 6) = unaff_r5[1];
  cVar1 = unaff_r5[9];
  *(char *)(unaff_r4 + 7) = cVar1 << 7;
  *(char *)(unaff_r4 + 7) = cVar1 << 7 | unaff_r5[10] << 6;
  *(char *)(unaff_r4 + 8) = unaff_r5[8];
  *(char *)(unaff_r4 + 9) = (char)*(undefined2 *)(unaff_r5 + 0xe);
  *(char *)(unaff_r4 + 10) = (char)((uint)*(undefined4 *)(unaff_r5 + 0xc) >> 8);
  *(char *)(unaff_r4 + 0xb) = (char)*(undefined4 *)(unaff_r5 + 0xc);
  *(char *)(unaff_r4 + 0xc) = (char)*(undefined2 *)(unaff_r5 + 0x12);
  *(char *)(unaff_r4 + 0xd) = (char)((uint)*(undefined4 *)(unaff_r5 + 0x10) >> 8);
  *(char *)(unaff_r4 + 0xe) = (char)*(undefined4 *)(unaff_r5 + 0x10);
  history_slot_link_append();
  if ((p_call_setup_sm_state_aux->mode_0x1 == 4) &&
     ((((cVar1 = *unaff_r5, cVar1 == '\x04' || (cVar1 == '\'')) || (cVar1 == '\x1f')) ||
      ((cVar1 == '\x1d' || ((cVar1 == '$' && (-1 < unaff_r5[7])))))))) {
    history_record_push();
  }
  return 0;
}

