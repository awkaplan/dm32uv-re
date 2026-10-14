/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: strncpy_nul_terminated @ 0306c994 (file base 0x03000000; code starts at 0x03001000)
 * Size: 98 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: runtime-lib
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

char * strncpy_nul_terminated(char *param_1,char *param_2,uint param_3)

{
  char *pcVar1;
  char cVar2;
  uint uVar3;
  
  if (param_1 != (char *)0x0) {
    if (param_2 == (char *)0x0) {
      param_1 = (char *)0x0;
    }
    else {
      cVar2 = *param_2;
      pcVar1 = param_1;
      if (cVar2 == '\0') {
        uVar3 = 0;
      }
      else if (param_3 == 0) {
        uVar3 = 0;
      }
      else {
        uVar3 = 0;
        do {
          *pcVar1 = cVar2;
          pcVar1 = pcVar1 + 1;
          if (pcVar1 == (char *)0x0) {
            return (char *)0x0;
          }
          param_2 = param_2 + 1;
          uVar3 = uVar3 + 1;
          if (param_2 == (char *)0x0) {
            return (char *)0x0;
          }
          cVar2 = *param_2;
        } while ((cVar2 != '\0') && (uVar3 < param_3));
      }
      if (uVar3 < param_3) {
        *pcVar1 = '\0';
      }
    }
  }
  return param_1;
}

