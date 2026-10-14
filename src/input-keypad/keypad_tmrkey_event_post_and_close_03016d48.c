/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: keypad_tmrkey_event_post_and_close @ 03016d48 (file base 0x03000000; code starts at 0x03001000)
 * Size: 28 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: input-keypad
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void keypad_tmrkey_event_post_and_close(undefined1 param_1)

{
  undefined4 *puVar1;
  undefined1 auStack_8 [4];
  
  puVar1 = PTR_DAT_03016e70;
  *(undefined1 *)((int)PTR_DAT_03016e70 + 0x29) = param_1;
  *(undefined1 *)((int)puVar1 + 0x2a) = 3;
  ucos_tmr_del(p_ucos_tmr_tmrkey,auStack_8);
  return;
}

