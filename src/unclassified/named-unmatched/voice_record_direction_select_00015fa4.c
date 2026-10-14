/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: voice_record_direction_select @ 00015fa4 (IRAM address; the boot stub copies these bytes from program flash 0x030c5bc4)
 * Size: 92 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void voice_record_direction_select(char param_1)

{
  if (param_1 == '\x01') {
    PTR_DAT_000160f4[0x19d4] = 1;
    PTR_DAT_000160f8[0x1496] = 0;
    return;
  }
  if (param_1 != '\x02') {
    PTR_DAT_000160f4[0x19d4] = param_1 == '\x03';
    PTR_DAT_000160f8[0x1496] = param_1 == '\x03';
    return;
  }
  PTR_DAT_000160f4[0x19d4] = 0;
  PTR_DAT_000160f8[0x1496] = 1;
  return;
}

