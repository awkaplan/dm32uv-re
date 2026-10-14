/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: periodic_task_and_queue_create_0x180 @ 0300cd6c (file base 0x03000000; code starts at 0x03001000)
 * Size: 66 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rtos
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void periodic_task_and_queue_create_0x180(void)

{
  undefined1 auStack_8 [4];
  
  radio_event_dispatch_by_name(p_ucos_flaggrp_00038340,0);
  OSSemCreate_shared_name_wrapper(_DAT_0300cddc,1);
  OSTaskCreate(_DAT_0300cde4,PTR_s_task_psint_0300cde8,PTR_ui_event_flag_dispatch_loop_0300cdec,0,
               0x14,PTR_DAT_0300cde0,0,0x180,0,0,0,3,auStack_8);
  return;
}

