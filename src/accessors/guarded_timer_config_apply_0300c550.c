/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: guarded_timer_config_apply @ 0300c550 (file base 0x03000000; code starts at 0x03001000)
 * Size: 134 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: accessors
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void guarded_timer_config_apply(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  undefined1 auStack_18 [4];
  
  uVar2 = (param_2 + 0x32U) / 100;
  iVar1 = guarded_state_validate_dispatch(param_3,auStack_18);
  if (iVar1 == 0) {
    if ((((*(uint *)(param_3 + 0x20) != uVar2) || (*(int *)(param_3 + 0x24) != 0)) ||
        (*(short *)(param_3 + 0x28) != 1)) || (*(int *)(param_3 + 8) != param_1)) {
      timer_object_cancel_and_unlink(param_3,auStack_18);
      OSTmrCreate(param_3,PTR_s_timer_0300c5e0,uVar2,0,1,param_1,0,auStack_18);
    }
  }
  else {
    timer_object_cancel_and_unlink(param_3,auStack_18);
    OSTmrCreate(param_3,PTR_s_timer_0300c5e0,uVar2,0,1,param_1,0,auStack_18);
  }
  ucos_tmr_del(param_3,auStack_18);
  noop_stub_0300c434();
  return;
}

