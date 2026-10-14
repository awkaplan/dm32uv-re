/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: settings_value_step_by_ten_clamped_write @ 0306597c (file base 0x03000000; code starts at 0x03001000)
 * Size: 74 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void settings_value_step_by_ten_clamped_write(char param_1)

{
  ushort uVar1;
  ushort uVar2;
  short sVar3;
  ushort uVar4;
  undefined4 *puVar5;
  
  puVar5 = PTR_DAT_03065b40;
  uVar1 = *(ushort *)PTR_DAT_03065b38;
  uVar2 = *(ushort *)PTR_DAT_03065b3c;
  if (param_1 == '\0') {
    uVar4 = *(ushort *)PTR_DAT_03065b40;
    if (uVar4 < 0xb) {
      *(ushort *)PTR_DAT_03065b40 = uVar1;
    }
    else {
      *(ushort *)PTR_DAT_03065b40 = uVar4 - 10;
      if ((ushort)(uVar4 - 10) < uVar2) {
        *(ushort *)puVar5 = uVar1;
      }
    }
  }
  else {
    sVar3 = *(short *)PTR_DAT_03065b40;
    *(ushort *)PTR_DAT_03065b40 = sVar3 + 10U;
    if (uVar1 < (ushort)(sVar3 + 10U)) {
      *(ushort *)puVar5 = uVar2;
    }
  }
  bcd_pack_and_write_flash_block4_0x702(*(undefined2 *)PTR_DAT_03065b40);
  return;
}

