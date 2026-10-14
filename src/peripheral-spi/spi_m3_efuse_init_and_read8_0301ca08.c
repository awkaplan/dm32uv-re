/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: spi_m3_efuse_init_and_read8 @ 0301ca08 (file base 0x03000000; code starts at 0x03001000)
 * Size: 60 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: peripheral-spi
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined4 spi_m3_efuse_init_and_read8(undefined4 param_1)

{
  SSI_Type_14150000.SSIENR = 0;
  table_entry_write_word0(3,0x47);
  SSI_Type_14150000.CTRLR1 = 0;
  table_entry_write_field_0x14(3,0x14);
  SSI_Type_14150000.RXFTLR = 7;
  SSI_Type_14150000.TXFTLR = 7;
  SSI_Type_14150000.IMR = 0;
  SSI_Type_14150000.RESERVED_76[0] = 0;
  SSI_Type_14150000.SSIENR = 1;
  SSI_Type_14150000.SER = 0;
  spi_m3_select_and_read_block(&SSI_Type_14150000,param_1,8);
  return 0;
}

