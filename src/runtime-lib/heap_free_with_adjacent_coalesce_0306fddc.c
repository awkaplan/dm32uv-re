/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: heap_free_with_adjacent_coalesce @ 0306fddc (file base 0x03000000; code starts at 0x03001000)
 * Size: 112 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: runtime-lib
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void heap_free_with_adjacent_coalesce(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  noop_stub_03070678(DAT_0306fe4c);
  if (param_1 != 0) {
    puVar2 = (undefined4 *)(param_1 + -8);
    puVar1 = (undefined4 *)(param_1 + *(int *)(param_1 + -4));
    puVar3 = (undefined4 *)*PTR_DAT_0306fe50;
    puVar5 = PTR_DAT_0306fe50;
    while( true ) {
      puVar4 = puVar3;
      if (puVar1 == puVar3) {
        *(int *)(param_1 + -4) = *(int *)(param_1 + -4) + puVar1[1] + 8;
        puVar4 = (undefined4 *)*puVar1;
      }
      if (puVar4 == (undefined4 *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = (undefined4 *)(puVar4[1] + 8 + (int)puVar4);
      }
      if (puVar3 == puVar2) {
        puVar4[1] = puVar4[1] + puVar3[1] + 8;
        puVar3[1] = 0;
        *puVar3 = puVar4;
        *puVar5 = puVar4;
        goto LAB_0306fe40;
      }
      if (puVar3 < puVar2) break;
      puVar3 = (undefined4 *)*puVar4;
      puVar5 = puVar4;
    }
    *puVar5 = puVar2;
    *puVar2 = puVar4;
  }
LAB_0306fe40:
  noop_stub_0307067c(DAT_0306fe4c);
  return;
}

