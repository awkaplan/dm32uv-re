/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: OSTmr_state_dispatch_callback @ 0306b4a0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 234 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rtos
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4
OSTmr_state_dispatch_callback(int *param_1,short param_2,undefined4 param_3,undefined4 *param_4)

{
  char cVar1;
  undefined4 uVar2;
  undefined1 auStack_18 [4];
  
  if (*(char *)PTR_OSIntNestingCtr_0306b4e4 == '\0') {
    if (param_1 == (int *)0x0) {
      *param_4 = 0x7342;
      uVar2 = 0;
    }
    else if (*param_1 == DAT_0306b654) {
      OSSchedLock(auStack_18);
      cVar1 = *(char *)((int)param_1 + 0x2a);
      if (cVar1 != '\x01') {
        if (cVar1 == '\0') {
          OSSchedUnlock(auStack_18);
          *param_4 = 0x733d;
          return 0;
        }
        if (cVar1 == '\x02') {
          timer_list_entry_unlink(param_1);
          *param_4 = 0;
          if (param_2 == 3) {
            if (param_1[2] == 0) {
              *param_4 = 0x7344;
            }
            else {
              (*(code *)(param_1[2] & 0xfffffffe))(param_1,param_1[3]);
            }
          }
          else if (param_2 == 4) {
            if (param_1[2] == 0) {
              *param_4 = 0x7344;
            }
            else {
              (*(code *)(param_1[2] & 0xfffffffe))(param_1,param_3);
            }
          }
          else if (param_2 != 0) {
            OSSchedUnlock(auStack_18);
            *param_4 = 0x5e25;
            return 0;
          }
          OSSchedUnlock(auStack_18);
          return 1;
        }
        if (cVar1 != '\x03') {
          OSSchedUnlock(auStack_18);
          *param_4 = 0x7341;
          return 0;
        }
      }
      OSSchedUnlock(auStack_18);
      *param_4 = 0x7349;
      uVar2 = 1;
    }
    else {
      *param_4 = 0x5dc4;
      uVar2 = 0;
    }
  }
  else {
    *param_4 = 0x7343;
    uVar2 = 0;
  }
  return uVar2;
}

