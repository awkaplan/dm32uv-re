/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_screen_entry_generic7 @ 0303f6a4 (file base 0x03000000; code starts at 0x03001000)
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

undefined4 menu_screen_entry_generic7(void)

{
  char cVar1;
  dialog_history_ui_state *pdVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  ushort *list;
  void *ctx;
  byte *out_list;
  
  uVar5 = cpu_sr_save_and_disable_irq_iram();
  OS_SchedLockTimeMeasStart();
  cVar1 = *(char *)PTR_OSSchedLockNestingCtr_0303f824;
  *(char *)PTR_OSSchedLockNestingCtr_0303f824 = cVar1 + '\x01';
  if ((char)(cVar1 + '\x01') == '\x01') {
    OS_SchedLockTimeMeasStart_variant4();
  }
  OS_SchedLockTimeMeasStop();
  cpu_sr_restore_irq_iram(uVar5);
  *(undefined1 *)PTR_DAT_0303f828 = 0;
  *(undefined1 *)p_menu_screen_state = 0;
  puVar3 = PTR_DAT_0303f830;
  *(undefined1 *)PTR_DAT_0303f830 = 0;
  *(undefined1 *)((int)puVar3 + 1) = 7;
  iVar4 = p_menu_navigation_index_table;
  ctx = (void *)(p_menu_navigation_index_table + -0x24);
  memcpy_bytes_iram(p_menu_navigation_index_table,ctx,0x23);
  list = (ushort *)(iVar4 + -0x26);
  *(char *)(iVar4 + 0x2bd) = (char)*list;
  menu_option_list_dispatch(0x17,list,ctx);
  if (*list == 0) {
LAB_0303f724:
    uVar5 = cpu_sr_save_and_disable_irq_iram();
    OS_SchedLockTimeMeasStart();
    cVar1 = *(char *)PTR_OSSchedLockNestingCtr_0303f824;
    *(char *)PTR_OSSchedLockNestingCtr_0303f824 = cVar1 + -1;
    if ((char)(cVar1 + -1) == '\0') {
      OS_SchedLockTimeMeasStop_variant4();
      if (*(short *)PTR_DAT_0303f838 == 0) {
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
    tx_gate_write_call_record(0);
    uVar5 = 0;
  }
  else {
    if (p_active_screen_index_list[2] == '\0') {
      uVar6 = 0;
    }
    else {
      uVar6 = 0;
      do {
        uVar6 = uVar6 + 1 & 0xff;
        if (*list <= uVar6) goto LAB_0303f724;
      } while (p_active_screen_index_list[uVar6 + 2] != '\0');
    }
    p_menu_screen_state->index_0x1 = (byte)uVar6;
    *(byte *)((int)PTR_DAT_0303f828 + 1) = (byte)uVar6 + 1;
    *(undefined1 *)((int)PTR_DAT_0303f830 + 2) = 0xe;
    iVar4 = DAT_0303f83c;
    out_list = (byte *)(DAT_0303f83c + -0x47);
    memcpy_bytes_iram(DAT_0303f83c,out_list,0x23);
    *(char *)(iVar4 + 0x29b) = (char)*(ushort *)(iVar4 + -0x49);
    build_sequential_index_list
              ((ushort)(byte)PTR_PTR_0303f844
                             [((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8 + 4],
               (ushort *)(iVar4 + -0x49),out_list);
    pdVar2 = p_dialog_history_ui_state;
    p_dialog_history_ui_state->field_0x1 = 2;
    *(undefined1 *)pdVar2 = 2;
    *(undefined1 *)(iVar4 + 0x299) = 2;
    *(undefined1 *)(iVar4 + 0x2ae) = 2;
    *(undefined1 *)p_active_screen_state_word = 0;
    *(undefined1 *)p_active_screen_flag_0003e5d5 = 1;
    pdVar2->index_0x2 = 3;
    pdVar2->field_0x3 = 0xe;
    uVar5 = cpu_sr_save_and_disable_irq_iram();
    OS_SchedLockTimeMeasStart();
    cVar1 = *(char *)PTR_OSSchedLockNestingCtr_0303f824;
    *(char *)PTR_OSSchedLockNestingCtr_0303f824 = cVar1 + -1;
    if ((char)(cVar1 + -1) == '\0') {
      OS_SchedLockTimeMeasStop_variant4();
      if (*(short *)PTR_DAT_0303f838 == 0) {
        OS_SchedLockTimeMeasStop();
        cpu_sr_restore_irq_iram(uVar5);
        uVar5 = 1;
      }
      else {
        OS_SchedLockTimeMeasStop();
        cpu_sr_restore_irq_iram(uVar5);
        irq_disable_save_and_release_reinit();
        uVar5 = 1;
      }
    }
    else {
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(uVar5);
      uVar5 = 1;
    }
  }
  return uVar5;
}

