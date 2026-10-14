/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: modem_control_state_stop @ 030293ac (file base 0x03000000; code starts at 0x03001000)
 * Size: 26 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: dmr-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void modem_control_state_stop(void)

{
  undefined1 *puVar1;
  
  puVar1 = PTR_DAT_03029400;
  PTR_DAT_03029400[0xe] = 0;
  puVar1[0xf] = 0;
  puVar1[0xc] = 0;
  puVar1[0xd] = 0;
  puVar1[9] = 0;
  puVar1[6] = 0xff;
  PTR_DAT_03029414[2] = 0;
  return;
}

