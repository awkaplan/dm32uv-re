/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: protocol_packet_build_with_checksum @ 03025c54 (file base 0x03000000; code starts at 0x03001000)
 * Size: 490 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: host-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void protocol_packet_build_with_checksum(char *param_1,char param_2)

{
  ushort uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  undefined4 local_38;
  undefined1 uStack_34;
  undefined1 uStack_33;
  undefined1 uStack_32;
  undefined1 uStack_31;
  undefined4 uStack_30;
  undefined1 uStack_2c;
  undefined1 uStack_2b;
  undefined1 uStack_2a;
  undefined1 uStack_29;
  undefined1 uStack_28;
  undefined1 uStack_27;
  undefined1 uStack_26;
  undefined1 uStack_25;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined2 uStack_18;
  
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  if (param_2 == '\x01') {
    local_38 = 0x21000045;
    uStack_34 = (undefined1)((ushort)*(undefined2 *)(param_1 + 0x30) >> 8);
    uStack_33 = (undefined1)*(undefined2 *)(param_1 + 0x30);
  }
  else {
    local_38 = CONCAT13((char)*(ushort *)(param_1 + 0x36c) + '\"',
                        CONCAT12((char)(*(ushort *)(param_1 + 0x36c) + 0x22 >> 8),0x45));
    uStack_34 = (undefined1)((ushort)*(undefined2 *)(param_1 + 0x30) >> 8);
    uStack_33 = (undefined1)*(undefined2 *)(param_1 + 0x30);
  }
  uStack_32 = 0;
  uStack_31 = 0;
  uStack_30 = 0x1140;
  uStack_2c = 0xc;
  uVar3 = *(undefined4 *)(param_1 + 0x2c);
  uStack_2b = (undefined1)((uint)uVar3 >> 0x10);
  uStack_2a = (undefined1)((uint)uVar3 >> 8);
  uStack_29 = (undefined1)uVar3;
  if (*param_1 == '\x01') {
    uStack_28 = 0xe1;
  }
  else {
    uStack_28 = 0xc;
  }
  uVar3 = *(undefined4 *)(param_1 + 0x28);
  uStack_27 = (undefined1)((uint)uVar3 >> 0x10);
  uStack_26 = (undefined1)((uint)uVar3 >> 8);
  uStack_25 = (undefined1)uVar3;
  uVar2 = internet_checksum16(&local_38,10);
  uStack_30 = CONCAT13((char)((ushort)uVar2 >> 8),CONCAT12((char)uVar2,(undefined2)uStack_30));
  uStack_24 = 0xa70fa70f;
  if (param_2 == '\x01') {
    uStack_20 = CONCAT22(SUBPIECE(uStack_20, 2, 2),0xd00);
    uStack_1c = CONCAT13((char)(*(ushort *)(param_1 + 0x32) >> 8),0xbf0300);
    uStack_18 = *(ushort *)(param_1 + 0x32) & 0xff;
    memcpy_bytes_iram(param_1 + 0x53,&uStack_2c,8);
    param_1[0x5b] = '\0';
    param_1[0x5c] = '\x11';
    param_1[0x5d] = '\0';
    param_1[0x5e] = '\r';
    memcpy_bytes_iram(param_1 + 0x5f,&uStack_24,0xe);
  }
  else {
    uVar1 = *(ushort *)(param_1 + 0x36c);
    SUBPIECE_SET(uStack_20, 0, 2, CONCAT11((char)uVar1 + '\x0e',(char)(uVar1 + 0xe >> 8)));
    SUBPIECE_SET(uStack_1c, 0, 2, CONCAT11((char)uVar1 + '\x04',(char)(uVar1 + 4 >> 8)));
    if (*param_1 == '\x01') {
      SUBPIECE_SET(uStack_1c, 0, 3, CONCAT12(0xa0,(undefined2)uStack_1c));
    }
    else {
      SUBPIECE_SET(uStack_1c, 0, 3, CONCAT12(0xe0,(undefined2)uStack_1c));
    }
    uStack_1c = CONCAT13((char)((ushort)*(undefined2 *)(param_1 + 0x32) >> 8),(undefined3)uStack_1c)
    ;
    uStack_18 = CONCAT11(4,(char)*(undefined2 *)(param_1 + 0x32));
    memcpy_bytes_iram(param_1 + 0x53,&uStack_2c,8);
    param_1[0x5b] = '\0';
    param_1[0x5c] = '\x11';
    param_1[0x5d] = (char)(*(ushort *)(param_1 + 0x36c) + 0xe >> 8);
    param_1[0x5e] = (char)*(ushort *)(param_1 + 0x36c) + '\x0e';
    memcpy_bytes_iram(param_1 + 0x5f,&uStack_24,0xe);
  }
  uVar2 = internet_checksum16(param_1 + 0x53,(*(ushort *)(param_1 + 0x36c) >> 1) + 0xd);
  uStack_20 = CONCAT13((char)((ushort)uVar2 >> 8),CONCAT12((char)uVar2,(undefined2)uStack_20));
  memcpy_bytes_iram(param_1 + 0x4b,&local_38,0x22);
  return;
}

