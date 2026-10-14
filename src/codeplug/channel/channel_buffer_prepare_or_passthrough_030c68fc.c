/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_buffer_prepare_or_passthrough @ 030c68fc (file base 0x03000000; code starts at 0x03001000)
 * Size: 132 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined2
channel_buffer_prepare_or_passthrough
          (undefined4 param_1,short param_2,undefined4 param_3,short param_4,short param_5,
          short param_6,int param_7)

{
  undefined2 uVar1;
  undefined1 auStack_ac [136];
  
  if (param_2 < 0x4c) {
    param_2 = 0x4c;
  }
  if (0x54 < param_2) {
    param_2 = 0x54;
  }
  *(undefined2 *)(param_7 + 0x170) = 0x50;
  if (param_6 == 0) {
    u16_buffer_fill_memset(auStack_ac,0,0x44);
    uVar1 = dmr_message_checksum_verify_and_status_resolve
                      (param_3,(int)param_4,(int)param_5,(int)param_2,param_7 + 1000,auStack_ac,
                       param_7);
    channel_buffer_frame_process(auStack_ac,param_1,(int)param_2,0,param_7);
  }
  else {
    uVar1 = 0;
    channel_buffer_frame_process(param_7 + 1000,param_1,(int)param_2,(int)param_6,param_7);
  }
  return uVar1;
}

