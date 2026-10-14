/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: ui_event_notify_alt @ 030305ac (file base 0x03000000; code starts at 0x03001000)
 * Size: 88 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-screen
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void ui_event_notify_alt(byte param_1)

{
  radio_mode_state_0003e318 *prVar1;
  void *flaggrp;
  void *mutex;
  undefined1 auStack_14 [4];
  
  mutex = p_ucos_mutex_0003e330;
  os_sem_pend_ms(p_ucos_mutex_0003e330,0);
  prVar1 = p_radio_mode_state_0003e318;
  p_radio_mode_state_0003e318->flags_0x4 = p_radio_mode_state_0003e318->flags_0x4 & 0xfb | 4;
  prVar1->field_0x1 = param_1;
  flaggrp = p_ucos_flaggrp_0003fd90;
  OSFlagPost_wrapper_set(p_ucos_flaggrp_0003fd90,8);
  OSFlagPend_wrapper_consume(flaggrp,4,0,0,auStack_14);
  OSFlagPost_wrapper_clr(flaggrp,4);
  mmio_11000074_bits78_set_from_status_nibble();
  prVar1->flags_0x4 = prVar1->flags_0x4 & 0xfb;
  os_sem_post(mutex);
  return;
}

