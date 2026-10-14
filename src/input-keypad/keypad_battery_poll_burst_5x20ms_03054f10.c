/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: keypad_battery_poll_burst_5x20ms @ 03054f10 (file base 0x03000000; code starts at 0x03001000)
 * Size: 50 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: input-keypad
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void keypad_battery_poll_burst_5x20ms(void)

{
  char cVar1;
  
  cVar1 = '\x05';
  do {
    keypad_event_maybe_forward_to_dialog();
    battery_monitor_adc_tick();
    OSTimeDly_ms_wrapper(0x14);
    cVar1 = cVar1 + -1;
  } while (cVar1 != '\0');
  if ((*(byte *)PTR_DAT_03054fc0 & 2) != 0) {
    FUN_0302179c(1);
  }
  return;
}

