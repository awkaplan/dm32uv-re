/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: fd6818b_shift_in_16bit @ 0002c298 (IRAM address; the boot stub copies these bytes from program flash 0x030dbeb8)
 * Size: 90 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rf-frontend
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

ushort fd6818b_shift_in_16bit(void)

{
  ushort uVar1;
  char cVar2;
  
  uRam14020004 = uRam14020004 & 0xfffffeff;
  gpio_clear_output_bit(7);
  busy_wait_delay_loop_short(10);
  cVar2 = '\x10';
  uVar1 = 0;
  do {
    uVar1 = uVar1 * 2;
    gpio_set_output_bit(7);
    busy_wait_delay_loop_short(10);
    if ((uRam14020050 & 0x100) != 0) {
      uVar1 = uVar1 | 1;
    }
    gpio_clear_output_bit(7);
    busy_wait_delay_loop_short(10);
    cVar2 = cVar2 + -1;
  } while (cVar2 != '\0');
  return uVar1;
}

