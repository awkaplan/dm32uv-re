/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: strlen_unaligned_path @ 030010e4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 28 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: runtime-lib
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Control flow encountered bad instruction data */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

int strlen_unaligned_path(char *param_1)

{
  int iVar1;
  
  if (((uint)param_1 & 3) != 0) {
    iVar1 = 0;
    for (; *param_1 != '\0'; param_1 = param_1 + 1) {
      iVar1 = iVar1 + 1;
    }
    return iVar1;
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

