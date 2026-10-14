/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: OSTimeTick @ 00014128 (IRAM address; the boot stub copies these bytes from program flash 0x030c3d48)
 * Size: 48 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rtos
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void OSTimeTick(void)

{
  undefined4 uVar1;
  undefined1 auStack_8 [4];
  
  func_0x00010854();
  uVar1 = func_0x0306ced4();
  ucos3_message_queue_post_with_overflow_check
            (uRam0001415c,iRam00014160 + (uint)*pbRam00014158 * 0xc,0,0,0,0,uVar1,auStack_8);
  return;
}

