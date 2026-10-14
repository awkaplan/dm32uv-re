/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: rtc_validate_and_set_default_datetime @ 0301c608 (file base 0x03000000; code starts at 0x03001000)
 * Size: 102 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rtos
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void rtc_validate_and_set_default_datetime(void)

{
  undefined4 *puVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  undefined3 extraout_var;
  
  bVar2 = rtc_register_read(4);
  bVar3 = rtc_register_read(3);
  bVar4 = rtc_register_read(0x12);
  if (((CONCAT31(extraout_var,bVar3) + (short)(ushort)bVar2 * 0x100 & 0xffffU) == 0) ||
     ((bVar4 & 1) == 0)) {
    rtc_reg17_pulse_low_25ms();
    rtc_reg_0x11_set_bit1();
    puVar1 = PTR_DAT_0301c770;
    *(undefined2 *)((int)PTR_DAT_0301c770 + 6) = 0x7e0;
    *(undefined1 *)((int)puVar1 + 5) = 9;
    *(undefined1 *)(puVar1 + 1) = 2;
    *(undefined1 *)puVar1 = 0x10;
    *(undefined1 *)((int)puVar1 + 1) = 0x2d;
    *(undefined1 *)((int)puVar1 + 2) = 0x14;
    rtc_date_validate_and_write(*puVar1,puVar1[1]);
    OSTimeDly_ms_wrapper(1000);
  }
  else {
    rtc_reg_0x11_set_bit1();
  }
  return;
}

