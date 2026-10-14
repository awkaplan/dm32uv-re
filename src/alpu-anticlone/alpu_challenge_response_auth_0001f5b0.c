/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: alpu_challenge_response_auth @ 0001f5b0 (IRAM address; the boot stub copies these bytes from program flash 0x030cf1d0)
 * Size: 486 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: alpu-anticlone
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

char alpu_challenge_response_auth(void)

{
  undefined1 uStack_28;
  undefined1 uStack_27;
  undefined1 auStack_24 [8];
  undefined1 auStack_1c [11];
  char cStack_11;
  int iStack_10;
  
  cStack_11 = i2c_read_block_0x7a(0x7a,0x30,0x4cb74cc,0x10);
  if (cStack_11 == '\0') {
    cStack_11 = 0;
    for (iStack_10 = 0; iStack_10 < 8; iStack_10 = iStack_10 + 2) {
      auStack_24[iStack_10] = PTR_DAT_0001f7ec[iStack_10 * 2];
      auStack_24[iStack_10 + 1] = PTR_DAT_0001f7ec[iStack_10 * 2 + 1];
    }
    uStack_28 = PTR_DAT_0001f7ec[0xb];
    uStack_27 = PTR_DAT_0001f7ec[2];
    *PTR_DAT_0001f7f0 = 0;
    PTR_DAT_0001f7f0[1] = 1;
    alpu_block_cipher(auStack_24,auStack_1c,&uStack_28,2,0x20,0);
    for (iStack_10 = 0; iStack_10 < 8; iStack_10 = iStack_10 + 1) {
      PTR_DAT_0001f7f4[iStack_10 * 2] = auStack_1c[iStack_10];
    }
    *PTR_DAT_0001f7f4 = ~*PTR_DAT_0001f7f4;
    PTR_DAT_0001f7f4[1] = 0;
    PTR_DAT_0001f7f4[3] = 0x16;
    PTR_DAT_0001f7f4[5] = 0xfa;
    PTR_DAT_0001f7f4[7] = 0xb1;
    PTR_DAT_0001f7f4[9] = 0xed;
    PTR_DAT_0001f7f4[0xb] = 0x9f;
    PTR_DAT_0001f7f4[0xd] = 0x25;
    PTR_DAT_0001f7f4[0xf] = 0x15;
    cStack_11 = i2c_write_block_0x7a(0x7a,0x30,PTR_DAT_0001f7f4,0x10);
    if (cStack_11 == '\0') {
      pass_through_wrapper(0x2a);
      cStack_11 = '\0';
    }
  }
  return cStack_11;
}

