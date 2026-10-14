/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: poll_flag_until_ff_or_timeout @ 030667a4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 66 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined4 poll_flag_until_ff_or_timeout(void)

{
  int iVar1;
  char local_20 [4];
  undefined1 local_1c [4];
  
  local_1c[0] = 0xff;
  iVar1 = 0;
  do {
    spi_controller_byte_xfer_rdwr(1,1,local_20,1,local_1c,0);
    if (local_20[0] == -1) {
      return 0;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 != 0xffff);
  return 1;
}

