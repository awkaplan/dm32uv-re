/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: gps_coordinate_table_entry_parse @ 03011aa4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 124 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: gps
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void gps_coordinate_table_entry_parse(uint param_1,char *param_2,char *param_3)

{
  char cVar1;
  int iVar2;
  char cVar3;
  
  param_1 = param_1 & 0xff;
  if (0x19 < param_1) {
    param_1 = 0;
  }
  iVar2 = *(int *)(*PTR_PTR_03011b3c + param_1 * 4);
  if (*(char *)(iVar2 + 3) == '\0') {
    cVar1 = '\0';
    cVar3 = '\0';
  }
  else {
    if (*(char *)(iVar2 + 5) == ':') {
      cVar3 = *(char *)(iVar2 + 4) + -0x30;
      cVar1 = *(char *)(iVar2 + 6) * '\n' + *(char *)(iVar2 + 7) + -0x10;
    }
    else {
      cVar3 = *(char *)(iVar2 + 5) + -0x10 + *(char *)(iVar2 + 4) * '\n';
      cVar1 = *(char *)(iVar2 + 8) + -0x10 + *(char *)(iVar2 + 7) * '\n';
    }
    if (*(char *)(iVar2 + 3) == '-') {
      cVar3 = -cVar3;
    }
  }
  *param_2 = cVar3;
  *param_3 = cVar1;
  return;
}

