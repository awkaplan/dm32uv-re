/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flash_talker_record_read @ 03033718 (file base 0x03000000; code starts at 0x03001000)
 * Size: 96 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: flash-storage
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void flash_talker_record_read(uint param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 local_14;
  
  local_14 = 0;
  iVar2 = *PTR_DAT_03033858;
  flash_read_mutex_guarded(iVar2,&local_14,4);
  if (param_1 < 0xc351) {
    if (param_1 < 0x2d) {
      iVar2 = iVar2 + -0x4c + param_1 * 0x5c;
    }
    else {
      uVar1 = param_1 / 0x2c & 0xffff;
      param_1 = param_1 % 0x2c;
      if (param_1 == 0) {
        uVar1 = uVar1 - 1 & 0xffff;
        param_1 = 0x2c;
      }
      iVar2 = uVar1 * 0x1000 + iVar2 + (param_1 - 1) * 0x5c;
    }
    flash_read_mutex_guarded(iVar2,param_2,0x5c);
  }
  return;
}

