/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: vfo_record_offset_select3 @ 030562d8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 74 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-screen
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void vfo_record_offset_select3(void *dest,void *src)

{
  undefined4 uVar1;
  
  if ((p_dm32_settings_block04[0x2d] & 4) == 0) {
    if ((p_dm32_settings_block04[0x2d] & 0x80) == 0) {
      *(undefined2 *)src = 0xfaf;
    }
    else {
      *(undefined2 *)src = 0xfdf;
    }
    *(undefined2 *)dest = 0x41;
  }
  else {
    uVar1 = channel_list_index_resolve(p_dm32_settings_block04[0x29],p_dm32_settings_block04[0x26]);
    channel_num_to_block_offset(uVar1,dest,src);
  }
  return;
}

