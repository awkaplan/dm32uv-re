/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: contact_index_log_and_display @ 0304df24 (file base 0x03000000; code starts at 0x03001000)
 * Size: 114 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void contact_index_log_and_display(void)

{
  vfo_display_state *pvVar1;
  undefined4 in_stack_00000028;
  
  pvVar1 = p_vfo_display_state;
  if (*(short *)PTR_DAT_0304e0ac == 0) {
    p_vfo_display_state->field_0x31_0 = 0;
    pvVar1->field_0x32 = 0;
  }
  else {
    flash_field_read_cached(0xb,(*(short *)PTR_DAT_0304e0ac + 0x7f) * 2,(int)&stack0x00000028 + 2,2)
    ;
    pvVar1 = p_vfo_display_state;
    p_vfo_display_state->field_0x31_0 = (byte)(SUBPIECE(in_stack_00000028, 2, 2) & 0xfff);
    pvVar1->field_0x32 = (char)((SUBPIECE(in_stack_00000028, 2, 2) & 0xfff) >> 8);
  }
  dmr_id_log_write(*(undefined2 *)&p_vfo_freq_display_state->field_0x54_0,
                   *(undefined2 *)&p_vfo_display_state->field_0x31_0);
  dialog_show_icon_and_number
            (1,**(undefined4 **)
                 (PTR_PTR_0304e0b8 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
  return;
}

