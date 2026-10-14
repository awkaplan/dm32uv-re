/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: signal_meter_bargraph_draw @ 0305fd90 (file base 0x03000000; code starts at 0x03001000)
 * Size: 420 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void signal_meter_bargraph_draw(char param_1,char param_2,ushort param_3)

{
  undefined4 *puVar1;
  short sVar2;
  byte bVar3;
  ushort x0;
  short sVar4;
  
  if ((((*(byte *)((int)PTR_DAT_0305ff34 + 3) & 2) == 0) &&
      ((p_dm32_settings_block04[0x6c] != '\0' || ((*PTR_DAT_0305ff34 & 0x18000) != 0x8000)))) &&
     ((*(char *)PTR_DAT_0305ff3c == '\0' || (*(char *)PTR_DAT_0305ff3c == 'w')))) {
    if ((PTR_DAT_0305ff40[1] & 1) == 0) {
      sVar4 = 0x76;
    }
    else {
      sVar4 = 0xec;
    }
    if (p_dm32_settings_block04[0x6c] == '\0') {
      sVar4 = 0x9f;
    }
    sVar2 = sVar4 + 2;
    bVar3 = param_2 * '\n' + 0x21;
    if (0xdf < bVar3) {
      bVar3 = 0xdf;
    }
    if (bVar3 < 0x22) {
      x0 = 0x21;
    }
    else {
      x0 = 0x21;
      do {
        if (param_1 == '\0') {
          if (x0 < 0x9f) {
            param_3 = 0xffff;
          }
          else {
            param_3 = 0x1f;
          }
        }
        display_fill_rect(x0,sVar2,x0 + 2,sVar4 + 0x11,param_3);
        x0 = x0 + 4;
      } while (x0 < bVar3);
      if (0xde < x0) {
        return;
      }
    }
    puVar1 = PTR_DAT_0305ff34;
    if (param_2 == '\0') {
      if (p_dm32_settings_block04[0x6c] == '\0') {
        if (x0 < 0xdf) {
          do {
            display_fill_rect(x0,sVar2,x0 + 2,sVar4 + 0x11,0x8430);
            x0 = x0 + 4;
          } while (x0 < 0xdf);
        }
      }
      else {
        sVar4 = 0x78;
        if ((PTR_DAT_0305ff40[1] & 1) == 0) {
          sVar4 = 0xee;
        }
        if ((PTR_DAT_0305ff40[1] & 1) == 0) {
          sVar2 = 0x78;
        }
        else {
          sVar2 = 0xee;
        }
        if (x0 < 0xdf) {
          do {
            display_fill_rect(x0,sVar2,x0 + 2,sVar2 + 0xf,0x8430);
            if ((*puVar1 & 0x18000) != 0x8000) {
              display_fill_rect(x0,sVar4,x0 + 2,sVar4 + 0xf,0x8430);
            }
            x0 = x0 + 4;
          } while (x0 < 0xdf);
        }
      }
    }
    else {
      do {
        display_fill_rect(x0,sVar2,x0 + 2,sVar4 + 0x11,0x8430);
        x0 = x0 + 4;
      } while (x0 < 0xdf);
    }
  }
  return;
}

