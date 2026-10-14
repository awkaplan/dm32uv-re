/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: aes_inv_shift_rows @ 030ccba8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 36 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void aes_inv_shift_rows(void)

{
  int iVar1;
  
  iVar1 = _DAT_030ccc94;
  rotate_uint32_bytes(_DAT_030ccc94 + 0x14,3);
  rotate_uint32_bytes(iVar1 + 0x18,2);
  rotate_uint32_bytes(iVar1 + 0x1c,1);
  return;
}

