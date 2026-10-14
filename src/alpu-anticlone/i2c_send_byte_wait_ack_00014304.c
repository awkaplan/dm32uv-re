/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: i2c_send_byte_wait_ack @ 00014304 (IRAM address; the boot stub copies these bytes from program flash 0x030c3f24)
 * Size: 282 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: alpu-anticlone
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

bool i2c_send_byte_wait_ack(uint param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  
  piVar2 = piRam000143a8;
  uRam14020004 = 1 << (*piRam000143a8 * 2 + 6U & 0x3f) | uRam14020004;
  uVar4 = 7;
  do {
    busy_wait_delay_loop_4arg(1);
    if (((int)(param_1 & 0xff) >> (uVar4 & 0x3f) & 1U) == 0) {
      uRam14020000 = uRam14020000 & ~(1 << (*piVar2 * 2 + 6U & 0x3f));
    }
    else {
      uRam14020000 = 1 << (*piVar2 * 2 + 6U & 0x3f) | uRam14020000;
    }
    busy_wait_delay_loop_4arg(1);
    uRam14020000 = 1 << (*piVar2 * 2 + 5U & 0x3f) | uRam14020000;
    busy_wait_delay_loop_4arg(1);
    piVar3 = piRam000143a8;
    uRam14020000 = uRam14020000 & ~(1 << (*piVar2 * 2 + 5U & 0x3f));
    uVar4 = uVar4 - 1;
  } while (uVar4 != 0xffffffff);
  uVar4 = ~(1 << (*piVar2 * 2 + 6U & 0x3f));
  uRam14020000 = uRam14020000 & uVar4;
  uRam14020004 = uVar4 & uRam14020004;
  busy_wait_delay_loop_4arg(1);
  uRam14020000 = 1 << (*piVar3 * 2 + 5U & 0x3f) | uRam14020000;
  busy_wait_delay_loop_4arg(1);
  iVar1 = *piVar3 * 2;
  uRam14020000 = uRam14020000 & ~(1 << (iVar1 + 5U & 0x3f));
  uVar4 = 1 << (iVar1 + 6U & 0x3f);
  uRam14020004 = uVar4 | uRam14020004;
  return (uVar4 & uRam14020050) != 0;
}

