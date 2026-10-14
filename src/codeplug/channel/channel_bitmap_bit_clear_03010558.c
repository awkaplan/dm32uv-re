/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_bitmap_bit_clear @ 03010558 (file base 0x03000000; code starts at 0x03001000)
 * Size: 92 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void channel_bitmap_bit_clear(int param_1)

{
  void *mutex;
  undefined2 uVar1;
  int iVar2;
  uint uVar3;
  byte local_19;
  
  mutex = p_ucos_mutex_0003944c;
  os_sem_pend_ms(p_ucos_mutex_0003944c,0);
  iVar2 = *PTR_DAT_030105c8;
  uVar1 = flash_page_tag_search(0,0xa5);
  uVar3 = (uint)(param_1 - iVar2) >> 3 & 0xffff;
  spi_flash_read_seq(uVar1,uVar3,&local_19,1);
  local_19 = local_19 & ~(byte)(1 << (param_1 - iVar2 & 7U));
  spi_flash_program_pagesplit(uVar1,uVar3,&local_19);
  os_sem_post(mutex);
  return;
}

