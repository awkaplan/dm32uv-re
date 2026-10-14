/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: rotate_uint32_bytes @ 030ccae4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 56 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void rotate_uint32_bytes(int param_1,int param_2)

{
  undefined1 auStack_18 [4];
  
  if ((param_2 - 1U & 0xff) < 3) {
    func_0x030dec8c(auStack_18,param_1,param_2);
    func_0x030dec8c(param_1,param_1 + param_2,4 - param_2);
    func_0x030dec8c(param_1 + (4 - param_2),auStack_18,param_2);
  }
  return;
}

