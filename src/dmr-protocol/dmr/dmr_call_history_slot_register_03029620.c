/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dmr_call_history_slot_register @ 03029620 (file base 0x03000000; code starts at 0x03001000)
 * Size: 138 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: dmr-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4
dmr_call_history_slot_register
          (undefined1 param_1,undefined1 param_2,undefined1 param_3,undefined4 param_4,
          undefined4 param_5)

{
  dmr_call_config_state *pdVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = history_slot_allocate();
  if (iVar3 == 0) {
    OSTimeDly_ms_wrapper(0x3c);
    iVar3 = history_slot_allocate();
    if (iVar3 == 0) {
      return 1;
    }
  }
  *(undefined1 *)(iVar3 + 2) = 0;
  *(undefined1 *)(iVar3 + 3) = 1;
  memset_bytes(iVar3 + 5,0,0x18);
  *(undefined1 *)(iVar3 + 5) = param_1;
  *(undefined1 *)(iVar3 + 6) = param_2;
  *(undefined1 *)(iVar3 + 7) = param_3;
  *(char *)(iVar3 + 8) = (char)((uint)param_4 >> 0x10);
  *(char *)(iVar3 + 9) = (char)((uint)param_4 >> 8);
  *(char *)(iVar3 + 10) = (char)param_4;
  *(char *)(iVar3 + 0xb) = (char)((uint)param_5 >> 0x10);
  *(char *)(iVar3 + 0xc) = (char)((uint)param_5 >> 8);
  *(char *)(iVar3 + 0xd) = (char)param_5;
  iVar2 = DAT_03029820;
  pdVar1 = p_dmr_call_config_state;
  memcpy_bytes_iram(DAT_03029820 + (uint)p_dmr_call_config_state->field_0x4 * 0xc,iVar3 + 5,9);
  history_slot_link_append(iVar3);
  *(undefined1 *)(iVar2 + (uint)pdVar1->field_0x4 + -0x20) = 1;
  return 0;
}

