/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: mode_transition_cleanup @ 030644d8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 64 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: radio-state
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void mode_transition_cleanup(void)

{
  undefined1 *puVar1;
  int iVar2;
  
  iVar2 = get_current_mode_state2();
  if (((iVar2 != 0) && (iVar2 != 4)) && (iVar2 = get_current_mode_state1(), iVar2 == 0)) {
    if ((PTR_DAT_03064558[1] & 1) != (byte)p_dm32_settings_block04[0x2d] >> 7) {
      vfo_exit_dual_watch_and_refresh();
    }
    puVar1 = PTR_DAT_03064560;
    PTR_DAT_03064560[0x1d] = 0;
    puVar1[0x1c] = 0;
    set_flag_byte_03064328(3);
  }
  return;
}

