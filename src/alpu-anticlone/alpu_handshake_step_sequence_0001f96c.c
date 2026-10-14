/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: alpu_handshake_step_sequence @ 0001f96c (IRAM address; the boot stub copies these bytes from program flash 0x030cf58c)
 * Size: 1238 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: alpu-anticlone
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

char alpu_handshake_step_sequence(int param_1,int param_2)

{
  undefined1 uVar1;
  char cVar2;
  int iVar3;
  undefined1 uStack_2c;
  undefined1 uStack_2b;
  undefined1 auStack_28 [4];
  undefined1 uStack_24;
  undefined1 uStack_23;
  undefined1 uStack_22;
  undefined1 uStack_21;
  int iStack_20;
  undefined1 uStack_1b;
  undefined1 uStack_1a;
  char cStack_19;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  
  uStack_1a = 0x87;
  iStack_18 = 0;
  do {
    if (1 < iStack_18) {
      return cStack_19;
    }
    uStack_1b = uStack_1a;
    if (*PTR_DAT_0001fa50 == '\0') {
      for (iStack_10 = 0; iStack_10 < 0x10; iStack_10 = iStack_10 + 1) {
        PTR_DAT_0001fa4c[iStack_10] = 0;
      }
      i2c_write_block_0x7a(0x7a,0x80,PTR_DAT_0001fa4c,8);
      pass_through_wrapper(1);
      i2c_write_block_0x7a(0x7a,0x20,PTR_DAT_0001fa4c,1);
      pass_through_wrapper(1);
      *PTR_DAT_0001fa4c = 0x83;
      i2c_write_block_0x7a(0x7a,0x22,PTR_DAT_0001fa4c,1);
      pass_through_wrapper(1);
      cStack_19 = alpu_challenge_response_auth();
      if (cStack_19 != '\0') {
        return cStack_19;
      }
      pass_through_wrapper(1);
      cStack_19 = alpu_handshake_challenge_read_32byte();
      if (cStack_19 != '\0') {
        return cStack_19;
      }
      cStack_19 = alpu_handshake_response_write_16byte();
      if (cStack_19 != '\0') {
        return cStack_19;
      }
    }
    for (iStack_10 = 0; iStack_10 < 8; iStack_10 = iStack_10 + 1) {
      PTR_DAT_0001fcf4[iStack_10 * 2] = *(undefined1 *)(param_1 + iStack_10);
      iVar3 = iStack_10 * 2;
      uVar1 = alpu_nonce_byte_next();
      PTR_DAT_0001fcf4[iVar3 + 1] = uVar1;
    }
    cStack_19 = i2c_write_block_0x7a(0x7a,uStack_1b,PTR_DAT_0001fcf4,0x10);
    if (cStack_19 != '\0') {
      return cStack_19;
    }
    pass_through_wrapper(5);
    cVar2 = i2c_read_block_0x7a(0x7a,uStack_1b,PTR_DAT_0001fcf8,0x10);
    if (cVar2 != '\0') {
      return cVar2;
    }
    auStack_28[0] = PTR_DAT_0001fcf8[3];
    auStack_28[1] = PTR_DAT_0001fcf8[4];
    auStack_28[2] = PTR_DAT_0001fcf8[5];
    auStack_28[3] = PTR_DAT_0001fcf8[6];
    uStack_24 = PTR_DAT_0001fcf8[10];
    uStack_23 = PTR_DAT_0001fcf8[0xc];
    uStack_22 = PTR_DAT_0001fcf8[0xd];
    uStack_21 = PTR_DAT_0001fcf8[0xe];
    *PTR_DAT_0001fcfc = 0;
    PTR_DAT_0001fcfc[1] = 0;
    if (iStack_18 != 0) {
      auStack_28[0] = PTR_DAT_0001fcf8[3];
      auStack_28[1] = PTR_DAT_0001fcf8[4];
      auStack_28[2] = PTR_DAT_0001fcf8[5];
      auStack_28[3] = PTR_DAT_0001fcf8[6];
      uStack_24 = PTR_DAT_0001fcf8[10];
      uStack_23 = PTR_DAT_0001fcf8[0xc];
      uStack_22 = PTR_DAT_0001fcf8[0xd];
      uStack_21 = PTR_DAT_0001fcf8[0xe];
      *PTR_DAT_0001fcfc = 0;
      PTR_DAT_0001fcfc[1] = 0;
    }
    uStack_2b = 0;
    uStack_2c = 0;
    iStack_20 = 1;
    cStack_19 = '\0';
    for (iStack_10 = 0; iStack_10 < iStack_20; iStack_10 = iStack_10 + 1) {
      alpu_block_cipher(auStack_28,param_2,&uStack_2c,8,0x80,2);
      for (iStack_14 = 0; iStack_14 < 8; iStack_14 = iStack_14 + 1) {
        auStack_28[iStack_14] = *(undefined1 *)(param_2 + iStack_14);
      }
    }
    for (iStack_10 = 0; iStack_10 < 8; iStack_10 = iStack_10 + 1) {
      if (*(char *)(param_1 + iStack_10) != *(char *)(param_2 + iStack_10)) {
        cStack_19 = '2';
        break;
      }
    }
    if (cStack_19 == '\0') {
      *puRam0001fe60 = 1;
      return '\0';
    }
    iStack_18 = iStack_18 + 1;
  } while( true );
}

