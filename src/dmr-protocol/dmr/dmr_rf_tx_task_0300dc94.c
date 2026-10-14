/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dmr_rf_tx_task @ 0300dc94 (file base 0x03000000; code starts at 0x03001000)
 * Size: 80 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: dmr-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void dmr_rf_tx_task(void)

{
  void *mutex;
  undefined1 *puVar1;
  vfo_display_state *pvVar2;
  undefined1 *puVar3;
  
  puVar3 = PTR_DAT_0300ddf8;
  pvVar2 = p_vfo_display_state;
  puVar1 = PTR_DAT_0300ddf0;
  mutex = DAT_0300ddec;
  while (os_sem_pend_ms(mutex,0), (*puVar1 & 2) == 0) {
    if ((pvVar2->flags_0x8 & 0xf0) == 0x10) {
      if (*puVar3 == '\x01') {
        rf_tx_enable_sequence();
        *puVar3 = 0;
      }
      else {
        rf_tx_disable_sequence();
        puVar3[1] = 0;
      }
    }
  }
  return;
}

