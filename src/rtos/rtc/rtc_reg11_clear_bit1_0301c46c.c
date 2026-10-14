/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: rtc_reg11_clear_bit1 @ 0301c46c (file base 0x03000000; code starts at 0x03001000)
 * Size: 20 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rtos
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void rtc_reg11_clear_bit1(void)

{
  byte bVar1;
  
  bVar1 = rtc_register_read(0x11);
  device_reg_write_selector_0xe0(0x11,bVar1 & 0xfd);
  return;
}

