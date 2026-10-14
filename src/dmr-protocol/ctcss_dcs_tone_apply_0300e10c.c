/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: ctcss_dcs_tone_apply @ 0300e10c (file base 0x03000000; code starts at 0x03001000)
 * Size: 188 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: dmr-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void ctcss_dcs_tone_apply(char param_1,undefined2 param_2)

{
  undefined2 uVar1;
  uint uVar2;
  
  PTR_DAT_0300e288[0x800] = 0xff;
  if (param_1 == '\0') {
    fd6818b_write_tone_divider_reg07(0x470);
    param_set_bit_0x2000(0x1ce);
    rf_mode_config_entry_0x51_apply(0);
  }
  else if (param_1 == '\x01') {
    bcd_unpack_u16_on_stack(param_2);
    PTR_DAT_0300e288[0x800] = 1;
    soft_double_from_int();
    soft_double_multiply();
    soft_double_add();
    uVar1 = soft_double_to_int();
    fd6818b_write_tone_divider_reg07(uVar1);
    param_set_bit_0x2000(0x1ce);
    rf_mode_config_entry_0x51_apply(4);
  }
  else {
    fd6818b_write_tone_divider_reg07(0xad7);
    if (param_1 == '\x01') {
      *PTR_DAT_0300e294 = 0;
      fd6818b_write_cdcss_code_reg08(0,0);
    }
    else {
      uVar2 = freq_bitpack_crc12_encode(param_2);
      *PTR_DAT_0300e294 = uVar2;
      fd6818b_write_cdcss_code_reg08(uVar2 >> 0xc & 0xffff,uVar2 & 0xfff);
      if (param_1 == '\x02') {
        rf_mode_config_entry_0x51_apply(2);
        return;
      }
    }
    rf_mode_config_entry_0x51_apply(3);
  }
  return;
}

