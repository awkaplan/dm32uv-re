/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: list_screen_event_dispatch @ 03065170 (file base 0x03000000; code starts at 0x03001000)
 * Size: 142 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

uint list_screen_event_dispatch(uint param_1,uint param_2)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  char cStack_3a;
  undefined4 local_34;
  undefined1 auStack_30 [19];
  undefined1 auStack_1d [5];
  
  uVar3 = param_1 >> 8 & 0xff;
  cStack_3a = (char)(param_1 >> 0x10);
  uVar4 = (param_2 & 0xff) << 8 | param_1 >> 0x18;
  local_34 = 0;
  iVar1 = vfo_active_side_mode_nibble();
  if ((param_1 & 0xff) == 0) {
    if (cStack_3a == '\0') {
      uVar3 = 0;
    }
    else if (cStack_3a == '\x01') {
      bVar2 = p_vfo_display_state->flags_0x8 & 0xf0;
      if ((bVar2 == 0) || (bVar2 == 0x20)) {
        iVar1 = flash_stored_setting_load_and_dispatch(param_1 >> 0x18);
        uVar3 = (uint)(iVar1 != 0);
      }
      else {
        uVar3 = 0;
      }
    }
    else if (cStack_3a == '\x02') {
      if (iVar1 == 0) {
        uVar3 = 0;
      }
      else if (iVar1 == 2) {
        uVar3 = 0;
      }
      else {
        *PTR_DAT_03065204 = *PTR_DAT_03065204 & 0xff0000ff | uVar4 << 8;
        record_read_by_index(uVar4,auStack_30);
        memcpy_bytes_iram(&local_34,auStack_1d,3);
        uVar3 = param_2 >> 8 & 0xff;
        if (uVar3 < 9) {
                    /* WARNING: Could not recover jumptable at 0x030651fc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          uVar3 = (*(code *)(PTR_PTR_03065208[uVar3] & 0xfffffffe))();
          return uVar3;
        }
        uVar3 = 0;
      }
    }
    else {
      uVar3 = 1;
    }
  }
  else if ((param_1 & 0xff) == 1) {
    if (uVar3 < 0xc) {
      if (iVar1 == 0) {
        return 0;
      }
      if (iVar1 == 2) {
        return 0;
      }
    }
    if (uVar3 < 0xe) {
                    /* WARNING: Could not recover jumptable at 0x030652c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar3 = (*(code *)(PTR_PTR_030652d4[uVar3] & 0xfffffffe))();
      return uVar3;
    }
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}

