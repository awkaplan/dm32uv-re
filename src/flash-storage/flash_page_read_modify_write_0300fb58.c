/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flash_page_read_modify_write @ 0300fb58 (file base 0x03000000; code starts at 0x03001000)
 * Size: 574 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: flash-storage
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void flash_page_read_modify_write
               (byte param_1,uint param_2,undefined1 *param_3,uint param_4,ushort param_5,
               undefined1 *param_6,ushort param_7)

{
  char cVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  undefined1 local_a4 [127];
  byte bStack_25;
  
  param_4 = param_4 & 0xffff;
  uVar11 = (uint)param_7;
  uVar5 = param_5 >> 7 & 0xff;
  uVar6 = param_5 & 0x7f;
  uVar7 = (param_2 & 0xffff) >> 7 & 0xff;
  param_2 = param_2 & 0x7f;
  uVar2 = cpu_sr_save_and_disable_irq_iram();
  OS_SchedLockTimeMeasStart();
  cVar1 = *(char *)PTR_OSSchedLockNestingCtr_0300fc28;
  *(char *)PTR_OSSchedLockNestingCtr_0300fc28 = cVar1 + '\x01';
  if ((char)(cVar1 + '\x01') == '\x01') {
    OS_SchedLockTimeMeasStart_variant4();
  }
  OS_SchedLockTimeMeasStop();
  cpu_sr_restore_irq_iram(uVar2);
  os_sem_pend_ms(p_ucos_mutex_0003944c,0);
  uVar3 = flash_block_id_resolve_helper1();
  uVar4 = flash_block_id_resolve(param_1);
  if (uVar3 == uVar4) {
    uVar3 = flash_block_id_resolve_helper2(uVar3);
  }
  uVar3 = uVar3 & 0xffff;
  flash_page_tag_write(uVar3,0x7f);
  uVar10 = 0;
  do {
    iVar8 = (uVar10 & 0x1ff) << 7;
    spi_flash_read_seq(uVar4,iVar8,local_a4,0x80);
    if (uVar7 == uVar10) {
      if (0 < (int)(0x80 - param_2)) {
        local_a4[param_2] = *param_3;
        param_3 = param_3 + 1;
        uVar12 = param_4 - 1;
        param_4 = uVar12 & 0xffff;
        if (uVar12 != 0) {
          uVar9 = 0;
          do {
            uVar9 = uVar9 + 1 & 0xff;
            if ((int)(0x80 - param_2) <= (int)uVar9) break;
            local_a4[param_2 + uVar9] = *param_3;
            param_3 = param_3 + 1;
            param_4 = param_4 - 1 & 0xffff;
          } while (uVar9 < uVar12);
        }
      }
    }
    else if ((uVar7 < uVar10) && (param_4 != 0)) {
      if (param_4 < 0x80) {
        uVar12 = 0;
        do {
          local_a4[uVar12] = *param_3;
          param_3 = param_3 + 1;
          uVar12 = uVar12 + 1 & 0xff;
        } while (uVar12 < param_4);
        param_4 = 0;
      }
      else {
        uVar12 = 0;
        do {
          local_a4[uVar12] = *param_3;
          param_3 = param_3 + 1;
          param_4 = param_4 - 1 & 0xffff;
          uVar12 = uVar12 + 1 & 0xff;
        } while (uVar12 != 0x80);
      }
    }
    if (uVar5 == uVar10) {
      if (0 < (int)(0x80 - uVar6)) {
        local_a4[uVar6] = *param_6;
        param_6 = param_6 + 1;
        uVar12 = uVar11 - 1;
        uVar11 = uVar12 & 0xffff;
        if (uVar12 != 0) {
          uVar9 = 0;
          do {
            uVar9 = uVar9 + 1 & 0xff;
            if ((int)(0x80 - uVar6) <= (int)uVar9) break;
            local_a4[uVar6 + uVar9] = *param_6;
            param_6 = param_6 + 1;
            uVar11 = uVar11 - 1 & 0xffff;
          } while (uVar9 < uVar12);
        }
      }
    }
    else if ((uVar5 < uVar10) && (uVar11 != 0)) {
      if (uVar11 < 0x80) {
        uVar12 = 0;
        do {
          local_a4[uVar12] = *param_6;
          param_6 = param_6 + 1;
          uVar12 = uVar12 + 1 & 0xff;
        } while (uVar12 < uVar11);
        uVar11 = 0;
      }
      else {
        uVar12 = 0;
        do {
          local_a4[uVar12] = *param_6;
          param_6 = param_6 + 1;
          uVar11 = uVar11 - 1 & 0xffff;
          uVar12 = uVar12 + 1 & 0xff;
        } while (uVar12 != 0x80);
      }
    }
    if (uVar10 == 0x1f) {
      bStack_25 = param_1;
      spi_flash_program_pagesplit(uVar3,0xf80,local_a4,0x80);
      goto LAB_0300fd42;
    }
    spi_flash_program_pagesplit(uVar3,iVar8,local_a4,0x80);
    uVar10 = uVar10 + 1;
    if (uVar10 == 0x20) {
LAB_0300fd42:
      flash_page_tag_write(uVar4,0);
      flash_page_invalidate_range();
      os_sem_post(p_ucos_mutex_0003944c);
      uVar2 = cpu_sr_save_and_disable_irq_iram();
      OS_SchedLockTimeMeasStart();
      cVar1 = *(char *)PTR_OSSchedLockNestingCtr_0300feec;
      *(char *)PTR_OSSchedLockNestingCtr_0300feec = cVar1 + -1;
      if ((char)(cVar1 + -1) == '\0') {
        OS_SchedLockTimeMeasStop_variant4();
        if (*(short *)PTR_DAT_0300fef0 == 0) {
          OS_SchedLockTimeMeasStop();
          cpu_sr_restore_irq_iram(uVar2);
        }
        else {
          OS_SchedLockTimeMeasStop();
          cpu_sr_restore_irq_iram(uVar2);
          irq_disable_save_and_release_reinit();
        }
      }
      else {
        OS_SchedLockTimeMeasStop();
        cpu_sr_restore_irq_iram(uVar2);
      }
      return;
    }
  } while( true );
}

