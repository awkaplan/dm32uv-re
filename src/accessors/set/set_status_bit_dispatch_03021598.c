/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: set_status_bit_dispatch @ 03021598 (file base 0x03000000; code starts at 0x03001000)
 * Size: 16 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: accessors
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void set_status_bit_dispatch(uint index,uint value)

{
  uint uVar1;
  
  uVar1 = index & 0xff;
  if (uVar1 < 7) {
                    /* WARNING: Could not recover jumptable at 0x030215a6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(PTR_PTR_030215a8[uVar1] & 0xfffffffe))(uVar1,value & 0xff);
    return;
  }
  return;
}

