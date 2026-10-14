/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: recording_index_lookup @ 030108a8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 90 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined2 recording_index_lookup(uint param_1)

{
  undefined2 local_e;
  
  os_sem_pend_ms(p_ucos_mutex_0003944c,0);
  if (param_1 < 0x7f9) {
    local_e = flash_page_tag_search(1,0xa5);
  }
  else {
    local_e = flash_page_tag_search(1,0xa6);
    param_1 = param_1 - 0x7f8;
  }
  spi_flash_read_seq(local_e,(param_1 + 0x7fff) * 2 & 0xffff,&local_e,2);
  os_sem_post(p_ucos_mutex_0003944c);
  return local_e;
}

