/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: rda5807m_set_volume @ 03065694 (file base 0x03000000; code starts at 0x03001000)
 * Size: 88 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void rda5807m_set_volume(byte param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  os_sem_pend_ms(p_ucos_mutex_0003b9d0,0);
  puVar1 = PTR_rda5807m_shadow_030657f8;
  *(byte *)((int)PTR_rda5807m_shadow_030657f8 + 7) =
       *(byte *)((int)PTR_rda5807m_shadow_030657f8 + 7) & 0xf0 | param_1 & 0xf;
  if (*(char *)puVar1 == -0x3d) {
    *(undefined1 *)PTR_rda5807m_shadow_030657f8 = 0xc0;
  }
  PTR_DAT_03065800[2] = PTR_DAT_03065800[2] & 0xfd;
  peripheral_reset_step_bit0x20();
  puVar2 = PTR_rda5807m_shadow_030657f8 + 2;
  puVar1 = PTR_rda5807m_shadow_030657f8;
  do {
    rda5807m_i2c_send_byte(*(undefined1 *)puVar1);
    puVar1 = (undefined4 *)((int)puVar1 + 1);
  } while (puVar1 != puVar2);
  rda5807m_i2c_stop();
  os_sem_post(p_ucos_mutex_0003b9d0);
  return;
}

