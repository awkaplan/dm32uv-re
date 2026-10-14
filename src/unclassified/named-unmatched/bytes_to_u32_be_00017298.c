/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: bytes_to_u32_be @ 00017298 (IRAM address; the boot stub copies these bytes from program flash 0x030c6eb8)
 * Size: 24 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

int bytes_to_u32_be(void)

{
  return (uint)*pbRam000172c8 * 0x1000000 + (uint)pbRam000172c8[1] * 0x10000 +
         (uint)pbRam000172c8[3] + (uint)pbRam000172c8[2] * 0x100;
}

