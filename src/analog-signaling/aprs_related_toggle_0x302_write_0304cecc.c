/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: aprs_related_toggle_0x302_write @ 0304cecc (file base 0x03000000; code starts at 0x03001000)
 * Size: 92 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: analog-signaling
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void aprs_related_toggle_0x302_write(char param_1)

{
  byte local_9;
  
  flash_field_read_cached(4,0x302,&local_9,1);
  if (param_1 == '\0') {
    local_9 = local_9 & 0xfe;
    *(byte *)PTR_DAT_0304cf2c = *(byte *)PTR_DAT_0304cf2c & 0xfb;
  }
  else {
    local_9 = local_9 | 1;
    *(byte *)PTR_DAT_0304cf2c = *(byte *)PTR_DAT_0304cf2c & 0xfb | 4;
  }
  flash_field_write_cached(4,0x302,local_9);
  return;
}

