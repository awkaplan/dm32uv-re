/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: i2c_read_block_0x7a @ 000144fc (IRAM address; the boot stub copies these bytes from program flash 0x030c411c)
 * Size: 404 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: alpu-anticlone
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4 i2c_read_block_0x7a(int param_1__w,int param_2__w,int param_3,int param_4)

{
  byte param_1 = (byte)param_1__w;
  undefined1 param_2 = (undefined1)param_2__w;
  int *piVar1;
  undefined1 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  piVar1 = piRam00014624;
  uRam14020000 = uRam14020000 & ~(1 << (*piRam00014624 * 2 + 6U & 0x3f));
  busy_wait_delay_loop_4arg(1);
  uRam14020000 = uRam14020000 & ~(1 << (*piVar1 * 2 + 5U & 0x3f));
  iVar3 = i2c_send_byte_wait_ack(param_1);
  if (iVar3 == 1) {
    uRam14020000 = 1 << (*piVar1 * 2 + 5U & 0x3f) | uRam14020000;
    busy_wait_delay_loop_4arg();
    uRam14020000 = 1 << (*piVar1 * 2 + 6U & 0x3f) | uRam14020000;
    busy_wait_delay_loop_4arg(1);
    return 0;
  }
  iVar3 = i2c_send_byte_wait_ack(param_2);
  if (iVar3 != 1) {
    busy_wait_delay_loop_4arg(1);
    uRam14020000 = 1 << (*piVar1 * 2 + 6U & 0x3f) | uRam14020000;
    busy_wait_delay_loop_4arg(1);
    uRam14020000 = 1 << (*piVar1 * 2 + 5U & 0x3f) | uRam14020000;
    busy_wait_delay_loop_4arg(5);
    uRam14020000 = uRam14020000 & ~(1 << (*piVar1 * 2 + 6U & 0x3f));
    busy_wait_delay_loop_4arg(1);
    uRam14020000 = uRam14020000 & ~(1 << (*piVar1 * 2 + 5U & 0x3f));
    iVar3 = i2c_send_byte_wait_ack(param_1 | 1);
    if (iVar3 == 1) {
      uRam14020000 = 1 << (*piVar1 * 2 + 5U & 0x3f) | uRam14020000;
    }
    else {
      if (param_4 != 1) {
        uVar5 = 0;
        do {
          uVar2 = i2c_bitbang_read_byte_with_ack(0);
          uVar4 = uVar5 + 1;
          *(undefined1 *)(param_3 + uVar5) = uVar2;
          uVar5 = uVar4;
        } while (uVar4 < param_4 - 1U);
      }
      uVar2 = i2c_bitbang_read_byte_with_ack(1);
      *(undefined1 *)(param_3 + param_4 + -1) = uVar2;
      uRam14020000 = 1 << (*piVar1 * 2 + 5U & 0x3f) | uRam14020000;
    }
    busy_wait_delay_loop_4arg(1);
    uRam14020000 = 1 << (*piVar1 * 2 + 6U & 0x3f) | uRam14020000;
    busy_wait_delay_loop_4arg(1);
    return 0;
  }
  uRam14020000 = 1 << (*piVar1 * 2 + 5U & 0x3f) | uRam14020000;
  busy_wait_delay_loop_4arg();
  uRam14020000 = 1 << (*piVar1 * 2 + 6U & 0x3f) | uRam14020000;
  busy_wait_delay_loop_4arg(2);
  return 0;
}

