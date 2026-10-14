/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: memcpy_ck803s @ 030703bc (file base 0x03000000; code starts at 0x03001000)
 * Size: 126 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: runtime-lib
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void memcpy_ck803s(void *dest,void *src,int n)

{
  undefined1 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  if ((((uint)src | (uint)dest) & 3) == 0) {
    for (; 0xf < n; n = n + -0x10) {
      uVar2 = *(undefined4 *)((int)src + 4);
      uVar3 = *(undefined4 *)((int)src + 8);
      *(undefined4 *)dest = *(undefined4 *)src;
      uVar4 = *(undefined4 *)((int)src + 0xc);
      *(undefined4 *)((int)dest + 4) = uVar2;
      *(undefined4 *)((int)dest + 8) = uVar3;
      *(undefined4 *)((int)dest + 0xc) = uVar4;
      src = (void *)((int)src + 0x10);
      dest = (void *)((int)dest + 0x10);
    }
    for (; 3 < n; n = n + -4) {
      uVar2 = *(undefined4 *)src;
      src = (void *)((int)src + 4);
      *(undefined4 *)dest = uVar2;
      dest = (void *)((int)dest + 4);
    }
    for (; n != 0; n = n + -1) {
      uVar1 = *(undefined1 *)src;
      src = (void *)((int)src + 1);
      *(undefined1 *)dest = uVar1;
      dest = (void *)((int)dest + 1);
    }
  }
  else {
    for (; n != 0; n = n + -1) {
      uVar1 = *(undefined1 *)src;
      src = (void *)((int)src + 1);
      *(undefined1 *)dest = uVar1;
      dest = (void *)((int)dest + 1);
    }
  }
  return;
}

