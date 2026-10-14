/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: tx_abort_and_radio_state_reset @ 0302fa70 (file base 0x03000000; code starts at 0x03001000)
 * Size: 272 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rf-frontend
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void tx_abort_and_radio_state_reset(void)

{
  char cVar1;
  vfo_display_state *pvVar2;
  undefined4 uVar3;
  
  ui_event_notify(0x18);
  display_fill_screen(0);
  p_radio_mode_state_0003e318[1].flags_0x2 = 0;
  if ((*(byte *)p_call_active_flag & 4) != 0) {
    *PTR_DAT_0302fb64 = *PTR_DAT_0302fb64 & 0xdf;
    tx_abort_reset();
  }
  fd6818b_filter_select_then_chipmode_normal();
  mode_transition_cleanup();
  *(undefined1 *)PTR_DAT_0302fb84 = 0;
  *(undefined1 *)PTR_DAT_0302fb88 = 0;
  *(undefined1 *)PTR_DAT_0302fb8c = 0;
  PTR_DAT_0302fb64[3] =
       PTR_DAT_0302fb64[3] & 0xa1 | 2 | (p_radio_mode_state_0003e318->flags_0x3 >> 3 & 1) << 4;
  pvVar2 = p_vfo_display_state;
  p_vfo_display_state->flags_0x8 = p_vfo_display_state->flags_0x8 & 0xf;
  config_table_entry_0300f15c();
  tx_power_mode_apply_from_flags(pvVar2);
  draw_dialog_header_and_centered_number();
  fd6818b_reg_write(FD6818_PAGE0_REG_0X32,0x245);
  uVar3 = cpu_sr_save_and_disable_irq_iram();
  OS_SchedLockTimeMeasStart();
  cVar1 = *(char *)PTR_OSSchedLockNestingCtr_0302fb94;
  *(char *)PTR_OSSchedLockNestingCtr_0302fb94 = cVar1 + '\x01';
  if ((char)(cVar1 + '\x01') == '\x01') {
    OS_SchedLockTimeMeasStart_variant4();
  }
  OS_SchedLockTimeMeasStop();
  cpu_sr_restore_irq_iram(uVar3);
  busy_wait_delay_n_units(200);
  uVar3 = cpu_sr_save_and_disable_irq_iram();
  OS_SchedLockTimeMeasStart();
  cVar1 = *(char *)PTR_OSSchedLockNestingCtr_0302fb94;
  *(char *)PTR_OSSchedLockNestingCtr_0302fb94 = cVar1 + -1;
  if ((char)(cVar1 + -1) == '\0') {
    OS_SchedLockTimeMeasStop_variant4();
    if (*(short *)PTR_DAT_0302fb98 == 0) {
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(uVar3);
    }
    else {
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(uVar3);
      irq_disable_save_and_release_reinit();
    }
  }
  else {
    OS_SchedLockTimeMeasStop();
    cpu_sr_restore_irq_iram(uVar3);
  }
  *(undefined1 *)PTR_DAT_0302fdf8 = 1;
  return;
}

