/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: snprintf_numeric_to_buffer @ 030706c4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 92 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: runtime-lib
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void snprintf_numeric_to_buffer(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  int local_28 [3];
  undefined1 *local_1c;
  undefined *puStack_18;
  
  local_1c = (undefined1 *)local_28;
  if (param_2 == 0) {
    local_28[2] = 0;
  }
  else {
    local_28[2] = param_2 - 1;
  }
  local_28[1] = 0;
  puStack_18 = PTR_strbuf_append_bounded_03070720;
  local_28[0] = param_1;
  uVar1 = vfprintf_core(&local_1c,param_3,param_4);
  if (((param_1 != 0) && (param_2 != 0)) && (-1 < (int)uVar1)) {
    if ((param_2 != 0xffffffff) && (param_2 <= uVar1)) {
      *(undefined1 *)(param_1 + param_2 + -1) = 0;
      return;
    }
    *(undefined1 *)(param_1 + uVar1) = 0;
  }
  return;
}

