/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: spi_m0_init_flash_cs_high @ 0301c94c (file base 0x03000000; code starts at 0x03001000)
 * Size: 68 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: peripheral-spi
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4 spi_m0_init_flash_cs_high(void)

{
  dword dVar1;
  
  dVar1 = SystemControl_Type_11000000.IO_DIPLEX1;
  SystemControl_Type_11000000.IO_DIPLEX1 = dVar1 & 0xfffffe07;
  gpio_pin_set_output_level(0x12,1);
  SSI_Type_140a0000.SSIENR = 0;
  table_entry_write_word0(0,7);
  table_entry_write_field_0x14(0,2);
  SSI_Type_140a0000.RXFTLR = 7;
  SSI_Type_140a0000.TXFTLR = 7;
  SSI_Type_140a0000.IMR = 0;
  SSI_Type_140a0000.SER = 0;
  OSSemCreate_shared_name_wrapper(_DAT_0301c994,1);
  return 0;
}

