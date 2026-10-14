/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: tx_led_tone_task_loop @ 03060d14 (file base 0x03000000; code starts at 0x03001000)
 * Size: 94 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rf-frontend
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void tx_led_tone_task_loop(void)

{
  void *flaggrp;
  undefined1 *puVar1;
  int iVar2;
  byte bVar3;
  undefined1 auStack_28 [4];
  
  iVar2 = DAT_03060d7c;
  puVar1 = PTR_DAT_03060d78;
  flaggrp = DAT_03060d74;
  do {
    do {
      do {
        OSFlagPend_wrapper_consume(flaggrp,0x4000,0,0,auStack_28);
        OSFlagPost_wrapper_clr(flaggrp,0x4000);
      } while ((*puVar1 & 2) != 0);
      bVar3 = *(char *)(iVar2 + 0x400) + 1;
      *(byte *)(iVar2 + 0x400) = bVar3;
    } while (bVar3 < 2);
    *(undefined1 *)(iVar2 + 0x400) = 0;
    call_status_indicator_byte_compute();
    tx_led_or_tone_service_tick_dispatch();
  } while( true );
}

