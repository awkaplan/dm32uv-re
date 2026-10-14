/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: rssi_meter_level_update_and_fault_reset @ 0301bb44 (file base 0x03000000; code starts at 0x03001000)
 * Size: 334 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rf-frontend
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void rssi_meter_level_update_and_fault_reset(uint param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = ((param_1 & 0xffff) * 100) / (((uint)(ushort)PTR_DAT_0301bc94[0x17] * 10) / 0x4b) & 0xffff
  ;
  p_radio_mode_state_0003e318->flags_0x7 = p_radio_mode_state_0003e318->flags_0x7 & 0xf7;
  if (uVar2 < 700) {
    *(undefined1 *)PTR_DAT_0301bca0 = 1;
    if (uVar2 < 0x28a) {
      if (uVar2 < 0x277) {
        p_radio_mode_state_0003e318->flags_0x7 = p_radio_mode_state_0003e318->flags_0x7 & 0xfb | 4;
        *(undefined1 *)PTR_DAT_0301bca0 = 0;
        if (uVar2 <= (ushort)PTR_DAT_0301bc94[0x18]) {
          p_radio_mode_state_0003e318->flags_0x7 =
               p_radio_mode_state_0003e318->flags_0x7 & 0xef | 0x10;
        }
      }
    }
    else {
      p_radio_mode_state_0003e318->flags_0x7 = p_radio_mode_state_0003e318->flags_0x7 & 0xeb;
    }
    if (uVar2 < 0x245) {
      *(byte *)((int)PTR_DAT_0301bc9c + 1) = *(byte *)((int)PTR_DAT_0301bc9c + 1) & 0xfb | 4;
      OSFlagPost_wrapper_set(p_ucos_flaggrp_0003fd90,0x40000);
    }
  }
  else {
    p_radio_mode_state_0003e318->flags_0x7 = p_radio_mode_state_0003e318->flags_0x7 & 0xeb;
    if ((*(byte *)((int)PTR_DAT_0301bc9c + 1) & 4) != 0) {
      flash_quad_enable_and_system_reset();
    }
    if (uVar2 < 900) {
      if (uVar2 < 800) {
        if (uVar2 < 0x2ef) {
          *(undefined1 *)PTR_DAT_0301bca0 = 2;
        }
        else {
          *(undefined1 *)PTR_DAT_0301bca0 = 3;
        }
      }
      else {
        *(undefined1 *)PTR_DAT_0301bca0 = 4;
      }
    }
    else {
      *(undefined1 *)PTR_DAT_0301bca0 = 4;
      p_radio_mode_state_0003e318->flags_0x7 = p_radio_mode_state_0003e318->flags_0x7 & 0xf7 | 8;
    }
  }
  if ((((*(char *)PTR_DAT_0301bca0 != *(char *)PTR_DAT_0301bca8) &&
       ((*(byte *)PTR_DAT_0301bc9c & 0x10) != 0)) &&
      ((*(char *)PTR_DAT_0301bcac == '\0' || (*(char *)PTR_DAT_0301bcac == '[')))) &&
     ((((iVar1 = read_byte_field_0302e118(), iVar1 == 0 || (iVar1 == 2)) || (iVar1 == 9)) ||
      (iVar1 == 3)))) {
    dialog_type_icon_draw_with_color();
    *(undefined1 *)PTR_DAT_0301bca8 = *(undefined1 *)PTR_DAT_0301bca0;
  }
  return;
}

