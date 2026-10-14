/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: rda5807m_power_down @ 030657c0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 52 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void rda5807m_power_down(void)

{
  undefined4 *puVar1;
  void *mutex;
  
  mutex = p_ucos_mutex_0003b9d0;
  os_sem_pend_ms(p_ucos_mutex_0003b9d0,0);
  peripheral_reset_step_bit0x20();
  puVar1 = PTR_rda5807m_shadow_030657f8;
  *(undefined1 *)PTR_rda5807m_shadow_030657f8 = 0x80;
  *(undefined1 *)((int)puVar1 + 1) = 0;
  rda5807m_i2c_send_byte(0x80);
  rda5807m_i2c_send_byte(*(undefined1 *)((int)puVar1 + 1));
  rda5807m_i2c_stop();
  os_sem_post(mutex);
  return;
}

