/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: os_post_message_opt_validated @ 0306a870 (file base 0x03000000; code starts at 0x03001000)
 * Size: 178 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rtos
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void os_post_message_opt_validated
               (int *param_1,undefined4 param_2,undefined2 param_3,ushort param_4,
               undefined4 *param_5)

{
  undefined4 uVar1;
  
  if (param_1 == (int *)0x0) {
    *param_5 = 0x5dc3;
    return;
  }
  if (param_4 != 0x210) {
    if (param_4 < 0x211) {
      if (((param_4 != 0x10) && (param_4 != 0x200)) && (param_4 != 0)) goto LAB_0306a8dc;
    }
    else if (param_4 != 0x8010) {
      if (param_4 < 0x8011) {
        if (param_4 != 0x8000) {
LAB_0306a8dc:
          *param_5 = 0x5e25;
          return;
        }
      }
      else if ((param_4 != 0x8200) && (param_4 != 0x8210)) goto LAB_0306a8dc;
    }
  }
  if (*param_1 == _LAB_0306a934) {
    uVar1 = CPU_TS_TmrRd();
    if (*_LAB_0306a938 == '\0') {
      reentrant_dispatch_single_or_list(param_1,param_2,param_3,param_4,uVar1,param_5);
    }
    else {
      ucos3_message_queue_post_with_overflow_check
                (_LAB_0306a934,param_1,param_2,param_3,0,param_4,uVar1,param_5);
    }
  }
  else {
    *param_5 = 0x5dc4;
  }
  return;
}

