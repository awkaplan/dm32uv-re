/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: modem_wait_ready_then_proceed @ 03003e4c (file base 0x03000000; code starts at 0x03001000)
 * Size: 66 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: dmr-protocol
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined4 modem_wait_ready_then_proceed(void)

{
  int iVar1;
  undefined4 uVar2;
  uint uStack_18;
  
  if (*PTR_LAB_03003e98 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    while ((iVar1 = FUN_03003d30(5,1,1,&uStack_18), (uStack_18 & 1) != 0 || (iVar1 != 0))) {
      FUN_03003cc4(10);
    }
    uVar2 = 0;
  }
  return uVar2;
}

