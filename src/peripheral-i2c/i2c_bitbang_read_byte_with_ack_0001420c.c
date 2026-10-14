/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: i2c_bitbang_read_byte_with_ack @ 0001420c (IRAM address; the boot stub copies these bytes from program flash 0x030c3e2c)
 * Size: 248 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: peripheral-i2c
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

byte i2c_bitbang_read_byte_with_ack(char param_1)

{
  int *piVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  
  piVar1 = piRam000143a8;
  uRam14020004 = uRam14020004 & ~(1 << (*piRam000143a8 * 2 + 6U & 0x3f));
  iVar3 = 8;
  bVar2 = 0;
  do {
    busy_wait_delay_loop_4arg(1);
    uRam14020000 = 1 << (*piVar1 * 2 + 5U & 0x3f) | uRam14020000;
    busy_wait_delay_loop_4arg(1);
    bVar2 = bVar2 * '\x02';
    iVar3 = iVar3 + -1;
    if ((1 << (*piVar1 * 2 + 6U & 0x3f) & uRam14020050) != 0) {
      bVar2 = bVar2 | 1;
    }
    uRam14020000 = uRam14020000 & ~(1 << (*piVar1 * 2 + 5U & 0x3f));
    busy_wait_delay_loop_4arg(1);
  } while (iVar3 != 0);
  uVar4 = 1 << (*piVar1 * 2 + 6U & 0x3f);
  uRam14020004 = uRam14020004 | uVar4;
  if (param_1 == '\0') {
    uRam14020000 = uRam14020000 & ~uVar4;
  }
  else {
    uRam14020000 = uVar4 | uRam14020000;
  }
  busy_wait_delay_loop_4arg(1);
  uRam14020000 = 1 << (*piVar1 * 2 + 5U & 0x3f) | uRam14020000;
  busy_wait_delay_loop_4arg(1);
  uRam14020000 = uRam14020000 & ~(1 << (*piVar1 * 2 + 5U & 0x3f)) &
                 ~(1 << (*piVar1 * 2 + 6U & 0x3f));
  return bVar2;
}

