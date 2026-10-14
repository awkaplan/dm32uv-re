/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_squelch_tone_scan_and_apply @ 0302fe94 (file base 0x03000000; code starts at 0x03001000)
 * Size: 378 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rf-frontend
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void channel_squelch_tone_scan_and_apply(int param_1__w)

{
  char param_1 = (char)param_1__w;
  undefined1 uVar1;
  undefined1 *puVar2;
  undefined2 *puVar3;
  undefined4 *puVar4;
  byte bVar5;
  ushort uVar6;
  ushort uVar7;
  float a;
  uint uVar8;
  ushort uVar9;
  uint uVar10;
  undefined4 *puVar11;
  int iVar12;
  uint uVar13;
  char cVar14;
  
  puVar4 = PTR_LAB_03030038;
  if (param_1 == '\x01') {
    soft_double_from_int(*(undefined2 *)PTR_DAT_03030010);
    soft_double_divide();
    a = (float)softdouble_extract_exponent_mantissa();
    softfloat32_mul(a,(float)*PTR_LAB_03030018);
    uVar6 = mutex_guarded_call_wrapper();
    puVar2 = PTR_LAB_03030020;
    uVar7 = *(ushort *)PTR_DAT_0303001c;
    if (uVar7 < uVar6) {
      uVar7 = uVar6 - uVar7;
    }
    else {
      uVar7 = uVar7 - uVar6;
    }
    if (uVar7 < 0x32) {
      iVar12 = 0;
      uVar10 = 0;
      do {
        uVar7 = bcd_frequency_decode(puVar2 + iVar12,2);
        puVar3 = PTR_DAT_03030028;
        if (uVar6 < uVar7) {
          uVar9 = uVar7 - uVar6;
        }
        else {
          uVar9 = uVar6 - uVar7;
        }
        if (uVar9 < 7) {
          uVar6 = uVar7;
          if (uVar10 < 0x32) {
            if (*(short *)PTR_DAT_03030024 == *(short *)PTR_DAT_0303001c) {
              uVar1 = PTR_LAB_03030020[uVar10 * 2 + 1];
              *(undefined1 *)((int)PTR_DAT_03030028 + 0x11) = PTR_LAB_03030020[uVar10 * 2];
              *(undefined1 *)(puVar3 + 9) = uVar1;
              *(undefined1 *)PTR_DAT_0303002c = 0;
              *(ushort *)PTR_DAT_0303001c = uVar7;
LAB_0302ffbc:
              *(undefined1 *)PTR_DAT_0303003c = 100;
              bVar5 = tone_signaling_type_classify(*(undefined2 *)((int)PTR_DAT_03030028 + 0x11));
              PTR_DAT_03030040[0x35] = PTR_DAT_03030040[0x35] & 0xf3 | (bVar5 & 3) << 2;
              rf_channel_mode_select_and_apply();
              return;
            }
            *(short *)PTR_DAT_03030024 = *(short *)PTR_DAT_0303001c;
          }
          break;
        }
        uVar10 = uVar10 + 1 & 0xff;
        iVar12 = iVar12 + 2;
      } while (uVar10 != 0x32);
    }
    *(ushort *)PTR_DAT_0303001c = uVar6;
  }
  else {
    cVar14 = '\0';
    uVar10 = (*(ushort *)PTR_DAT_03030030 & 0x7ff) << 0xc | (uint)*_DAT_03030034;
    puVar11 = puVar4;
    uVar13 = 0;
    do {
      do {
        uVar8 = freq_bitpack_crc12_encode(*(undefined2 *)puVar11);
        uVar8 = count_clear_bits_low23(uVar8 ^ uVar10);
        if (0x14 < uVar8) {
          *(undefined1 *)PTR_DAT_0303002c = 1;
          puVar3 = PTR_DAT_03030028;
          bVar5 = *(byte *)((int)PTR_LAB_03030038 + uVar13 + 1);
          *(undefined1 *)((int)PTR_DAT_03030028 + 0x11) =
               *(undefined1 *)((int)PTR_LAB_03030038 + uVar13);
          *(byte *)(puVar3 + 9) = bVar5 | 0x80;
          goto LAB_0302ffbc;
        }
        uVar13 = uVar13 + 2 & 0xff;
        puVar11 = (undefined4 *)((int)puVar11 + 2);
      } while (uVar13 != 0xd2);
      uVar13 = uVar10 & 0x400000;
      uVar10 = uVar10 * 2;
      if (uVar13 != 0) {
        uVar10 = uVar10 | 1;
      }
      cVar14 = cVar14 + '\x01';
      puVar11 = puVar4;
      uVar13 = 0;
    } while (cVar14 != '\x17');
  }
  return;
}

