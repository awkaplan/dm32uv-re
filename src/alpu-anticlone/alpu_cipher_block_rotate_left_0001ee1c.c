/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: alpu_cipher_block_rotate_left @ 0001ee1c (IRAM address; the boot stub copies these bytes from program flash 0x030cea3c)
 * Size: 226 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: alpu-anticlone
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void alpu_cipher_block_rotate_left(undefined1 *param_1)

{
  undefined1 auStack_14 [7];
  undefined1 uStack_d;
  int iStack_c;
  
  for (iStack_c = 0; iStack_c < 7; iStack_c = iStack_c + 1) {
    auStack_14[iStack_c] = param_1[iStack_c + 1];
  }
  uStack_d = *param_1;
  for (iStack_c = 0; iStack_c < 8; iStack_c = iStack_c + 1) {
    param_1[iStack_c] = auStack_14[iStack_c];
  }
  return;
}

