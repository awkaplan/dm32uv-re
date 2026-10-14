/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: memmove_overlap_safe @ 0306bb08 (file base 0x03000000; code starts at 0x03001000)
 * Size: 182 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: runtime-lib
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void memmove_overlap_safe(void *param_1,void *param_2,uint param_3)

{
  undefined1 *puVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  
  if (((param_3 != 0) && (param_1 != (void *)0x0)) && (param_2 != (void *)0x0)) {
    if (param_1 < param_2) {
      memcpy_ck803s(param_1,param_2,param_3);
    }
    else {
      puVar1 = (undefined1 *)((int)param_1 + (param_3 - 1));
      puVar3 = (undefined1 *)((int)param_2 + (param_3 - 1));
      if ((3 < (uint)((int)puVar1 - (int)puVar3)) &&
         (uVar5 = (uint)puVar1 & 3, uVar5 == ((uint)puVar3 & 3))) {
        if (uVar5 != 3) {
          uVar5 = uVar5 - 1;
          do {
            *puVar1 = *puVar3;
            puVar1 = puVar1 + -1;
            puVar3 = puVar3 + -1;
            param_3 = param_3 - 1;
            if (param_3 == 0) {
              return;
            }
            uVar5 = (uVar5 & 0xff) - 1;
          } while (-1 < (char)((char)uVar5 + '\x01'));
        }
        puVar2 = (undefined4 *)(puVar1 + -3);
        puVar4 = (undefined4 *)(puVar3 + -3);
        uVar5 = param_3;
        puVar7 = puVar2;
        puVar8 = puVar4;
        if (3 < param_3) {
          do {
            *puVar7 = *puVar8;
            uVar5 = uVar5 - 4;
            puVar7 = puVar7 + -1;
            puVar8 = puVar8 + -1;
          } while (3 < uVar5);
          uVar5 = ~(param_3 - 4) & 0xfffffffc;
          puVar2 = (undefined4 *)((int)puVar2 + uVar5);
          puVar4 = (undefined4 *)((int)puVar4 + uVar5);
          param_3 = param_3 - 4 & 3;
        }
        if (param_3 == 0) {
          return;
        }
        puVar1 = (undefined1 *)((int)puVar2 + 3);
        puVar3 = (undefined1 *)((int)puVar4 + 3);
      }
      iVar6 = 0;
      do {
        puVar1[iVar6] = puVar3[iVar6];
        iVar6 = iVar6 + -1;
      } while (iVar6 + param_3 != 0);
    }
  }
  return;
}

