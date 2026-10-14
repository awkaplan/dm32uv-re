/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flash_block_write @ 0300f878 (file base 0x03000000; code starts at 0x03001000)
 * Size: 420 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: flash-storage
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void flash_block_write(int param_1__w,uint param_2,undefined1 *param_3,uint param_4)

{
  byte param_1 = (byte)param_1__w;
  char cVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  undefined1 local_a4 [127];
  byte bStack_25;
  
  param_4 = param_4 & 0xffff;
  uVar6 = (param_2 & 0xffff) >> 7 & 0xff;
  param_2 = param_2 & 0x7f;
  uVar2 = cpu_sr_save_and_disable_irq_iram();
  OS_SchedLockTimeMeasStart();
  cVar1 = *(char *)PTR_OSSchedLockNestingCtr_0300fa1c;
  *(char *)PTR_OSSchedLockNestingCtr_0300fa1c = cVar1 + '\x01';
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
  uVar8 = 0;
  do {
    iVar9 = (uVar8 & 0x1ff) << 7;
    spi_flash_read_seq(uVar4,iVar9,local_a4,0x80);
    if (uVar6 == uVar8) {
      if (0 < (int)(0x80 - param_2)) {
        local_a4[param_2] = *param_3;
        param_3 = param_3 + 1;
        uVar5 = param_4 - 1;
        param_4 = uVar5 & 0xffff;
        if (uVar5 != 0) {
          uVar7 = 0;
          do {
            uVar7 = uVar7 + 1 & 0xff;
            if ((int)(0x80 - param_2) <= (int)uVar7) break;
            local_a4[uVar7 + param_2] = *param_3;
            param_3 = param_3 + 1;
            param_4 = param_4 - 1 & 0xffff;
          } while (uVar7 < uVar5);
        }
      }
    }
    else if ((uVar6 < uVar8) && (param_4 != 0)) {
      if (param_4 < 0x80) {
        uVar5 = 0;
        do {
          local_a4[uVar5] = *param_3;
          param_3 = param_3 + 1;
          uVar5 = uVar5 + 1 & 0xff;
        } while (uVar5 < param_4);
        param_4 = 0;
      }
      else {
        uVar5 = 0;
        do {
          local_a4[uVar5] = *param_3;
          param_3 = param_3 + 1;
          param_4 = param_4 - 1 & 0xffff;
          uVar5 = uVar5 + 1 & 0xff;
        } while (uVar5 != 0x80);
      }
    }
    if (uVar8 == 0x1f) {
      bStack_25 = param_1;
      spi_flash_program_pagesplit(uVar3,0xf80,local_a4,0x80);
      goto LAB_0300f9b4;
    }
    spi_flash_program_pagesplit(uVar3,iVar9,local_a4,0x80);
    uVar8 = uVar8 + 1;
    if (uVar8 == 0x20) {
LAB_0300f9b4:
      flash_page_tag_write(uVar3,param_1);
      flash_page_tag_write(uVar4,0);
      flash_page_invalidate_range();
      os_sem_post(p_ucos_mutex_0003944c);
      uVar2 = cpu_sr_save_and_disable_irq_iram();
      OS_SchedLockTimeMeasStart();
      cVar1 = *(char *)PTR_OSSchedLockNestingCtr_0300fa1c;
      *(char *)PTR_OSSchedLockNestingCtr_0300fa1c = cVar1 + -1;
      if ((char)(cVar1 + -1) == '\0') {
        OS_SchedLockTimeMeasStop_variant4();
        if (*(short *)PTR_DAT_0300fa24 == 0) {
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

