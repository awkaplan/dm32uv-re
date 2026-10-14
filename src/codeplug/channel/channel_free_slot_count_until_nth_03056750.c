/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_free_slot_count_until_nth @ 03056750 (file base 0x03000000; code starts at 0x03001000)
 * Size: 158 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

ushort channel_free_slot_count_until_nth(int param_1__w,int param_2__w)

{
  char param_1 = (char)param_1__w;
  short param_2 = (short)param_2__w;
  ushort uVar1;
  byte bVar2;
  ushort uVar3;
  ushort uVar4;
  ushort *puVar5;
  byte bVar6;
  short sVar7;
  ushort local_a4;
  ushort local_a2 [63];
  short local_24;
  undefined1 local_22 [2];
  
  channel_offset_minus_0x10(param_1 + '\x01',local_22,&local_24);
  flash_field_read_cached(local_22[0],local_24 + 0x11,&local_a4,0x80);
  SUBPIECE_SET(uVar1, 0, 1, p_radio_mode_state_0003e318[1].field_0x8);
  SUBPIECE_SET(uVar1, 1, 1, p_radio_mode_state_0003e318[1].field_0x9);
  if (uVar1 != 0) {
    bVar2 = *(byte *)PTR_DAT_030567f8;
    sVar7 = 0;
    uVar4 = 1;
    do {
      if (bVar2 == 0) {
LAB_030567c4:
        sVar7 = sVar7 + 1;
        if (sVar7 == param_2) {
          return uVar4;
        }
      }
      else {
        puVar5 = local_a2;
        bVar6 = 0;
        if (local_a4 != uVar4) {
          do {
            bVar6 = bVar6 + 1;
            if (bVar2 <= bVar6) break;
            uVar3 = *puVar5;
            puVar5 = puVar5 + 1;
          } while (uVar3 != uVar4);
          if (bVar2 == bVar6) goto LAB_030567c4;
        }
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 <= uVar1);
  }
  return 0;
}

