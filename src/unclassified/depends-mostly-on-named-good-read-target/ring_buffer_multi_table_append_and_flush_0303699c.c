/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: ring_buffer_multi_table_append_and_flush @ 0303699c (file base 0x03000000; code starts at 0x03001000)
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

void ring_buffer_multi_table_append_and_flush(void)

{
  byte bVar1;
  dialog_history_ui_state *pdVar2;
  undefined1 *puVar3;
  
  pdVar2 = p_dialog_history_ui_state;
  bVar1 = p_dialog_history_ui_state->field_0x1;
  PTR_DAT_03036a30[bVar1] = *(undefined1 *)p_active_screen_flag_0003e5d5;
  pdVar2->field_0x1 = bVar1 + 1;
  bVar1 = *(byte *)pdVar2;
  (&p_menu_screen_state->field_0x0)[bVar1] = *(undefined1 *)p_active_screen_state_word;
  *(byte *)pdVar2 = bVar1 + 1;
  bVar1 = pdVar2->index_0x2;
  PTR_DAT_03036a3c[bVar1] = pdVar2->field_0x3;
  pdVar2->index_0x2 = bVar1 + 1;
  puVar3 = p_active_screen_index_list;
  memcpy_bytes_iram(p_active_screen_index_list +
                    (uint)(byte)p_active_screen_index_list[0x2e2] * 0x23 + 0x26,
                    p_active_screen_index_list + 2,0x23);
  puVar3[0x2e2] = puVar3[0x2e2] + '\x01';
  bVar1 = puVar3[0x2f7];
  puVar3[bVar1 + 0x2e3] = (char)*(undefined2 *)puVar3;
  puVar3[0x2f7] = bVar1 + 1;
  *(undefined1 *)PTR_DAT_03036a44 = 0xf0;
  return;
}

