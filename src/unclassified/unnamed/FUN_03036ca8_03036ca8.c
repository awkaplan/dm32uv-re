/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_03036ca8 @ 03036ca8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 116 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

void FUN_03036ca8(void)

{
  undefined1 auStack_8 [4];
  
  if (((PTR_DAT_03036de0[6] & 0xc) != 0) || ((*(uint *)PTR_DAT_03036de4 & 0x18000) == 0x8000)) {
    PTR_DAT_03036de4[4] = PTR_DAT_03036de4[4] & 0xdf | 0x20;
    if ((p_dm32_settings_block04[0x2d] & 0x80) == 0) {
      *(byte *)PTR_DAT_03036de8 = *(byte *)PTR_DAT_03036de8 & 0xf7;
    }
    else {
      *(byte *)PTR_DAT_03036de8 = *(byte *)PTR_DAT_03036de8 & 0xef;
    }
  }
  PTR_DAT_03036de0[6] = PTR_DAT_03036de0[6] & 0xfb;
  OSTmr_state_dispatch_callback(DAT_03036dec,0,0,auStack_8);
  history_queue_pop();
  return;
}

