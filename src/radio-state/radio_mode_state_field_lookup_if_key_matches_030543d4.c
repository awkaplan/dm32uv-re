/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: radio_mode_state_field_lookup_if_key_matches @ 030543d4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 116 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: radio-state
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined1 radio_mode_state_field_lookup_if_key_matches(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined1 uStack_10;
  
  if (p_radio_mode_state_0003e318[1].flags_0x5 == 1) {
    iVar3 = 4;
  }
  else if (p_radio_mode_state_0003e318[1].flags_0x5 == 2) {
    iVar3 = 5;
  }
  else {
    iVar3 = 2;
  }
  uStack_10 = 0;
  uStack_18 = *(undefined4 *)(param_1 + iVar3);
  uStack_14 = ((undefined4 *)(param_1 + iVar3))[1];
  iVar2 = strcmp_byte_ordinal(PTR_LAB_03054460,&uStack_18);
  if (iVar2 == 0) {
    uVar1 = *(undefined1 *)(param_1 + iVar3 + 10);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

