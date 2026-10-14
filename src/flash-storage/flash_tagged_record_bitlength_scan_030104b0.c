/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flash_tagged_record_bitlength_scan @ 030104b0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 168 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: flash-storage
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

uint flash_tagged_record_bitlength_scan(void)

{
  char cVar1;
  byte bVar2;
  undefined4 *puVar3;
  undefined2 uVar4;
  char *pcVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  
  uVar4 = flash_page_tag_search(0,0xa5);
  uVar9 = (uint)*PTR_DAT_030105c0 >> 3 & 0xffff;
  spi_flash_read_seq(uVar4,0,PTR_DAT_030105c4,uVar9);
  if (uVar9 == 0) {
    uVar9 = 0;
  }
  else {
    if (*(char *)PTR_DAT_030105c4 == '\0') {
      iVar10 = 0;
      uVar8 = 0;
      pcVar5 = PTR_DAT_030105cc;
      do {
        uVar8 = uVar8 + 1 & 0xffff;
        if (uVar9 <= uVar8) {
          return 0;
        }
        iVar10 = iVar10 + 1;
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 == '\0');
    }
    else {
      iVar10 = 0;
      uVar8 = 0;
    }
    if ((*(byte *)((int)PTR_DAT_030105c4 + iVar10) & 1) == 0) {
      bVar2 = *(byte *)((int)PTR_DAT_030105c4 + iVar10) >> 1;
      uVar7 = (uint)bVar2;
      *(byte *)((int)PTR_DAT_030105c4 + iVar10) = bVar2;
      puVar3 = PTR_DAT_030105c4;
      uVar6 = 1;
      do {
        if ((uVar7 & 1) != 0) break;
        uVar7 = uVar7 >> 1;
        *(char *)((int)puVar3 + iVar10) = (char)uVar7;
        uVar6 = uVar6 + 1 & 0xff;
      } while (uVar6 != 8);
    }
    else {
      uVar6 = 0;
    }
    if (uVar8 < uVar9) {
      uVar9 = uVar6 + uVar8 * 8 + *PTR_DAT_030105c8 & 0xffff;
    }
    else {
      uVar9 = 0;
    }
  }
  return uVar9;
}

