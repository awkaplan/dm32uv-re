/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flash_page_trailing_count_read @ 03010938 (file base 0x03000000; code starts at 0x03001000)
 * Size: 50 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: flash-storage
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

ushort flash_page_trailing_count_read(int param_1__w)

{
  undefined2 param_1 = (undefined2)param_1__w;
  void *mutex;
  ushort local_12;
  
  mutex = p_ucos_mutex_0003944c;
  os_sem_pend_ms(p_ucos_mutex_0003944c,0);
  spi_flash_read_seq(param_1,0xffe,&local_12,2);
  os_sem_post(mutex);
  return local_12 & 0xfff;
}

