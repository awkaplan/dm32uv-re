/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: mutex_guarded_call3_wrapper @ 03010db8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 36 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rtos
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void mutex_guarded_call3_wrapper(undefined4 param_1,undefined4 param_2,undefined2 param_3)

{
  void *mutex;
  
  mutex = p_ucos_mutex_0003944c;
  os_sem_pend_ms(p_ucos_mutex_0003944c,0);
  flash_cache_sector_modify_and_writeback(param_1,param_2,param_3);
  os_sem_post(mutex);
  return;
}

