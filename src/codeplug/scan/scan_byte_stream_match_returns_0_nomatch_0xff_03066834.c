/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: scan_byte_stream_match_returns_0_nomatch_0xff @ 03066834 (file base 0x03000000; code starts at 0x03001000)
 * Size: 84 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4 scan_byte_stream_match_returns_0_nomatch_0xff(char param_1)

{
  short sVar1;
  char local_24 [4];
  undefined1 local_20 [4];
  
  local_20[0] = 0xff;
  sVar1 = -1;
  do {
    spi_controller_byte_xfer_rdwr(1,1,local_24,1,local_20,0);
    if (local_24[0] == param_1) {
      if (sVar1 == 0) {
        return 0xff;
      }
      return 0;
    }
    sVar1 = sVar1 + -1;
  } while (sVar1 != 0);
  return 0xff;
}

