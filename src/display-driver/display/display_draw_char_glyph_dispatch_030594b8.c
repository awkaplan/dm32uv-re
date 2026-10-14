/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: display_draw_char_glyph_dispatch @ 030594b8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 30 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: display-driver
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void display_draw_char_glyph_dispatch(void)

{
  short sVar1;
  undefined4 *puVar2;
  undefined1 uStack_c;
  undefined1 uStack_b;
  
  puVar2 = p_text_entry_current_char;
  uStack_b = 0;
  if ((&p_state_0003ff3c->field_0x3)[p_state_0003ff3c->field_0x1] < 0x10) {
                    /* WARNING: Could not recover jumptable at 0x030594d4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(PTR_PTR_030594e0[(&p_state_0003ff3c->field_0x3)[p_state_0003ff3c->field_0x1]] &
              0xfffffffe))();
    return;
  }
  display_draw_glyph_row_mutex
            (*(undefined2 *)PTR_DAT_030595bc,*(undefined2 *)p_text_entry_current_char,&uStack_c,0,
             0xffff);
  sVar1 = *(short *)puVar2;
  *(ushort *)puVar2 = sVar1 + 8U;
  if (0xe7 < (ushort)(sVar1 + 8U)) {
    *(undefined2 *)puVar2 = 5;
    *(short *)PTR_DAT_030595bc = *(short *)PTR_DAT_030595bc + 0x10;
  }
  return;
}

