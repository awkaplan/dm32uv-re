/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: memset_ck803s @ 0307043c (file base 0x03000000; code starts at 0x03001000)
 * Size: 158 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: runtime-lib
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void memset_ck803s(uint *param_1,uint param_2,int param_3)

{
  undefined1 uVar1;
  int iVar2;
  uint *puVar3;
  
  if (param_3 != 0) {
    uVar1 = (undefined1)param_2;
    iVar2 = param_3;
    puVar3 = param_1;
    if (((uint)param_1 & 3) != 0) {
      *(undefined1 *)param_1 = uVar1;
      iVar2 = param_3 + -1;
      if (iVar2 == 0) {
        return;
      }
      puVar3 = (uint *)((int)param_1 + 1);
      if (((uint)puVar3 & 3) != 0) {
        *(undefined1 *)puVar3 = uVar1;
        iVar2 = param_3 + -2;
        if (iVar2 == 0) {
          return;
        }
        puVar3 = (uint *)((int)param_1 + 2);
        if (((uint)puVar3 & 3) != 0) {
          *(undefined1 *)puVar3 = uVar1;
          iVar2 = param_3 + -3;
          puVar3 = (uint *)((int)param_1 + 3);
        }
      }
    }
    param_2 = param_2 | param_2 << 8;
    param_2 = param_2 | param_2 << 0x10;
    for (; 0xf < iVar2; iVar2 = iVar2 + -0x10) {
      *puVar3 = param_2;
      puVar3[1] = param_2;
      puVar3[2] = param_2;
      puVar3[3] = param_2;
      puVar3 = puVar3 + 4;
    }
    for (; 3 < iVar2; iVar2 = iVar2 + -4) {
      *puVar3 = param_2;
      puVar3 = puVar3 + 1;
    }
    if (((iVar2 != 0) && (*(undefined1 *)puVar3 = uVar1, iVar2 != 1)) &&
       (*(undefined1 *)((int)puVar3 + 1) = uVar1, iVar2 != 2)) {
      *(undefined1 *)((int)puVar3 + 2) = uVar1;
      return;
    }
  }
  return;
}

