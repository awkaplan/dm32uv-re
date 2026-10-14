/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: fixed21_slot_table_remove_last_used @ 0305851c (file base 0x03000000; code starts at 0x03001000)
 * Size: 104 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

uint fixed21_slot_table_remove_last_used(undefined4 param_1,undefined1 *param_2)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = 0;
  bVar1 = false;
  do {
    uVar4 = uVar3 & 0xff;
    uVar2 = (uint)*(byte *)((int)PTR_DAT_030586d4 + uVar3);
    if (uVar2 == 0) {
      bVar1 = true;
    }
    else if (bVar1) goto LAB_0305854a;
    uVar3 = uVar3 + 1;
  } while (uVar3 != 0x15);
  uVar2 = (uint)*(byte *)PTR_DAT_030586d4;
  uVar4 = 0;
LAB_0305854a:
  if ((uVar2 - 1 & 0xff) < 0x14) {
    *(undefined1 *)((int)PTR_DAT_030586d4 + uVar4) = 0;
    *param_2 = 1;
    uVar3 = ((int)(uVar2 - 1) / 9 + 1) * 0x80 + ((int)(uVar2 - 1) % 9) * 0xe & 0xffff;
  }
  else {
    *param_2 = 0;
    uVar3 = 0;
  }
  return uVar3;
}

