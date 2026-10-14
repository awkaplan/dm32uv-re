/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: vfo_active_side_mode_nibble @ 0002deb8 (IRAM address; the boot stub copies these bytes from program flash 0x030ddad8)
 * Size: 89 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-screen
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

byte vfo_active_side_mode_nibble(void)

{
  byte bVar1;
  char cVar2;
  
  if ((PTR_DAT_0002df64[0x2d] & 0x80) == 0) {
    cVar2 = func_0x0300d810(*(undefined4 *)PTR_DAT_0002df68);
    if (cVar2 == '\x01') {
      PTR_DAT_0002df68[8] = PTR_DAT_0002df68[8] & 0xf;
    }
    bVar1 = PTR_DAT_0002df68[8];
  }
  else {
    cVar2 = func_0x0300d810(*(undefined4 *)PTR_DAT_0002df6c);
    if (cVar2 == '\x01') {
      PTR_DAT_0002df6c[8] = PTR_DAT_0002df6c[8] & 0xf;
    }
    bVar1 = PTR_DAT_0002df6c[8];
  }
  return bVar1 >> 4;
}

