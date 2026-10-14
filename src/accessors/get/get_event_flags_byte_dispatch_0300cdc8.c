/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: get_event_flags_byte_dispatch @ 0300cdc8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 14 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: accessors
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

byte get_event_flags_byte_dispatch(uint index)

{
  byte bVar1;
  
  if ((index & 0xff) < 0x15) {
                    /* WARNING: Could not recover jumptable at 0x0300cdd4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    bVar1 = (*(code *)(PTR_PTR_0300cdf0[index & 0xff] & 0xfffffffe))();
    return bVar1;
  }
  return 0;
}

