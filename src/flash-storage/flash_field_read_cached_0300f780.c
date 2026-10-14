/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flash_field_read_cached @ 0300f780 (file base 0x03000000; code starts at 0x03001000)
 * Size: 44 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: flash-storage
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void flash_field_read_cached(int param_1__w,int param_2__w,undefined4 param_3,int param_4__w)

{
  byte param_1 = (byte)param_1__w;
  undefined2 param_2 = (undefined2)param_2__w;
  undefined2 param_4 = (undefined2)param_4__w;
  void *mutex;
  int iVar1;
  
  mutex = p_ucos_mutex_0003944c;
  os_sem_pend_ms(p_ucos_mutex_0003944c,0);
  iVar1 = flash_block_id_resolve(param_1);
  spi_flash_read_seq(iVar1,param_2,param_3,param_4);
  os_sem_post(mutex);
  return;
}

