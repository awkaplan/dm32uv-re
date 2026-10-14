/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_screen_advance_step_with_scan @ 03036a70 (file base 0x03000000; code starts at 0x03001000)
 * Size: 342 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void menu_screen_advance_step_with_scan(void)

{
  char cVar1;
  ushort *puVar2;
  undefined4 uVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  byte bVar7;
  
  if ((PTR_DAT_03036bdc[2] & 2) == 0) {
    if ((PTR_DAT_03036be0[0x2d] & 4) != 0) {
      write_status_mode_byte_pair(0x4d,0);
    }
    if ((PTR_DAT_03036be4[8] & 0xf0) == 0x10) {
      uVar3 = cpu_sr_save_and_disable_irq_iram();
      OS_SchedLockTimeMeasStart();
      cVar1 = *(char *)PTR_OSSchedLockNestingCtr_03036be8;
      *(char *)PTR_OSSchedLockNestingCtr_03036be8 = cVar1 + '\x01';
      if ((char)(cVar1 + '\x01') == '\x01') {
        OS_SchedLockTimeMeasStart_variant4();
      }
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(uVar3);
      PTR_DAT_03036bec[0x12] = 0;
      p_dialog_history_ui_state->field_0x3 = 7;
      ring_buffer_multi_table_append_and_flush();
      puVar2 = p_active_screen_index_list;
      menu_option_list_dispatch(0x17,p_active_screen_index_list,p_active_screen_index_list + 1);
      if (*puVar2 != 0) {
        uVar6 = (uint)*(byte *)p_active_screen_state_word;
        bVar7 = *(byte *)p_active_screen_flag_0003e5d5;
        bVar4 = 1;
        uVar5 = 0;
        do {
          if ((*(char *)((int)p_active_screen_index_list + uVar5 + 2) == '\x04') &&
             (uVar6 = uVar5, bVar7 = bVar4, 8 < bVar4)) {
            bVar7 = 8;
          }
          uVar5 = uVar5 + 1 & 0xff;
          bVar4 = bVar4 + 1;
        } while (uVar5 < *puVar2);
        *(char *)p_active_screen_state_word = (char)uVar6;
        *(byte *)p_active_screen_flag_0003e5d5 = bVar7;
      }
      p_dialog_history_ui_state->field_0x3 = 0xe;
      ring_buffer_multi_table_append_and_flush();
      *(undefined *)PTR_active_screen_option_count_03036bf8 =
           PTR_PTR_03036bf4[((byte)PTR_DAT_03036bf0[0x30] >> 6 & 1) * 8 + 4];
      menu_option_list_dispatch(5,p_active_screen_index_list,p_active_screen_index_list + 1);
      *(undefined1 *)p_active_screen_state_word = 0;
      *(undefined1 *)p_active_screen_flag_0003e5d5 = 1;
      uVar3 = cpu_sr_save_and_disable_irq_iram();
      OS_SchedLockTimeMeasStart();
      cVar1 = *(char *)PTR_OSSchedLockNestingCtr_03036be8;
      *(char *)PTR_OSSchedLockNestingCtr_03036be8 = cVar1 + -1;
      if ((char)(cVar1 + -1) == '\0') {
        OS_SchedLockTimeMeasStop_variant4();
        if (*(short *)PTR_DAT_03036bfc == 0) {
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
      write_status_mode_byte_pair(0x15,1);
    }
  }
  else {
    write_status_mode_byte_pair(0x4d,0);
  }
  return;
}

