/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flash_field_find_nth_matching_value @ 03056a84 (file base 0x03000000; code starts at 0x03001000)
 * Size: 168 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: flash-storage
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

ushort flash_field_find_nth_matching_value(int param_1__w,int param_2__w)

{
  ushort param_1 = (ushort)param_1__w;
  short param_2 = (short)param_2__w;
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  short sVar4;
  uint uVar5;
  undefined2 local_40;
  
  flash_field_read_cached(0x11,((param_1 & 0xff) - 1) * 0x39 + 0x1b,&local_40,0x1e);
  SUBPIECE_SET(uVar1, 0, 1, p_radio_mode_state_0003e318[1].field_0x8);
  SUBPIECE_SET(uVar1, 1, 1, p_radio_mode_state_0003e318[1].field_0x9);
  if (uVar1 != 0) {
    uVar5 = p_vfo_freq_display_state->field_0x1 - 1;
    sVar4 = 0;
    uVar2 = 1;
    do {
      if ((int)uVar5 < 1) {
        uVar3 = 0;
      }
      else {
        uVar3 = 0;
        if (local_40 == uVar2) {
          uVar3 = 0;
        }
        else {
          do {
            uVar3 = uVar3 + 1 & 0xff;
            if ((int)uVar5 <= (int)uVar3) break;
          } while (CONCAT11(*(undefined1 *)((int)&local_40 + uVar3 * 2 + 1),
                            *(undefined1 *)(&local_40 + uVar3)) != uVar2);
        }
      }
      if ((uVar5 == uVar3) && (sVar4 = sVar4 + 1, sVar4 == param_2)) {
        return uVar2;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 <= uVar1);
  }
  return 0;
}

