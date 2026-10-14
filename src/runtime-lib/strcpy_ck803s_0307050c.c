/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: strcpy_ck803s @ 0307050c (file base 0x03000000; code starts at 0x03001000)
 * Size: 34 bytes
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

void strcpy_ck803s(char *param_1,char *param_2)

{
  char cVar1;
  
  if ((((uint)param_2 | (uint)param_1) & 3) != 0) {
    do {
      cVar1 = *param_2;
      *param_1 = cVar1;
      param_2 = param_2 + 1;
      param_1 = param_1 + 1;
    } while (cVar1 != '\0');
    return;
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

