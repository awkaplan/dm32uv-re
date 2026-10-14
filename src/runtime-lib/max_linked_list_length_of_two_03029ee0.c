/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: max_linked_list_length_of_two @ 03029ee0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 64 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: runtime-lib
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

byte max_linked_list_length_of_two(void)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  
  iVar3 = PTR_DAT_03029f2c[0x29];
  if (iVar3 == 0) {
    bVar2 = 0;
  }
  else {
    bVar2 = 0;
    do {
      bVar2 = bVar2 + 1;
      iVar3 = *(int *)(iVar3 + 0x20);
    } while (iVar3 != 0);
  }
  iVar3 = PTR_DAT_03029f2c[0x2a];
  if (iVar3 == 0) {
    bVar1 = 0;
  }
  else {
    bVar1 = 0;
    do {
      bVar1 = bVar1 + 1;
      iVar3 = *(int *)(iVar3 + 0x20);
    } while (iVar3 != 0);
  }
  if (bVar1 < bVar2) {
    bVar1 = bVar2;
  }
  return bVar1;
}

