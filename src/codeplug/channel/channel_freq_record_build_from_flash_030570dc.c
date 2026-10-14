/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_freq_record_build_from_flash @ 030570dc (file base 0x03000000; code starts at 0x03001000)
 * Size: 138 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void * channel_freq_record_build_from_flash(void *param_1,int param_2)

{
  undefined4 uVar1;
  undefined1 auStack_64 [8];
  undefined1 auStack_5c [24];
  undefined4 local_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined2 uStack_14;
  
  if (param_2 == 0) {
    uVar1 = 0xfaf;
  }
  else {
    uVar1 = 0xfdf;
  }
  flash_field_read_cached(0x41,uVar1,auStack_64,0x20);
  memcpy_bytes_iram(&uStack_3c,auStack_5c,0x18);
  local_44 = bcd_frequency_decode(auStack_64,4);
  uStack_40 = channel_apply_frequency_offset
                        (local_44,uStack_40,uStack_3c,uStack_38,uStack_34,uStack_30,uStack_2c,
                         uStack_28,uStack_24,uStack_20,uStack_1c,uStack_18,uStack_14);
  memcpy_ck803s(param_1,&local_44,0x33);
  return param_1;
}

