/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: display_draw_glyph_row_advance_0x41 @ 030594ec (file base 0x03000000; code starts at 0x03001000)
 * Size: 8 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: display-driver
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void display_draw_glyph_row_advance_0x41(void)

{
  short sVar1;
  undefined4 *puVar2;
  undefined4 uStack00000000;
  undefined1 uStack00000004;
  
  puVar2 = p_text_entry_current_char;
  uStack00000004 = 0x41;
  uStack00000000 = 0xffff;
  display_draw_glyph_row_mutex
            (*(undefined2 *)PTR_DAT_030595bc,*(undefined2 *)p_text_entry_current_char,
             &stack0x00000004,0);
  sVar1 = *(short *)puVar2;
  *(ushort *)puVar2 = sVar1 + 8U;
  if (0xe7 < (ushort)(sVar1 + 8U)) {
    *(undefined2 *)puVar2 = 5;
    *(short *)PTR_DAT_030595bc = *(short *)PTR_DAT_030595bc + 0x10;
  }
  return;
}

