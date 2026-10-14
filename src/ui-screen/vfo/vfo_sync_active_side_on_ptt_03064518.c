/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: vfo_sync_active_side_on_ptt @ 03064518 (file base 0x03000000; code starts at 0x03001000)
 * Size: 62 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-screen
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void vfo_sync_active_side_on_ptt(void)

{
  int iVar1;
  
  iVar1 = get_current_mode_state2();
  if (iVar1 == 0) {
    if ((PTR_DAT_03064558[1] & 1) != (byte)p_dm32_settings_block04[0x2d] >> 7) {
      PTR_DAT_03064558[1] = PTR_DAT_03064558[1] & 0xfe | (byte)p_dm32_settings_block04[0x2d] >> 7;
      vfo_apply_active_side_config();
    }
  }
  else {
    PTR_DAT_03064560[0x1d] = 0;
    set_flag_byte_03064328(1);
  }
  return;
}

