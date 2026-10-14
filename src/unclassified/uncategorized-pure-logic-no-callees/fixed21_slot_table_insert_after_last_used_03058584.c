/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: fixed21_slot_table_insert_after_last_used @ 03058584 (file base 0x03000000; code starts at 0x03001000)
 * Size: 88 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined4 fixed21_slot_table_insert_after_last_used(undefined4 param_1,uint param_2)

{
  char cVar1;
  bool bVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  
  uVar4 = (((param_2 & 0xffff) >> 7) - 1) * 9 + (param_2 & 0x7f) / 0xe;
  cVar1 = (char)uVar4 + '\x01';
  if ((uVar4 & 0xff) < 0x14) {
    iVar5 = 0;
    bVar2 = false;
    do {
      if (*(char *)((int)PTR_DAT_030586d4 + iVar5) == '\0') {
        if (bVar2) {
          *(char *)((int)PTR_DAT_030586d4 + iVar5) = cVar1;
          return 1;
        }
      }
      else {
        bVar2 = true;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 != 0x15);
    *(char *)PTR_DAT_030586d4 = cVar1;
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}

