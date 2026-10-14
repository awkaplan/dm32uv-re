/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: history_record_build_typed_dispatch @ 030265ac (file base 0x03000000; code starts at 0x03001000)
 * Size: 230 bytes
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
history_record_build_typed_dispatch
          (char param_1,undefined1 param_2,undefined1 param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6,byte param_7)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  puVar1 = PTR_DAT_03026798;
  if (param_1 == '\0') {
    *PTR_DAT_03026798 = 0;
    puVar1[1] = 0;
    puVar1[4] = 1;
    puVar1[5] = 4;
    *(undefined4 *)(puVar1 + 0x28) = param_4;
    *(undefined4 *)(puVar1 + 0x2c) = param_5;
    puVar1[0x11] = 0;
    puVar1[0x16] = 0;
    puVar1[0x17] = param_2;
    puVar1[0x18] = param_3;
    history_record_push_typed();
  }
  else if (param_1 == '\x01') {
    *PTR_DAT_03026798 = 0;
    puVar1[1] = 0;
    puVar1[4] = 1;
    puVar1[5] = 4;
    *(undefined4 *)(puVar1 + 0x28) = param_4;
    *(undefined4 *)(puVar1 + 0x2c) = param_5;
    puVar1[0x11] = 0;
    puVar1[0x16] = 1;
    puVar1[0x17] = param_2;
    puVar1[0x18] = param_3;
    history_record_push_typed();
  }
  else if (param_1 == '\x02') {
    *PTR_DAT_03026798 = 0;
    puVar1[1] = 0;
    puVar1[4] = 1;
    puVar1[5] = 4;
    *(undefined4 *)(puVar1 + 0x28) = param_4;
    *(undefined4 *)(puVar1 + 0x2c) = param_5;
    puVar2 = PTR_DAT_03026798;
    if (param_7 < 9) {
      PTR_DAT_03026798[0x11] = 1;
      *(undefined2 *)(puVar2 + 0x36c) = 8;
    }
    else {
      puVar1[0x11] = 2;
      *(undefined2 *)(puVar1 + 0x36c) = 0x14;
    }
    puVar1 = PTR_DAT_03026798;
    PTR_DAT_03026798[0x16] = 2;
    puVar1[0x17] = param_2;
    puVar1[0x18] = param_3;
    puVar1[0x35] = 7;
    puVar1[0x34] = 0xc;
    history_record_push_typed(puVar1);
    *(undefined2 *)(puVar1 + 0x36e) = 0;
    memcpy_bytes_iram(puVar1 + 0x4b,param_6,*(undefined2 *)(puVar1 + 0x36c));
    dmr_message_split_into_history_slots(puVar1);
  }
  return 0;
}

