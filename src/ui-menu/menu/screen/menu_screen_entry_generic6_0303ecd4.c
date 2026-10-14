/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_screen_entry_generic6 @ 0303ecd4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 664 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined4 menu_screen_entry_generic6(char param_1)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined1 *puVar4;
  dialog_history_ui_state *pdVar5;
  undefined4 *puVar6;
  dialog_history_ui_state *pdVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  ushort *puVar12;
  void *pvVar13;
  
  uVar8 = cpu_sr_save_and_disable_irq_iram();
  OS_SchedLockTimeMeasStart();
  cVar1 = *(char *)PTR_OSSchedLockNestingCtr_0303edbc;
  *(char *)PTR_OSSchedLockNestingCtr_0303edbc = cVar1 + '\x01';
  if ((char)(cVar1 + '\x01') == '\x01') {
    OS_SchedLockTimeMeasStart_variant4();
  }
  OS_SchedLockTimeMeasStop();
  cpu_sr_restore_irq_iram(uVar8);
  *(undefined1 *)PTR_DAT_0303edc4 = 0;
  *(undefined1 *)p_menu_screen_state = 0;
  puVar2 = PTR_DAT_0303edcc;
  *(undefined1 *)PTR_DAT_0303edcc = 0;
  *(undefined1 *)((int)puVar2 + 1) = 7;
  iVar3 = p_menu_navigation_index_table;
  pvVar13 = (void *)(p_menu_navigation_index_table + -0x24);
  memcpy_bytes_iram(p_menu_navigation_index_table,pvVar13,0x23);
  puVar12 = (ushort *)(iVar3 + -0x26);
  *(char *)(iVar3 + 0x2bd) = (char)*puVar12;
  menu_option_list_dispatch(0x17,puVar12,pvVar13);
  puVar6 = PTR_PTR_0303f12c;
  puVar2 = PTR_PTR_0303ef44;
  if (*puVar12 == 0) {
LAB_0303ed56:
    uVar8 = cpu_sr_save_and_disable_irq_iram();
    OS_SchedLockTimeMeasStart();
    cVar1 = *(char *)PTR_OSSchedLockNestingCtr_0303edbc;
    *(char *)PTR_OSSchedLockNestingCtr_0303edbc = cVar1 + -1;
    if ((char)(cVar1 + -1) == '\0') {
      OS_SchedLockTimeMeasStop_variant4();
      if (*(short *)PTR_DAT_0303edc0 == 0) {
        OS_SchedLockTimeMeasStop();
        cpu_sr_restore_irq_iram(uVar8);
      }
      else {
        OS_SchedLockTimeMeasStop();
        cpu_sr_restore_irq_iram(uVar8);
        irq_disable_save_and_release_reinit();
      }
    }
    else {
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(uVar8);
    }
    tx_gate_write_call_record(0);
    uVar8 = 0;
  }
  else {
    if (p_active_screen_index_list[2] == '\x04') {
      uVar10 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
      *(undefined1 *)p_active_screen_option_count =
           *(undefined1 *)(PTR_PTR_0303f12c + uVar10 * 2 + 1);
      *p_active_screen_option_ptr_array = puVar6[uVar10 * 2];
      *(undefined1 *)PTR_active_screen_subtype_0303f138 =
           *(undefined1 *)((int)puVar6 + uVar10 * 8 + 5);
      p_menu_screen_state->index_0x1 = 0;
      PTR_DAT_0303f140[1] = 1;
    }
    else {
      uVar10 = 0;
      do {
        uVar11 = uVar10 + 1;
        uVar10 = uVar11 & 0xff;
        if (*puVar12 <= uVar10) goto LAB_0303ed56;
      } while (p_active_screen_index_list[uVar10 + 2] != '\x04');
      uVar9 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
      *(undefined1 *)p_active_screen_option_count =
           *(undefined1 *)(PTR_PTR_0303ef44 + uVar9 * 2 + 1);
      *p_active_screen_option_ptr_array = puVar2[uVar9 * 2];
      *(undefined1 *)PTR_active_screen_subtype_0303ef50 =
           *(undefined1 *)((int)puVar2 + uVar9 * 8 + 5);
      p_menu_screen_state->index_0x1 = (byte)uVar11;
      PTR_DAT_0303ef58[1] = (char)(uVar10 + 1);
      if (8 < (uVar10 + 1 & 0xff)) {
        PTR_DAT_0303ef58[1] = 8;
      }
    }
    iVar3 = DAT_0303ef5c;
    pvVar13 = (void *)(DAT_0303ef5c + -0x47);
    memcpy_bytes_iram(DAT_0303ef5c,pvVar13,0x23);
    puVar12 = (ushort *)(iVar3 + -0x49);
    *(char *)(iVar3 + 0x29b) = (char)*puVar12;
    PTR_DAT_0303ef60[2] = 0xe;
    menu_option_list_dispatch(5,puVar12,pvVar13);
    pdVar7 = p_dialog_history_ui_state;
    pdVar5 = p_dialog_history_ui_state;
    if (*puVar12 == 0) {
LAB_0303ee66:
      uVar8 = cpu_sr_save_and_disable_irq_iram();
      OS_SchedLockTimeMeasStart();
      cVar1 = *(char *)PTR_OSSchedLockNestingCtr_0303ef68;
      *(char *)PTR_OSSchedLockNestingCtr_0303ef68 = cVar1 + -1;
      if ((char)(cVar1 + -1) == '\0') {
        OS_SchedLockTimeMeasStop_variant4();
        if (*(short *)PTR_DAT_0303ef6c == 0) {
          OS_SchedLockTimeMeasStop();
          cpu_sr_restore_irq_iram(uVar8);
        }
        else {
          OS_SchedLockTimeMeasStop();
          cpu_sr_restore_irq_iram(uVar8);
          irq_disable_save_and_release_reinit();
        }
      }
      else {
        OS_SchedLockTimeMeasStop();
        cpu_sr_restore_irq_iram(uVar8);
      }
      tx_gate_write_call_record(0);
      uVar8 = 0;
    }
    else {
      if (p_active_screen_index_list[2] == param_1) {
        p_dialog_history_ui_state->field_0x1 = 2;
        *(undefined1 *)pdVar7 = 2;
        puVar4 = p_active_screen_index_list;
        p_active_screen_index_list[0x2e2] = 2;
        puVar4[0x2f7] = 2;
        *(undefined1 *)p_active_screen_state_word = 0;
        *(undefined1 *)p_active_screen_flag_0003e5d5 = 1;
      }
      else {
        uVar10 = 0;
        do {
          uVar11 = uVar10 + 1;
          uVar10 = uVar11 & 0xff;
          if (*puVar12 <= uVar10) goto LAB_0303ee66;
        } while (p_active_screen_index_list[uVar10 + 2] != param_1);
        p_dialog_history_ui_state->field_0x1 = 2;
        *(undefined1 *)pdVar5 = 2;
        puVar4 = p_active_screen_index_list;
        p_active_screen_index_list[0x2e2] = 2;
        puVar4[0x2f7] = 2;
        *(char *)p_active_screen_state_word = (char)uVar11;
        *(char *)p_active_screen_flag_0003e5d5 = (char)(uVar10 + 1);
        if (8 < (uVar10 + 1 & 0xff)) {
          *(undefined1 *)p_active_screen_flag_0003e5d5 = 8;
        }
      }
      pdVar5 = p_dialog_history_ui_state;
      p_dialog_history_ui_state->index_0x2 = 3;
      pdVar5->field_0x3 = 0xe;
      uVar8 = cpu_sr_save_and_disable_irq_iram();
      OS_SchedLockTimeMeasStart();
      cVar1 = *(char *)PTR_OSSchedLockNestingCtr_0303ef68;
      *(char *)PTR_OSSchedLockNestingCtr_0303ef68 = cVar1 + -1;
      if ((char)(cVar1 + -1) == '\0') {
        OS_SchedLockTimeMeasStop_variant4();
        if (*(short *)PTR_DAT_0303ef6c == 0) {
          OS_SchedLockTimeMeasStop();
          cpu_sr_restore_irq_iram(uVar8);
          uVar8 = 1;
        }
        else {
          OS_SchedLockTimeMeasStop();
          cpu_sr_restore_irq_iram(uVar8);
          irq_disable_save_and_release_reinit();
          uVar8 = 1;
        }
      }
      else {
        OS_SchedLockTimeMeasStop();
        cpu_sr_restore_irq_iram(uVar8);
        uVar8 = 1;
      }
    }
  }
  return uVar8;
}

