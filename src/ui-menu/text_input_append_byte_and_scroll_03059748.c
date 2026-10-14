/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: text_input_append_byte_and_scroll @ 03059748 (file base 0x03000000; code starts at 0x03001000)
 * Size: 230 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-menu
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void text_input_append_byte_and_scroll(byte param_1)

{
  state_0003ff3c *psVar1;
  undefined1 *puVar2;
  uint uVar3;
  
  if (((p_radio_mode_state_0003e318->flags_0x6 & 0xc) == 0) &&
     ((*PTR_DAT_030597cc & 0x18000) != 0x8000)) {
    display_blit_bitmap_1bpp_rows
              (*(undefined2 *)PTR_DAT_030597b4,*(undefined2 *)p_text_entry_current_char,
               PTR_LAB_030597d0,1);
  }
  puVar2 = PTR_DAT_03059944;
  psVar1 = p_state_0003ff3c;
  uVar3 = (uint)*(byte *)PTR_DAT_030597b0;
  if (uVar3 < (byte)PTR_DAT_030597c4[2]) {
    if ((p_radio_mode_state_0003e318->flags_0x5 & 0x10) == 0) {
      PTR_DAT_03059944[uVar3] = param_1;
      *(char *)PTR_DAT_03059948 = (char)(uVar3 + 1);
      puVar2[uVar3 + 1 & 0xff] = 0;
    }
    else {
      (&p_state_0003ff3c->field_0x3)[uVar3] = param_1;
      *(char *)PTR_DAT_030597b0 = (char)(uVar3 + 1);
      (&psVar1->field_0x3)[uVar3 + 1 & 0xff] = 0;
    }
    if (((p_radio_mode_state_0003e318->flags_0x6 & 0xc) == 0) ||
       ((*(byte *)((int)PTR_DAT_03059950 + 1) & 0x80) != 0)) {
      *(short *)p_text_entry_current_char = *(short *)p_text_entry_current_char + 0xc;
    }
    else {
      *(short *)p_text_entry_current_char = *(short *)p_text_entry_current_char + 0xc;
    }
    if (0xe4 < *(ushort *)p_text_entry_current_char) {
      *(undefined2 *)p_text_entry_current_char = 5;
      *(short *)PTR_DAT_03059958 = *(short *)PTR_DAT_03059958 + 0x18;
    }
  }
  if (((p_radio_mode_state_0003e318->flags_0x6 & 0xc) == 0) &&
     ((*PTR_DAT_03059950 & 0x18000) != 0x8000)) {
    display_blit_bitmap_1bpp_rows
              (*(undefined2 *)PTR_DAT_03059958,*(undefined2 *)p_text_entry_current_char,
               PTR_DAT_0305995c,1);
  }
  return;
}

