/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: identifier_matched_command_dispatch_030c1cfc @ 030c1cfc (file base 0x03000000; code starts at 0x03001000)
 * Size: 136 bytes
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

undefined4
identifier_matched_command_dispatch_030c1cfc(int *param_1,ushort param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  if (param_1 == (int *)0x0) {
    *param_3 = 0x5dc3;
    return 0;
  }
  if (param_2 == 0x200) {
LAB_030c1d3c:
    if (*param_1 == _DAT_030c1d84) {
      uVar1 = func_0x0611caf4();
      if (*(char *)PTR_OSIntNestingCtr_030c1d88 == '\0') {
        uVar1 = OS_SemPost_variant2(param_1,param_2,uVar1,param_3);
      }
      else {
        bounded_queue_append_with_dropcount(_DAT_030c1d84,param_1,0,0,0,param_2,uVar1,param_3);
        uVar1 = 0;
      }
    }
    else {
      *param_3 = 0x5dc4;
      uVar1 = 0;
    }
  }
  else {
    if (param_2 < 0x201) {
      if (param_2 == 0) goto LAB_030c1d3c;
    }
    else if ((param_2 == 0x8000) || (param_2 == 0x8200)) goto LAB_030c1d3c;
    *param_3 = 0x5e25;
    uVar1 = 0;
  }
  return uVar1;
}

