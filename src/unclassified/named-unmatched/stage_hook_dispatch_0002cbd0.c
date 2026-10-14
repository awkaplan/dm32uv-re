/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: stage_hook_dispatch @ 0002cbd0 (IRAM address; the boot stub copies these bytes from program flash 0x030dc7f0)
 * Size: 16 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void stage_hook_dispatch(uint param_1)

{
  if ((param_1 & 0xff) < 6) {
                    /* WARNING: Could not recover jumptable at 0x0002cbdc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(*(uint *)(iRam0002cbe0 + (param_1 & 0xff) * 4) & 0xfffffffe))();
    return;
  }
  return;
}

