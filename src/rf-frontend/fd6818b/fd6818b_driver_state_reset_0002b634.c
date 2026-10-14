/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: fd6818b_driver_state_reset @ 0002b634 (IRAM address; the boot stub copies these bytes from program flash 0x030db254)
 * Size: 64 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rf-frontend
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void fd6818b_driver_state_reset(void)

{
  byte bVar1;
  undefined *puVar2;
  
  puVar2 = PTR_DAT_0002b7e4;
  if ((PTR_DAT_0002b7e0[8] & 0xf0) != 0x10) {
    bVar1 = PTR_DAT_0002b7e4[0x1d];
    PTR_DAT_0002b7e8[0x1e] = 0;
    puVar2[0x16] = 0;
    puVar2[0x1d] = bVar1 & 0xfc;
    puVar2[0x14] = 0;
    puVar2[4] = 0;
    puVar2[0x15] = 0;
    *(undefined4 *)(puVar2 + 0x18) = 0;
    *(undefined4 *)(puVar2 + 0xc) = 0;
    PTR_DAT_0002b7ec[0x16] = PTR_DAT_0002b7ec[0x16] & 0xbf;
  }
  func_0x0300e918();
  return;
}

