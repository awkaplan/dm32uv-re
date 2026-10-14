/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: tone_synth_mix4_stream @ 03021d10 (file base 0x03000000; code starts at 0x03001000)
 * Size: 300 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: analog-signaling
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void tone_synth_mix4_stream(uint param_1,uint param_2,uint param_3,uint param_4,int param_5__w,int param_6__w,int param_7__w,int param_8__w,int param_9__w)

{
  ushort param_5 = (ushort)param_5__w;
  byte param_6 = (byte)param_6__w;
  byte param_7 = (byte)param_7__w;
  byte param_8 = (byte)param_8__w;
  byte param_9 = (byte)param_9__w;
  dword dVar1;
  undefined *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  uint uStack_74;
  char acStack_64 [64];
  
  puVar2 = PTR_LAB_03021fdc;
  if ((param_1 & 0xffff) != 0) {
    uStack_74 = 0;
    do {
      pcVar8 = acStack_64;
      uVar4 = uStack_74;
      do {
        uVar5 = uVar4 * (param_3 & 0xffff) & 0x800007ff;
        if ((int)uVar5 < 0) {
          uVar5 = (uVar5 - 1 | 0xfffff800) + 1;
        }
        uVar6 = uVar4 * (param_2 & 0xffff) & 0x800007ff;
        if ((int)uVar6 < 0) {
          uVar6 = (uVar6 - 1 | 0xfffff800) + 1;
        }
        uVar7 = uVar4 * (param_4 & 0xffff) & 0x800007ff;
        if ((int)uVar7 < 0) {
          uVar7 = (uVar7 - 1 | 0xfffff800) + 1;
        }
        uVar3 = param_5 * uVar4 & 0x800007ff;
        if ((int)uVar3 < 0) {
          uVar3 = (uVar3 - 1 | 0xfffff800) + 1;
        }
        uVar5 = ((uint)(((int)*(short *)(puVar2 + (uVar5 & 0xffff) * 2) >> (param_7 & 0x3f)) +
                        ((int)*(short *)(puVar2 + (uVar6 & 0xffff) * 2) >> (param_6 & 0x3f)) +
                        ((int)*(short *)(puVar2 + (uVar7 & 0xffff) * 2) >> (param_8 & 0x3f)) +
                       ((int)*(short *)(puVar2 + (uVar3 & 0xffff) * 2) >> (param_9 & 0x3f))) >> 1 &
                 0x7fff ^ 0x4000) - 0x4000 & 0xffff;
        pcVar8[1] = ((byte)(uVar5 >> 8) ^ 0x80) + 0x80;
        *pcVar8 = (char)uVar5;
        uVar4 = uVar4 + 1 & 0xffff;
        pcVar8 = pcVar8 + 2;
      } while (pcVar8 != &stack0xffffffdc);
      uStack_74 = uStack_74 + 0x20 & 0xffff;
      do {
        dVar1 = SystemControl_Type_11000000.AUDIO_CONTROL;
      } while ((int)dVar1 < 0);
      memcpy_bytes_iram(DAT_03021e38,acStack_64,0x40);
    } while (uStack_74 < (param_1 & 0xffff));
  }
  return;
}

