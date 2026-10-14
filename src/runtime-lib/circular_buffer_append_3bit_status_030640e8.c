/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: circular_buffer_append_3bit_status @ 030640e8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 140 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: runtime-lib
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void circular_buffer_append_3bit_status(uint param_1)

{
  byte bVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  byte extraout_var;
  uint uVar4;
  
  fd6818_reg_read(FD6818_PAGE0_REG_0BH);
  puVar2 = PTR_DAT_03064188;
  if ((((param_1 & 0x800) != 0) && ((*(byte *)PTR_DAT_03064180 & 0x20) != 0)) &&
     ((p_vfo_display_state->field_0xc & 0xf0) != 0)) {
    if ((p_vfo_display_state->field_0x16 & 0xe) == 4) {
      PTR_DAT_03064188[2] = extraout_var & 0xf;
      puVar2[1] = 2;
    }
    else if ((p_radio_mode_state_0003e318[2].flags_0x2 & 2) == 0) {
      p_radio_mode_state_0003e318[2].flags_0x2 = p_radio_mode_state_0003e318[2].flags_0x2 & 0xfb | 4
      ;
      PTR_DAT_03064190[0x25] = 0;
      puVar3 = PTR_DAT_03064194;
      bVar1 = *(byte *)PTR_DAT_03064194;
      PTR_DAT_03064198[bVar1] = extraout_var & 0xf;
      uVar4 = bVar1 + 1;
      *(char *)puVar3 = (char)uVar4;
      if (0x17 < (uVar4 & 0xff)) {
        *(undefined1 *)PTR_DAT_03064194 = 0;
      }
    }
  }
  return;
}

