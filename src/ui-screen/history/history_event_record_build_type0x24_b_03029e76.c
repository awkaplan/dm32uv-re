/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: history_event_record_build_type0x24_b @ 03029e76 (file base 0x03000000; code starts at 0x03001000)
 * Size: 28 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-screen
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void history_event_record_build_type0x24_b(void)

{
  undefined1 uStack00000008;
  undefined1 uStack00000009;
  undefined1 uStack0000000a;
  undefined1 uStack0000000f;
  undefined4 uStack00000018;
  
  uStack00000008 = 0x24;
  uStack00000009 = 0x10;
  uStack0000000a = 0;
  uStack0000000f = 0x7e;
  uStack00000018 = *(undefined4 *)&p_call_setup_sm_state_aux->field_0x24_0;
  PTR_DAT_03029f24[4] = 0;
  history_record_push_type3(&stack0x00000008);
  *(undefined1 *)p_call_setup_sm_state = 2;
  return;
}

