/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: zone_name_exists_check @ 030569d4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 90 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4 zone_name_exists_check(undefined4 param_1)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  undefined1 auStack_38 [20];
  undefined2 local_24;
  undefined1 local_22 [2];
  
  uVar2 = get_zone_count();
  if (uVar2 != 0) {
    uVar3 = 1;
    do {
      channel_offset_minus_0x10(uVar3 & 0xff,local_22,&local_24);
      flash_field_read_cached(local_22[0],local_24,auStack_38,0x10);
      cVar1 = strncmp_ck803s(param_1,auStack_38,0x10);
      if (cVar1 == '\0') {
        return 1;
      }
      uVar3 = uVar3 + 1 & 0xffff;
    } while (uVar3 <= uVar2);
  }
  return 0;
}

