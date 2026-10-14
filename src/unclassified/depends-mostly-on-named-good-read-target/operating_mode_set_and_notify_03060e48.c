/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: operating_mode_set_and_notify @ 03060e48 (file base 0x03000000; code starts at 0x03001000)
 * Size: 54 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void operating_mode_set_and_notify(byte param_1)

{
  undefined1 *puVar1;
  
  if (param_1 < 2) {
    if (PTR_DAT_03060f24[1] != '\0') {
      ui_mode_noop_stub_variant_03060e3c();
      return;
    }
    PTR_DAT_03060f24[1] = PTR_DAT_03060f28[0xc];
  }
  os_sem_pend_ms(p_ucos_mutex_0003ff10,0);
  puVar1 = PTR_DAT_03060f2c;
  PTR_DAT_03060f2c[3] = param_1;
  puVar1[1] = 1;
  ui_event_notify(0x28);
  return;
}

