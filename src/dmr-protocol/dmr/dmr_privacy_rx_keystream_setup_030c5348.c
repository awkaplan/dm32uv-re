/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dmr_privacy_rx_keystream_setup @ 030c5348 (file base 0x03000000; code starts at 0x03001000)
 * Size: 202 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: dmr-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void dmr_privacy_rx_keystream_setup(char param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  undefined1 auStack_24 [16];
  
  pcVar2 = param_2 + 0x29;
  func_0x030dec8c(pcVar2,param_2 + 3,0x20);
  cVar1 = *param_2;
  if (cVar1 == '\x01') {
    func_0x030dec8c(param_2 + 0x2e,param_2 + 0x23,4);
    rc4_key_scheduling_init(param_2 + 0x23c,pcVar2,9);
    if (param_1 == '\x01') {
      rc4_keystream_generate_to_buffer(param_2 + 0x23c,param_2 + 0x33c,0x7e);
    }
  }
  else if (cVar1 == '\x02') {
    dmr_privacy_alg2_key_setup_stub(param_2 + 0x13c,pcVar2);
    if (param_1 == '\x01') {
      dmr_privacy_mi_expand_lfsr(param_2 + 0x23,auStack_24,1);
      dmr_privacy_alg2_block_encrypt_stub(auStack_24,param_2 + 0x13c,param_2 + 0x33c);
    }
  }
  else {
    if (cVar1 == '\x04') {
      aes_key_schedule_expand(pcVar2,param_2 + 0x4c,4,10);
    }
    else if (cVar1 == '\x05') {
      aes_key_schedule_expand(pcVar2,param_2 + 0x4c,8,0xe);
    }
    if (param_1 == '\x01') {
      dmr_privacy_mi_expand_lfsr(param_2 + 0x23,auStack_24,3);
      dmr_privacy_aes_ofb_keystream_128(*param_2,auStack_24,param_2 + 0x4c,param_2 + 0x33c);
      return;
    }
  }
  return;
}

