/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: modem_buffer_char_remap_write_03055850 @ 03055850 (file base 0x03000000; code starts at 0x03001000)
 * Size: 48 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: dmr-protocol
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void modem_buffer_char_remap_write_03055850(uint param_1)

{
  byte bVar1;
  
  bVar1 = PTR_LAB_030558d4[param_1 & 0xff];
  if (bVar1 < 0x20) {
    bVar1 = 0x1f - bVar1;
  }
  else if (bVar1 < 0x40) {
    bVar1 = 0x5f - bVar1;
  }
  else {
    bVar1 = 0;
  }
  PTR_DAT_030558d8[0xdf] = bVar1 | 0x80;
  return;
}

