/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: ucos_crit_section_nest_exit_with_lock_time_track @ 030c0e0c (file base 0x03000000; code starts at 0x03001000)
 * Size: 46 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void ucos_crit_section_nest_exit_with_lock_time_track(void)

{
  int iVar1;
  uint uVar2;
  
  if (*(char *)PTR_OSSchedLockNestingCtr_030c0e58 == '\0') {
    iVar1 = func_0x0611caf4();
    uVar2 = iVar1 - *PTR_DAT_030c0e5c;
    if ((uint)*PTR_DAT_030c0e68 < uVar2) {
      *PTR_DAT_030c0e68 = uVar2;
    }
    if ((uint)*PTR_DAT_030c0e6c < uVar2) {
      *PTR_DAT_030c0e6c = uVar2;
    }
  }
  return;
}

