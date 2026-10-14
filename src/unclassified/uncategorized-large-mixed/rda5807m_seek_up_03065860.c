/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: rda5807m_seek_up @ 03065860 (file base 0x03000000; code starts at 0x03001000)
 * Size: 140 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void rda5807m_seek_up(uint param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  
  os_sem_pend_ms(p_ucos_mutex_0003b9d0,0);
  if ((*(byte *)PTR_DAT_0306596c & 2) == 0) {
    uVar2 = ((int)((param_1 & 0xffff) - 0x1964) / 5 & 0x3ffU) << 6 | 0xe;
  }
  else {
    uVar2 = ((int)((param_1 & 0xffff) - 0x1db0) / 5 & 0x3ffU) << 6 | 10;
  }
  peripheral_reset_step_bit0x20();
  rda5807m_i2c_send_byte(0xc3);
  puVar1 = PTR_rda5807m_shadow_03065970;
  *(undefined1 *)PTR_rda5807m_shadow_03065970 = 0xc3;
  rda5807m_i2c_send_byte(1);
  *(undefined1 *)((int)puVar1 + 1) = 1;
  rda5807m_i2c_send_byte(uVar2 >> 8);
  *(char *)((int)puVar1 + 2) = (char)(uVar2 >> 8);
  rda5807m_i2c_send_byte(uVar2 & 0xff);
  *(char *)((int)puVar1 + 3) = (char)uVar2;
  rda5807m_i2c_stop();
  os_sem_post(p_ucos_mutex_0003b9d0);
  return;
}

