/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_freq_bcd_decode_by_slot @ 03030908 (file base 0x03000000; code starts at 0x03001000)
 * Size: 60 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void channel_freq_bcd_decode_by_slot(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined1 auStack_28 [4];
  undefined1 auStack_24 [28];
  
  if (param_1 == 0) {
    uVar1 = 0xfaf;
  }
  else {
    uVar1 = 0xfdf;
  }
  flash_field_read_cached(0x41,uVar1,auStack_28,0x20);
  if (param_2 == 0) {
    bcd_frequency_decode(auStack_24,4);
  }
  else {
    bcd_frequency_decode(auStack_28,4);
  }
  return;
}

