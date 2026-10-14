/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: ui_mode_dispatch @ 0300d0a4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 26 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-screen
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void ui_mode_dispatch(uint param_1)

{
  os_sem_pend_ms(p_ucos_mutex_00038438,0);
  if ((param_1 & 0xff) < 0x21) {
                    /* WARNING: Could not recover jumptable at 0x0300d0bc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(PTR_PTR_0300d0c8[param_1 & 0xff] & 0xfffffffe))();
    return;
  }
  os_sem_post(p_ucos_mutex_00038438);
  return;
}

