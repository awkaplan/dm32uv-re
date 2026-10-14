/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: queued_slot_tag_match_b @ 030c08f0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 52 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void queued_slot_tag_match_b(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  short sVar3;
  
  sVar3 = *(short *)(param_2 + 0x3e);
  if (sVar3 != 0) {
    iVar2 = *(int *)(*(int *)(param_2 + 0x30) + 0xc);
    iVar1 = *(int *)(param_2 + 0x30);
    while (iVar2 != param_1) {
      sVar3 = sVar3 + -1;
      if (sVar3 == 0) {
        return;
      }
      iVar2 = *(int *)(iVar1 + 0x2c);
      iVar1 = iVar1 + 0x20;
    }
    *(int *)(iVar1 + 0x10) = param_1;
    *(undefined4 *)(iVar1 + 0x1c) = param_3;
  }
  return;
}

