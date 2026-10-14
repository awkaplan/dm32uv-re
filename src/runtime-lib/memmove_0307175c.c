/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: memmove @ 0307175c (file base 0x03000000; code starts at 0x03001000)
 * Size: 184 bytes
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

void * memmove(void *dest,void *src,int n)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined4 *puVar6;
  
  if (n != 0) {
    if (((int)dest < (int)src) || (n <= (int)dest - (int)src)) {
      puVar4 = dest;
      puVar6 = dest;
      if ((((uint)dest | (uint)src) & 3) != 0) {
        do {
          *puVar4 = *(undefined1 *)src;
          src = (void *)((int)src + 1);
          puVar4 = puVar4 + 1;
          n = n + -1;
        } while (n != 0);
        return dest;
      }
      for (; 0xf < n; n = n + -0x10) {
        uVar1 = *(undefined4 *)((int)src + 4);
        uVar3 = *(undefined4 *)((int)src + 8);
        *puVar6 = *(undefined4 *)src;
        uVar2 = *(undefined4 *)((int)src + 0xc);
        puVar6[1] = uVar1;
        puVar6[2] = uVar3;
        puVar6[3] = uVar2;
        src = (void *)((int)src + 0x10);
        puVar6 = puVar6 + 4;
      }
      for (; 3 < n; n = n + -4) {
        uVar1 = *(undefined4 *)src;
        src = (void *)((int)src + 4);
        *puVar6 = uVar1;
        puVar6 = puVar6 + 1;
      }
      if (((n != 0) && (*(undefined1 *)puVar6 = *(undefined1 *)src, n != 1)) &&
         (*(undefined1 *)((int)puVar6 + 1) = *(undefined1 *)((int)src + 1), n != 2)) {
        *(undefined1 *)((int)puVar6 + 2) = *(undefined1 *)((int)src + 2);
        return dest;
      }
    }
    else {
      puVar5 = (undefined1 *)((int)dest + n);
      puVar4 = (undefined1 *)((int)src + n);
      do {
        puVar5 = puVar5 + -1;
        puVar4 = puVar4 + -1;
        *puVar5 = *puVar4;
        n = n + -1;
      } while (n != 0);
    }
  }
  return dest;
}

