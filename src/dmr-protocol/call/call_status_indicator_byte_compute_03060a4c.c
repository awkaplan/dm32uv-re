/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: call_status_indicator_byte_compute @ 03060a4c (file base 0x03000000; code starts at 0x03001000)
 * Size: 214 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: dmr-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void call_status_indicator_byte_compute(void)

{
  byte bVar1;
  byte bVar2;
  bool bVar3;
  int iVar4;
  undefined1 uVar5;
  
  iVar4 = get_current_mode_state1();
  if (iVar4 == 0) {
    uVar5 = 0;
  }
  else {
    iVar4 = get_current_mode_state1();
    if (iVar4 == 3) {
      uVar5 = 4;
    }
    else {
      iVar4 = get_current_mode_state1();
      if (iVar4 == 6) {
        if ((*(byte *)p_dialog_flags_from_flash & 1) == 0) {
          uVar5 = 0;
        }
        else {
          uVar5 = 4;
        }
      }
      else {
        uVar5 = 0;
      }
    }
  }
  bVar1 = p_tx_ptt_ui_state->field_0x7;
  if (bVar1 == 5) {
    uVar5 = 7;
  }
  else if (bVar1 == 6) {
    uVar5 = 10;
  }
  bVar2 = *(byte *)p_call_active_flag;
  if ((bVar2 & 0x40) != 0) {
    uVar5 = 0xb;
  }
  if ((*(byte *)PTR_DAT_03060b48 & 0x20) == 0) {
    bVar3 = p_radio_mode_state_0003e318[1].flags_0x2 != 0;
  }
  else {
    bVar3 = true;
  }
  if ((bVar2 & 1) == 0) {
    if (bVar3) {
      uVar5 = 2;
    }
  }
  else {
    uVar5 = 2;
  }
  if (((bVar2 & 10) != 0) && ((*(byte *)p_dialog_flags_from_flash & 1) == 0)) {
    uVar5 = 3;
  }
  if (bVar1 == 4) {
    uVar5 = 6;
  }
  if ((*(byte *)PTR_DAT_03060b48 & 0x40) != 0) {
    uVar5 = 9;
  }
  PTR_DAT_03060b50[2] = uVar5;
  return;
}

