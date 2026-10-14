/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: deferred_callback_pair_run_and_clear @ 030331fc (file base 0x03000000; code starts at 0x03001000)
 * Size: 54 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void deferred_callback_pair_run_and_clear(void)

{
  undefined4 *puVar1;
  
  os_sem_pend_ms(p_ucos_mutex_00032080,0);
  puVar1 = PTR_DAT_030332c4;
  if (*PTR_DAT_030332c4 != 0) {
    (*(code *)(*PTR_DAT_030332c4 & 0xfffffffe))(PTR_DAT_030332c4[1]);
    *puVar1 = 0;
  }
  puVar1 = PTR_DAT_030332c8;
  if (*PTR_DAT_030332c8 != 0) {
    (*(code *)(*PTR_DAT_030332c8 & 0xfffffffe))(PTR_DAT_030332c8[1]);
    *puVar1 = 0;
  }
  os_sem_post(p_ucos_mutex_00032080);
  return;
}

