/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flash_mutex_guarded_op @ 0300f700 (file base 0x03000000; code starts at 0x03001000)
 * Size: 28 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: flash-storage
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void flash_mutex_guarded_op(int param_1__w)

{
  undefined2 param_1 = (undefined2)param_1__w;
  void *mutex;
  
  mutex = p_ucos_mutex_0003944c;
  os_sem_pend_ms(p_ucos_mutex_0003944c,0);
  spi_flash_sector_erase(param_1);
  os_sem_post(mutex);
  return;
}

