/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_select_type_dispatch @ 0305ce84 (file base 0x03000000; code starts at 0x03001000)
 * Size: 180 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void channel_select_type_dispatch(int param_1__w,undefined4 param_2,undefined4 param_3,int param_4__w)

{
  char param_1 = (char)param_1__w;
  undefined1 param_4 = (undefined1)param_4__w;
  int iVar1;
  undefined2 uVar2;
  
  iVar1 = DAT_0305cf58;
  if ((p_tx_ptt_ui_state->flags_0xa & 0x30) == 0x10) {
    *PTR_DAT_0305cf3c = 0;
    format_and_write_status_field2
              (**(undefined4 **)
                 (PTR_PTR_0305cf44 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
  }
  else if ((p_vfo_display_state->flags_0x8 & 8) == 0) {
    uVar2 = gb2312_string_reencode(param_1,param_3,param_4,DAT_0305cf58);
    *(undefined2 *)(iVar1 + -2) = uVar2;
    tx_abort_on_condition();
    if ((byte)(param_1 - 3) < 8) {
                    /* WARNING: Could not recover jumptable at 0x0305cf36. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(PTR_PTR_0305cf5c[(byte)(param_1 - 3)] & 0xfffffffe))();
      return;
    }
  }
  else {
    *PTR_DAT_0305cf3c = 0;
    format_and_write_status_field2
              (**(undefined4 **)
                 (PTR_PTR_0305cf4c + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
    if ((p_radio_mode_state_0003e318[1].flags_0x6 & 0x80) != 0) {
      p_radio_mode_state_0003e318[1].flags_0x6 = p_radio_mode_state_0003e318[1].flags_0x6 & 0x7f;
      if (PTR_DAT_0305cf54[1] != 0) {
        ui_event_notify_alt(0x17);
      }
    }
  }
  return;
}

