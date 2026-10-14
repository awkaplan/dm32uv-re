/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: aprs_log_clear @ 03062e90 (file base 0x03000000; code starts at 0x03001000)
 * Size: 70 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: analog-signaling
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void aprs_log_clear(void)

{
  void *mutex;
  undefined4 uVar1;
  undefined1 local_14;
  undefined1 uStack_13;
  
  uVar1 = flash_block_id_resolve_locked(1);
  mutex = p_ucos_mutex_0003944c;
  local_14 = 0;
  uStack_13 = 0;
  os_sem_pend_ms(p_ucos_mutex_0003944c,0);
  spi_flash_sector_erase(uVar1);
  spi_flash_program_pagesplit(uVar1,0,&local_14,2);
  flash_page_tag_write(uVar1,1);
  os_sem_post(mutex);
  return;
}

