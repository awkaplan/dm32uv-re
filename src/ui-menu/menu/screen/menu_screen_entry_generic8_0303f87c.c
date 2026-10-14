/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_screen_entry_generic8 @ 0303f87c (file base 0x03000000; code starts at 0x03001000)
 * Size: 334 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void menu_screen_entry_generic8(void)

{
  char cVar1;
  undefined4 *puVar2;
  menu_screen_state *pmVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined1 *puVar6;
  dialog_history_ui_state *pdVar7;
  undefined *puVar8;
  undefined4 uVar9;
  uint uVar10;
  ushort *list;
  void *ctx;
  
  uVar9 = cpu_sr_save_and_disable_irq_iram();
  OS_SchedLockTimeMeasStart();
  cVar1 = *(char *)PTR_OSSchedLockNestingCtr_0303f9d4;
  *(char *)PTR_OSSchedLockNestingCtr_0303f9d4 = cVar1 + '\x01';
  if ((char)(cVar1 + '\x01') == '\x01') {
    OS_SchedLockTimeMeasStart_variant4();
  }
  OS_SchedLockTimeMeasStop();
  cpu_sr_restore_irq_iram(uVar9);
  puVar2 = PTR_DAT_0303f9d8;
  *(undefined1 *)PTR_DAT_0303f9d8 = 1;
  pmVar3 = p_menu_screen_state;
  *(undefined1 *)p_menu_screen_state = 0;
  puVar4 = PTR_DAT_0303f9e0;
  *(undefined1 *)PTR_DAT_0303f9e0 = 0;
  *(undefined1 *)((int)puVar4 + 1) = 7;
  iVar5 = p_menu_navigation_index_table;
  ctx = (void *)(p_menu_navigation_index_table + -0x24);
  memcpy_bytes_iram(p_menu_navigation_index_table,ctx,0x23);
  list = (ushort *)(iVar5 + -0x26);
  *(char *)(iVar5 + 0x2bd) = (char)*list;
  menu_option_list_dispatch(0x17,list,ctx);
  *(undefined1 *)((int)puVar2 + 1) = 1;
  pmVar3->index_0x1 = 0;
  *(undefined1 *)((int)puVar4 + 2) = 0xe;
  memcpy_bytes_iram(iVar5 + 0x23,ctx,0x23);
  *(char *)(iVar5 + 0x2be) = (char)*list;
  menu_option_list_dispatch(4,list,ctx);
  pdVar7 = p_dialog_history_ui_state;
  if (*list == 0) {
    uVar10 = 0;
  }
  else if (p_active_screen_index_list[2] == '\x03') {
    uVar10 = 0;
  }
  else {
    uVar10 = 0;
    do {
      uVar10 = uVar10 + 1 & 0xff;
      if (*list <= uVar10) break;
    } while (p_active_screen_index_list[uVar10 + 2] != '\x03');
  }
  p_dialog_history_ui_state->field_0x1 = 2;
  *(undefined1 *)pdVar7 = 2;
  puVar6 = p_active_screen_index_list;
  p_active_screen_index_list[0x2e2] = 2;
  puVar6[0x2f7] = 2;
  *(char *)p_active_screen_state_word = (char)uVar10;
  *(char *)p_active_screen_flag_0003e5d5 = (char)uVar10 + '\x01';
  pdVar7->index_0x2 = 3;
  pdVar7->field_0x3 = 0xe;
  uVar9 = cpu_sr_save_and_disable_irq_iram();
  OS_SchedLockTimeMeasStart();
  cVar1 = *(char *)PTR_OSSchedLockNestingCtr_0303f9d4;
  *(char *)PTR_OSSchedLockNestingCtr_0303f9d4 = cVar1 + -1;
  if ((char)(cVar1 + -1) == '\0') {
    OS_SchedLockTimeMeasStop_variant4();
    if (*(short *)PTR_DAT_0303f9f8 == 0) {
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(uVar9);
    }
    else {
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(uVar9);
      irq_disable_save_and_release_reinit();
    }
  }
  else {
    OS_SchedLockTimeMeasStop();
    cpu_sr_restore_irq_iram(uVar9);
  }
  puVar8 = PTR_s_66660501_0303f9fc;
  pdVar7 = p_dialog_history_ui_state;
  p_dialog_history_ui_state->field_0x3 =
       PTR_s_66660501_0303f9fc[(uint)p_dialog_history_ui_state->field_0x3 * 0xc + 0x11];
  uVar10 = *(uint *)(puVar8 + (uint)pdVar7->field_0x3 * 0xc + 0x14);
  *PTR_DAT_0303fa00 = uVar10;
  (*(code *)(uVar10 & 0xfffffffe))();
  return;
}

