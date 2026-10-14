/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: spi_flash_config_block_magic_scan @ 03061280 (file base 0x03000000; code starts at 0x03001000)
 * Size: 282 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: peripheral-spi
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void spi_flash_config_block_magic_scan(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  char cStack_25;
  
  uVar3 = *PTR_DAT_03061490;
  uVar5 = uVar3 >> 0xc;
  *PTR_DAT_03061494 = uVar5;
  *PTR_DAT_03061498 = uVar5 + 2;
  *PTR_DAT_0306149c = uVar5 + 3;
  *PTR_DAT_030614a0 = uVar5 + 8;
  uVar4 = *PTR_DAT_030614a4;
  *PTR_DAT_030614a8 = (uVar4 - uVar3 >> 0xc) - 9;
  *PTR_DAT_030614ac = uVar4 >> 0xc;
  *PTR_DAT_030614b0 = uVar5 + 9;
  puVar1 = PTR_DAT_03061498;
  uVar3 = uVar5 & 0xffff;
  if (uVar3 <= uVar5 + 2) {
    do {
      spi_flash_read_seq(uVar3,0xfff,&cStack_25,1);
      if (cStack_25 == -0x5b) break;
      uVar3 = uVar3 + 1 & 0xffff;
    } while (uVar3 <= (uint)*puVar1);
  }
  puVar1 = PTR_DAT_030614a0;
  uVar5 = *PTR_DAT_03061498;
  uVar4 = (uint)*(ushort *)PTR_DAT_0306149c;
  if (uVar4 <= (uint)*PTR_DAT_030614a0) {
    do {
      spi_flash_read_seq(uVar4,0xfff,&cStack_25,1);
      puVar2 = PTR_DAT_030614a0;
      if (cStack_25 == -0x5b) {
        if ((uVar4 <= (uint)*PTR_DAT_030614a0) &&
           (uVar4 = (uint)*(ushort *)PTR_DAT_0306149c, uVar4 <= (uint)*PTR_DAT_030614a0)) {
          goto LAB_0306135e;
        }
        break;
      }
      uVar4 = uVar4 + 1 & 0xffff;
    } while (uVar4 <= (uint)*puVar1);
  }
  goto LAB_0306138c;
  while (uVar4 = uVar4 + 1 & 0xffff, uVar4 <= (uint)*puVar2) {
LAB_0306135e:
    spi_flash_read_seq(uVar4,0xfff,&cStack_25,1);
    if (cStack_25 == -0x5a) {
      if ((uVar4 <= (uint)*PTR_DAT_030614a0) && (uVar3 <= uVar5)) goto LAB_03061390;
      break;
    }
  }
LAB_0306138c:
  flash_pagesplit_write_with_split_markers();
LAB_03061390:
  flash_state_and_tag_dispatcher(0);
  return;
}

