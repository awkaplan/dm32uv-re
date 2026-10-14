/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_record_commit_step_with_fixedpoint_scale @ 030c6b5c (file base 0x03000000; code starts at 0x03001000)
 * Size: 132 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

ushort channel_record_commit_step_with_fixedpoint_scale
                 (undefined4 param_1,short param_2,undefined4 param_3,short param_4,ushort param_5,
                 ushort param_6,short param_7,int param_8)

{
  ushort uVar1;
  uint uVar2;
  
  if (param_4 < 0x4c) {
    param_4 = 0x4c;
  }
  if (0x54 < param_4) {
    param_4 = 0x54;
  }
  tone_squelch_detection_frame_dispatch
            (param_8,param_3,(int)param_4,(int)(short)param_5,(int)(short)param_6);
  uVar1 = param_6 & 1;
  if ((param_6 & 1) != 0) {
    uVar1 = param_5 & 0x2000;
    if ((param_5 & 0x2000) != 0) {
      uVar2 = fixedpoint_level_gain_select(param_8 + 0x938,param_8 + 0x63a,param_8 + 0x16a2);
      uVar1 = (ushort)((uVar2 & 0xffff) * 0xaa16 >> 0xf);
    }
    uVar1 = dmr_signaling_param_block_build_and_dispatch
                      (param_1,(int)param_2,(int)(short)param_5,(int)param_7,param_8,
                       (int)(short)uVar1);
  }
  return uVar1;
}

