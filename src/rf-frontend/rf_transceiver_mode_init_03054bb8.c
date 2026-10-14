/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: rf_transceiver_mode_init @ 03054bb8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 154 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rf-frontend
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void rf_transceiver_mode_init(char param_1)

{
  os_sem_pend_ms(p_ucos_mutex_0003ebc8,0);
  PTR_DAT_03054d3c[1] = 3;
  crystal_osc_and_timer5_init();
  if (*(char *)PTR_DAT_03054d40 == '\0') {
    if ((p_vfo_display_state->flags_0x8 & 0xf0) == 0x10) {
      fd6818b_reg_write(FD6818_PAGE0_REG_0X37,0x1f1f);
    }
    else {
      fd6818b_reg_write(FD6818_PAGE0_REG_0X37,0x1f0f);
    }
    fd6818b_reg_write(FD6818_PAGE0_REG_0X30,0xbff1);
    antenna_switch_select_gpio_24_22(1);
  }
  else if (param_1 == '\0') {
    if (*(char *)PTR_DAT_03054d40 == '\x01') {
      *(undefined1 *)((int)PTR_DAT_03054d48 + 0x1d) = 2;
    }
    key_hold_debounce_state_dispatcher();
  }
  else {
    if (param_1 == '\x01') {
      if ((*(byte *)((int)PTR_DAT_03054d40 + 1) & 1) != (byte)p_dm32_settings_block04[0x2d] >> 7) {
        vfo_exit_dual_watch_and_refresh();
      }
    }
    set_flag_byte_03064328(3);
  }
  PTR_DAT_03054d3c[1] = 1;
  os_sem_post(p_ucos_mutex_0003ebc8);
  return;
}

