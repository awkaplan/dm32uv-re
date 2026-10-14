/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_030c03e0 @ 030c03e0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 4 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

void FUN_030c03e0(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if (*PTR_DAT_030c0464 != 0) {
    (*(code *)(*PTR_DAT_030c0464 & 0xfffffffe))();
  }
  iVar1 = func_0x0611caf4();
  iVar5 = *piRam030c0468;
  iVar4 = *piRam030c046c;
  if (iVar5 != iVar4) {
    iVar3 = iVar1 - *(int *)(iVar5 + 0x98);
    *(int *)(iVar5 + 0x94) = iVar3;
    *(int *)(iVar5 + 0x9c) = iVar3 + *(int *)(iVar5 + 0x9c);
  }
  *(int *)(iVar4 + 0x98) = iVar1;
  uVar2 = irq_take_and_clear_u32_global();
  iVar1 = *piRam030c0468;
  if (*(uint *)(iVar1 + 0xb4) < uVar2) {
    *(uint *)(iVar1 + 0xb4) = uVar2;
  }
  if (*(uint *)(iVar1 + 0xb8) < *puRam030c0470) {
    *(uint *)(iVar1 + 0xb8) = *puRam030c0470;
  }
  *puRam030c0470 = 0;
  return;
}

