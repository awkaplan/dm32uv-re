/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: call_record_line_advance_or_close_tx @ 03052c04 (file base 0x03000000; code starts at 0x03001000)
 * Size: 116 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void call_record_line_advance_or_close_tx(void)

{
  byte bVar1;
  short sVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if ((uint)*(ushort *)PTR_DAT_03052c88 + (uint)*(ushort *)PTR_DAT_03052c8c <
      (uint)*(ushort *)PTR_DAT_03052c7c) {
    tx_gate_write_call_record(1);
    display_fill_rect(0,0x1b,0xf0,0x121,0);
    puVar4 = PTR_DAT_03052c88;
    sVar2 = *(short *)PTR_DAT_03052c88;
    *(short *)PTR_DAT_03052c8c = sVar2 + *(short *)PTR_DAT_03052c8c;
    puVar3 = PTR_DAT_03052c84;
    bVar1 = *(byte *)PTR_DAT_03052c84;
    PTR_DAT_03052c90[bVar1] = (char)sVar2;
    *(byte *)puVar3 = bVar1 + 1;
    *(undefined2 *)puVar4 = 0;
    if (*(char *)PTR_DAT_03052c94 == '\x01') {
      call_log_entry_render_basic();
    }
    else if (*(char *)PTR_DAT_03052c94 == '\x03') {
      call_log_entry_render_with_header();
    }
    else {
      draw_wrapped_string_then_dialog_header();
    }
  }
  else {
    tx_gate_write_call_record(0);
  }
  return;
}

