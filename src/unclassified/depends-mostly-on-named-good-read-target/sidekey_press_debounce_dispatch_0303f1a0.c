/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: sidekey_press_debounce_dispatch @ 0303f1a0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 352 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4 sidekey_press_debounce_dispatch(void)

{
  char cVar1;
  dialog_history_ui_state *pdVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  byte *out_list;
  
  uVar5 = cpu_sr_save_and_disable_irq_iram();
  OS_SchedLockTimeMeasStart();
  cVar1 = *(char *)PTR_OSSchedLockNestingCtr_0303f304;
  *(char *)PTR_OSSchedLockNestingCtr_0303f304 = cVar1 + '\x01';
  if ((char)(cVar1 + '\x01') == '\x01') {
    OS_SchedLockTimeMeasStart_variant4();
  }
  OS_SchedLockTimeMeasStop();
  cpu_sr_restore_irq_iram(uVar5);
  *(undefined1 *)PTR_DAT_0303f308 = 0;
  *(undefined1 *)p_menu_screen_state = 0;
  puVar4 = PTR_DAT_0303f310;
  *(undefined1 *)PTR_DAT_0303f310 = 0;
  *(undefined1 *)((int)puVar4 + 1) = 7;
  iVar6 = p_menu_navigation_index_table;
  memcpy_bytes_iram(p_menu_navigation_index_table,p_menu_navigation_index_table + -0x24,0x23);
  *(char *)(iVar6 + 0x2bd) = (char)*(undefined2 *)(iVar6 + -0x26);
  iVar6 = vfo_active_side_mode_nibble();
  puVar3 = p_active_screen_index_list;
  if (iVar6 == 0) {
    uVar7 = 0x18;
  }
  else if (iVar6 == 2) {
    uVar7 = 0x18;
  }
  else {
    uVar7 = 0x17;
  }
  menu_option_list_dispatch(uVar7,p_active_screen_index_list,p_active_screen_index_list + 2);
  if ((*(ushort *)puVar3 == 0) || (puVar3[2] == '\b')) {
    p_menu_screen_state->index_0x1 = 0;
    PTR_DAT_0303f49c[1] = 1;
  }
  else {
    uVar7 = 0;
    do {
      uVar8 = uVar7 + 1;
      uVar7 = uVar8 & 0xff;
      if (*(ushort *)puVar3 <= uVar7) break;
    } while (puVar3[uVar7 + 2] != '\b');
    p_menu_screen_state->index_0x1 = (byte)uVar8;
    *(char *)((int)PTR_DAT_0303f308 + 1) = (char)(uVar7 + 1);
    if (8 < (uVar7 + 1 & 0xff)) {
      *(undefined1 *)((int)PTR_DAT_0303f308 + 1) = 8;
    }
  }
  iVar6 = DAT_0303f318;
  out_list = (byte *)(DAT_0303f318 + -0x47);
  memcpy_bytes_iram(DAT_0303f318,out_list,0x23);
  *(char *)(iVar6 + 0x29b) = (char)*(ushort *)(iVar6 + -0x49);
  build_sequential_index_list
            ((ushort)(byte)PTR_PTR_0303f320[((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8 + 4],
             (ushort *)(iVar6 + -0x49),out_list);
  pdVar2 = p_dialog_history_ui_state;
  p_dialog_history_ui_state->field_0x1 = 2;
  *(undefined1 *)pdVar2 = 2;
  *(undefined1 *)(iVar6 + 0x299) = 2;
  *(undefined1 *)(iVar6 + 0x2ae) = 2;
  *(undefined1 *)p_active_screen_state_word = 1;
  *(undefined1 *)p_active_screen_flag_0003e5d5 = 2;
  pdVar2->index_0x2 = 3;
  pdVar2->field_0x3 = 0xe;
  *(undefined1 *)((int)PTR_DAT_0303f310 + 2) = 0xe;
  uVar5 = cpu_sr_save_and_disable_irq_iram();
  OS_SchedLockTimeMeasStart();
  cVar1 = *(char *)PTR_OSSchedLockNestingCtr_0303f304;
  *(char *)PTR_OSSchedLockNestingCtr_0303f304 = cVar1 + -1;
  if ((char)(cVar1 + -1) == '\0') {
    OS_SchedLockTimeMeasStop_variant4();
    if (*(short *)PTR_DAT_0303f324 == 0) {
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
  return 1;
}

