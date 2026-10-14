/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: frequency_band_range_check_and_status_set @ 0300d84c (file base 0x03000000; code starts at 0x03001000)
 * Size: 458 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rf-frontend
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void frequency_band_range_check_and_status_set(uint param_1,uint param_2)

{
  byte bVar1;
  char cVar2;
  byte bVar3;
  radio_mode_state_0003e318 *prVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  prVar4 = p_radio_mode_state_0003e318;
  if ((param_1 < (uint)PTR_DAT_0300d9a8[8]) || ((uint)PTR_DAT_0300d9a8[9] <= param_1)) {
    if ((p_radio_mode_state_0003e318[1].flags_0x7 & 0x20) != 0) {
      p_radio_mode_state_0003e318[1].flags_0x7 = p_radio_mode_state_0003e318[1].flags_0x7 & 0xdf;
      PTR_DAT_0300d9b0[3] = PTR_DAT_0300d9b0[3] & 0xfe;
    }
    bVar1 = PTR_DAT_0300d9b4[1];
    bVar3 = p_dm32_settings_block04[0x2d];
    if ((bVar1 & 1) == bVar3 >> 7) {
      p_radio_mode_state_0003e318->flags_0x3 = p_radio_mode_state_0003e318->flags_0x3 & 0xbf;
    }
    else {
      p_radio_mode_state_0003e318[1].flags_0x6 = p_radio_mode_state_0003e318[1].flags_0x6 & 0xdf;
    }
    if ((param_1 < (uint)*PTR_DAT_0300d9a8) || ((uint)PTR_DAT_0300d9a8[1] < param_1)) {
      if ((param_1 < (uint)PTR_DAT_0300d9a8[2]) || ((uint)PTR_DAT_0300d9a8[3] < param_1)) {
        if ((bVar1 & 1) == bVar3 >> 7) {
          p_radio_mode_state_0003e318->flags_0x3 =
               p_radio_mode_state_0003e318->flags_0x3 & 0xbf | 0x40;
        }
        else {
          p_radio_mode_state_0003e318[1].flags_0x6 =
               p_radio_mode_state_0003e318[1].flags_0x6 & 0xdf | 0x20;
        }
      }
      else {
        p_radio_mode_state_0003e318->flags_0x3 = p_radio_mode_state_0003e318->flags_0x3 & 0xf7;
      }
    }
    else {
      p_radio_mode_state_0003e318->flags_0x3 = p_radio_mode_state_0003e318->flags_0x3 & 0xf7 | 8;
    }
    p_radio_mode_state_0003e318->flags_0x3 = p_radio_mode_state_0003e318->flags_0x3 & 0xdf;
    cVar2 = *(char *)PTR_DAT_0300d9bc;
    uVar5 = DAT_0300db20;
    uVar6 = DAT_0300db30;
    uVar7 = DAT_0300db1c;
    if (cVar2 == '\x01') {
      uVar8 = 14400000;
    }
    else if (cVar2 == '\0') {
      uVar8 = 14400000;
      uVar6 = DAT_0300db24;
    }
    else if (cVar2 == '\x02') {
      uVar5 = DAT_0300db2c;
      uVar8 = 14400000;
      uVar7 = DAT_0300db28;
    }
    else {
      uVar7 = DAT_0300d9c4;
      if (cVar2 == '\x03') {
        uVar7 = DAT_0300d9c0;
      }
      uVar8 = 13600000;
      uVar5 = DAT_0300d9cc;
      uVar6 = DAT_0300d9d4;
      if (cVar2 == '\x03') {
        uVar5 = DAT_0300d9c8;
        uVar8 = 14400000;
        uVar6 = DAT_0300d9d0;
      }
    }
    if ((param_2 < uVar6) || (uVar5 <= param_2)) {
      if ((param_2 < uVar8) || (uVar7 <= param_2)) {
        p_radio_mode_state_0003e318->flags_0x3 =
             p_radio_mode_state_0003e318->flags_0x3 & 0xdf | 0x20;
      }
      else {
        p_radio_mode_state_0003e318->flags_0x3 = p_radio_mode_state_0003e318->flags_0x3 & 0xef;
      }
    }
    else {
      p_radio_mode_state_0003e318->flags_0x3 = p_radio_mode_state_0003e318->flags_0x3 & 0xef | 0x10;
    }
  }
  else {
    p_radio_mode_state_0003e318[1].flags_0x7 =
         p_radio_mode_state_0003e318[1].flags_0x7 & 0xdf | 0x20;
    prVar4->flags_0x3 = prVar4->flags_0x3 & 0xf7;
  }
  return;
}

