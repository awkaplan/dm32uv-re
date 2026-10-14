/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flash_block_id_resolve_locked @ 0300f594 (file base 0x03000000; code starts at 0x03001000)
 * Size: 32 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: flash-storage
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

int flash_block_id_resolve_locked(byte param_1)

{
  void *mutex;
  int iVar1;
  
  mutex = p_ucos_mutex_0003944c;
  os_sem_pend_ms(p_ucos_mutex_0003944c,0);
  iVar1 = flash_block_id_resolve(param_1);
  os_sem_post(mutex);
  return iVar1;
}

