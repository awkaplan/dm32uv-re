/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: rf_frequency_adjust_and_display_refresh @ 0302fcd0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 360 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rf-frontend
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void rf_frequency_adjust_and_display_refresh(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  undefined1 auStack_20 [16];
  
  uVar3 = _DAT_0302fe1c;
  uVar5 = CONCAT22(*(undefined2 *)PTR_DAT_0302fe20,*(undefined2 *)PTR_DAT_0302fe24);
  uVar4 = *PTR_DAT_0302fdfc;
  if (uVar4 < uVar5) {
    uVar4 = uVar5 - uVar4;
  }
  else {
    uVar4 = uVar4 - uVar5;
  }
  if (uVar4 < 500) {
    if (uVar5 <= _DAT_0302fe28) {
      uVar5 = uVar5 + 0x3e;
    }
    int_to_bcd_bytes_const4h_fwd(_DAT_0302fe1c,uVar5);
    FUN_0302fc64();
    uVar5 = bcd_frequency_decode(uVar3,4);
    number_to_string_format_2args(auStack_20,_DAT_0302fe2c,uVar5 / 100000,uVar5 % 100000);
    display_fill_rect(0,100,0xf0,0x7c,0);
    display_draw_number_centered(100,0xffff,0,(uint)auStack_20);
    display_draw_number_centered(0x82,0xffff,0,_DAT_0302fe30);
    puVar2 = PTR_DAT_0302fe34;
    *(char *)PTR_DAT_0302fe34 = (char)uVar5;
    *(char *)((int)puVar2 + 1) = (char)(uVar5 >> 8);
    *(char *)((int)puVar2 + 2) = (char)(uVar5 >> 0x10);
    *(char *)((int)puVar2 + 3) = (char)(uVar5 >> 0x18);
    *(undefined1 *)((int)puVar2 + 0x11) = 0xff;
    *(undefined1 *)((int)puVar2 + 0x12) = 0xff;
    bandwidth_deviation_threshold_store(uVar5,_DAT_0302fe38);
    channel_change_apply_squelch();
    dialog_header_number_draw_variant();
    uVar3 = cpu_sr_save_and_disable_irq_iram();
    OS_SchedLockTimeMeasStart();
    cVar1 = *(char *)PTR_OSSchedLockNestingCtr_0302fe3c;
    *(char *)PTR_OSSchedLockNestingCtr_0302fe3c = cVar1 + '\x01';
    if ((char)(cVar1 + '\x01') == '\x01') {
      OS_SchedLockTimeMeasStart_variant4();
    }
    OS_SchedLockTimeMeasStop();
    cpu_sr_restore_irq_iram(uVar3);
    busy_wait_delay_n_units(100);
    fd6818b_reg_write(FD6818_PAGE0_REG_51H,0x300);
    fd6818b_filter_select_then_chipmode_normal();
    busy_wait_delay_n_units(500);
    uVar3 = cpu_sr_save_and_disable_irq_iram();
    OS_SchedLockTimeMeasStart();
    cVar1 = *(char *)PTR_OSSchedLockNestingCtr_0302fe3c;
    *(char *)PTR_OSSchedLockNestingCtr_0302fe3c = cVar1 + -1;
    if ((char)(cVar1 + -1) == '\0') {
      OS_SchedLockTimeMeasStop_variant4();
      if (*(short *)PTR_DAT_0302fe40 == 0) {
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
    *(byte *)(_DAT_0302fe84 + 3) = *(byte *)(_DAT_0302fe84 + 3) & 0xf7 | 8;
    *_DAT_0302fe88 = 0;
    *_DAT_0302fe8c = 0;
  }
  else {
    fd6818b_reg_write(FD6818_PAGE0_REG_0X32,0x245);
  }
  *_DAT_0302fe90 = uVar5;
  return;
}

