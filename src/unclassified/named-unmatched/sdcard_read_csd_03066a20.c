/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: sdcard_read_csd @ 03066a20 (file base 0x03000000; code starts at 0x03001000)
 * Size: 42 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

bool sdcard_read_csd(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = spi_sdcard_send_command(9,0,1);
  if (iVar1 == 0) {
    iVar1 = spi_sdcard_sync_byte_probe(param_1,0x10);
  }
  spi_sdcard_read_status_register();
  return iVar1 != 0;
}

