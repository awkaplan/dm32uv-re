/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: timer_wheel_tick_task @ 03003ad8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 40 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rtos
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void timer_wheel_tick_task(void)

{
  undefined1 *puVar1;
  undefined1 auStack_1c [4];
  int iStack_18;
  
  puVar1 = PTR_LAB_00016d4c_1_03003b00;
  do {
    do {
      do {
        ucos_sem_pend_wait_variant(0,0,auStack_1c,&iStack_18);
      } while (iStack_18 != 0);
    } while (*puVar1 != '\x01');
    OS_TickListUpdate();
  } while( true );
}

