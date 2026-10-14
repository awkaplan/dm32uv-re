/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: ui_event_notify @ 03021ca4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 40 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-screen
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void ui_event_notify(byte event_id)

{
  void *mutex;
  
  mutex = p_ucos_mutex_0003bd54;
  os_sem_pend_ms(p_ucos_mutex_0003bd54,0);
  *(byte *)PTR_DAT_03021e28 = event_id;
  *(undefined1 *)PTR_DAT_03021e2c = 0;
  OSFlagPost_wrapper_set(p_ucos_flaggrp_0003fd90,0x40);
  os_sem_post(mutex);
  return;
}

