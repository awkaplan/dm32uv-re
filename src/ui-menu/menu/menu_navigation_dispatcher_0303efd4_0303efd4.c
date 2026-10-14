/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_navigation_dispatcher_0303efd4 @ 0303efd4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 396 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined4 menu_navigation_dispatcher_0303efd4(void)

{
  char cVar1;
  dialog_history_ui_state *pdVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  dialog_history_ui_state *pdVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  
  uVar6 = cpu_sr_save_and_disable_irq_iram();
  OS_SchedLockTimeMeasStart();
  cVar1 = *(char *)PTR_OSSchedLockNestingCtr_0303f154;
  *(char *)PTR_OSSchedLockNestingCtr_0303f154 = cVar1 + '\x01';
  if ((char)(cVar1 + '\x01') == '\x01') {
    OS_SchedLockTimeMeasStart_variant4();
  }
  OS_SchedLockTimeMeasStop();
  cpu_sr_restore_irq_iram(uVar6);
  *PTR_DAT_0303f140 = 0;
  *(undefined1 *)p_menu_screen_state = 0;
  puVar4 = PTR_DAT_0303f158;
  *(undefined1 *)PTR_DAT_0303f158 = 0;
  *(undefined1 *)((int)puVar4 + 1) = 7;
  iVar7 = p_menu_navigation_index_table;
  memcpy_bytes_iram(p_menu_navigation_index_table,p_menu_navigation_index_table + -0x24,0x23);
  *(char *)(iVar7 + 0x2bd) = (char)*(undefined2 *)(iVar7 + -0x26);
  iVar7 = vfo_active_side_mode_nibble();
  puVar3 = p_active_screen_index_list;
  if (iVar7 == 0) {
    uVar8 = 0x18;
  }
  else if (iVar7 == 2) {
    uVar8 = 0x18;
  }
  else {
    uVar8 = 0x17;
  }
  menu_option_list_dispatch(uVar8,p_active_screen_index_list,p_active_screen_index_list + 2);
  pdVar5 = p_dialog_history_ui_state;
  pdVar2 = p_dialog_history_ui_state;
  if (*(ushort *)puVar3 == 0) {
LAB_0303f06a:
    uVar6 = cpu_sr_save_and_disable_irq_iram();
    OS_SchedLockTimeMeasStart();
    cVar1 = *(char *)PTR_OSSchedLockNestingCtr_0303f154;
    *(char *)PTR_OSSchedLockNestingCtr_0303f154 = cVar1 + -1;
    if ((char)(cVar1 + -1) == '\0') {
      OS_SchedLockTimeMeasStop_variant4();
      if (*(short *)PTR_DAT_0303f160 == 0) {
        OS_SchedLockTimeMeasStop();
        cpu_sr_restore_irq_iram(uVar6);
      }
      else {
        OS_SchedLockTimeMeasStop();
        cpu_sr_restore_irq_iram(uVar6);
        irq_disable_save_and_release_reinit();
      }
    }
    else {
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(uVar6);
    }
    tx_gate_write_call_record(0);
    uVar6 = 0;
  }
  else {
    if (puVar3[2] == '\x01') {
      p_dialog_history_ui_state->field_0x1 = 1;
      *(undefined1 *)pdVar5 = 1;
      puVar3 = p_active_screen_index_list;
      p_active_screen_index_list[0x2e2] = 1;
      puVar3[0x2f7] = 1;
      *(undefined1 *)p_active_screen_state_word = 0;
      *(undefined1 *)p_active_screen_flag_0003e5d5 = 1;
    }
    else {
      uVar8 = 0;
      do {
        uVar9 = uVar8 + 1;
        uVar8 = uVar9 & 0xff;
        if (*(ushort *)puVar3 <= uVar8) goto LAB_0303f06a;
      } while (puVar3[uVar8 + 2] != '\x01');
      p_dialog_history_ui_state->field_0x1 = 1;
      *(undefined1 *)pdVar2 = 1;
      puVar3 = p_active_screen_index_list;
      p_active_screen_index_list[0x2e2] = 1;
      puVar3[0x2f7] = 1;
      *(char *)p_active_screen_state_word = (char)uVar9;
      *(char *)p_active_screen_flag_0003e5d5 = (char)(uVar8 + 1);
      if (8 < (uVar8 + 1 & 0xff)) {
        *(undefined1 *)p_active_screen_flag_0003e5d5 = 8;
      }
    }
    pdVar2 = p_dialog_history_ui_state;
    p_dialog_history_ui_state->index_0x2 = 2;
    pdVar2->field_0x3 = 7;
    uVar6 = cpu_sr_save_and_disable_irq_iram();
    OS_SchedLockTimeMeasStart();
    cVar1 = *(char *)PTR_OSSchedLockNestingCtr_0303f154;
    *(char *)PTR_OSSchedLockNestingCtr_0303f154 = cVar1 + -1;
    if ((char)(cVar1 + -1) == '\0') {
      OS_SchedLockTimeMeasStop_variant4();
      if (*(short *)PTR_DAT_0303f160 == 0) {
        OS_SchedLockTimeMeasStop();
        cpu_sr_restore_irq_iram(uVar6);
        uVar6 = 1;
      }
      else {
        OS_SchedLockTimeMeasStop();
        cpu_sr_restore_irq_iram(uVar6);
        irq_disable_save_and_release_reinit();
        uVar6 = 1;
      }
    }
    else {
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(uVar6);
      uVar6 = 1;
    }
  }
  return uVar6;
}

