/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: rda5807m_tune @ 030656ec (file base 0x03000000; code starts at 0x03001000)
 * Size: 158 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void rda5807m_tune(uint param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  
  param_1 = param_1 & 0xffff;
  os_sem_pend_ms(p_ucos_mutex_0003b9d0,0);
  if (param_1 < 0x1db0) {
    *(byte *)PTR_DAT_03065804 = *(byte *)PTR_DAT_03065804 & 0xfd;
    uVar2 = ((int)(param_1 - 0x1964) / 5 & 0x3ffU) << 6 | 0x1e;
  }
  else {
    *(byte *)PTR_DAT_03065804 = *(byte *)PTR_DAT_03065804 & 0xfd | 2;
    uVar2 = ((int)(param_1 - 0x1db0) / 5 & 0x3ffU) << 6 | 0x1a;
  }
  peripheral_reset_step_bit0x20();
  rda5807m_i2c_send_byte(0xc0);
  puVar1 = PTR_rda5807m_shadow_030657f8;
  *(undefined1 *)PTR_rda5807m_shadow_030657f8 = 0xc0;
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

