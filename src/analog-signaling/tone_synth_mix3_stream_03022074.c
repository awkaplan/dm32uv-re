/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: tone_synth_mix3_stream @ 03022074 (file base 0x03000000; code starts at 0x03001000)
 * Size: 370 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: analog-signaling
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void tone_synth_mix3_stream(uint param_1,uint param_2,uint param_3,uint param_4,int param_5__w,int param_6__w,int param_7__w,int param_8__w)

{
  byte param_5 = (byte)param_5__w;
  byte param_6 = (byte)param_6__w;
  byte param_7 = (byte)param_7__w;
  byte param_8 = (byte)param_8__w;
  dword dVar1;
  undefined *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined1 *puVar6;
  uint uVar7;
  uint uVar8;
  short sVar9;
  uint uVar10;
  uint uStack_78;
  uint uStack_74;
  undefined1 local_64 [64];
  
  puVar2 = PTR_LAB_030221ec;
  uVar7 = (uint)param_8;
  if ((param_1 & 0xffff) != 0) {
    uStack_74 = 0;
    uStack_78 = 0;
    do {
      puVar6 = local_64;
      uVar3 = uStack_74;
      uVar4 = uStack_78;
      do {
        uVar8 = uVar4 * (param_2 & 0xffff) & 0x800007ff;
        if ((int)uVar8 < 0) {
          uVar8 = (uVar8 - 1 | 0xfffff800) + 1;
        }
        uVar10 = uVar4 * (param_3 & 0xffff) & 0x800007ff;
        if ((int)uVar10 < 0) {
          uVar10 = (uVar10 - 1 | 0xfffff800) + 1;
        }
        uVar5 = (param_4 & 0xffff) * uVar4 & 0x800007ff;
        if ((int)uVar5 < 0) {
          uVar5 = (uVar5 - 1 | 0xfffff800) + 1;
        }
        if (uVar7 == 0) {
          sVar9 = (short)((int)*(short *)(puVar2 + (uVar5 & 0xffff) * 2) >> (param_7 & 0x3f)) +
                  (short)((int)*(short *)(puVar2 + (uVar8 & 0xffff) * 2) >> (param_5 & 0x3f)) +
                  (short)((int)*(short *)(puVar2 + (uVar10 & 0xffff) * 2) >> (param_6 & 0x3f));
        }
        else {
          sVar9 = (short)((int)((8 - ((*(ushort *)(puVar2 + (uVar3 & 0x7ff) * 2) >> 10 ^ 0x20) -
                                     0x20)) *
                               (((int)*(short *)(puVar2 + (uVar5 & 0xffff) * 2) >> (param_7 & 0x3f))
                               + ((int)*(short *)(puVar2 + (uVar8 & 0xffff) * 2) >> (param_5 & 0x3f)
                                 ) + ((int)*(short *)(puVar2 + (uVar10 & 0xffff) * 2) >>
                                     (param_6 & 0x3f)))) >> 4);
        }
        puVar6[1] = (char)((ushort)sVar9 >> 8);
        *puVar6 = (char)sVar9;
        uVar4 = uVar4 + 1 & 0xffff;
        puVar6 = puVar6 + 2;
        uVar3 = uVar3 + uVar7 & 0xffff;
      } while (puVar6 != &stack0xffffffdc);
      uStack_78 = uStack_78 + 0x20 & 0xffff;
      do {
        dVar1 = SystemControl_Type_11000000.AUDIO_CONTROL;
      } while ((int)dVar1 < 0);
      memcpy_bytes_iram(DAT_030221e8,local_64,0x40);
      uStack_74 = uStack_74 + uVar7 * 0x20 & 0xffff;
    } while (uStack_78 < (param_1 & 0xffff));
  }
  return;
}

