/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: scan_list_row_render @ 0305a06c (file base 0x03000000; code starts at 0x03001000)
 * Size: 150 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined4 * scan_list_row_render(int param_1)

{
  byte bVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  display_fill_rect(0,0x104,0xf0,0x11c,0xc618);
  display_draw_string_mutex_variant
            (0x104,5,param_1 + (*(byte *)PTR_DAT_0305a120 / 9) * 0x12,0,0xc618);
  dialog_header_draw_two_lines();
  puVar2 = PTR_DAT_0305a120;
  if ((*(char *)PTR_DAT_0305a124 == '\x02') || (*(char *)PTR_DAT_0305a124 == '\x04')) {
    display_draw_string_ascii_mixed
              (0x104,((uint)*(byte *)PTR_DAT_0305a120 % 9) * 0x18 + 5,
               param_1 + (uint)*(byte *)PTR_DAT_0305a120 * 2,2,0xffff,0xc618);
    puVar3 = p_text_entry_buffer_alias;
    bVar1 = *(byte *)puVar2;
    *(undefined1 *)p_text_entry_buffer_alias = *(undefined1 *)(param_1 + (uint)bVar1 * 2);
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)(param_1 + (uint)bVar1 * 2 + 1);
  }
  return p_text_entry_buffer_alias;
}

