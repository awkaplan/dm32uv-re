/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_screen_entry_generic_0303e424 @ 0303e424 (file base 0x03000000; code starts at 0x03001000)
 * Size: 550 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined4 menu_screen_entry_generic_0303e424(char param_1)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  dialog_history_ui_state *pdVar4;
  undefined1 *puVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  ushort *puVar9;
  void *pvVar10;
  
  uVar6 = cpu_sr_save_and_disable_irq_iram();
  OS_SchedLockTimeMeasStart();
  cVar1 = *(char *)PTR_OSSchedLockNestingCtr_0303e5a8;
  *(char *)PTR_OSSchedLockNestingCtr_0303e5a8 = cVar1 + '\x01';
  if ((char)(cVar1 + '\x01') == '\x01') {
    OS_SchedLockTimeMeasStart_variant4();
  }
  OS_SchedLockTimeMeasStop();
  cpu_sr_restore_irq_iram(uVar6);
  *(undefined1 *)PTR_DAT_0303e5ac = 0;
  *(undefined1 *)p_menu_screen_state = 0;
  puVar2 = PTR_DAT_0303e5b4;
  *(undefined1 *)PTR_DAT_0303e5b4 = 0;
  *(undefined1 *)((int)puVar2 + 1) = 7;
  iVar3 = p_menu_navigation_index_table;
  pvVar10 = (void *)(p_menu_navigation_index_table + -0x24);
  memcpy_bytes_iram(p_menu_navigation_index_table,pvVar10,0x23);
  puVar9 = (ushort *)(iVar3 + -0x26);
  *(char *)(iVar3 + 0x2bd) = (char)*puVar9;
  menu_option_list_dispatch(0x18,puVar9,pvVar10);
  if (*puVar9 == 0) {
LAB_0303e4a6:
    uVar6 = cpu_sr_save_and_disable_irq_iram();
    OS_SchedLockTimeMeasStart();
    cVar1 = *(char *)PTR_OSSchedLockNestingCtr_0303e5a8;
    *(char *)PTR_OSSchedLockNestingCtr_0303e5a8 = cVar1 + -1;
    if ((char)(cVar1 + -1) == '\0') {
      OS_SchedLockTimeMeasStop_variant4();
      if (*(short *)PTR_DAT_0303e5c0 == 0) {
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
    if (p_active_screen_index_list[2] == '\x01') {
      uVar7 = 0;
    }
    else {
      uVar7 = 0;
      do {
        uVar7 = uVar7 + 1 & 0xff;
        if (*puVar9 <= uVar7) goto LAB_0303e4a6;
      } while (p_active_screen_index_list[uVar7 + 2] != '\x01');
    }
    p_menu_screen_state->index_0x1 = (byte)uVar7;
    *(byte *)((int)PTR_DAT_0303e5ac + 1) = (byte)uVar7 + 1;
    *(undefined1 *)((int)PTR_DAT_0303e5b4 + 2) = 0xe;
    iVar3 = DAT_0303e5c4;
    pvVar10 = (void *)(DAT_0303e5c4 + -0x47);
    memcpy_bytes_iram(DAT_0303e5c4,pvVar10,0x23);
    puVar9 = (ushort *)(iVar3 + -0x49);
    *(char *)(iVar3 + 0x29b) = (char)*puVar9;
    menu_option_list_dispatch(0xd,puVar9,pvVar10);
    pdVar4 = p_dialog_history_ui_state;
    if (*puVar9 == 0) {
LAB_0303e552:
      uVar6 = cpu_sr_save_and_disable_irq_iram();
      OS_SchedLockTimeMeasStart();
      cVar1 = *(char *)PTR_OSSchedLockNestingCtr_0303e5a8;
      *(char *)PTR_OSSchedLockNestingCtr_0303e5a8 = cVar1 + -1;
      if ((char)(cVar1 + -1) == '\0') {
        OS_SchedLockTimeMeasStop_variant4();
        if (*(short *)PTR_DAT_0303e5c0 == 0) {
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
      if (p_active_screen_index_list[2] == param_1) {
        p_dialog_history_ui_state->field_0x1 = 2;
        *(undefined1 *)pdVar4 = 2;
        puVar5 = p_active_screen_index_list;
        p_active_screen_index_list[0x2e2] = 2;
        puVar5[0x2f7] = 2;
        *(undefined1 *)p_active_screen_state_word = 0;
        *(undefined1 *)p_active_screen_flag_0003e5d5 = 1;
      }
      else {
        uVar7 = 0;
        do {
          uVar8 = uVar7 + 1;
          uVar7 = uVar8 & 0xff;
          if (*puVar9 <= uVar7) goto LAB_0303e552;
        } while (p_active_screen_index_list[uVar7 + 2] != param_1);
        p_dialog_history_ui_state->field_0x1 = 2;
        *(undefined1 *)pdVar4 = 2;
        puVar5 = p_active_screen_index_list;
        p_active_screen_index_list[0x2e2] = 2;
        puVar5[0x2f7] = 2;
        *(char *)p_active_screen_state_word = (char)uVar8;
        *(char *)p_active_screen_flag_0003e5d5 = (char)(uVar7 + 1);
        if (8 < (uVar7 + 1 & 0xff)) {
          *(undefined1 *)p_active_screen_flag_0003e5d5 = 8;
        }
      }
      pdVar4 = p_dialog_history_ui_state;
      p_dialog_history_ui_state->index_0x2 = 3;
      pdVar4->field_0x3 = 0xe;
      uVar6 = cpu_sr_save_and_disable_irq_iram();
      OS_SchedLockTimeMeasStart();
      cVar1 = *(char *)PTR_OSSchedLockNestingCtr_0303e754;
      *(char *)PTR_OSSchedLockNestingCtr_0303e754 = cVar1 + -1;
      if ((char)(cVar1 + -1) == '\0') {
        OS_SchedLockTimeMeasStop_variant4();
        if (*(short *)PTR_DAT_0303e758 == 0) {
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
  }
  return uVar6;
}

