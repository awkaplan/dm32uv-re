/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: short_sample_vs_twolevel_pattern_sse_metric @ 030c932c (file base 0x03000000; code starts at 0x03001000)
 * Size: 76 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

int short_sample_vs_twolevel_pattern_sse_metric(int param_1,int param_2,short param_3,short param_4)

{
  short *psVar1;
  int iVar2;
  int iVar3;
  
  param_3 = param_3 + -1;
  if (param_3 < 0) {
    iVar3 = 0;
  }
  else {
    psVar1 = (short *)(param_2 + param_3 * 2);
    iVar3 = 0;
    do {
      param_3 = param_3 + -1;
      iVar2 = (int)(short)(*psVar1 -
                          ((short)(1 << ((int)param_4 & 0x3fU)) + -1) * ((ushort)param_1 & 1));
      iVar3 = iVar3 + iVar2 * iVar2;
      param_1 = param_1 >> 1;
      psVar1 = psVar1 + -1;
    } while (-1 < param_3);
  }
  return iVar3;
}

