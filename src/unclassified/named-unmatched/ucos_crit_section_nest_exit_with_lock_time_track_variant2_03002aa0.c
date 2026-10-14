/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: ucos_crit_section_nest_exit_with_lock_time_track_variant2 @ 03002aa0 (file base 0x03000000; code starts at 0x03001000)
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

void ucos_crit_section_nest_exit_with_lock_time_track_variant2(void)

{
  int iVar1;
  uint uVar2;
  
  if (*(char *)PTR_LAB_03002ad0 == '\0') {
    iVar1 = func_0x05ff3ac0();
    uVar2 = iVar1 - *PTR_DAT_03002ad4;
    if ((uint)*PTR_DAT_03002ad8 < uVar2) {
      *PTR_DAT_03002ad8 = uVar2;
    }
    if ((uint)*PTR_DAT_03002adc < uVar2) {
      *PTR_DAT_03002adc = uVar2;
    }
  }
  return;
}

