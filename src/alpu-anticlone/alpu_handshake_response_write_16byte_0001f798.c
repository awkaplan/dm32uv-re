/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: alpu_handshake_response_write_16byte @ 0001f798 (IRAM address; the boot stub copies these bytes from program flash 0x030cf3b8)
 * Size: 450 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: alpu-anticlone
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

char alpu_handshake_response_write_16byte(void)

{
  undefined1 uVar1;
  char cVar2;
  int iVar3;
  byte abStack_1c [4];
  byte bStack_18;
  byte bStack_17;
  byte bStack_16;
  byte bStack_15;
  int iStack_10;
  
  abStack_1c[0] = *PTR_DAT_0001f7f8 ^ 0x42;
  abStack_1c[1] = PTR_DAT_0001f7f8[1] ^ 0xd7;
  abStack_1c[2] = PTR_DAT_0001f7f8[2] ^ 0x16;
  abStack_1c[3] = bRam6c4d6c4e ^ 0x98;
  bStack_18 = bRam6c4d6c4f ^ 0xa9;
  bStack_17 = bRam6c4d6c50 ^ 0xd3;
  bStack_16 = PTR_DAT_0001fa44[6] ^ 0xda;
  bStack_15 = PTR_DAT_0001fa44[7] ^ 0x52;
  PTR_DAT_0001fa48[1] = PTR_DAT_0001fa48[1] + '\x02';
  for (iStack_10 = 1; iStack_10 < 8; iStack_10 = iStack_10 + 2) {
    iVar3 = iStack_10 * 2;
    uVar1 = alpu_nonce_byte_next();
    PTR_DAT_0001fa4c[iVar3] = uVar1;
  }
  for (iStack_10 = 0; iStack_10 < 8; iStack_10 = iStack_10 + 1) {
    PTR_DAT_0001fa4c[iStack_10 * 2] = abStack_1c[iStack_10];
  }
  cVar2 = i2c_write_block_0x7a(0x7a,0x40,PTR_DAT_0001fa4c,0x10);
  if (cVar2 == '\0') {
    cVar2 = '\0';
  }
  return cVar2;
}

