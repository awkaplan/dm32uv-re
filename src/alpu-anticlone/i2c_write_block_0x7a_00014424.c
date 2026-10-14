/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: i2c_write_block_0x7a @ 00014424 (IRAM address; the boot stub copies these bytes from program flash 0x030c4044)
 * Size: 216 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: alpu-anticlone
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4 i2c_write_block_0x7a(int param_1__w,int param_2__w,int param_3,uint param_4)

{
  undefined1 param_1 = (undefined1)param_1__w;
  undefined1 param_2 = (undefined1)param_2__w;
  int *piVar1;
  int iVar2;
  uint uVar3;
  
  piVar1 = piRam00014624;
  uRam14020000 = uRam14020000 & ~(1 << (*piRam00014624 * 2 + 6U & 0x3f));
  busy_wait_delay_loop_4arg(1);
  uRam14020000 = uRam14020000 & ~(1 << (*piVar1 * 2 + 5U & 0x3f));
  iVar2 = i2c_send_byte_wait_ack(param_1);
  if ((iVar2 == 1) || (iVar2 = i2c_send_byte_wait_ack(param_2), iVar2 == 1)) {
    uRam14020000 = 1 << (*piVar1 * 2 + 5U & 0x3f) | uRam14020000;
  }
  else {
    if (param_4 != 0) {
      uVar3 = 0;
      do {
        iVar2 = i2c_send_byte_wait_ack(*(undefined1 *)(param_3 + uVar3));
        uVar3 = uVar3 + 1;
        if (iVar2 == 1) {
          uRam14020000 = 1 << (*piVar1 * 2 + 5U & 0x3f) | uRam14020000;
          goto LAB_000144c4;
        }
      } while (uVar3 < param_4);
    }
    uRam14020000 = 1 << (*piVar1 * 2 + 5U & 0x3f) | uRam14020000;
  }
LAB_000144c4:
  busy_wait_delay_loop_4arg(1);
  uRam14020000 = 1 << (*piVar1 * 2 + 6U & 0x3f) | uRam14020000;
  busy_wait_delay_loop_4arg(1);
  return 0;
}

