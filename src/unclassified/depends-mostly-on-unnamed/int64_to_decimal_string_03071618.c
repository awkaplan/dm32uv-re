/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: int64_to_decimal_string @ 03071618 (file base 0x03000000; code starts at 0x03001000)
 * Size: 192 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

uint int64_to_decimal_string
               (byte *param_1,int param_2,int param_3,int param_4,int param_5,char param_6)

{
  char cVar1;
  byte bVar2;
  int n;
  byte *src;
  uint uVar3;
  uint uVar4;
  
  src = param_1 + param_2 + -1;
  *src = 0;
  if (param_5 == 0) {
    param_5 = 10;
  }
  else if (0x24 < param_5) {
    param_5 = 10;
  }
  if (param_3 != 0 || param_4 != 0) {
    n = 1;
  }
  else {
    src = src + -1;
    *src = 0x30;
    n = 2;
  }
  uVar4 = (uint)(param_3 == 0 && param_4 == 0);
  if ((param_1 < src) && (param_3 != 0 || param_4 != 0)) {
    do {
      uVar3 = uVar4;
      cVar1 = udivdi3_64by32(param_3,param_4,param_5,param_5 >> 0x1f);
      bVar2 = cVar1 + 0x30;
      src = src + -1;
      *src = bVar2;
      uVar4 = uVar3 + 1;
      if (0x39 < bVar2) {
        if (param_6 == '\0') {
          cVar1 = '\'';
        }
        else {
          cVar1 = '\a';
        }
        *src = cVar1 + bVar2;
      }
    } while ((param_1 < src) &&
            (param_3 = fixed_16_16_divide(param_3,param_4,param_5,param_5 >> 0x1f),
            param_3 != 0 || param_4 != 0));
    n = uVar3 + 2;
  }
  memmove(param_1,src,n);
  return uVar4;
}

