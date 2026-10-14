/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: uint_to_hex_string @ 030716d8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 132 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

uint uint_to_hex_string(char *param_1,int param_2,uint param_3,uint param_4,int param_5)

{
  char *src;
  char cVar1;
  int n;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  char cVar5;
  
  src = param_1 + param_2 + -1;
  *src = '\0';
  if (0x23 < param_4 - 1) {
    param_4 = 10;
  }
  if (param_3 != 0) {
    n = 1;
  }
  else {
    src = src + -1;
    *src = '0';
    n = 2;
  }
  uVar4 = (uint)(param_3 == 0);
  if ((param_1 < src) && (param_3 != 0)) {
    do {
      uVar3 = uVar4;
      uVar2 = (param_3 - param_4 * (param_3 / param_4)) + 0x30;
      src = src + -1;
      cVar1 = (char)uVar2;
      *src = cVar1;
      uVar4 = uVar3 + 1;
      if (0x39 < (uVar2 & 0xff)) {
        if (param_5 == 0) {
          cVar5 = '\'';
        }
        else {
          cVar5 = '\a';
        }
        *src = cVar5 + cVar1;
      }
    } while ((param_1 < src) && (param_3 = param_3 / param_4, param_3 != 0));
    n = uVar3 + 2;
  }
  memmove(param_1,src,n);
  return uVar4;
}

