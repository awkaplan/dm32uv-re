/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_screen_entry_generic1 @ 0303e0b8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 768 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined4 menu_screen_entry_generic1(void)

{
  char cVar1;
  byte bVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  dialog_history_ui_state *pdVar6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  ushort *puVar10;
  void *pvVar11;
  byte *out_list;
  
  uVar7 = cpu_sr_save_and_disable_irq_iram();
  OS_SchedLockTimeMeasStart();
  cVar1 = *(char *)PTR_OSSchedLockNestingCtr_0303e228;
  *(char *)PTR_OSSchedLockNestingCtr_0303e228 = cVar1 + '\x01';
  if ((char)(cVar1 + '\x01') == '\x01') {
    OS_SchedLockTimeMeasStart_variant4();
  }
  OS_SchedLockTimeMeasStop();
  cpu_sr_restore_irq_iram(uVar7);
  *(undefined1 *)PTR_DAT_0303e22c = 0;
  *(undefined1 *)p_menu_screen_state = 0;
  puVar3 = PTR_DAT_0303e234;
  *(undefined1 *)PTR_DAT_0303e234 = 0;
  *(undefined1 *)((int)puVar3 + 1) = 7;
  iVar4 = p_menu_navigation_index_table;
  pvVar11 = (void *)(p_menu_navigation_index_table + -0x24);
  memcpy_bytes_iram(p_menu_navigation_index_table,pvVar11,0x23);
  puVar10 = (ushort *)(iVar4 + -0x26);
  *(char *)(iVar4 + 0x2bd) = (char)*puVar10;
  menu_option_list_dispatch(0x18,puVar10,pvVar11);
  if (*puVar10 == 0) {
LAB_0303e138:
    uVar7 = cpu_sr_save_and_disable_irq_iram();
    OS_SchedLockTimeMeasStart();
    cVar1 = *(char *)PTR_OSSchedLockNestingCtr_0303e228;
    *(char *)PTR_OSSchedLockNestingCtr_0303e228 = cVar1 + -1;
    if ((char)(cVar1 + -1) == '\0') {
      OS_SchedLockTimeMeasStop_variant4();
      if (*(short *)PTR_DAT_0303e23c == 0) {
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
    if (p_active_screen_index_list[2] == '\x05') {
      uVar8 = 0;
    }
    else {
      uVar8 = 0;
      do {
        uVar8 = uVar8 + 1 & 0xff;
        if (*puVar10 <= uVar8) goto LAB_0303e138;
      } while (p_active_screen_index_list[uVar8 + 2] != '\x05');
    }
    p_menu_screen_state->index_0x1 = (byte)uVar8;
    *(byte *)((int)PTR_DAT_0303e22c + 1) = (byte)uVar8 + 1;
    *(undefined1 *)((int)PTR_DAT_0303e234 + 2) = 0xe;
    iVar4 = DAT_0303e240;
    pvVar11 = (void *)(DAT_0303e240 + -0x47);
    memcpy_bytes_iram(DAT_0303e240,pvVar11,0x23);
    puVar10 = (ushort *)(iVar4 + -0x49);
    *(char *)(iVar4 + 0x29b) = (char)*puVar10;
    menu_option_list_dispatch(0x19,puVar10,pvVar11);
    if (*puVar10 == 0) {
LAB_0303e1e4:
      uVar7 = cpu_sr_save_and_disable_irq_iram();
      OS_SchedLockTimeMeasStart();
      cVar1 = *(char *)PTR_OSSchedLockNestingCtr_0303e228;
      *(char *)PTR_OSSchedLockNestingCtr_0303e228 = cVar1 + -1;
      if ((char)(cVar1 + -1) == '\0') {
        OS_SchedLockTimeMeasStop_variant4();
        if (*(short *)PTR_DAT_0303e23c == 0) {
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
      if (p_active_screen_index_list[2] == '\x01') {
        uVar8 = 0;
      }
      else {
        uVar8 = 0;
        do {
          uVar8 = uVar8 + 1 & 0xff;
          if (*puVar10 <= uVar8) goto LAB_0303e1e4;
        } while (p_active_screen_index_list[uVar8 + 2] != '\x01');
      }
      p_menu_screen_state->index_0x2 = (byte)uVar8;
      *(byte *)(_LAB_0303e3e8 + 2) = (byte)uVar8 + 1;
      *(undefined1 *)(_LAB_0303e3ec + 3) = 0x15;
      iVar4 = _LAB_0303e3f0;
      pvVar11 = (void *)(_LAB_0303e3f0 + -0x6a);
      memcpy_bytes_iram(_LAB_0303e3f0,pvVar11,0x23);
      puVar10 = (ushort *)(iVar4 + -0x6c);
      *(char *)(iVar4 + 0x279) = (char)*puVar10;
      menu_option_list_dispatch(6,puVar10,pvVar11);
      if (*puVar10 == 0) {
LAB_0303e2bc:
        uVar7 = cpu_sr_save_and_disable_irq_iram();
        OS_SchedLockTimeMeasStart();
        cVar1 = *_LAB_0303e3f8;
        *_LAB_0303e3f8 = cVar1 + -1;
        if ((char)(cVar1 + -1) == '\0') {
          OS_SchedLockTimeMeasStop_variant4();
          if (*_LAB_0303e3fc == 0) {
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
        if (*(char *)(_p_active_screen_index_list + 2) == '\x03') {
          uVar8 = 0;
        }
        else {
          uVar8 = 0;
          do {
            uVar8 = uVar8 + 1 & 0xff;
            if (*puVar10 <= uVar8) goto LAB_0303e2bc;
          } while (*(char *)(_p_active_screen_index_list + uVar8 + 2) != '\x03');
        }
        p_menu_screen_state->index_0x3 = (byte)uVar8;
        *(byte *)(_LAB_0303e3e8 + 3) = (byte)uVar8 + 1;
        *(undefined1 *)(_LAB_0303e3ec + 4) = 0x1c;
        iVar4 = _LAB_0303e400;
        out_list = (byte *)(_LAB_0303e400 + -0x8d);
        memcpy_bytes_iram(_LAB_0303e400,out_list,0x23);
        *(char *)(iVar4 + 599) = (char)*(ushort *)(iVar4 + -0x8f);
        iVar5 = _LAB_0303e408;
        uVar8 = *(byte *)(_p_dm32_settings_block04 + 0x30) >> 6 & 1;
        iVar9 = _LAB_0303e408 + uVar8 * 8;
        bVar2 = *(byte *)(iVar9 + 4);
        *_p_active_screen_option_count = bVar2;
        *_p_active_screen_option_ptr_array = *(undefined4 *)(iVar5 + uVar8 * 8);
        *_DAT_0303e414 = *(undefined1 *)(iVar9 + 5);
        build_sequential_index_list((ushort)bVar2,(ushort *)(iVar4 + -0x8f),out_list);
        pdVar6 = p_dialog_history_ui_state;
        p_dialog_history_ui_state->field_0x1 = 4;
        *(undefined1 *)pdVar6 = 4;
        *(undefined1 *)(iVar4 + 0x253) = 4;
        *(undefined1 *)(iVar4 + 0x268) = 4;
        *_p_active_screen_state_word = 2;
        *_p_active_screen_flag_0003e5d5 = 3;
        pdVar6->index_0x2 = 5;
        pdVar6->field_0x3 = 0x1c;
        uVar7 = cpu_sr_save_and_disable_irq_iram();
        OS_SchedLockTimeMeasStart();
        cVar1 = *_LAB_0303e3f8;
        *_LAB_0303e3f8 = cVar1 + -1;
        if ((char)(cVar1 + -1) == '\0') {
          OS_SchedLockTimeMeasStop_variant4();
          if (*_LAB_0303e3fc == 0) {
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
    }
  }
  return uVar7;
}

