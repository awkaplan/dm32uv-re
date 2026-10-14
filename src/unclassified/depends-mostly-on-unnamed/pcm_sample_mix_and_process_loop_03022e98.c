/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: pcm_sample_mix_and_process_loop @ 03022e98 (file base 0x03000000; code starts at 0x03001000)
 * Size: 254 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void pcm_sample_mix_and_process_loop(uint param_1,uint param_2,uint param_3)

{
  dword dVar1;
  undefined *puVar2;
  undefined4 *puVar3;
  float fVar4;
  float b;
  uint uVar5;
  undefined4 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  uint uVar9;
  float b_00;
  uint uStack_74;
  undefined1 local_64 [64];
  
  puVar3 = PTR_CODEC_Type_03022fa0;
  puVar2 = PTR_LAB_03022f9c;
  if (((param_1 & 0xffff) != 0) && ((*SUB_03022f98 & 1) == 0)) {
    uStack_74 = 0;
    do {
      dVar1 = SystemControl_Type_11000000.AUDIO_CONTROL;
      if ((int)dVar1 < 0) {
        tx_forbid_flag_clear_call();
      }
      else {
        puVar7 = local_64;
        b_00 = *(float *)PTR_LAB_03022fa4;
        puVar8 = puVar7;
        uVar9 = uStack_74;
        do {
          uVar5 = uVar9 * (param_2 & 0xffff) & 0x800007ff;
          if ((int)uVar5 < 0) {
            uVar5 = (uVar5 - 1 | 0xfffff800) + 1;
          }
          fVar4 = (float)int32_to_float32_special_case_only
                                   ((int)*(short *)(puVar2 + (uVar5 & 0xffff) * 2));
          fVar4 = softfloat32_mul(fVar4,b_00);
          uVar5 = (param_3 & 0xffff) * uVar9 & 0x800007ff;
          if ((int)uVar5 < 0) {
            uVar5 = (uVar5 - 1 | 0xfffff800) + 1;
          }
          b = (float)int32_to_float32_special_case_only
                               ((int)*(short *)(puVar2 + (uVar5 & 0xffff) * 2));
          softfloat32_add(fVar4,b);
          uVar5 = mutex_guarded_call_wrapper();
          *puVar8 = (char)(uVar5 & 0xffff);
          puVar8[1] = (char)((uVar5 & 0xffff) >> 8);
          uVar9 = uVar9 + 1 & 0xffff;
          puVar8 = puVar8 + 2;
        } while (puVar8 != &stack0xffffffdc);
        uStack_74 = uStack_74 + 0x20 & 0xffff;
        puVar6 = PTR_DAT_03022fa8;
        do {
          *(undefined1 *)puVar6 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar6 = (undefined4 *)((int)puVar6 + 1);
        } while (puVar6 != puVar3);
      }
    } while ((uStack_74 < (param_1 & 0xffff)) && ((*SUB_03022f98 & 1) == 0));
  }
  return;
}

