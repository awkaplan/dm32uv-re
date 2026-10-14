/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: ucos3_task_create_checked @ 0306ae44 (file base 0x03000000; code starts at 0x03001000)
 * Size: 122 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void ucos3_task_create_checked(undefined4 *param_1)

{
  *PTR_DAT_0306aec4 = 0;
  *PTR_DAT_0306aedc = 0;
  *PTR_DAT_0306aed4 = 0;
  *(undefined1 *)PTR_DAT_0306aed8 = 0;
  *(undefined1 *)PTR_DAT_0306aee0 = 0;
  if (*(int *)PTR_LAB_0306aee4 == 0) {
    *param_1 = 0x6e2b;
  }
  else if (*(uint *)PTR_LAB_0306aee8 < *(uint *)PTR_LAB_0306aeec) {
    *param_1 = 0x6e2c;
  }
  else if ((byte)*PTR_LAB_0306aef0 < 0x3f) {
    OSTaskCreate(_DAT_0306aef8,_DAT_0306aefc,_DAT_0306af00,0,*PTR_LAB_0306aef0,
                 *(int *)PTR_LAB_0306aee4,*(undefined4 *)PTR_LAB_0306aef4,*(uint *)PTR_LAB_0306aee8,
                 0,0,0,3,param_1);
  }
  else {
    *param_1 = 0x6e2a;
  }
  return;
}

