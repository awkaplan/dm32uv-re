/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: board_gpio_init @ 03001600 (file base 0x03000000; code starts at 0x03001000)
 * Size: 138 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: peripheral-gpio
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void board_gpio_init(void)

{
  gpio_drv_set_output(0x20,0);
  gpio_drv_set_output(0x21,0);
  gpio_pin_configure(0x2b,1,2);
  gpio_pin_configure(0x33,1,2);
  gpio_drv_set_output(0x47,1);
  gpio_drv_set_output(0x48,1);
  gpio_drv_set_output(0x49,1);
  gpio_drv_set_output(0x4a,1);
  gpio_drv_set_output(0x4b,1);
  gpio_drv_set_output(0x4c,1);
  gpio_drv_set_output(0x4d,1);
  gpio_drv_set_output(0x4e,1);
  FUN_00011d38(0x20);
  FUN_00011d38(0x21);
  GPIOA_14020000.DEBOUNCE = 0xffffffff;
  GPIOB_14100000.DEBOUNCE = 0xffffffff;
  GPIOC_14110000.DEBOUNCE = 0xffffffff;
  return;
}

