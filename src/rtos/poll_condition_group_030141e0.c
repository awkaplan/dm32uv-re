/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: poll_condition_group @ 030141e0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 46 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rtos
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

int poll_condition_group(uint group)

{
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  
  if ((PTR_DAT_0301421c[3] & 2) == 0) {
    puVar3 = PTR_DAT_03014220 + 0xc;
    puVar2 = PTR_DAT_03014220;
    do {
      iVar1 = (*(code *)(*puVar2 & 0xfffffffe))(group & 0xff);
      if (iVar1 == 0) {
        return 0;
      }
      puVar2 = puVar2 + 1;
    } while (puVar2 != puVar3);
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}

