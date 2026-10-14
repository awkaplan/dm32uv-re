/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dmr_privacy_aes_ofb_keystream_128 @ 030cd08c (file base 0x03000000; code starts at 0x03001000)
 * Size: 74 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: dmr-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void dmr_privacy_aes_ofb_keystream_128(int param_1__w,undefined4 param_2,undefined4 param_3,int param_4)

{
  char param_1 = (char)param_1__w;
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 auStack_24 [16];
  
  if (param_1 == '\x04') {
    uVar3 = 10;
  }
  else {
    uVar3 = 0xe;
  }
  aes_block_encrypt(param_2,auStack_24,param_3,uVar3);
  aes_block_encrypt(auStack_24,param_4,param_3,uVar3);
  iVar1 = param_4;
  do {
    iVar2 = iVar1 + 0x10;
    aes_block_encrypt(iVar1,iVar2,param_3,uVar3);
    iVar1 = iVar2;
  } while (iVar2 != param_4 + 0x70);
  return;
}

