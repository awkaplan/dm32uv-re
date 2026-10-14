/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: OSSemPost @ 000120dc (IRAM address; the boot stub copies these bytes from program flash 0x030c1cfc)
 * Size: 135 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rtos
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4 OSSemPost(int *param_1,ushort param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  if (param_1 == (int *)0x0) {
    *param_3 = 0x5dc3;
    return 0;
  }
  if (param_2 == 0x200) {
LAB_0001211c:
    if (*param_1 == iRam00012164) {
      uVar1 = func_0x0306ced4();
      if (*pcRam00012168 == '\0') {
        uVar1 = OS_SemPost(param_1,param_2,uVar1,param_3);
      }
      else {
        ucos3_message_queue_post_with_overflow_check
                  (iRam00012164,param_1,0,0,0,param_2,uVar1,param_3);
        uVar1 = 0;
      }
    }
    else {
      *param_3 = 0x5dc4;
      uVar1 = 0;
    }
  }
  else {
    if (param_2 < 0x201) {
      if (param_2 == 0) goto LAB_0001211c;
    }
    else if ((param_2 == 0x8000) || (param_2 == 0x8200)) goto LAB_0001211c;
    *param_3 = 0x5e25;
    uVar1 = 0;
  }
  return uVar1;
}

