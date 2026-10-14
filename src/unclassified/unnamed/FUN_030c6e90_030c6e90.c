/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_030c6e90 @ 030c6e90 (file base 0x03000000; code starts at 0x03001000)
 * Size: 40 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_030c6e90(void)

{
  SSI_Type_14150000.SSIENR = 0;
  SSI_Type_14150000.CTRLR0 = 0x47;
  SSI_Type_14150000.CTRLR1 = 0;
  SSI_Type_14150000.BAUDR = 0x14;
  SSI_Type_14150000.RXFTLR = 7;
  SSI_Type_14150000.TXFTLR = 7;
  SSI_Type_14150000.IMR = 0;
  SSI_Type_14150000.SER = 0;
  FUN_030c6e5c(_DAT_030c6ee8,8);
  return;
}

