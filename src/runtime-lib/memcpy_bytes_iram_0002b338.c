/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: memcpy_bytes_iram @ 0002b338 (IRAM address; the boot stub copies these bytes from program flash 0x030daf58)
 * Size: 22 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: runtime-lib
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void memcpy_bytes_iram(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  if (0 < param_3) {
    iVar1 = 0;
    do {
      *(undefined1 *)(param_1 + iVar1) = *(undefined1 *)(param_2 + iVar1);
      iVar1 = iVar1 + 1;
    } while (iVar1 != param_3);
  }
  return;
}

