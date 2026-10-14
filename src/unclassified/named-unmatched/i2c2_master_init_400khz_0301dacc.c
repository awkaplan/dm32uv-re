/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: i2c2_master_init_400khz @ 0301dacc (file base 0x03000000; code starts at 0x03001000)
 * Size: 114 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void i2c2_master_init_400khz(void)

{
  uint uVar1;
  
  OSSemCreate_shared_name_wrapper(_DAT_0301dc0c,1);
  OSSemCreate_shared_name_wrapper(_DAT_0301dc10,1);
  OSSemCreate_shared_name_wrapper(_DAT_0301dc14,1);
  gpio_pin_set_output_level(5,1);
  gpio_pin_set_output_level(6,1);
  gpio_pin_set_output_level(7,1);
  gpio_pin_set_output_level(8,1);
  I2C2_RTC_14080000.IC_ENABLE = 0;
  I2C2_RTC_14080000.IC_CON = 0x65;
  I2C2_RTC_14080000.IC_INTR_MASK = 0x40;
  uVar1 = (uint)*PTR_DAT_0301dc18 / 400000 >> 1;
  I2C2_RTC_14080000.IC_FS_SCL_HCNT = uVar1 - 8;
  I2C2_RTC_14080000.IC_FS_SCL_LCNT = ((uint)*PTR_DAT_0301dc18 / 400000 - 1) - uVar1;
  I2C2_RTC_14080000.IC_TX_TL = 6;
  I2C2_RTC_14080000.IC_RX_TL = 6;
  return;
}

