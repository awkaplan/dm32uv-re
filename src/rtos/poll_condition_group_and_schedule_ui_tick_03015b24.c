/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: poll_condition_group_and_schedule_ui_tick @ 03015b24 (file base 0x03000000; code starts at 0x03001000)
 * Size: 138 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rtos
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void poll_condition_group_and_schedule_ui_tick(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = poll_condition_group(0x1c);
  if (iVar2 != 0) {
    if (p_dm32_settings_block04[0x6c] == '\0') {
      ui_event_notify(0x1b);
      format_and_write_status_field2(PTR_PTR_03015c6c[(byte)p_dm32_settings_block04[0x30] >> 6 & 1])
      ;
    }
    else if ((((*(byte *)p_call_active_flag & 8) == 0) &&
             ((((*(byte *)p_call_active_flag & 2) == 0 ||
               ((*(byte *)p_dialog_flags_from_flash & 1) != 0)) &&
              (iVar2 = ui_dialog_tick_scheduler(0), puVar1 = PTR_DAT_03015c78, iVar2 != 0)))) &&
            ((*(byte *)PTR_DAT_03015c78 & 0x10) != 0)) {
      *(byte *)((int)PTR_DAT_03015c78 + 5) = *(byte *)((int)PTR_DAT_03015c78 + 5) & 0xfe | 1;
      *(byte *)puVar1 = *(byte *)puVar1 & 0x7f | 0x80;
      request_display_refresh(4);
    }
  }
  return;
}

