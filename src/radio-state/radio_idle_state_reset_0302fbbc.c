/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: radio_idle_state_reset @ 0302fbbc (file base 0x03000000; code starts at 0x03001000)
 * Size: 138 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: radio-state
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void radio_idle_state_reset(char param_1)

{
  undefined1 *puVar1;
  
  if (param_1 == '\x01') {
    ui_event_notify(0x19);
  }
  fd6818b_reg_write(FD6818_PAGE0_REG_0X32,0x244);
  OSTimeDly_ms_wrapper(100);
  *PTR_DAT_0302fdfc = 0;
  *(undefined2 *)PTR_DAT_0302fe00 = 0;
  *(undefined2 *)PTR_DAT_0302fe04 = 0;
  *(undefined1 *)PTR_DAT_0302fe08 = 0;
  *(undefined1 *)PTR_DAT_0302fdf8 = 0;
  PTR_DAT_0302fe0c[3] = PTR_DAT_0302fe0c[3] & 0xb1;
  write_field_and_mbox_post(1,100);
  puVar1 = PTR_DAT_0302fe10;
  PTR_DAT_0302fe10[0x1d] = 0;
  puVar1[0x1c] = 0;
  vfo_load_side_config();
  settings_bitfield_remap_0x2d();
  PTR_DAT_0302fe14[1] = PTR_DAT_0302fe14[1] & 0xfe | (byte)p_dm32_settings_block04[0x2d] >> 7;
  ui_event_notify_alt(0x13);
  return;
}

