/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: timer_state_ensure_valid_or_recreate @ 0300c5e4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 134 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rtos
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void timer_state_ensure_valid_or_recreate(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  undefined1 auStack_18 [4];
  
  uVar2 = (param_2 + 0x32U) / 100;
  iVar1 = guarded_state_validate_dispatch(param_3,auStack_18);
  if (iVar1 == 0) {
    if ((((*(int *)(param_3 + 0x20) != 0) || (*(uint *)(param_3 + 0x24) != uVar2)) ||
        (*(short *)(param_3 + 0x28) != 2)) || (*(int *)(param_3 + 8) != param_1)) {
      timer_object_cancel_and_unlink(param_3,auStack_18);
      OSTmrCreate(param_3,PTR_s_timer_0300c760,0,uVar2,2,param_1,0,auStack_18);
    }
  }
  else {
    timer_object_cancel_and_unlink(param_3,auStack_18);
    OSTmrCreate(param_3,PTR_s_timer_0300c760,0,uVar2,2,param_1,0,auStack_18);
  }
  ucos_tmr_del(param_3,auStack_18);
  noop_stub_0300c434();
  return;
}

