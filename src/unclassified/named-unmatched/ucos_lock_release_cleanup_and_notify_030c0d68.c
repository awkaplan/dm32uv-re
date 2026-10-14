/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: ucos_lock_release_cleanup_and_notify @ 030c0d68 (file base 0x03000000; code starts at 0x03001000)
 * Size: 50 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void ucos_lock_release_cleanup_and_notify(void)

{
  int iVar1;
  undefined4 sr;
  
  sr = cpu_sr_save_and_disable_irq_variant2();
  *(undefined1 *)PTR_OSPrioHighRdy_030c0e48 = 0;
  iVar1 = _DAT_030c0e4c;
  *PTR_OSTCBHighRdyPtr_030c0e50 = _DAT_030c0e4c;
  *(int *)(iVar1 + 0x90) = *(int *)(iVar1 + 0x90) + 1;
  *PTR_OSTaskCtxSwCtr_030c0e54 = *PTR_OSTaskCtxSwCtr_030c0e54 + 1;
  ucos3_highrdy_commit();
  cpu_sr_restore_irq_variant2(sr);
  return;
}

