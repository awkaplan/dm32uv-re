/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: status_mode_or_settings_menu_command_dispatch @ 0304e560 (file base 0x03000000; code starts at 0x03001000)
 * Size: 24 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-screen
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void status_mode_or_settings_menu_command_dispatch(void)

{
  uint uVar1;
  
  uVar1 = (uint)*(byte *)((uint)p_menu_screen_state->index_0x2 + DAT_0304e598 + 2);
  if (uVar1 < 7) {
                    /* WARNING: Could not recover jumptable at 0x0304e576. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(PTR_PTR_0304e59c[uVar1] & 0xfffffffe))();
    return;
  }
  write_status_mode_byte_pair(*(undefined1 *)((uint)*DAT_0304e95c + DAT_0304e960),0);
  return;
}

