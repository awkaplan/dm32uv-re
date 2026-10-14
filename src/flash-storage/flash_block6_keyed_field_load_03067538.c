/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flash_block6_keyed_field_load @ 03067538 (file base 0x03000000; code starts at 0x03001000)
 * Size: 42 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: flash-storage
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void flash_block6_keyed_field_load(void)

{
  undefined1 *puVar1;
  
  puVar1 = PTR_DAT_03067658;
  memcpy_bytes_iram(PTR_DAT_03067658,_DAT_0306765c,5);
  byte_bitplane_differential_xor_invert(puVar1,5);
  memset_bytes_wrapper();
  flash_field_read_cached(6,0xa20,_DAT_03067660,9);
  return;
}

