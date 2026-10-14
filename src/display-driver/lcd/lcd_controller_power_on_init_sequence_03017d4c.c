/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: lcd_controller_power_on_init_sequence @ 03017d4c (file base 0x03000000; code starts at 0x03001000)
 * Size: 506 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: display-driver
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void lcd_controller_power_on_init_sequence(void)

{
  dword dVar1;
  
  OSSemCreate_shared_name_wrapper(p_ucos_mutex_00039344,1);
  gpio_pin_set_output_level(0x42,1);
  gpio_pin_set_output_level(0x46,1);
  I80_Type_12000000.WCFG = 0x303;
  dVar1 = I80_Type_12000000.UNDOC_0x28;
  I80_Type_12000000.UNDOC_0x28 = dVar1 | 1;
  do {
    dVar1 = I80_Type_12000000.UNDOC_0x28;
  } while ((dVar1 & 2) == 0);
  dVar1 = SystemControl_Type_11000000.IO_DIPLEX2;
  SystemControl_Type_11000000.IO_DIPLEX2 = dVar1 & _DAT_03017f4c;
  gpio_set_output_bit(0x42);
  OSTimeDly_ms_wrapper(0x78);
  gpio_clear_output_bit(0x42);
  OSTimeDly_ms_wrapper(0x78);
  gpio_set_output_bit(0x42);
  OSTimeDly_ms_wrapper(0x78);
  lcd_write_command(MIPI_DCS_EXIT_SLEEP_MODE);
  OSTimeDly_ms_wrapper(0x78);
  lcd_write_command(ST7789V_PORCTRL);
  lcd_write_data(0xc);
  lcd_write_data(0xc);
  lcd_write_data(0);
  lcd_write_data(0x33);
  lcd_write_data(0x33);
  lcd_write_command(MIPI_DCS_SET_TEAR_ON);
  lcd_write_data(0);
  lcd_set_orientation(PTR_DAT_03017f50[0x6d] & 1);
  lcd_write_command(MIPI_DCS_SET_PIXEL_FORMAT);
  lcd_write_data(5);
  lcd_write_command(ST7789V_GCTRL);
  lcd_write_data(0x56);
  lcd_write_command(ST7789V_VCOMS);
  lcd_write_data(0x17);
  lcd_write_command(ST7789V_LCMCTRL);
  lcd_write_data(0x2c);
  lcd_write_command(ST7789V_VDVVRHEN);
  lcd_write_data(1);
  lcd_write_command(ST7789V_VRHS);
  lcd_write_data(0xb);
  lcd_write_command(ST7789V_FRCTRL2);
  lcd_write_data(0xef);
  lcd_write_command(ST7789V_PWCTRL1);
  lcd_write_data(0xa7);
  lcd_write_command(ST7789V_PWCTRL1);
  lcd_write_data(0xa4);
  lcd_write_data(0xa1);
  lcd_write_command(ST7789V_UNDOC_CMD_D6);
  lcd_write_data(0xa1);
  lcd_write_command(ST7789V_PVGAMCTRL);
  lcd_write_data(0x70);
  lcd_write_data(3);
  lcd_write_data(8);
  lcd_write_data(7);
  lcd_write_data(8);
  lcd_write_data(0x15);
  lcd_write_data(0x30);
  lcd_write_data(0x54);
  lcd_write_data(0x47);
  lcd_write_data(0x3a);
  lcd_write_data(0x15);
  lcd_write_data(0x14);
  lcd_write_data(0x2b);
  lcd_write_data(0x2e);
  lcd_write_command(ST7789V_NVGAMCTRL);
  lcd_write_data(0x70);
  lcd_write_data(6);
  lcd_write_data(10);
  lcd_write_data(9);
  lcd_write_data(6);
  lcd_write_data(3);
  lcd_write_data(0x2f);
  lcd_write_data(0x44);
  lcd_write_data(0x47);
  lcd_write_data(0x38);
  lcd_write_data(0x12);
  lcd_write_data(0x15);
  lcd_write_data(0x29);
  lcd_write_data(0x2f);
  display_clear_fullscreen();
  lcd_write_command(MIPI_DCS_ENTER_INVERT_MODE);
  lcd_write_command(MIPI_DCS_SET_DISPLAY_ON);
  lcd_write_command(MIPI_DCS_WRITE_MEMORY_START);
  return;
}

