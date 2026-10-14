/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: strbuf_append_bounded @ 03070684 (file base 0x03000000; code starts at 0x03001000)
 * Size: 62 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

uint strbuf_append_bounded(void *param_1,uint param_2,int *param_3)

{
  int iVar1;
  uint n;
  
  iVar1 = param_3[1];
  n = param_3[2] - iVar1;
  if (n != 0) {
    if (param_2 <= n) {
      n = param_2;
    }
    if (*param_3 != 0) {
      memcpy_ck803s((void *)(*param_3 + iVar1),param_1,n);
      *(undefined1 *)(*param_3 + n + param_3[1]) = 0;
      iVar1 = param_3[1];
    }
    param_3[1] = iVar1 + n;
  }
  return param_2;
}

