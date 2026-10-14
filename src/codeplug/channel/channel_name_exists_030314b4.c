/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_name_exists @ 030314b4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 74 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4 channel_name_exists(undefined4 param_1)

{
  short sVar1;
  ushort uVar2;
  radio_mode_state_0003e318 *prVar3;
  char cVar4;
  ushort uVar5;
  undefined1 auStack_2c [20];
  
  prVar3 = p_radio_mode_state_0003e318;
  SUBPIECE_SET(sVar1, 0, 1, p_radio_mode_state_0003e318[1].field_0x8);
  SUBPIECE_SET(sVar1, 1, 1, p_radio_mode_state_0003e318[1].field_0x9);
  if (sVar1 != 0) {
    uVar5 = 1;
    do {
      channel_record_read_full(uVar5,auStack_2c);
      cVar4 = strncmp_ck803s(param_1,auStack_2c,0x10);
      if (cVar4 == '\0') {
        return 1;
      }
      uVar5 = uVar5 + 1;
      SUBPIECE_SET(uVar2, 0, 1, prVar3[1].field_0x8);
      SUBPIECE_SET(uVar2, 1, 1, prVar3[1].field_0x9);
    } while (uVar5 <= uVar2);
  }
  return 0;
}

