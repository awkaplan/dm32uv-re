/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: status_queue_push_and_signal @ 03033234 (file base 0x03000000; code starts at 0x03001000)
 * Size: 72 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-screen
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void status_queue_push_and_signal(int param_1,int param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  
  os_sem_pend_ms(p_ucos_mutex_00032080,0);
  puVar1 = PTR_DAT_030332c4;
  if (param_1 == 0) {
    param_1 = 1;
  }
  iVar2 = *PTR_DAT_030332c8;
  if ((iVar2 != 0) && (iVar2 != param_2)) {
    *PTR_DAT_030332c4 = iVar2;
    puVar1[1] = PTR_DAT_030332c8[1];
  }
  puVar1 = PTR_DAT_030332c8;
  *PTR_DAT_030332c8 = param_2;
  puVar1[1] = param_3;
  puVar1 = p_ucos_tmr_dlyhnd;
  p_ucos_tmr_dlyhnd[8] = param_1;
  puVar1[9] = param_1;
  set_flag_bits_and_post_os_flag_0x8000(0x10);
  os_sem_post(p_ucos_mutex_00032080);
  return;
}

