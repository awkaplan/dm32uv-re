/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: reverse_char_search_bounded @ 0306ccb0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 70 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

char * reverse_char_search_bounded(char *param_1,int param_2,char param_3)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  
  if (param_1 == (char *)0x0) {
    pcVar3 = (char *)0x0;
  }
  else if (param_2 == 0) {
    pcVar3 = (char *)0x0;
  }
  else {
    iVar2 = strnlen_impl(param_1,param_2 + -1);
    pcVar3 = param_1 + iVar2;
    if (pcVar3 != (char *)0x0) {
      if (param_1 == pcVar3) {
LAB_0306cce2:
        if (*pcVar3 != param_3) {
          pcVar3 = (char *)0x0;
        }
      }
      else {
        cVar1 = *pcVar3;
        while (cVar1 != param_3) {
          pcVar3 = pcVar3 + -1;
          if (param_1 == pcVar3) goto LAB_0306cce2;
          cVar1 = *pcVar3;
        }
      }
    }
  }
  return pcVar3;
}

