/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: reentrant_state_reset_sequence @ 03035c38 (file base 0x03000000; code starts at 0x03001000)
 * Size: 282 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rtos
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void reentrant_state_reset_sequence(void)

{
  char cVar1;
  dialog_history_ui_state *pdVar2;
  undefined1 *puVar3;
  radio_mode_state_0003e318 *prVar4;
  undefined4 uVar5;
  
  uVar5 = cpu_sr_save_and_disable_irq_iram();
  OS_SchedLockTimeMeasStart();
  cVar1 = *(char *)PTR_OSSchedLockNestingCtr_03035d64;
  *(char *)PTR_OSSchedLockNestingCtr_03035d64 = cVar1 + '\x01';
  if ((char)(cVar1 + '\x01') == '\x01') {
    OS_SchedLockTimeMeasStart_variant4();
  }
  OS_SchedLockTimeMeasStop();
  cpu_sr_restore_irq_iram(uVar5);
  pdVar2 = p_dialog_history_ui_state;
  p_dialog_history_ui_state->field_0x1 = 0;
  *(undefined1 *)pdVar2 = 0;
  puVar3 = p_active_screen_index_list;
  p_active_screen_index_list[0x2e2] = 0;
  puVar3[0x2f7] = 0;
  *(undefined1 *)PTR_active_screen_subtype_03035d6c = 2;
  pdVar2->field_0x3 = 0;
  *(undefined1 *)PTR_DAT_03035d70 = 0;
  pdVar2->index_0x2 = 1;
  prVar4 = p_radio_mode_state_0003e318;
  p_radio_mode_state_0003e318->flags_0x7 = p_radio_mode_state_0003e318->flags_0x7 & 0x7f;
  prVar4->field_0x8 = prVar4->field_0x8 & 0xc0;
  prVar4->flags_0x4 = prVar4->flags_0x4 & 0xf;
  prVar4->flags_0x6 = prVar4->flags_0x6 & 0x83;
  prVar4->flags_0x5 = prVar4->flags_0x5 & 2;
  *(undefined1 *)PTR_DAT_03035d78 = 0;
  *(undefined1 *)PTR_DAT_03035d7c = 0;
  *(undefined1 *)p_active_screen_state_word = 0;
  uVar5 = cpu_sr_save_and_disable_irq_iram();
  OS_SchedLockTimeMeasStart();
  cVar1 = *(char *)PTR_OSSchedLockNestingCtr_03035d64;
  *(char *)PTR_OSSchedLockNestingCtr_03035d64 = cVar1 + -1;
  if ((char)(cVar1 + -1) == '\0') {
    OS_SchedLockTimeMeasStop_variant4();
    if (*(short *)PTR_DAT_03035d84 == 0) {
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(uVar5);
    }
    else {
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(uVar5);
      irq_disable_save_and_release_reinit();
    }
  }
  else {
    OS_SchedLockTimeMeasStop();
    cpu_sr_restore_irq_iram(uVar5);
  }
  return;
}

