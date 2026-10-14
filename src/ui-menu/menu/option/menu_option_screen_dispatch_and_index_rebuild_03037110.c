/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_option_screen_dispatch_and_index_rebuild @ 03037110 (file base 0x03000000; code starts at 0x03001000)
 * Size: 518 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-menu
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void menu_option_screen_dispatch_and_index_rebuild(void)

{
  char cVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  byte bVar9;
  uint uVar10;
  uint uVar11;
  byte bVar12;
  undefined1 auStack_58 [8];
  byte bStack_50;
  
  FUN_0002dea4(auStack_58);
  if ((PTR_DAT_030372c8[0x16] & 1) == 0) {
    if ((bStack_50 & 0xf0) == 0x10) {
      uVar8 = cpu_sr_save_and_disable_irq_iram();
      OS_SchedLockTimeMeasStart();
      cVar1 = *(char *)PTR_OSSchedLockNestingCtr_030372f0;
      *(char *)PTR_OSSchedLockNestingCtr_030372f0 = cVar1 + '\x01';
      if ((char)(cVar1 + '\x01') == '\x01') {
        OS_SchedLockTimeMeasStart_variant4();
      }
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(uVar8);
      reentrant_state_reset_sequence();
      PTR_DAT_030372d8[3] = 7;
      ring_buffer_multi_table_append_and_flush();
      puVar4 = PTR_active_screen_index_list_030372f4;
      menu_option_list_dispatch
                (0x17,PTR_active_screen_index_list_030372f4,
                 (void *)((int)PTR_active_screen_index_list_030372f4 + 2));
      if (*(ushort *)puVar4 != 0) {
        uVar11 = (uint)*(byte *)PTR_active_screen_state_word_030372f8;
        bVar12 = *(byte *)PTR_active_screen_flag_0003e5d5_030372fc;
        bVar9 = 1;
        uVar10 = 0;
        do {
          if ((*(char *)((int)PTR_active_screen_index_list_030372f4 + uVar10 + 2) == '\x03') &&
             (uVar11 = uVar10, bVar12 = bVar9, 8 < bVar9)) {
            bVar12 = 8;
          }
          uVar10 = uVar10 + 1 & 0xff;
          bVar9 = bVar9 + 1;
        } while (uVar10 < *(ushort *)puVar4);
        *(char *)PTR_active_screen_state_word_030372f8 = (char)uVar11;
        *(byte *)PTR_active_screen_flag_0003e5d5_030372fc = bVar12;
      }
      puVar3 = PTR_DAT_030372d8;
      PTR_DAT_030372d8[3] = 0xe;
      ring_buffer_multi_table_append_and_flush();
      puVar5 = PTR_active_screen_state_word_030372f8;
      *(undefined1 *)PTR_active_screen_state_word_030372f8 = 0;
      puVar6 = PTR_active_screen_flag_0003e5d5_030372fc;
      *(undefined1 *)PTR_active_screen_flag_0003e5d5_030372fc = 1;
      puVar7 = PTR_active_screen_option_count_03037304;
      puVar2 = PTR_DAT_030372cc;
      bVar12 = PTR_PTR_03037300[((byte)PTR_DAT_030372cc[0x30] >> 6 & 1) * 8 + 4];
      *(byte *)PTR_active_screen_option_count_03037304 = bVar12;
      puVar4 = PTR_active_screen_index_list_030372f4;
      build_sequential_index_list
                ((ushort)bVar12,(ushort *)PTR_active_screen_index_list_030372f4,DAT_03037308);
      puVar3[3] = 0x15;
      ring_buffer_multi_table_append_and_flush();
      *(undefined1 *)puVar5 = 0;
      *(undefined1 *)puVar6 = 1;
      bVar12 = PTR_PTR_0303730c[((byte)puVar2[0x30] >> 6 & 1) * 8 + 4];
      *(byte *)puVar7 = bVar12;
      build_sequential_index_list((ushort)bVar12,(ushort *)puVar4,DAT_03037308);
      puVar3[3] = 0x1c;
      ring_buffer_multi_table_append_and_flush();
      *(undefined1 *)puVar5 = 0;
      *(undefined1 *)puVar6 = 1;
      *(char *)PTR_DAT_03037310 = (char)*(undefined2 *)puVar4;
      *(undefined2 *)puVar4 = 0;
      *(undefined1 *)puVar7 = PTR_DAT_03037314[4];
      *(undefined1 *)PTR_DAT_03037318 = 1;
      uVar8 = cpu_sr_save_and_disable_irq_iram();
      OS_SchedLockTimeMeasStart();
      cVar1 = *(char *)PTR_OSSchedLockNestingCtr_030372f0;
      *(char *)PTR_OSSchedLockNestingCtr_030372f0 = cVar1 + -1;
      if ((char)(cVar1 + -1) == '\0') {
        OS_SchedLockTimeMeasStop_variant4();
        if (*(short *)PTR_DAT_0303731c == 0) {
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
      write_status_mode_byte_pair(0x23,1);
    }
    else {
      ui_event_notify(0x1b);
      dialog_show_icon_and_two_numbers
                (0x30,0x30,PTR_DAT_030374f8,
                 **(undefined4 **)(PTR_PTR_030374f4 + ((byte)PTR_DAT_030374f0[0x30] >> 6 & 1) * 8),
                 (*(undefined4 **)(PTR_PTR_030374f4 + ((byte)PTR_DAT_030374f0[0x30] >> 6 & 1) * 8))
                 [1]);
      OSTimeDly_ms_wrapper(1000);
      history_queue_pop();
    }
  }
  else {
    history_queue_pop();
    PTR_DAT_030372c8[0x16] = PTR_DAT_030372c8[0x16] & 0xfe;
    puVar2 = PTR_DAT_030372e8;
    PTR_DAT_030372e8[1] = PTR_DAT_030372e8[1] & 0xf7;
    puVar2[0x2d] = puVar2[0x2d] & 0xf3;
    *(byte *)PTR_DAT_030372ec = *(byte *)PTR_DAT_030372ec & 0x7f;
  }
  return;
}

