/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: ucos_tmr_del @ 0306b5a8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 170 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined4 ucos_tmr_del(int *param_1,undefined4 *param_2)

{
  char cVar1;
  undefined4 uVar2;
  undefined1 auStack_10 [4];
  
  if (*(char *)PTR_OSIntNestingCtr_0306b658 == '\0') {
    if (param_1 == (int *)0x0) {
      *param_2 = 0x7342;
      uVar2 = 0;
    }
    else if (*param_1 == DAT_0306b654) {
      OSSchedLock(auStack_10);
      cVar1 = *(char *)((int)param_1 + 0x2a);
      if (cVar1 != '\x01') {
        if (cVar1 == '\0') {
          OSSchedUnlock(auStack_10);
          *param_2 = 0x733d;
          return 0;
        }
        if (cVar1 == '\x02') {
          timer_list_entry_unlink(param_1);
          sorted_bucket_deadline_list_insert(param_1,0);
          OSSchedUnlock(auStack_10);
          *param_2 = 0;
          return 1;
        }
        if (cVar1 != '\x03') {
          OSSchedUnlock(auStack_10);
          *param_2 = 0x7341;
          return 0;
        }
      }
      sorted_bucket_deadline_list_insert(param_1,0);
      OSSchedUnlock(auStack_10);
      *param_2 = 0;
      uVar2 = 1;
    }
    else {
      *param_2 = 0x5dc4;
      uVar2 = 0;
    }
  }
  else {
    *param_2 = 0x7343;
    uVar2 = 0;
  }
  return uVar2;
}

