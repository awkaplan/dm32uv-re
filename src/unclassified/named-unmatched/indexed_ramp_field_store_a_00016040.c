/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: indexed_ramp_field_store_a @ 00016040 (IRAM address; the boot stub copies these bytes from program flash 0x030c5c60)
 * Size: 34 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void indexed_ramp_field_store_a(undefined4 param_1,uint param_2)

{
  if (6 < (param_2 & 0xff)) {
    func_0x0002e3f0(PTR_DAT_000160fc,param_1,0x31);
    return;
  }
  func_0x0002e3f0(PTR_DAT_000160fc,param_1,(param_2 & 0x1f) << 3);
  return;
}

