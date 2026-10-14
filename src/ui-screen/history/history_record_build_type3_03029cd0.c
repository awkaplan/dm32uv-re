/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: history_record_build_type3 @ 03029cd0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 24 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-screen
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void history_record_build_type3(undefined4 param_1,undefined4 param_2)

{
  undefined4 *record;
  
  record = PTR_DAT_03029d90;
  *(undefined1 *)PTR_DAT_03029d90 = 0x38;
  *(undefined1 *)((int)record + 1) = 0;
  record[3] = param_1;
  record[4] = param_2;
  history_record_push_type3(record);
  return;
}

