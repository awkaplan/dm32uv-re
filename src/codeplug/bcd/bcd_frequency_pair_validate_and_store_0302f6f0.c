/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: bcd_frequency_pair_validate_and_store @ 0302f6f0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 190 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4 bcd_frequency_pair_validate_and_store(int param_1__w,byte *param_2)

{
  char param_1 = (char)param_1__w;
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined1 local_14;
  undefined1 uStack_13;
  byte bStack_12;
  byte bStack_11;
  
  bStack_11 = param_2[1];
  bStack_12 = *param_2 & 0xf0;
  uStack_13 = 0;
  local_14 = 0;
  iVar1 = bcd_frequency_in_range_check(param_1,&local_14);
  if (iVar1 == 0) {
    if (param_1 == '\0') {
      uVar2 = bcd_frequency_decode(&local_14,4);
      *PTR_DAT_0302f788 = uVar2;
      uVar2 = 1;
    }
    else {
      uVar2 = bcd_frequency_decode(&local_14,4);
      *PTR_DAT_0302f78c = uVar2;
      uVar2 = 1;
    }
  }
  else {
    uVar2 = 0;
  }
  bStack_11 = param_2[3] << 4 | param_2[2] >> 4;
  bStack_12 = param_2[2] << 4;
  iVar1 = bcd_frequency_in_range_check(param_1,&local_14);
  if (iVar1 == 0) {
    if (param_1 == '\0') {
      uVar3 = bcd_frequency_decode(&local_14,4);
      *PTR_DAT_0302f790 = uVar3;
    }
    else {
      uVar3 = bcd_frequency_decode(&local_14,4);
      *PTR_DAT_0302f944 = uVar3;
    }
  }
  else {
    uVar2 = 0;
  }
  if ((uint)*PTR_DAT_0302f94c <= (uint)*PTR_DAT_0302f948) {
    uVar2 = 0;
  }
  if ((uint)*PTR_DAT_0302f950 <= (uint)*PTR_DAT_0302f944) {
    uVar2 = 0;
  }
  return uVar2;
}

