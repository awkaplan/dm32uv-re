/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: alpu_cipher_xor_mix_and_swap_halves @ 0001ebf8 (IRAM address; the boot stub copies these bytes from program flash 0x030ce818)
 * Size: 318 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: alpu-anticlone
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void alpu_cipher_xor_mix_and_swap_halves(int param_1,int param_2)

{
  byte abStack_14 [4];
  byte abStack_10 [4];
  int iStack_c;
  
  for (iStack_c = 0; iStack_c < 4; iStack_c = iStack_c + 1) {
    abStack_10[iStack_c] = *(byte *)(param_1 + iStack_c) ^ *(byte *)(param_2 + iStack_c);
    abStack_14[iStack_c] = *(byte *)(param_1 + iStack_c + 4) ^ *(byte *)(param_2 + iStack_c + 4);
  }
  for (iStack_c = 0; iStack_c < 8; iStack_c = iStack_c + 1) {
    *(byte *)(param_1 + iStack_c) = abStack_14[iStack_c];
  }
  return;
}

