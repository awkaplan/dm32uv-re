/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: comma_delimited_field_extractor @ 030113c8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 88 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void comma_delimited_field_extractor(int param_1,undefined1 *param_2,int param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  uVar2 = 0;
  iVar3 = 0;
  iVar4 = 0;
  do {
    uVar1 = strlen_ck803s(param_1);
    if (uVar1 <= uVar2) {
      *param_2 = 0;
      return;
    }
    if (*(char *)(param_1 + uVar2) == ',') {
      iVar4 = iVar4 + 1;
      if (iVar4 == param_3) {
        param_2[iVar3] = 0;
        return;
      }
      iVar3 = 0;
    }
    else {
      param_2[iVar3] = *(char *)(param_1 + uVar2);
      iVar3 = iVar3 + 1;
      if (param_4 + -1 < iVar3) {
        *param_2 = 0;
        return;
      }
    }
    uVar2 = uVar2 + 1;
  } while( true );
}

