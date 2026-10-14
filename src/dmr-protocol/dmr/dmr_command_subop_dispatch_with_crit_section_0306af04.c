/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dmr_command_subop_dispatch_with_crit_section @ 0306af04 (file base 0x03000000; code starts at 0x03001000)
 * Size: 188 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: dmr-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

int dmr_command_subop_dispatch_with_crit_section(int *param_1,undefined4 *param_2)

{
  char cVar1;
  int iVar2;
  undefined1 auStack_14 [4];
  
  if (*(char *)PTR_OSIntNestingCtr_0306b048 == '\0') {
    if (param_1 == (int *)0x0) {
      *param_2 = 0x7342;
      iVar2 = 0;
    }
    else if (*param_1 == DAT_0306b04c) {
      OSSchedLock(auStack_14);
      cVar1 = *(char *)((int)param_1 + 0x2a);
      if (cVar1 == '\x01') {
        if ((short)param_1[10] == 2) {
          iVar2 = param_1[8];
          if (iVar2 == 0) {
            iVar2 = param_1[9];
          }
        }
        else {
          iVar2 = param_1[8];
        }
        param_1[7] = iVar2;
        OSSchedUnlock(auStack_14);
        *param_2 = 0;
      }
      else if (cVar1 == '\0') {
        OSSchedUnlock(auStack_14);
        *param_2 = 0x733d;
        iVar2 = 0;
      }
      else if (cVar1 == '\x02') {
        iVar2 = param_1[6] - *PTR_DAT_0306b050;
        param_1[7] = iVar2;
        OSSchedUnlock(auStack_14);
        *param_2 = 0;
      }
      else if (cVar1 == '\x03') {
        OSSchedUnlock(auStack_14);
        iVar2 = 0;
        *param_2 = 0;
      }
      else {
        OSSchedUnlock(auStack_14);
        *param_2 = 0x7341;
        iVar2 = 0;
      }
    }
    else {
      *param_2 = 0x5dc4;
      iVar2 = 0;
    }
  }
  else {
    *param_2 = 0x7343;
    iVar2 = 0;
  }
  return iVar2;
}

