/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: key_event_state_clear_preserve_bit0 @ 03064d14 (file base 0x03000000; code starts at 0x03001000)
 * Size: 32 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: input-keypad
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void key_event_state_clear_preserve_bit0(void)

{
  byte bVar1;
  undefined2 *puVar2;
  
  puVar2 = PTR_DAT_03064e50;
  if ((*(byte *)PTR_DAT_03064e50 & 1) != 0) {
    bVar1 = *(byte *)PTR_DAT_03064e50;
    PTR_DAT_03064e50[2] = 0;
    *(byte *)puVar2 = bVar1 & 0xf9;
  }
  return;
}

