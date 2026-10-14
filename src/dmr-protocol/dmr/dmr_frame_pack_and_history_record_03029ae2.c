/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dmr_frame_pack_and_history_record @ 03029ae2 (file base 0x03000000; code starts at 0x03001000)
 * Size: 124 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: dmr-protocol
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined4 dmr_frame_pack_and_history_record(undefined4 param_1,undefined4 param_2,byte param_3)

{
  byte bVar1;
  char cVar2;
  int unaff_r4;
  char *unaff_r5;
  
  bVar1 = unaff_r5[7];
  if (bVar1 < 0x80) {
    if ((0x7d < bVar1) || (bVar1 == 0)) {
      *(undefined1 *)(unaff_r4 + 5) = 0xa4;
      *(char *)(unaff_r4 + 6) = unaff_r5[1];
      *(char *)(unaff_r4 + 8) = unaff_r5[7];
      *(char *)(unaff_r4 + 9) = (char)*(undefined2 *)(unaff_r5 + 0x12);
      *(char *)(unaff_r4 + 10) = (char)((uint)*(undefined4 *)(unaff_r5 + 0x10) >> 8);
      *(char *)(unaff_r4 + 0xb) = (char)*(undefined4 *)(unaff_r5 + 0x10);
      *(char *)(unaff_r4 + 0xc) = (char)*(undefined2 *)(unaff_r5 + 0xe);
      *(char *)(unaff_r4 + 0xd) = (char)((uint)*(undefined4 *)(unaff_r5 + 0xc) >> 8);
      *(char *)(unaff_r4 + 0xe) = (char)*(undefined4 *)(unaff_r5 + 0xc);
    }
  }
  else if ((bVar1 == 0x80) || (0xfd < bVar1)) {
    *(byte *)(unaff_r4 + 5) = param_3 | 0x80;
    *(char *)(unaff_r4 + 6) = unaff_r5[1];
    *(char *)(unaff_r4 + 8) = unaff_r5[7];
    *(char *)(unaff_r4 + 9) = (char)*(undefined2 *)(unaff_r5 + 0xe);
    *(char *)(unaff_r4 + 10) = (char)((uint)*(undefined4 *)(unaff_r5 + 0xc) >> 8);
    *(char *)(unaff_r4 + 0xb) = (char)*(undefined4 *)(unaff_r5 + 0xc);
    *(char *)(unaff_r4 + 0xc) = (char)*(undefined2 *)(unaff_r5 + 0x12);
    *(char *)(unaff_r4 + 0xd) = (char)((uint)*(undefined4 *)(unaff_r5 + 0x10) >> 8);
    *(char *)(unaff_r4 + 0xe) = (char)*(undefined4 *)(unaff_r5 + 0x10);
  }
  history_slot_link_append();
  if ((p_call_setup_sm_state_aux->mode_0x1 == 4) &&
     ((((cVar2 = *unaff_r5, cVar2 == '\x04' || (cVar2 == '\'')) || (cVar2 == '\x1f')) ||
      ((cVar2 == '\x1d' || ((cVar2 == '$' && (-1 < unaff_r5[7])))))))) {
    history_record_push();
  }
  return 0;
}

