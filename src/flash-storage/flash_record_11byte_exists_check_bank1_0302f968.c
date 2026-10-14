/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flash_record_11byte_exists_check_bank1 @ 0302f968 (file base 0x03000000; code starts at 0x03001000)
 * Size: 82 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: flash-storage
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4 flash_record_11byte_exists_check_bank1(undefined4 param_1)

{
  byte bVar1;
  char cVar2;
  short sVar3;
  ushort uVar4;
  undefined1 auStack_2c [12];
  
  bVar1 = *(byte *)p_vfo_freq_display_state;
  if (bVar1 != 0) {
    sVar3 = 1;
    uVar4 = 0;
    do {
      flash_field_read_cached(0x11,sVar3,auStack_2c,0xb);
      cVar2 = strncmp_ck803s(param_1,auStack_2c,0xb);
      if (cVar2 == '\0') {
        return 1;
      }
      uVar4 = uVar4 + 1;
      sVar3 = sVar3 + 0x39;
    } while (uVar4 < bVar1);
  }
  return 0;
}

