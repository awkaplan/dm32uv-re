/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: integer_to_radix_string_format @ 0306c788 (file base 0x03000000; code starts at 0x03001000)
 * Size: 454 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

int integer_to_radix_string_format
              (uint param_1,uint param_2,uint param_3,int param_4,char param_5,char param_6,
              char param_7,int param_8)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint unaff_r4;
  byte bVar6;
  char *pcVar7;
  uint uStack_28;
  
  if (param_8 == 0) {
    return 0;
  }
  if ((param_3 - 2 & 0xff) < 0x23) {
    bVar6 = ~(param_2 != 0);
  }
  else {
    bVar6 = 1;
  }
  if (param_5 != '\0') {
    iVar3 = FUN_0306b824(param_5);
    if (iVar3 != 1) {
      bVar6 = 1;
      goto LAB_0306c880;
    }
    if (param_5 != '0') {
      if (param_6 == '\x01') {
        cVar1 = -0x61;
      }
      else {
        cVar1 = -0x41;
      }
      if (param_3 < 0xb) {
        if ((byte)(param_5 - 0x30) < param_3) {
          bVar6 = 1;
          goto LAB_0306c880;
        }
      }
      else {
        if ((byte)(param_5 - 0x30) < 10) {
          bVar6 = 1;
          goto LAB_0306c880;
        }
        if ((uint)(byte)(param_5 + cVar1) < param_3 - 10) {
          bVar6 = 1;
          goto LAB_0306c880;
        }
      }
    }
  }
  if (bVar6 == 0) {
    if (param_1 < param_3) {
      uVar4 = 1;
    }
    else {
      uVar4 = 1;
      uVar5 = param_1;
      do {
        uVar4 = uVar4 + 1 & 0xff;
        uVar5 = uVar5 / param_3;
      } while (param_3 <= uVar5);
    }
    uVar5 = (uint)(byte)~(param_4 != 1);
    unaff_r4 = param_1;
    if ((int)param_2 < (int)(uVar4 + uVar5)) {
      bVar6 = 1;
    }
    else {
      if (param_2 < uVar4) {
        uVar4 = param_2;
      }
      if (param_5 == '\0') {
        param_2 = (uVar4 & 0xff) + uVar5 & 0xff;
        uStack_28 = 0;
      }
      else if (uVar5 == (param_2 - (uVar4 & 0xff) & 0xff)) {
        uStack_28 = 0;
      }
      else {
        uStack_28 = (uint)(param_5 == '0');
      }
    }
  }
LAB_0306c880:
  if (param_7 != '\0') {
    *(undefined1 *)(param_2 + param_8) = 0;
  }
  if (param_2 != 0) {
    pcVar7 = (undefined1 *)(param_2 + param_8) + -1;
    bVar2 = false;
    uVar4 = 0;
    do {
      if (bVar6 == 0) {
        if ((unaff_r4 == 0) && (uVar4 != 0)) {
          if (param_4 == 1) {
            if (uStack_28 == 0) {
              if (!bVar2) {
LAB_0306c918:
                *pcVar7 = '-';
                pcVar7 = pcVar7 + -1;
                bVar2 = true;
                goto LAB_0306c93c;
              }
            }
            else if (param_2 - 1 == uVar4) goto LAB_0306c918;
          }
          if (param_5 != '\0') {
            *pcVar7 = param_5;
            pcVar7 = pcVar7 + -1;
          }
        }
        else {
          uVar5 = unaff_r4 - param_3 * (unaff_r4 / param_3);
          cVar1 = (char)uVar5;
          if ((uVar5 & 0xff) < 10) {
            *pcVar7 = cVar1 + '0';
          }
          else if (param_6 == '\x01') {
            *pcVar7 = cVar1 + 'W';
          }
          else {
            *pcVar7 = cVar1 + '7';
          }
          pcVar7 = pcVar7 + -1;
          unaff_r4 = unaff_r4 / param_3;
        }
      }
      else {
        *pcVar7 = '?';
        pcVar7 = pcVar7 + -1;
      }
LAB_0306c93c:
      uVar4 = uVar4 + 1;
    } while (uVar4 < param_2);
  }
  if (bVar6 != 0) {
    param_8 = 0;
  }
  return param_8;
}

