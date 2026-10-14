/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: malloc_best_fit @ 0306fd40 (file base 0x03000000; code starts at 0x03001000)
 * Size: 138 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void * malloc_best_fit(int size)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint in_r3;
  uint uVar6;
  undefined4 *unaff_r6;
  
  noop_stub_03070678(DAT_0306fdcc);
  puVar2 = PTR_DAT_0306fdd4;
  puVar5 = PTR_DAT_0306fdd0;
  if (*PTR_DAT_0306fdd0 == 0) {
    PTR_DAT_0306fdd0[1] = PTR_DAT_0306fdd4;
    *puVar2 = 0;
    in_r3 = (DAT_0306fdd8 - (int)puVar2) - 8;
    puVar2[1] = in_r3;
    *puVar5 = 1;
  }
  uVar6 = size + 7U & 0xfffffff8;
  puVar2 = (undefined4 *)0x0;
  puVar1 = (undefined4 *)puVar5[1];
  puVar5 = puVar5 + 1;
  while (puVar3 = puVar1, puVar3 != (undefined4 *)0x0) {
    uVar4 = puVar3[1];
    if ((uVar6 <= uVar4) && ((puVar2 == (undefined4 *)0x0 || (uVar4 < in_r3)))) {
      puVar2 = puVar3;
      in_r3 = uVar4;
      unaff_r6 = puVar5;
    }
    puVar5 = puVar3;
    puVar1 = (undefined4 *)*puVar3;
  }
  if (puVar2 != (undefined4 *)0x0) {
    if ((int)(puVar2[1] - uVar6) < 0xf) {
      *unaff_r6 = *puVar2;
    }
    else {
      puVar5 = (undefined4 *)((int)puVar2 + uVar6 + 8);
      *puVar5 = *puVar2;
      puVar5[1] = (puVar2[1] + -8) - uVar6;
      *unaff_r6 = puVar5;
      puVar2[1] = uVar6;
    }
    puVar2 = puVar2 + 2;
  }
  noop_stub_0307067c(DAT_0306fdcc);
  return puVar2;
}

