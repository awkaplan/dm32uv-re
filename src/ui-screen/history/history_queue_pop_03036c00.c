/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: history_queue_pop @ 03036c00 (file base 0x03000000; code starts at 0x03001000)
 * Size: 166 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-screen
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void history_queue_pop(void)

{
  char cVar1;
  dialog_history_ui_state *pdVar2;
  undefined1 *puVar3;
  byte bVar4;
  
  p_dm32_settings_block04[0x55] = *(undefined1 *)PTR_DAT_03036db0;
  *(undefined1 *)PTR_DAT_03036db8 = 0;
  *(undefined1 *)PTR_DAT_03036dbc = 0;
  *(undefined1 *)PTR_DAT_03036dc0 = 0xf0;
  pdVar2 = p_dialog_history_ui_state;
  if (1 < p_dialog_history_ui_state->index_0x2) {
    bVar4 = p_dialog_history_ui_state->index_0x2 - 1;
    p_dialog_history_ui_state->index_0x2 = bVar4;
    pdVar2->field_0x3 = *(byte *)((uint)bVar4 + DAT_03036dc8);
    bVar4 = pdVar2->field_0x1 - 1;
    pdVar2->field_0x1 = bVar4;
    *(undefined1 *)p_active_screen_flag_0003e5d5 = PTR_DAT_03036dcc[bVar4];
    cVar1 = *(char *)pdVar2;
    *(byte *)pdVar2 = cVar1 - 1U;
    *(undefined1 *)p_active_screen_state_word =
         (&p_menu_screen_state->field_0x0)[(byte)(cVar1 - 1U)];
    puVar3 = p_active_screen_index_list;
    cVar1 = p_active_screen_index_list[0x2e2];
    p_active_screen_index_list[0x2e2] = cVar1 - 1U;
    memcpy_bytes_iram(puVar3 + 2,puVar3 + (uint)(byte)(cVar1 - 1U) * 0x23 + 0x26,0x23);
    cVar1 = puVar3[0x2f7];
    puVar3[0x2f7] = cVar1 - 1U;
    *(ushort *)puVar3 = (ushort)(byte)puVar3[(byte)(cVar1 - 1U) + 0x2e3];
  }
  if (p_dialog_history_ui_state->field_0x4 != 1) {
    p_dialog_history_ui_state->field_0x4 = 3;
  }
  return;
}

