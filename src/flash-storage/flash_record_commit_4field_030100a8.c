/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flash_record_commit_4field @ 030100a8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 1018 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: flash-storage
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void flash_record_commit_4field
               (byte param_1,uint param_2,undefined1 *param_3,uint param_4,ushort param_5,
               undefined1 *param_6,ushort param_7,ushort param_8,undefined1 *param_9,ushort param_10
               ,ushort param_11,undefined1 *param_12,ushort param_13)

{
  char cVar1;
  undefined2 uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uStack_e8;
  uint uStack_e4;
  undefined1 local_a4 [127];
  byte bStack_25;
  
  uStack_e8 = param_4 & 0xffff;
  uStack_e4 = (uint)param_7;
  uVar15 = (uint)param_10;
  uVar14 = (uint)param_13;
  uVar16 = (param_2 & 0xffff) >> 7 & 0xff;
  param_2 = param_2 & 0x7f;
  uVar6 = param_5 >> 7 & 0xff;
  uVar7 = param_5 & 0x7f;
  uVar8 = param_8 >> 7 & 0xff;
  uVar9 = param_8 & 0x7f;
  uVar10 = param_11 >> 7 & 0xff;
  uVar3 = param_11 & 0x7f;
  uVar4 = cpu_sr_save_and_disable_irq_iram();
  OS_SchedLockTimeMeasStart();
  cVar1 = *(char *)PTR_OSSchedLockNestingCtr_03010228;
  *(char *)PTR_OSSchedLockNestingCtr_03010228 = cVar1 + '\x01';
  if ((char)(cVar1 + '\x01') == '\x01') {
    OS_SchedLockTimeMeasStart_variant4();
  }
  OS_SchedLockTimeMeasStop();
  cpu_sr_restore_irq_iram(uVar4);
  os_sem_pend_ms(p_ucos_mutex_0003944c,0);
  uVar2 = flash_block_id_resolve_helper1();
  iVar5 = flash_block_id_resolve(param_1);
  flash_page_tag_write(uVar2,0x7f);
  uVar13 = 0;
  do {
    iVar11 = (uVar13 & 0x1ff) << 7;
    spi_flash_read_seq(iVar5,iVar11,local_a4,0x80);
    if (uVar16 == uVar13) {
      if (0 < (int)(0x80 - param_2)) {
        local_a4[param_2] = *param_3;
        param_3 = param_3 + 1;
        uVar17 = uStack_e8 - 1;
        uStack_e8 = uVar17 & 0xffff;
        if (uVar17 != 0) {
          uVar12 = 0;
          do {
            uVar12 = uVar12 + 1 & 0xff;
            if ((int)(0x80 - param_2) <= (int)uVar12) break;
            local_a4[param_2 + uVar12] = *param_3;
            param_3 = param_3 + 1;
            uStack_e8 = uStack_e8 - 1 & 0xffff;
          } while (uVar12 < uVar17);
        }
      }
    }
    else if ((uVar16 < uVar13) && (uStack_e8 != 0)) {
      if (uStack_e8 < 0x80) {
        uVar17 = 0;
        do {
          local_a4[uVar17] = *param_3;
          param_3 = param_3 + 1;
          uVar17 = uVar17 + 1 & 0xff;
        } while (uVar17 < uStack_e8);
        uStack_e8 = 0;
      }
      else {
        uVar17 = 0;
        do {
          local_a4[uVar17] = *param_3;
          param_3 = param_3 + 1;
          uStack_e8 = uStack_e8 - 1 & 0xffff;
          uVar17 = uVar17 + 1 & 0xff;
        } while (uVar17 != 0x80);
      }
    }
    if (uVar6 == uVar13) {
      if (0 < (int)(0x80 - uVar7)) {
        local_a4[uVar7] = *param_6;
        param_6 = param_6 + 1;
        uVar17 = uStack_e4 - 1;
        uStack_e4 = uVar17 & 0xffff;
        if (uVar17 != 0) {
          uVar12 = 0;
          do {
            uVar12 = uVar12 + 1 & 0xff;
            if ((int)(0x80 - uVar7) <= (int)uVar12) break;
            local_a4[uVar7 + uVar12] = *param_6;
            param_6 = param_6 + 1;
            uStack_e4 = uStack_e4 - 1 & 0xffff;
          } while (uVar12 < uVar17);
        }
      }
    }
    else if ((uVar6 < uVar13) && (uStack_e4 != 0)) {
      if (uStack_e4 < 0x80) {
        uVar17 = 0;
        do {
          local_a4[uVar17] = *param_6;
          param_6 = param_6 + 1;
          uVar17 = uVar17 + 1 & 0xff;
        } while (uVar17 < uStack_e4);
        uStack_e4 = 0;
      }
      else {
        uVar17 = 0;
        do {
          local_a4[uVar17] = *param_6;
          param_6 = param_6 + 1;
          uStack_e4 = uStack_e4 - 1 & 0xffff;
          uVar17 = uVar17 + 1 & 0xff;
        } while (uVar17 != 0x80);
      }
    }
    if (uVar8 == uVar13) {
      if (0 < (int)(0x80 - uVar9)) {
        local_a4[uVar9] = *param_9;
        param_9 = param_9 + 1;
        uVar17 = uVar15 - 1;
        uVar15 = uVar17 & 0xffff;
        if (uVar17 != 0) {
          uVar12 = 0;
          do {
            uVar12 = uVar12 + 1 & 0xff;
            if ((int)(0x80 - uVar9) <= (int)uVar12) break;
            local_a4[uVar9 + uVar12] = *param_9;
            param_9 = param_9 + 1;
            uVar15 = uVar15 - 1 & 0xffff;
          } while (uVar12 < uVar17);
        }
      }
    }
    else if ((uVar8 < uVar13) && (uVar15 != 0)) {
      if (uVar15 < 0x80) {
        uVar17 = 0;
        do {
          local_a4[uVar17] = *param_9;
          param_9 = param_9 + 1;
          uVar17 = uVar17 + 1 & 0xff;
        } while (uVar17 < uVar15);
        uVar15 = 0;
      }
      else {
        uVar17 = 0;
        do {
          local_a4[uVar17] = *param_9;
          param_9 = param_9 + 1;
          uVar15 = uVar15 - 1 & 0xffff;
          uVar17 = uVar17 + 1 & 0xff;
        } while (uVar17 != 0x80);
      }
    }
    if (uVar10 == uVar13) {
      if (0 < (int)(0x80 - uVar3)) {
        local_a4[uVar3] = *param_12;
        param_12 = param_12 + 1;
        uVar17 = uVar14 - 1;
        uVar14 = uVar17 & 0xffff;
        if (uVar17 != 0) {
          uVar12 = 0;
          do {
            uVar12 = uVar12 + 1 & 0xff;
            if ((int)(0x80 - uVar3) <= (int)uVar12) break;
            local_a4[uVar3 + uVar12] = *param_12;
            param_12 = param_12 + 1;
            uVar14 = uVar14 - 1 & 0xffff;
          } while (uVar12 < uVar17);
        }
      }
    }
    else if ((uVar10 < uVar13) && (uVar14 != 0)) {
      if (uVar14 < 0x80) {
        uVar17 = 0;
        do {
          local_a4[uVar17] = *param_12;
          param_12 = param_12 + 1;
          uVar17 = uVar17 + 1 & 0xff;
        } while (uVar17 < uVar14);
        uVar14 = 0;
      }
      else {
        uVar17 = 0;
        do {
          local_a4[uVar17] = *param_12;
          param_12 = param_12 + 1;
          uVar14 = uVar14 - 1 & 0xffff;
          uVar17 = uVar17 + 1 & 0xff;
        } while (uVar17 != 0x80);
      }
    }
    if (uVar13 == 0x1f) {
      bStack_25 = param_1;
      spi_flash_program_pagesplit(uVar2,0xf80,local_a4,0x80);
      goto LAB_03010450;
    }
    spi_flash_program_pagesplit(uVar2,iVar11,local_a4,0x80);
    uVar13 = uVar13 + 1;
    if (uVar13 == 0x20) {
LAB_03010450:
      flash_page_tag_write(iVar5,0);
      flash_page_invalidate_range();
      os_sem_post(p_ucos_mutex_0003944c);
      uVar4 = cpu_sr_save_and_disable_irq_iram();
      OS_SchedLockTimeMeasStart();
      cVar1 = *(char *)PTR_OSSchedLockNestingCtr_030105b8;
      *(char *)PTR_OSSchedLockNestingCtr_030105b8 = cVar1 + -1;
      if ((char)(cVar1 + -1) == '\0') {
        OS_SchedLockTimeMeasStop_variant4();
        if (*(short *)PTR_DAT_030105bc == 0) {
          OS_SchedLockTimeMeasStop();
          cpu_sr_restore_irq_iram(uVar4);
        }
        else {
          OS_SchedLockTimeMeasStop();
          cpu_sr_restore_irq_iram(uVar4);
          irq_disable_save_and_release_reinit();
        }
      }
      else {
        OS_SchedLockTimeMeasStop();
        cpu_sr_restore_irq_iram(uVar4);
      }
      return;
    }
  } while( true );
}

