/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: tone_mixer_3osc_additive @ 03021e68 (file base 0x03000000; code starts at 0x03001000)
 * Size: 506 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: audio
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void tone_mixer_3osc_additive(uint param_1,uint param_2,uint param_3,uint param_4,int param_5__w,int param_6__w,int param_7__w,int param_8__w)

{
  byte param_5 = (byte)param_5__w;
  byte param_6 = (byte)param_6__w;
  byte param_7 = (byte)param_7__w;
  byte param_8 = (byte)param_8__w;
  bool bVar1;
  dword dVar2;
  undefined *puVar3;
  radio_mode_state_0003e318 *prVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined1 *puVar8;
  uint uVar9;
  uint uVar10;
  short sVar11;
  uint uVar12;
  uint uStack_74;
  uint uStack_70;
  undefined1 local_64 [64];
  
  uStack_70 = param_1 & 0xffff;
  uVar9 = (uint)param_8;
  bVar1 = uStack_70 == 0;
  if (bVar1) {
    p_radio_mode_state_0003e318->flags_0x7 = p_radio_mode_state_0003e318->flags_0x7 & 0xfe | 1;
    uStack_70 = 0xffff;
  }
  puVar3 = PTR_LAB_03021fdc;
  uStack_74 = 0;
  do {
    prVar4 = p_radio_mode_state_0003e318;
    if ((bVar1) && (0xfff0 < uStack_74)) {
      uStack_74 = 0;
    }
    if ((p_radio_mode_state_0003e318->flags_0x6 & 0x80) != 0) {
      p_radio_mode_state_0003e318->flags_0x6 = p_radio_mode_state_0003e318->flags_0x6 & 0x7f;
      prVar4->flags_0x7 = prVar4->flags_0x7 & 0xfe;
      OSFlagPost_wrapper_set(p_ucos_flaggrp_0003fd90,0x80000);
      return;
    }
    if ((*(byte *)PTR_DAT_03021fe8 & 0x40) != 0) {
      p_radio_mode_state_0003e318->flags_0x6 = p_radio_mode_state_0003e318->flags_0x6 & 0x7f;
      prVar4->flags_0x7 = prVar4->flags_0x7 & 0xfe;
      return;
    }
    dVar2 = SystemControl_Type_11000000.AUDIO_CONTROL;
    if ((int)dVar2 < 0) {
      tx_forbid_flag_clear_call();
    }
    else {
      puVar8 = local_64;
      uVar5 = uStack_74 * uVar9;
      uVar6 = uStack_74;
      do {
        uVar10 = uVar6 * (param_2 & 0xffff) & 0x800007ff;
        if ((int)uVar10 < 0) {
          uVar10 = (uVar10 - 1 | 0xfffff800) + 1;
        }
        uVar12 = uVar6 * (param_3 & 0xffff) & 0x800007ff;
        if ((int)uVar12 < 0) {
          uVar12 = (uVar12 - 1 | 0xfffff800) + 1;
        }
        uVar7 = (param_4 & 0xffff) * uVar6 & 0x800007ff;
        if ((int)uVar7 < 0) {
          uVar7 = (uVar7 - 1 | 0xfffff800) + 1;
        }
        if (uVar9 == 0) {
          sVar11 = (short)((int)*(short *)(puVar3 + (uVar7 & 0xffff) * 2) >> (param_7 & 0x3f)) +
                   (short)((int)*(short *)(puVar3 + (uVar10 & 0xffff) * 2) >> (param_5 & 0x3f)) +
                   (short)((int)*(short *)(puVar3 + (uVar12 & 0xffff) * 2) >> (param_6 & 0x3f));
        }
        else {
          sVar11 = (short)((int)((8 - ((*(ushort *)(puVar3 + (uVar5 & 0x7ff) * 2) >> 10 ^ 0x20) -
                                      0x20)) *
                                (((int)*(short *)(puVar3 + (uVar7 & 0xffff) * 2) >> (param_7 & 0x3f)
                                 ) + ((int)*(short *)(puVar3 + (uVar10 & 0xffff) * 2) >>
                                     (param_5 & 0x3f)) +
                                     ((int)*(short *)(puVar3 + (uVar12 & 0xffff) * 2) >>
                                     (param_6 & 0x3f)))) >> 4);
        }
        puVar8[1] = (char)((ushort)sVar11 >> 8);
        *puVar8 = (char)sVar11;
        uVar6 = uVar6 + 1 & 0xffff;
        puVar8 = puVar8 + 2;
        uVar5 = (uVar5 & 0xffff) + uVar9;
      } while (puVar8 != &stack0xffffffdc);
      uStack_74 = uStack_74 + 0x20 & 0xffff;
      memcpy_bytes_iram(DAT_030221e8,local_64,0x40);
    }
  } while (uStack_74 < uStack_70);
  return;
}

