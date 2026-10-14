/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: settings_toggle_and_notify_0x45 @ 03061a88 (file base 0x03000000; code starts at 0x03001000)
 * Size: 108 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void settings_toggle_and_notify_0x45(char param_1)

{
  byte local_d;
  
  flash_field_read_cached(4,0x45,&local_d,1);
  local_d = local_d & 0xfe;
  if (param_1 == '\0') {
    PTR_DAT_03061b08[0x2b] = PTR_DAT_03061b08[0x2b] & 0xfe;
  }
  else {
    local_d = local_d | 1;
    PTR_DAT_03061b08[0x2b] = PTR_DAT_03061b08[0x2b] & 0xfe | 1;
  }
  flash_field_write_cached(4,0x45,local_d);
  set_single_bit_field_0x3(PTR_DAT_03061b08[0x2b] & 1);
  return;
}

