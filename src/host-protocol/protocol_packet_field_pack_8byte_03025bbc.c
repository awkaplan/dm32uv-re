/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: protocol_packet_field_pack_8byte @ 03025bbc (file base 0x03000000; code starts at 0x03001000)
 * Size: 148 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: host-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void protocol_packet_field_pack_8byte(char *param_1,char param_2)

{
  undefined4 local_10;
  char cStack_c;
  undefined1 uStack_b;
  undefined1 uStack_a;
  undefined1 uStack_9;
  undefined1 uStack_8;
  
  uStack_8 = 0;
  if (param_2 == '\x01') {
    SUBPIECE_SET(local_10, 0, 3, CONCAT12((char)*(undefined2 *)(param_1 + 0x30),0x44));
    local_10 = (uint)(uint3)local_10;
    cStack_c = 3;
    uStack_b = 0xbf;
    uStack_a = (undefined1)((ushort)*(undefined2 *)(param_1 + 0x32) >> 8);
    uStack_9 = (undefined1)*(undefined2 *)(param_1 + 0x32);
    memcpy_bytes_iram(param_1 + 0x4b,&local_10,8);
  }
  else {
    SUBPIECE_SET(local_10, 0, 3, CONCAT12((char)*(undefined2 *)(param_1 + 0x30),0x44));
    local_10 = CONCAT13((char)(*(ushort *)(param_1 + 0x36c) + 4 >> 8),(uint3)local_10);
    cStack_c = (char)*(ushort *)(param_1 + 0x36c) + '\x04';
    if (*param_1 == '\x01') {
      uStack_b = 0xa0;
    }
    else {
      uStack_b = 0xe0;
    }
    uStack_a = (undefined1)((ushort)*(undefined2 *)(param_1 + 0x32) >> 8);
    uStack_9 = (undefined1)*(undefined2 *)(param_1 + 0x32);
    uStack_8 = 4;
    memcpy_bytes_iram(param_1 + 0x4b,&local_10,8);
  }
  return;
}

