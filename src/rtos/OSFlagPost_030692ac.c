/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: OSFlagPost @ 030692ac (file base 0x03000000; code starts at 0x03001000)
 * Size: 128 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rtos
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4 OSFlagPost(int *param_1,undefined4 param_2,uint param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  param_3 = param_3 & 0xffff;
  if (param_1 == (int *)0x0) {
    *param_4 = 0x5dc3;
    uVar1 = 0;
  }
  else if ((param_3 < 2) || (param_3 - 0x8000 < 2)) {
    if (*param_1 == DAT_0306932c) {
      uVar1 = CPU_TS_TmrRd();
      if (*(char *)PTR_OSIntNestingCtr_03069330 == '\0') {
        uVar1 = OSFlagPost_internal(param_1,param_2,param_3,uVar1,param_4);
      }
      else {
        ucos3_message_queue_post_with_overflow_check
                  (DAT_0306932c,param_1,0,0,param_2,param_3,uVar1,param_4);
        uVar1 = 0;
      }
    }
    else {
      *param_4 = 0x5dc4;
      uVar1 = 0;
    }
  }
  else {
    *param_4 = 0x5e25;
    uVar1 = 0;
  }
  return uVar1;
}

