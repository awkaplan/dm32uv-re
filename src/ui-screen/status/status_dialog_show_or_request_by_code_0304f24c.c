/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: status_dialog_show_or_request_by_code @ 0304f24c (file base 0x03000000; code starts at 0x03001000)
 * Size: 80 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-screen
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void status_dialog_show_or_request_by_code(void)

{
  int iVar1;
  
  iVar1 = scan_feature_enabled(0);
  if (iVar1 == 0) {
    display_draw_dialog_panel();
    display_draw_number_centered
              (0x82,0,0xc618,
               *(uint *)(PTR_PTR_0304f2fc[(byte)p_dm32_settings_block04[0x30] >> 6 & 1] + 0x10));
    OSTimeDly_ms_wrapper(1000);
    write_status_mode_byte_pair(*(undefined1 *)((uint)*DAT_0304f2e0 + DAT_0304f2e4),3);
  }
  else {
    status_dialog_request_by_code_dispatch_b();
  }
  return;
}

