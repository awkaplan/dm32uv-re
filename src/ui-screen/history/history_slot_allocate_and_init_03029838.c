/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: history_slot_allocate_and_init @ 03029838 (file base 0x03000000; code starts at 0x03001000)
 * Size: 212 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-screen
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4 history_slot_allocate_and_init(char param_1,undefined4 param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined1 local_20;
  undefined1 uStack_1f;
  undefined1 uStack_1e;
  undefined1 uStack_1d;
  undefined1 uStack_1c;
  undefined1 uStack_1b;
  undefined1 uStack_1a;
  undefined1 uStack_19;
  undefined1 uStack_18;
  
  iVar2 = history_slot_allocate();
  if (iVar2 == 0) {
    OSTimeDly_ms_wrapper(0x46);
    iVar2 = history_slot_allocate();
    if (iVar2 == 0) {
      return 1;
    }
  }
  *(undefined1 *)(iVar2 + 2) = 0;
  *(undefined1 *)(iVar2 + 3) = 2;
  iVar3 = iVar2 + 5;
  memset_bytes(iVar3,0,0x18);
  if (param_1 == '\0') {
    memcpy_bytes_iram(iVar3,DAT_0302995c + (uint)p_dmr_call_config_state->field_0x4 * 0xc,9);
  }
  else {
    local_20 = PTR_DAT_03029958[(uint)p_dmr_call_config_state->field_0x4 * 0xc + 0x2c];
    uStack_1f = PTR_DAT_03029958[(uint)p_dmr_call_config_state->field_0x4 * 0xc + 0x2d];
    uStack_1e = 0x10;
    uStack_1d = 0;
    uStack_1c = 0;
    uStack_1b = 0;
    uStack_1a = (undefined1)((uint)param_2 >> 0x10);
    uStack_19 = (undefined1)((uint)param_2 >> 8);
    uStack_18 = (undefined1)param_2;
    memcpy_bytes_iram(iVar3,&local_20,9);
  }
  history_slot_link_append(iVar2);
  bVar1 = p_dmr_call_config_state->field_0x4;
  PTR_DAT_03029958[bVar1 + 0xc] = 0;
  iVar2 = _DAT_03029960 + (uint)bVar1;
  *(undefined1 *)(iVar2 + 0xc) = 0;
  *(undefined1 *)(iVar2 + 0xe) = 0;
  if (p_call_setup_sm_state_aux->mode_0x1 == 4) {
    history_record_push();
  }
  return 0;
}

