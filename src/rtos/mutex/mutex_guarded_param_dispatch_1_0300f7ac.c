/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: mutex_guarded_param_dispatch_1 @ 0300f7ac (file base 0x03000000; code starts at 0x03001000)
 * Size: 48 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rtos
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void mutex_guarded_param_dispatch_1(uint param_1,int param_2__w)

{
  undefined1 param_2 = (undefined1)param_2__w;
  void *mutex;
  undefined1 local_14 [4];
  
  mutex = p_ucos_mutex_0003944c;
  local_14[0] = param_2;
  os_sem_pend_ms(p_ucos_mutex_0003944c,0);
  spi_flash_program_pagesplit(param_1 >> 0xc & 0xffff,param_1 & 0xfff,local_14,1);
  os_sem_post(mutex);
  return;
}

