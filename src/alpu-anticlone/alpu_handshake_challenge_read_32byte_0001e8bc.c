/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: alpu_handshake_challenge_read_32byte @ 0001e8bc (IRAM address; the boot stub copies these bytes from program flash 0x030ce4dc)
 * Size: 568 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: alpu-anticlone
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

char alpu_handshake_challenge_read_32byte(void)

{
  undefined1 auStack_1c [4];
  undefined1 auStack_18 [7];
  char cStack_11;
  int iStack_10;
  
  cStack_11 = i2c_read_block_0x7a(0x7a,0x73,auStack_1c,8);
  if (cStack_11 == '\0') {
    for (iStack_10 = 0; iStack_10 < 4; iStack_10 = iStack_10 + 1) {
      *(undefined1 *)(iRam0001eaf4 + iStack_10) = auStack_18[iStack_10];
    }
    cStack_11 = i2c_read_block_0x7a(0x7a,0x74,auStack_1c,8);
    if (cStack_11 == '\0') {
      for (iStack_10 = 4; iStack_10 < 8; iStack_10 = iStack_10 + 1) {
        *(undefined1 *)(iRam0001eaf4 + iStack_10) = auStack_1c[iStack_10];
      }
      cStack_11 = i2c_read_block_0x7a(0x7a,0x75,auStack_1c,8);
      if (cStack_11 == '\0') {
        for (iStack_10 = 0; iStack_10 < 4; iStack_10 = iStack_10 + 1) {
          *(undefined1 *)(iRam0001eaf8 + iStack_10) = auStack_18[iStack_10];
        }
        cStack_11 = i2c_read_block_0x7a(0x7a,0x76,auStack_1c,8);
        if (cStack_11 == '\0') {
          for (iStack_10 = 4; iStack_10 < 8; iStack_10 = iStack_10 + 1) {
            *(undefined1 *)(iRam0001eaf8 + iStack_10) = auStack_1c[iStack_10];
          }
          cStack_11 = '\0';
        }
      }
    }
  }
  return cStack_11;
}

