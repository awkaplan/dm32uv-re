/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: modem_tx_enable @ 03023b6c (file base 0x03000000; code starts at 0x03001000)
 * Size: 26 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: dmr-protocol
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void modem_tx_enable(void)

{
  dword dVar1;
  
  dVar1 = SystemControl_Type_11000000.LAYER2_CONTROL;
  SystemControl_Type_11000000.LAYER2_CONTROL = dVar1 | 0x10;
  SystemControl_Type_11000000.LAYER2_SLOT_CNT = 0x20000000;
  dVar1 = SystemControl_Type_11000000.LAYER2_SLOTON;
  SystemControl_Type_11000000.LAYER2_SLOTON = dVar1 | 2;
  return;
}

