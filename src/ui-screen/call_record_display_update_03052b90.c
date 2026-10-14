/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: call_record_display_update @ 03052b90 (file base 0x03000000; code starts at 0x03001000)
 * Size: 114 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-screen
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void call_record_display_update(void)

{
  char cVar1;
  short sVar2;
  undefined4 *puVar3;
  
  if ((*(ushort *)PTR_DAT_03052c8c < *(ushort *)PTR_DAT_03052c88) ||
     (*(ushort *)PTR_DAT_03052c8c == 0)) {
    tx_gate_write_call_record(0);
  }
  else {
    tx_gate_write_call_record(1);
    puVar3 = PTR_DAT_03052c8c;
    sVar2 = *(short *)PTR_DAT_03052c8c;
    cVar1 = *(char *)PTR_DAT_03052c84;
    *(byte *)PTR_DAT_03052c84 = cVar1 - 1U;
    *(ushort *)puVar3 = sVar2 - (ushort)(byte)PTR_DAT_03052c90[(byte)(cVar1 - 1U)];
    *(undefined2 *)PTR_DAT_03052c88 = 0;
    display_fill_rect(0,0x1b,0xf0,0x121,0);
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
  return;
}

