/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: locked_radio_id_lookup_by_string @ 03058314 (file base 0x03000000; code starts at 0x03001000)
 * Size: 74 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4 locked_radio_id_lookup_by_string(undefined4 param_1,ushort param_2)

{
  char cVar1;
  undefined4 uVar2;
  ushort uVar3;
  undefined1 auStack_28 [16];
  
  if (param_2 == 0) {
    uVar2 = 0;
  }
  else {
    flash_block_id_resolve_locked(0x67);
    uVar3 = 0;
    do {
      if (param_2 <= uVar3) {
        return 0;
      }
      uVar3 = uVar3 + 1 & 0xff;
      radio_id_entry_read_and_terminate(uVar3,auStack_28);
      cVar1 = strncmp_ck803s(param_1,auStack_28,0xc);
    } while (cVar1 != '\0');
    uVar2 = 1;
  }
  return uVar2;
}

