/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flash_block_read @ 0300f71c (file base 0x03000000; code starts at 0x03001000)
 * Size: 98 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: flash-storage
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void flash_block_read(ushort block_id,uint offset,void *dest,uint len)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = len & 0xffff;
  os_sem_pend_ms(p_ucos_mutex_0003944c,0);
  uVar2 = (offset & 0xf00) + 0x100;
  if (uVar2 < uVar1 + (offset & 0xfff)) {
    uVar3 = ((offset & 0xf00) - (offset & 0xfff)) + 0x100 & 0xffff;
    spi_flash_read_seq(block_id,offset & 0xffff,dest,uVar3);
    spi_flash_read_seq(block_id,uVar2,(int)dest + uVar3,uVar1 - uVar3 & 0xffff);
  }
  else {
    spi_flash_read_seq(block_id,offset & 0xffff,dest,uVar1);
  }
  os_sem_post(p_ucos_mutex_0003944c);
  return;
}

