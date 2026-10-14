/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: call_setup_debounce_and_ui_state_driver @ 0300d284 (file base 0x03000000; code starts at 0x03001000)
 * Size: 326 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: dmr-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void call_setup_debounce_and_ui_state_driver(void)

{
  char cVar1;
  byte bVar2;
  short sVar3;
  call_setup_sm_state *pcVar4;
  undefined4 *puVar5;
  uint uVar6;
  
  if (((*(byte *)((int)PTR_DAT_0300d3d4 + 7) & 1) != 0) && (p_call_setup_sm_state->field_0x5 == 5))
  {
    cVar1 = *(char *)PTR_DAT_0300d3d8;
    *(byte *)PTR_DAT_0300d3d8 = cVar1 + 1U;
    if ((uint)*(byte *)((int)PTR_DAT_0300d3dc + 0x22) * 6 + 0x2d < (uint)(byte)(cVar1 + 1U)) {
      *(undefined1 *)PTR_DAT_0300d3d8 = 0;
      cVar1 = *(char *)(PTR_DAT_0300d3d4 + 2);
      *(byte *)(PTR_DAT_0300d3d4 + 2) = cVar1 + 1U;
      if (*(byte *)((int)PTR_DAT_0300d3dc + 0x16) < (byte)(cVar1 + 1U)) {
        *(byte *)((int)PTR_DAT_0300d3d4 + 7) = *(byte *)((int)PTR_DAT_0300d3d4 + 7) & 0xfe;
        ui_mode_dispatch(5);
      }
      else {
        ui_mode_dispatch(4);
        history_push_call_and_type3(PTR_DAT_0300d3d4[4],PTR_DAT_0300d3d4[5]);
      }
    }
  }
  if (*(char *)PTR_DAT_0300d3e0 != '\0') {
    if (*(byte *)PTR_DAT_0300d3e4 < 0xfa) {
      *(byte *)PTR_DAT_0300d3e4 = *(byte *)PTR_DAT_0300d3e4 + 1;
    }
    else {
      *(undefined1 *)PTR_DAT_0300d3e4 = 0;
      *(undefined1 *)PTR_DAT_0300d3e0 = 0;
    }
  }
  if ((*(byte *)PTR_DAT_0300d3e8 & 0x40) != 0) {
    if (*(char *)((int)PTR_DAT_0300d3e8 + 3) == '\x06') {
      bVar2 = p_call_setup_sm_state->field_0x17;
      uVar6 = 0x76;
    }
    else {
      uVar6 = (uint)*(byte *)((int)PTR_DAT_0300d3dc + 0x22) * 6 + 100;
      bVar2 = *(byte *)(PTR_DAT_0300d3dc + 6);
    }
    cVar1 = *(char *)(PTR_DAT_0300d3d8 + 2);
    *(byte *)(PTR_DAT_0300d3d8 + 2) = cVar1 + 1U;
    if (uVar6 < (byte)(cVar1 + 1U)) {
      *(undefined1 *)(PTR_DAT_0300d3d8 + 2) = 0;
      puVar5 = PTR_DAT_0300d3e8;
      cVar1 = *(char *)(PTR_DAT_0300d3e8 + 1);
      *(byte *)(PTR_DAT_0300d3e8 + 1) = cVar1 + 1U;
      if (bVar2 < (byte)(cVar1 + 1U)) {
        *(byte *)PTR_DAT_0300d3e8 = *(byte *)PTR_DAT_0300d3e8 & 0xbf;
        dialog_state_set_substate(2);
      }
      else {
        history_event_record_build_dispatch(puVar5[2],PTR_DAT_0300d3dc[9]);
        dialog_state_set_substate(0);
      }
    }
  }
  if (((((p_call_setup_sm_state->flags_0x18 & 1) != 0) && (p_call_setup_sm_state->field_0x1 == 0))
      && (*(char *)PTR_DAT_0300d3d4 == '\0')) &&
     (sVar3 = PTR_DAT_0300d3d8[1], PTR_DAT_0300d3d8[1] = sVar3 + 1U,
     *(ushort *)(PTR_DAT_0300d3dc + 8) <= (ushort)(sVar3 + 1U))) {
    PTR_DAT_0300d3d8[1] = 0;
    pcVar4 = p_call_setup_sm_state;
    p_call_setup_sm_state->flags_0x18 = p_call_setup_sm_state->flags_0x18 & 0xfe;
    pcVar4->field_0x14 = 0;
  }
  return;
}

