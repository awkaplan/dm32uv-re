/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: soft_timer_wheel_task @ 0306b408 (file base 0x03000000; code starts at 0x03001000)
 * Size: 152 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void soft_timer_wheel_task(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined1 auStack_2c [4];
  undefined1 auStack_28 [4];
  
  puVar2 = PTR_DAT_0306b4e0;
  puVar1 = PTR_DAT_0306b4dc;
  do {
    OSTaskSemPend(0,0,auStack_2c,auStack_28);
    OSSchedLock(auStack_28);
    iVar3 = CPU_TS_TmrRd();
    uVar5 = *puVar1 + 1;
    *puVar1 = uVar5;
    iVar4 = PTR_DAT_0306b4cc
            [(uVar5 - (uVar5 / (ushort)*PTR_DAT_0306b4d4) * (uint)(ushort)*PTR_DAT_0306b4d4 & 0xffff
             ) * 2];
    while ((iVar6 = iVar4, iVar6 != 0 &&
           (iVar4 = *(int *)(iVar6 + 0x10), *(int *)(iVar6 + 0x18) == *puVar1))) {
      timer_list_entry_unlink(iVar6);
      if (*(short *)(iVar6 + 0x28) == 2) {
        sorted_bucket_deadline_list_insert(iVar6,1);
      }
      else {
        *(undefined1 *)(iVar6 + 0x2a) = 3;
      }
      if (*(uint *)(iVar6 + 8) != 0) {
        (*(code *)(*(uint *)(iVar6 + 8) & 0xfffffffe))(iVar6,*(undefined4 *)(iVar6 + 0xc));
      }
    }
    iVar4 = CPU_TS_TmrRd();
    OSSchedUnlock(auStack_28);
    if ((uint)*puVar2 < (uint)(iVar4 - iVar3)) {
      *puVar2 = iVar4 - iVar3;
    }
  } while( true );
}

