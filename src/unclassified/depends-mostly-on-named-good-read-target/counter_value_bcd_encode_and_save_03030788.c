/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: counter_value_bcd_encode_and_save @ 03030788 (file base 0x03000000; code starts at 0x03001000)
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

void counter_value_bcd_encode_and_save(uint param_1)

{
  uint uVar1;
  undefined4 uVar2;
  byte *pbVar3;
  byte local_10 [4];
  
  pbVar3 = local_10;
  os_sem_pend_ms(p_ucos_mutex_0003e330,0);
  do {
    uVar1 = (param_1 % 100) / 10;
    *pbVar3 = (char)(param_1 % 100) + (char)uVar1 * -10 | (byte)(uVar1 << 4);
    pbVar3 = pbVar3 + 1;
    param_1 = param_1 / 100;
  } while (pbVar3 != &stack0xfffffff4);
  if ((p_dm32_settings_block04[0x2d] & 0x80) == 0) {
    uVar2 = 0xfcb;
  }
  else {
    uVar2 = 0xffb;
  }
  flash_block_write(0x41,uVar2,local_10,4);
  os_sem_post(p_ucos_mutex_0003e330);
  ui_event_notify_alt(8);
  return;
}

