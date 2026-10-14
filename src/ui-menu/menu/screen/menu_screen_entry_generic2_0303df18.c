/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_screen_entry_generic2 @ 0303df18 (file base 0x03000000; code starts at 0x03001000)
 * Size: 374 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined4 menu_screen_entry_generic2(void)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined1 *puVar4;
  dialog_history_ui_state *pdVar5;
  dialog_history_ui_state *pdVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  ushort *list;
  void *ctx;
  
  uVar7 = cpu_sr_save_and_disable_irq_iram();
  OS_SchedLockTimeMeasStart();
  cVar1 = *(char *)PTR_OSSchedLockNestingCtr_0303e070;
  *(char *)PTR_OSSchedLockNestingCtr_0303e070 = cVar1 + '\x01';
  if ((char)(cVar1 + '\x01') == '\x01') {
    OS_SchedLockTimeMeasStart_variant4();
  }
  OS_SchedLockTimeMeasStop();
  cpu_sr_restore_irq_iram(uVar7);
  *(undefined1 *)PTR_DAT_0303e074 = 0;
  *(undefined1 *)p_menu_screen_state = 0;
  puVar2 = PTR_DAT_0303e07c;
  *(undefined1 *)PTR_DAT_0303e07c = 0;
  *(undefined1 *)((int)puVar2 + 1) = 7;
  iVar3 = p_menu_navigation_index_table;
  ctx = (void *)(p_menu_navigation_index_table + -0x24);
  memcpy_bytes_iram(p_menu_navigation_index_table,ctx,0x23);
  list = (ushort *)(iVar3 + -0x26);
  *(char *)(iVar3 + 0x2bd) = (char)*list;
  menu_option_list_dispatch(0x17,list,ctx);
  pdVar6 = p_dialog_history_ui_state;
  pdVar5 = p_dialog_history_ui_state;
  if (*list == 0) {
LAB_0303df98:
    uVar7 = cpu_sr_save_and_disable_irq_iram();
    OS_SchedLockTimeMeasStart();
    cVar1 = *(char *)PTR_OSSchedLockNestingCtr_0303e070;
    *(char *)PTR_OSSchedLockNestingCtr_0303e070 = cVar1 + -1;
    if ((char)(cVar1 + -1) == '\0') {
      OS_SchedLockTimeMeasStop_variant4();
      if (*(short *)PTR_DAT_0303e088 == 0) {
        OS_SchedLockTimeMeasStop();
        cpu_sr_restore_irq_iram(uVar7);
      }
      else {
        OS_SchedLockTimeMeasStop();
        cpu_sr_restore_irq_iram(uVar7);
        irq_disable_save_and_release_reinit();
      }
    }
    else {
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(uVar7);
    }
    tx_gate_write_call_record(0);
    uVar7 = 0;
  }
  else {
    if (p_active_screen_index_list[2] == '\x03') {
      p_dialog_history_ui_state->field_0x1 = 1;
      *(undefined1 *)pdVar6 = 1;
      puVar4 = p_active_screen_index_list;
      p_active_screen_index_list[0x2e2] = 1;
      puVar4[0x2f7] = 1;
      *(undefined1 *)p_active_screen_state_word = 0;
      *(undefined1 *)p_active_screen_flag_0003e5d5 = 1;
    }
    else {
      uVar8 = 0;
      do {
        uVar9 = uVar8 + 1;
        uVar8 = uVar9 & 0xff;
        if (*list <= uVar8) goto LAB_0303df98;
      } while (p_active_screen_index_list[uVar8 + 2] != '\x03');
      p_dialog_history_ui_state->field_0x1 = 1;
      *(undefined1 *)pdVar5 = 1;
      puVar4 = p_active_screen_index_list;
      p_active_screen_index_list[0x2e2] = 1;
      puVar4[0x2f7] = 1;
      *(char *)p_active_screen_state_word = (char)uVar9;
      *(char *)p_active_screen_flag_0003e5d5 = (char)(uVar8 + 1);
      if (8 < (uVar8 + 1 & 0xff)) {
        *(undefined1 *)p_active_screen_flag_0003e5d5 = 8;
      }
    }
    pdVar5 = p_dialog_history_ui_state;
    p_dialog_history_ui_state->index_0x2 = 2;
    pdVar5->field_0x3 = 7;
    uVar7 = cpu_sr_save_and_disable_irq_iram();
    OS_SchedLockTimeMeasStart();
    cVar1 = *(char *)PTR_OSSchedLockNestingCtr_0303e070;
    *(char *)PTR_OSSchedLockNestingCtr_0303e070 = cVar1 + -1;
    if ((char)(cVar1 + -1) == '\0') {
      OS_SchedLockTimeMeasStop_variant4();
      if (*(short *)PTR_DAT_0303e088 == 0) {
        OS_SchedLockTimeMeasStop();
        cpu_sr_restore_irq_iram(uVar7);
        uVar7 = 1;
      }
      else {
        OS_SchedLockTimeMeasStop();
        cpu_sr_restore_irq_iram(uVar7);
        irq_disable_save_and_release_reinit();
        uVar7 = 1;
      }
    }
    else {
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(uVar7);
      uVar7 = 1;
    }
  }
  return uVar7;
}

