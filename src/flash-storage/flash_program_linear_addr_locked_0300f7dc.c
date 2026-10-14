/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flash_program_linear_addr_locked @ 0300f7dc (file base 0x03000000; code starts at 0x03001000)
 * Size: 96 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: flash-storage
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined4 flash_program_linear_addr_locked(uint param_1,int param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  os_sem_pend_ms(p_ucos_mutex_0003944c,0);
  uVar3 = param_1 >> 0xc & 0xffff;
  uVar1 = param_1 & 0xfff;
  uVar2 = (param_1 & 0xf00) + 0x100;
  if (uVar2 < param_3 + uVar1) {
    uVar4 = ((param_1 & 0xf00) - uVar1) + 0x100 & 0xffff;
    spi_flash_program_pagesplit(uVar3,uVar1,param_2,uVar4);
    spi_flash_program_pagesplit(uVar3,uVar2,param_2 + uVar4,param_3 - uVar4 & 0xffff);
  }
  else {
    spi_flash_program_pagesplit(uVar3,uVar1,param_2,param_3 & 0xffff);
  }
  os_sem_post(p_ucos_mutex_0003944c);
  return 1;
}

