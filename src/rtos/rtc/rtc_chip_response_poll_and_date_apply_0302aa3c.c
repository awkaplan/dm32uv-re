/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: rtc_chip_response_poll_and_date_apply @ 0302aa3c (file base 0x03000000; code starts at 0x03001000)
 * Size: 170 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rtos
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void rtc_chip_response_poll_and_date_apply(void)

{
  undefined4 *puVar1;
  byte bVar2;
  byte bVar3;
  undefined1 uVar4;
  undefined4 local_40;
  undefined4 uStack_3c;
  int local_38;
  char local_34 [4];
  byte bStack_30;
  undefined2 uStack_2f;
  undefined1 uStack_2d;
  undefined1 uStack_2c;
  undefined1 uStack_2b;
  undefined1 uStack_2a;
  undefined1 uStack_29;
  
  puVar1 = PTR_DAT_0302ab68;
  while( true ) {
    (*(code *)(*puVar1 & 0xfffffffe))(local_34,5,2000,&local_38);
    bVar2 = bStack_30;
    if ((((7 < bStack_30) ||
         (bVar3 = (*(code *)(*puVar1 & 0xfffffffe))(&uStack_2f,bStack_30,500,&local_38),
         bVar3 != bVar2)) || (local_38 == 0x72d9)) || (local_34[0] != 'T')) break;
    local_34[0] = '\x06';
    (*(code *)(puVar1[1] & 0xfffffffe))(local_34,1);
    SUBPIECE_SET(local_40, 0, 3, CONCAT12(uStack_29,CONCAT11(uStack_2a,uStack_2b)));
    uStack_3c = CONCAT22(uStack_2f,CONCAT11(uStack_2d,uStack_2c));
    uVar4 = day_of_week_calculate((undefined3)local_40,uStack_3c);
    local_40 = CONCAT13(uVar4,(undefined3)local_40);
    rtc_date_validate_and_write(local_40,uStack_3c);
    OSTimeDly_ms_wrapper(500);
    flash_quad_enable_and_system_reset();
  }
  return;
}

