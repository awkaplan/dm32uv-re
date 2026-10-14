/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dmr_call_history_slot_register_short @ 030296ac (file base 0x03000000; code starts at 0x03001000)
 * Size: 92 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: dmr-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4 dmr_call_history_slot_register_short(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = history_slot_allocate();
  if (iVar1 == 0) {
    OSTimeDly_ms_wrapper(0x3c);
    iVar1 = history_slot_allocate();
    if (iVar1 == 0) {
      return 1;
    }
  }
  *(undefined1 *)(iVar1 + 2) = 0;
  *(undefined1 *)(iVar1 + 3) = 0;
  memset_bytes(iVar1 + 5,0,0x18);
  memcpy_bytes_iram(DAT_03029824 + (uint)p_dmr_call_config_state->field_0x4 * 0xc,param_1,10);
  memcpy_bytes_iram(iVar1 + 5,param_1,10);
  history_slot_link_append(iVar1);
  return 0;
}

