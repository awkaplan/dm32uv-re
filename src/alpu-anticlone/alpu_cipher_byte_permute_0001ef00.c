/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: alpu_cipher_byte_permute @ 0001ef00 (IRAM address; the boot stub copies these bytes from program flash 0x030ceb20)
 * Size: 294 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: alpu-anticlone
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void alpu_cipher_byte_permute(undefined1 *param_1)

{
  undefined1 auStack_14 [4];
  undefined1 uStack_10;
  undefined1 uStack_f;
  undefined1 uStack_e;
  undefined1 uStack_d;
  int iStack_c;
  
  auStack_14[0] = param_1[1];
  auStack_14[1] = param_1[3];
  auStack_14[2] = param_1[7];
  auStack_14[3] = param_1[5];
  uStack_10 = *param_1;
  uStack_f = param_1[6];
  uStack_e = param_1[4];
  uStack_d = param_1[2];
  for (iStack_c = 0; iStack_c < 8; iStack_c = iStack_c + 1) {
    param_1[iStack_c] = auStack_14[iStack_c];
  }
  return;
}

