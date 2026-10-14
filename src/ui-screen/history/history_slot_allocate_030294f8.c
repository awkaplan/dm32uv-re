/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: history_slot_allocate @ 030294f8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 90 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-screen
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined4 * history_slot_allocate(void)

{
  undefined4 *puVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  
  puVar1 = PTR_DAT_0302960c;
  if (*(char *)PTR_DAT_0302960c == '\0') {
    iVar3 = 0;
    uVar4 = 0;
LAB_03029518:
    *(undefined1 *)(PTR_DAT_0302960c + iVar3 * 9) = 1;
    *(undefined1 *)((int)puVar1 + iVar3 * 0x24 + 2) = 0;
    *(undefined1 *)((int)puVar1 + iVar3 * 0x24 + 3) = 0;
    puVar1[iVar3 * 9 + 8] = 0;
    memset_bytes((int)puVar1 + iVar3 * 0x24 + 5,0,0x18);
    puVar1 = puVar1 + uVar4 * 9;
  }
  else {
    iVar3 = 0;
    uVar4 = 1;
    pcVar2 = PTR_DAT_03029614;
    do {
      iVar3 = iVar3 + 1;
      if (*pcVar2 == '\0') goto LAB_03029518;
      uVar4 = uVar4 + 1 & 0xff;
      pcVar2 = pcVar2 + 0x24;
    } while (uVar4 != 0x32);
    puVar1 = (undefined4 *)0x0;
  }
  return puVar1;
}

