/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dialog_icon_or_commit_on_flag_0x40 @ 03050a12 (file base 0x03000000; code starts at 0x03001000)
 * Size: 120 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-dialog
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void dialog_icon_or_commit_on_flag_0x40(void)

{
  undefined4 uVar1;
  char cVar2;
  
  if ((*(byte *)PTR_DAT_03050a88 & 0x40) == 0) {
    dialog_show_icon_and_number
              (0,**(undefined4 **)
                   (PTR_PTR_03050c10 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
  }
  else {
    wlt_cmd_string_build(1);
    uVar1 = p_text_entry_buffer;
    cVar2 = strlen_ck803s(p_text_entry_buffer);
    *(char *)PTR_DAT_03050a90 = cVar2 + '\x01';
    p_radio_mode_state_0003e318[1].flags_0x7 = p_radio_mode_state_0003e318[1].flags_0x7 & 0xfb | 4;
    channel_select_commit_and_notify(3,*PTR_DAT_03050a98,uVar1);
    write_status_mode_byte_pair(*(undefined1 *)((uint)*DAT_03050c20 + DAT_03050c24),0);
  }
  return;
}

