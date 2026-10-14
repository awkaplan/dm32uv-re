/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: alpu_block_cipher @ 0001f028 (IRAM address; the boot stub copies these bytes from program flash 0x030cec48)
 * Size: 1394 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: alpu-anticlone
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void alpu_block_cipher(int param_1,int param_2,int param_3,byte param_4,int param_5,char param_6)

{
  byte bVar1;
  byte bVar2;
  undefined4 uStack_20;
  byte abStack_1c [8];
  byte bStack_14;
  byte bStack_13;
  byte bStack_12;
  byte bStack_11;
  int iStack_10;
  
  for (iStack_10 = 0; iStack_10 < 8; iStack_10 = iStack_10 + 1) {
    *(undefined1 *)(param_2 + iStack_10) = *(undefined1 *)(param_1 + iStack_10);
  }
  uStack_20 = param_1;
  for (bStack_11 = 0; bStack_11 < param_4; bStack_11 = bStack_11 + 1) {
    if (param_6 == '\0') {
      for (iStack_10 = 0; iStack_10 < 8; iStack_10 = iStack_10 + 1) {
        abStack_1c[iStack_10] = *(byte *)(iRam0001f2c8 + (uint)bStack_11 * 8 + iStack_10);
      }
    }
    else {
      for (iStack_10 = 0; iStack_10 < 8; iStack_10 = iStack_10 + 1) {
        abStack_1c[iStack_10] =
             *(byte *)(iRam0001f2cc + (uint)bStack_11 * 8 + iStack_10) ^ PTR_DAT_0001f2d0[iStack_10]
             ^ PTR_DAT_0001f2d4[iStack_10];
      }
    }
    for (iStack_10 = 0; iStack_10 < 2; iStack_10 = iStack_10 + 1) {
      abStack_1c[iStack_10] = abStack_1c[iStack_10] ^ *(byte *)(param_3 + iStack_10);
    }
    for (iStack_10 = 0; iStack_10 < 2; iStack_10 = iStack_10 + 1) {
      abStack_1c[iStack_10 + 2] = abStack_1c[iStack_10 + 2] ^ PTR_DAT_0001f2d8[iStack_10];
    }
    for (bStack_12 = 0; (int)(uint)bStack_12 < param_5 + -1; bStack_12 = bStack_12 + 1) {
      bStack_13 = abStack_1c[0];
      for (iStack_10 = 0; iStack_10 < 7; iStack_10 = iStack_10 + 1) {
        abStack_1c[iStack_10] = abStack_1c[iStack_10 + 1] >> 5 | abStack_1c[iStack_10] << 3;
      }
      abStack_1c[7] = bStack_13 >> 5 | abStack_1c[7] << 3;
    }
    for (bStack_12 = 0; bVar1 = abStack_1c[7], (int)(uint)bStack_12 < param_5 + -1;
        bStack_12 = bStack_12 + 1) {
      bStack_13 = abStack_1c[7];
      for (iStack_10 = 7; 0 < iStack_10; iStack_10 = iStack_10 + -1) {
        abStack_1c[iStack_10] = abStack_1c[iStack_10 + -1] << 5 | abStack_1c[iStack_10] >> 3;
      }
      bVar2 = bVar1 << 5;
      abStack_1c[0] = bVar2 | abStack_1c[0] >> 3;
      bStack_14 = (bVar2 & 0x20) >> 3 | (bVar1 & 7) >> 1;
      if (bStack_14 == 0) {
        alpu_cipher_invert_and_fold_halfblock(param_2);
      }
      else if (bStack_14 == 1) {
        alpu_cipher_xor_mix_and_swap_halves(param_2,abStack_1c);
      }
      else if ((param_6 == '\0') || (bStack_14 != 3)) {
        if ((param_6 == '\0') || (bStack_14 != 4)) {
          if ((param_6 != '\0') && (bStack_14 == 5)) {
            alpu_cipher_byte_permute(param_2);
          }
        }
        else {
          alpu_cipher_block_rotate_left(param_2);
        }
      }
      else {
        alpu_cipher_byte_rotate_right(param_2);
      }
    }
  }
  return;
}

