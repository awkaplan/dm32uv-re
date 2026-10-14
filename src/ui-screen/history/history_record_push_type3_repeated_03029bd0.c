/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: history_record_push_type3_repeated @ 03029bd0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 92 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-screen
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined4
history_record_push_type3_repeated
          (undefined1 param_1,undefined4 param_2,undefined4 param_3,char param_4,char param_5,
          char param_6)

{
  undefined4 uVar1;
  undefined1 local_30;
  undefined1 uStack_2f;
  char cStack_28;
  undefined1 uStack_27;
  undefined1 uStack_26;
  undefined4 uStack_24;
  undefined4 uStack_20;
  
  if (param_4 == '\0') {
    uVar1 = 1;
  }
  else {
    local_30 = 0x3d;
    uStack_2f = 0;
    uStack_26 = param_1;
    uStack_24 = param_2;
    uStack_20 = param_3;
    do {
      cStack_28 = param_4 + param_6 + -1;
      uStack_27 = param_5 != '\0';
      history_record_push_type3(&local_30);
      param_4 = param_4 + -1;
    } while (param_4 != '\0');
    uVar1 = 0;
  }
  return uVar1;
}

