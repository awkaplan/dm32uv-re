/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: rda5807m_init @ 0306565c (file base 0x03000000; code starts at 0x03001000)
 * Size: 56 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void rda5807m_init(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  gpio_pin_set_output_level(0x19,0);
  gpio_pin_set_output_level(0x1a,0);
  peripheral_reset_step_bit0x20();
  puVar2 = (undefined4 *)((int)PTR_LAB_030657f4 + 0x7a);
  puVar1 = PTR_LAB_030657f4;
  do {
    rda5807m_i2c_send_byte(*(undefined1 *)puVar1);
    puVar1 = (undefined4 *)((int)puVar1 + 1);
  } while (puVar1 != puVar2);
  rda5807m_i2c_stop();
  memcpy_bytes_iram(PTR_rda5807m_shadow_030657f8,PTR_LAB_030657f4,8);
  return;
}

