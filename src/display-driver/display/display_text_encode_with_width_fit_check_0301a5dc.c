/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: display_text_encode_with_width_fit_check @ 0301a5dc (file base 0x03000000; code starts at 0x03001000)
 * Size: 190 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: display-driver
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void display_text_encode_with_width_fit_check(byte *param_1)

{
  undefined4 *puVar1;
  byte bVar2;
  ushort uVar3;
  uint uVar4;
  
  uVar4 = 0;
  *(byte *)(PTR_DAT_0301a6b0 + 5) = *(byte *)(PTR_DAT_0301a6b0 + 5) & 0xfe;
  uVar3 = 10;
  do {
    if (param_1[uVar4] == 0) goto LAB_0301a634;
    if ((param_1[uVar4] < 0x81) || (param_1[uVar4 + 1] < 0x81)) {
      uVar4 = uVar4 + 1;
      uVar3 = uVar3 + 0xc;
    }
    else {
      uVar4 = uVar4 + 2;
      uVar3 = uVar3 + 0x10;
    }
    uVar4 = uVar4 & 0xff;
  } while (uVar3 < 0xc4);
  *(byte *)(PTR_DAT_0301a6b0 + 5) = *(byte *)(PTR_DAT_0301a6b0 + 5) & 0xfe | 1;
LAB_0301a634:
  puVar1 = PTR_DAT_0301a6b0;
  if ((*(byte *)(PTR_DAT_0301a6b0 + 5) & 1) == 0) {
    *(byte *)(PTR_DAT_0301a6b0 + 5) = *(byte *)(PTR_DAT_0301a6b0 + 5) & 0xfe;
  }
  else {
    *(byte *)(PTR_DAT_0301a6b0 + 5) = *(byte *)(PTR_DAT_0301a6b0 + 5) & 0xfc | 1;
    bVar2 = strlen_ck803s(param_1);
    *(byte *)puVar1 = bVar2;
    memcpy_ck803s((void *)((int)puVar1 + 3),param_1,(uint)bVar2);
    *(undefined1 *)((int)puVar1 + bVar2 + 3) = 0;
    *(undefined1 *)((int)puVar1 + 2) = 1;
    if ((*param_1 < 0x81) || (param_1[1] < 0x81)) {
      *(undefined1 *)((int)PTR_DAT_0301a6b0 + 1) = 1;
    }
    else {
      *(undefined1 *)((int)puVar1 + 1) = 2;
    }
  }
  return;
}

