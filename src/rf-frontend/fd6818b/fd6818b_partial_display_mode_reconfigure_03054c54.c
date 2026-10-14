/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: fd6818b_partial_display_mode_reconfigure @ 03054c54 (file base 0x03000000; code starts at 0x03001000)
 * Size: 84 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rf-frontend
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void fd6818b_partial_display_mode_reconfigure(void)

{
  os_sem_pend_ms(p_ucos_mutex_0003ebc8,0);
  PTR_DAT_03054d3c[1] = 4;
  fd6818b_reg_write(FD6818_PAGE0_REG_0X30,0);
  if ((p_vfo_display_state->flags_0x8 & 0xf0) == 0x10) {
    fd6818b_reg_write(FD6818_PAGE0_REG_0X37,0x1d11);
  }
  else {
    fd6818b_reg_write(FD6818_PAGE0_REG_0X37,0x1d00);
  }
  antenna_switch_select_gpio_24_22(0);
  PTR_DAT_03054d3c[1] = 2;
  clock_uart_reconfigure();
  os_sem_post(p_ucos_mutex_0003ebc8);
  return;
}

