/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: label_table_segment_copy @ 0001620c (IRAM address; the boot stub copies these bytes from program flash 0x030c5e2c)
 * Size: 100 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined4 label_table_segment_copy(uint param_1,undefined4 param_2,uint param_3,int param_4)

{
  param_1 = param_1 & 0xff;
  param_3 = param_3 & 0xff;
  if (0x1a < param_1) {
    return 1;
  }
  if (0x1b < param_3) {
    return 2;
  }
  if (0x1b < param_3 + param_1) {
    return 3;
  }
  if (param_4 != 0) {
    func_0x00016188(PTR_DAT_00016290,param_4);
  }
  if (*PTR_DAT_00016284 != '\0') {
    func_0x0002f06c(param_2,PTR_DAT_00016288 + param_1,param_3);
    return 0;
  }
  func_0x0002f06c(param_2,PTR_DAT_0001628c + param_1,param_3);
  return 0;
}

