/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: libc_memcpy_bytes @ 03004274 (file base 0x03000000; code starts at 0x03001000)
 * Size: 22 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: runtime-lib
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void libc_memcpy_bytes(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  if (0 < param_3) {
    iVar1 = 0;
    do {
      *(undefined1 *)(param_1 + iVar1) = *(undefined1 *)(param_2 + iVar1);
      iVar1 = iVar1 + 1;
    } while (iVar1 != param_3);
  }
  return;
}

