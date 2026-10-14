/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: spi_sdcard_select_and_wait_ready @ 03066810 (file base 0x03000000; code starts at 0x03001000)
 * Size: 34 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: peripheral-spi
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

bool spi_sdcard_select_and_wait_ready(void)

{
  int iVar1;
  
  gpio_clear_output_bit(0x17);
  busy_wait_delay_loop_short(10);
  iVar1 = poll_flag_until_ff_or_timeout();
  if (iVar1 != 0) {
    spi_sdcard_read_status_register();
  }
  return iVar1 != 0;
}

