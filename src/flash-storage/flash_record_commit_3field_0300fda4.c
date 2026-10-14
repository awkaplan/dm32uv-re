/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flash_record_commit_3field @ 0300fda4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 756 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: flash-storage
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void flash_record_commit_3field
               (byte param_1,uint param_2,undefined1 *param_3,uint param_4,ushort param_5,
               undefined1 *param_6,ushort param_7,ushort param_8,undefined1 *param_9,ushort param_10
               )

{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  undefined1 local_a4 [127];
  byte bStack_25;
  
  param_4 = param_4 & 0xffff;
  uVar14 = (uint)param_7;
  uVar13 = (uint)param_10;
  uVar2 = (param_2 & 0xffff) >> 7 & 0xff;
  param_2 = param_2 & 0x7f;
  uVar6 = param_5 >> 7 & 0xff;
  uVar7 = param_5 & 0x7f;
  uVar8 = param_8 >> 7 & 0xff;
  uVar9 = param_8 & 0x7f;
  uVar3 = cpu_sr_save_and_disable_irq_iram();
  OS_SchedLockTimeMeasStart();
  cVar1 = *(char *)PTR_OSSchedLockNestingCtr_0300feec;
  *(char *)PTR_OSSchedLockNestingCtr_0300feec = cVar1 + '\x01';
  if ((char)(cVar1 + '\x01') == '\x01') {
    OS_SchedLockTimeMeasStart_variant4();
  }
  OS_SchedLockTimeMeasStop();
  cpu_sr_restore_irq_iram(uVar3);
  os_sem_pend_ms(p_ucos_mutex_0003944c,0);
  uVar4 = flash_block_id_resolve_helper1();
  uVar5 = flash_block_id_resolve(param_1);
  if (uVar4 == uVar5) {
    uVar4 = flash_block_id_resolve_helper2(uVar4);
  }
  uVar4 = uVar4 & 0xffff;
  flash_page_tag_write(uVar4,0x7f);
  uVar12 = 0;
  do {
    iVar10 = (uVar12 & 0x1ff) << 7;
    spi_flash_read_seq(uVar5,iVar10,local_a4,0x80);
    if (uVar2 == uVar12) {
      if (0 < (int)(0x80 - param_2)) {
        local_a4[param_2] = *param_3;
        param_3 = param_3 + 1;
        uVar15 = param_4 - 1;
        param_4 = uVar15 & 0xffff;
        if (uVar15 != 0) {
          uVar11 = 0;
          do {
            uVar11 = uVar11 + 1 & 0xff;
            if ((int)(0x80 - param_2) <= (int)uVar11) break;
            local_a4[param_2 + uVar11] = *param_3;
            param_3 = param_3 + 1;
            param_4 = param_4 - 1 & 0xffff;
          } while (uVar11 < uVar15);
        }
      }
    }
    else if ((uVar2 < uVar12) && (param_4 != 0)) {
      if (param_4 < 0x80) {
        uVar15 = 0;
        do {
          local_a4[uVar15] = *param_3;
          param_3 = param_3 + 1;
          uVar15 = uVar15 + 1 & 0xff;
        } while (uVar15 < param_4);
        param_4 = 0;
      }
      else {
        uVar15 = 0;
        do {
          local_a4[uVar15] = *param_3;
          param_3 = param_3 + 1;
          param_4 = param_4 - 1 & 0xffff;
          uVar15 = uVar15 + 1 & 0xff;
        } while (uVar15 != 0x80);
      }
    }
    if (uVar6 == uVar12) {
      if (0 < (int)(0x80 - uVar7)) {
        local_a4[uVar7] = *param_6;
        param_6 = param_6 + 1;
        uVar15 = uVar14 - 1;
        uVar14 = uVar15 & 0xffff;
        if (uVar15 != 0) {
          uVar11 = 0;
          do {
            uVar11 = uVar11 + 1 & 0xff;
            if ((int)(0x80 - uVar7) <= (int)uVar11) break;
            local_a4[uVar7 + uVar11] = *param_6;
            param_6 = param_6 + 1;
            uVar14 = uVar14 - 1 & 0xffff;
          } while (uVar11 < uVar15);
        }
      }
    }
    else if ((uVar6 < uVar12) && (uVar14 != 0)) {
      if (uVar14 < 0x80) {
        uVar15 = 0;
        do {
          local_a4[uVar15] = *param_6;
          param_6 = param_6 + 1;
          uVar15 = uVar15 + 1 & 0xff;
        } while (uVar15 < uVar14);
        uVar14 = 0;
      }
      else {
        uVar15 = 0;
        do {
          local_a4[uVar15] = *param_6;
          param_6 = param_6 + 1;
          uVar14 = uVar14 - 1 & 0xffff;
          uVar15 = uVar15 + 1 & 0xff;
        } while (uVar15 != 0x80);
      }
    }
    if (uVar8 == uVar12) {
      if (0 < (int)(0x80 - uVar9)) {
        local_a4[uVar9] = *param_9;
        param_9 = param_9 + 1;
        uVar15 = uVar13 - 1;
        uVar13 = uVar15 & 0xffff;
        if (uVar15 != 0) {
          uVar11 = 0;
          do {
            uVar11 = uVar11 + 1 & 0xff;
            if ((int)(0x80 - uVar9) <= (int)uVar11) break;
            local_a4[uVar9 + uVar11] = *param_9;
            param_9 = param_9 + 1;
            uVar13 = uVar13 - 1 & 0xffff;
          } while (uVar11 < uVar15);
        }
      }
    }
    else if ((uVar8 < uVar12) && (uVar13 != 0)) {
      if (uVar13 < 0x80) {
        uVar15 = 0;
        do {
          local_a4[uVar15] = *param_9;
          param_9 = param_9 + 1;
          uVar15 = uVar15 + 1 & 0xff;
        } while (uVar15 < uVar13);
        uVar13 = 0;
      }
      else {
        uVar15 = 0;
        do {
          local_a4[uVar15] = *param_9;
          param_9 = param_9 + 1;
          uVar13 = uVar13 - 1 & 0xffff;
          uVar15 = uVar15 + 1 & 0xff;
        } while (uVar15 != 0x80);
      }
    }
    if (uVar12 == 0x1f) {
      bStack_25 = param_1;
      spi_flash_program_pagesplit(uVar4,0xf80,local_a4,0x80);
      goto LAB_03010046;
    }
    spi_flash_program_pagesplit(uVar4,iVar10,local_a4,0x80);
    uVar12 = uVar12 + 1;
    if (uVar12 == 0x20) {
LAB_03010046:
      flash_page_tag_write(uVar5,0);
      flash_page_invalidate_range();
      os_sem_post(p_ucos_mutex_0003944c);
      uVar3 = cpu_sr_save_and_disable_irq_iram();
      OS_SchedLockTimeMeasStart();
      cVar1 = *(char *)PTR_OSSchedLockNestingCtr_03010228;
      *(char *)PTR_OSSchedLockNestingCtr_03010228 = cVar1 + -1;
      if ((char)(cVar1 + -1) == '\0') {
        OS_SchedLockTimeMeasStop_variant4();
        if (*(short *)PTR_DAT_0301022c == 0) {
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
      return;
    }
  } while( true );
}

