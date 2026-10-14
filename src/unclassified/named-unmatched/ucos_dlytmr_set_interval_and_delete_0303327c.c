/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: ucos_dlytmr_set_interval_and_delete @ 0303327c (file base 0x03000000; code starts at 0x03001000)
 * Size: 56 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void ucos_dlytmr_set_interval_and_delete(int param_1)

{
  undefined4 *puVar1;
  undefined1 auStack_c [4];
  
  os_sem_pend_ms(p_ucos_mutex_00032080,0);
  OSTmr_state_dispatch_callback(p_ucos_tmr_dlyhnd,0,0,auStack_c);
  puVar1 = p_ucos_tmr_dlyhnd;
  if (param_1 == 0) {
    param_1 = 1;
  }
  p_ucos_tmr_dlyhnd[8] = param_1;
  puVar1[9] = param_1;
  ucos_tmr_del(puVar1,auStack_c);
  os_sem_post(p_ucos_mutex_00032080);
  return;
}

