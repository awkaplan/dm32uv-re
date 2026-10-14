/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: spi_flash_dual_log_reset_with_marker_scan @ 030106b4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 330 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: peripheral-spi
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void spi_flash_dual_log_reset_with_marker_scan(void)

{
  undefined4 *puVar1;
  uint uVar2;
  char cStack_1d;
  
  os_sem_pend_ms(p_ucos_mutex_0003944c,0);
  puVar1 = PTR_DAT_030107d4;
  uVar2 = (uint)*(ushort *)PTR_DAT_030107d0;
  if (uVar2 <= (uint)*PTR_DAT_030107d4) {
    do {
      spi_flash_read_seq(uVar2,0xfff,&cStack_1d,1);
      if (cStack_1d == -0x5b) {
        if (uVar2 <= (uint)*PTR_DAT_030107d4) goto LAB_03010724;
        break;
      }
      uVar2 = uVar2 + 1 & 0xffff;
    } while (uVar2 <= (uint)*puVar1);
  }
  puVar1 = PTR_DAT_030107d0;
  spi_flash_sector_erase(*(undefined2 *)PTR_DAT_030107d0);
  cStack_1d = -0x5b;
  spi_flash_program_pagesplit(*(undefined2 *)puVar1,0xfff,&cStack_1d,1);
LAB_03010724:
  puVar1 = PTR_DAT_030107dc;
  uVar2 = (uint)*(ushort *)PTR_DAT_030107d8;
  if (uVar2 <= (uint)*PTR_DAT_030107dc) {
    do {
      spi_flash_read_seq(uVar2,0xfff,&cStack_1d,1);
      if (cStack_1d == -0x5b) {
        if (uVar2 <= (uint)*PTR_DAT_030107dc) goto LAB_03010788;
        break;
      }
      uVar2 = uVar2 + 1 & 0xffff;
    } while (uVar2 <= (uint)*puVar1);
  }
  puVar1 = PTR_DAT_030107d8;
  spi_flash_sector_erase(*(undefined2 *)PTR_DAT_030107d8);
  cStack_1d = -0x5b;
  spi_flash_program_pagesplit(*(undefined2 *)puVar1,0xfff,&cStack_1d,1);
LAB_03010788:
  puVar1 = PTR_DAT_030107dc;
  uVar2 = (uint)*(ushort *)PTR_DAT_030107d8;
  if (uVar2 <= (uint)*PTR_DAT_030107dc) {
    do {
      spi_flash_read_seq(uVar2,0xfff,&cStack_1d,1);
      if (cStack_1d == -0x5a) {
        if (uVar2 <= (uint)*PTR_DAT_0301096c) goto LAB_0301080e;
        break;
      }
      uVar2 = uVar2 + 1 & 0xffff;
    } while (uVar2 <= (uint)*puVar1);
  }
  puVar1 = PTR_DAT_03010970;
  spi_flash_sector_erase(*PTR_DAT_03010970 + 3 & 0xffff);
  cStack_1d = -0x5a;
  spi_flash_program_pagesplit(*puVar1 + 3 & 0xffff,0xfff,&cStack_1d,1);
LAB_0301080e:
  os_sem_post(p_ucos_mutex_0003944c);
  return;
}

