/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: fd6818b_default_register_init @ 0300ecb8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 290 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rf-frontend
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void fd6818b_default_register_init(void)

{
  fd6818b_reg_write(FD6818_PAGE0_REG_00H,0x8000);
  fd6818b_reg_write(FD6818_PAGE0_REG_00H,0);
  fd6818b_reg_write(FD6818_PAGE0_REG_0X37,0x1d0f);
  fd6818b_mode_register_table_apply(0);
  fd6818b_reg_write(FD6818_PAGE0_REG_48H,0x33ef);
  fd6818b_reg_write(FD6818_PAGE0_REG_0X1F,0x5454);
  fd6818b_reg_write(FD6818_PAGE0_REG_25H,0xc1ba);
  fd6818b_reg_write(FD6818_PAGE0_REG_0X77,0x88ef);
  fd6818b_reg_write(FD6818_PAGE0_REG_0X3E,0xa037);
  fd6818b_reg_write(FD6818_PAGE0_REG_13H,0x37e);
  config_table_entry_0x7d_indexed(p_dm32_settings_block04[0x6a]);
  fd6818b_pa_power_level_select(0);
  fd6818b_reg33_indexed_bit_set_and_dispatch(6,9,0);
  fd6818b_reg33_indexed_bit_set_and_dispatch(5,1,0);
  fd6818b_reg_write(FD6818_PAGE0_REG_0X10,0x7a);
  fd6818b_reg_write(FD6818_PAGE0_REG_0X11,0x27b);
  fd6818b_reg_write(FD6818_PAGE0_REG_0X12,0x37b);
  fd6818b_reg_write(FD6818_PAGE0_REG_13H,0x3be);
  fd6818b_reg_write(FD6818_PAGE0_REG_0X14,0x19);
  fd6818b_reg_write(FD6818_PAGE0_REG_0X1F,0x5454);
  fd6818b_reg_write(FD6818_PAGE0_REG_0X30,0xbff1);
  fd6818b_reg_write(FD6818_PAGE0_REG_0X37,0x1d1f);
  fd6818b_reg_write(FD6818_PAGE0_REG_0X3E,0xa037);
  fd6818b_reg_write(FD6818_PAGE0_REG_47H,0x100);
  fd6818b_reg_write(FD6818_PAGE0_REG_48H,0xbbbf);
  fd6818b_reg_write(FD6818_PAGE0_REG_0X49,0x2a38);
  fd6818b_reg_write(FD6818_PAGE0_REG_0X4E,0x4708);
  fd6818b_reg_write(FD6818_PAGE0_REG_4FH,0x302f);
  fd6818b_reg_write(FD6818_PAGE0_REG_52H,0x28f);
  fd6818b_reg_write(FD6818_PAGE0_REG_0X7B,0x8420);
  return;
}

