/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: OS_PrioGetHighest_variant2 @ 030c160c (file base 0x03000000; code starts at 0x03001000)
 * Size: 38 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

char OS_PrioGetHighest_variant2(void)

{
  char cVar1;
  int *piVar2;
  char cVar3;
  
  if (*PTR_OSPrioTbl_030c1674 == 0) {
    cVar3 = '\0';
    piVar2 = PTR_OSPrioTbl_030c1674;
    do {
      cVar3 = cVar3 + ' ';
      piVar2 = piVar2 + 1;
    } while (*piVar2 == 0);
  }
  else {
    cVar3 = '\0';
  }
  cVar1 = thin_wrapper_to_030c0000();
  return cVar3 + cVar1;
}

