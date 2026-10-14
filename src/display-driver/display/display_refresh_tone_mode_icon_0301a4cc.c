/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: display_refresh_tone_mode_icon @ 0301a4cc (file base 0x03000000; code starts at 0x03001000)
 * Size: 230 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: display-driver
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void display_refresh_tone_mode_icon(void)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  byte bVar5;
  
  iVar2 = get_current_mode_state2();
  if (((((p_radio_mode_state_0003e318->flags_0x3 & 0x40) == 0) && ((PTR_DAT_0301a528[3] & 2) == 0))
      && (*(char *)PTR_DAT_0301a520 == '\0')) &&
     ((iVar3 = read_byte_field_0302e118(), iVar3 == 0 &&
      (iVar3 = get_current_mode_state1(), puVar1 = PTR_DAT_0301a69c, iVar3 == 0)))) {
    if (iVar2 == 0) {
      iVar2 = read_byte_field_0305fca8();
      if (iVar2 == 0) {
        if ((p_dm32_settings_block04[0x2d] & 0x80) == 0) {
          bVar5 = (byte)PTR_DAT_0301a6a0[8] >> 4;
          uVar4 = 0xf800;
        }
        else {
          bVar5 = (byte)PTR_DAT_0301a6a4[8] >> 4;
          uVar4 = 0xf800;
        }
      }
      else {
        bVar5 = p_vfo_display_state->flags_0x8 >> 4;
        uVar4 = 0x7ff;
      }
      display_draw_tone_mode_icon((byte)p_dm32_settings_block04[0x2d] >> 7,bVar5,uVar4);
    }
    else {
      if (iVar2 == 3) {
        bVar5 = p_vfo_display_state->flags_0x8 >> 4;
        uVar4 = 0x7ff;
      }
      else if ((PTR_DAT_0301a69c[1] & 1) == 0) {
        bVar5 = (byte)PTR_DAT_0301a6a0[8] >> 4;
        uVar4 = 0xf800;
      }
      else {
        bVar5 = (byte)PTR_DAT_0301a6a4[8] >> 4;
        uVar4 = 0xf800;
      }
      display_clear_status_row_at_y_by_flag(PTR_DAT_0301a69c[1] & 1);
      display_draw_tone_mode_icon(puVar1[1] & 1,bVar5,uVar4);
    }
  }
  return;
}

