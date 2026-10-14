/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_command_dispatch_with_dmr_fallback @ 0304dc8c (file base 0x03000000; code starts at 0x03001000)
 * Size: 28 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void menu_command_dispatch_with_dmr_fallback(void)

{
  uint uVar1;
  undefined1 auStack_1c [4];
  
  uVar1 = (uint)*(byte *)((uint)p_menu_screen_state->index_0x3 + DAT_0304dcac + 2);
  if (uVar1 < 0x16) {
                    /* WARNING: Could not recover jumptable at 0x0304dca6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(PTR_PTR_0304dcc0[uVar1] & 0xfffffffe))();
    return;
  }
  if (*(char *)PTR_active_screen_subtype_0304e4b8 == '\n') {
    if (*(char *)PTR_DAT_0304e4bc == '\x03') {
      if (uVar1 == 8) {
        OSTmr_state_dispatch_callback(p_ucos_tmr_inputcursor,0,0,auStack_1c);
        *(undefined1 *)PTR_DAT_0304e4c0 = 0xf0;
        settings_write_0x50_wrapper(p_text_entry_buffer,*(undefined1 *)PTR_DAT_0304e4c8);
        dialog_show_icon_and_two_numbers
                  (0x30,0x30,PTR_DAT_0304e4ac,
                   **(undefined4 **)
                     (PTR_PTR_0304e4a4 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8),
                   PTR_LAB_0304e4a8);
        p_radio_mode_state_0003e318->flags_0x5 = p_radio_mode_state_0003e318->flags_0x5 & 0xfe;
        OSTimeDly_ms_wrapper(1000);
        write_status_mode_byte_pair(0,1);
      }
      else {
        write_status_mode_byte_pair(0x23,1);
      }
    }
    else {
      scan_state_tick();
      write_status_mode_byte_pair(*(undefined1 *)((uint)*DAT_0304e578 + DAT_0304e57c),0);
    }
  }
  else {
    write_status_mode_byte_pair(0x23,1);
  }
  return;
}

