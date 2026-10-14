/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: string_find_nth_comma_index @ 03011420 (file base 0x03000000; code starts at 0x03001000)
 * Size: 48 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: runtime-lib
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

char string_find_nth_comma_index(char *param_1,char param_2)

{
  char cVar1;
  char cVar2;
  char cVar3;
  
  cVar3 = '\0';
  cVar2 = '\0';
  do {
    cVar1 = cVar2;
    if ((*param_1 == ',') && (cVar3 = cVar3 + '\x01', cVar3 == param_2)) break;
    cVar2 = cVar1 + '\x01';
    param_1 = param_1 + 1;
  } while (cVar2 != 'd');
  return cVar1 + '\x01';
}

