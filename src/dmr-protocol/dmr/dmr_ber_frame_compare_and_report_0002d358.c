/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: dmr_ber_frame_compare_and_report @ 0002d358 (IRAM address; the boot stub copies these bytes from program flash 0x030dcf78)
 * Size: 276 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: dmr-protocol
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void dmr_ber_frame_compare_and_report(void)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  undefined *puVar4;
  int iVar5;
  uint uVar6;
  byte *pbVar7;
  byte *pbVar8;
  undefined1 auStack_16 [6];
  undefined4 uStack_10;
  
  *puRam0002d4b4 = 1;
  iVar5 = func_0x03027400(pbRam0002d4b8);
  if (iVar5 == 1) {
    pbRam0002d4b8[0x24] = 0;
  }
  pbVar3 = pbRam0002d4b8;
  *(int *)(pbRam0002d4b8 + 0x28) = *(int *)(pbRam0002d4b8 + 0x28) + 1;
  pbVar8 = (byte *)(iRam0002d4bc + (uint)pbVar3[0x24] * 0x21);
  pbVar7 = pbVar3;
  do {
    bVar1 = *pbVar7;
    bVar2 = *pbVar8;
    if ((bVar1 ^ bVar2) != 0) {
      uVar6 = 0;
      do {
        if (((int)(uint)(bVar1 ^ bVar2) >> (uVar6 & 0x3f) & 1U) != 0) {
          *(int *)(pbVar3 + 0x2c) = *(int *)(pbVar3 + 0x2c) + 1;
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 != 8);
    }
    pbVar8 = pbVar8 + 1;
    pbVar7 = pbVar7 + 1;
  } while (pbVar7 != pbVar3 + 0x21);
  bVar1 = pbRam0002d4b8[0x24];
  pbRam0002d4b8[0x24] = bVar1 + 1;
  if (5 < (byte)(bVar1 + 1)) {
    pbRam0002d4b8[0x24] = 0;
  }
  if (0x77 < *(uint *)(pbRam0002d4b8 + 0x28)) {
    func_0x0306e8c4(*(undefined4 *)(pbRam0002d4b8 + 0x2c));
    func_0x0306e898();
    func_0x0306efb8();
    func_0x0306efb8();
    uStack_10 = func_0x0306f450();
    puVar4 = PTR_DAT_0002d4cc;
    if (*PTR_DAT_0002d4c8 == '\0') {
      func_0x03023128(PTR_DAT_0002d4cc,uStack_10,2,4);
      memcpy_bytes_iram(PTR_DAT_0002d4d0,puVar4,10);
      if ((PTR_DAT_0002d4d4[1] & 0x10) == 0) {
        func_0x03017c50(0,0x82,0xf0,0xdc,0);
        pbVar3 = pbRam0002d4b8;
        func_0x03019fc4(0x82,0,0xffff,0,uRam0002d4d8,*(undefined4 *)(pbRam0002d4b8 + 0x28));
        func_0x03019fc4(0xa0,0,0xffff,0,uRam0002d4dc,*(undefined4 *)(pbVar3 + 0x2c));
        func_0x030231e8(0xbe,0,uRam0002d4e0,pbVar3 + 0x30);
      }
    }
    else {
      memcpy_bytes_iram(auStack_16,&uStack_10,4);
    }
    pbVar3 = pbRam0002d4b8;
    pbVar3[0x2c] = 0;
    pbVar3[0x2d] = 0;
    pbVar3[0x2e] = 0;
    pbVar3[0x2f] = 0;
    pbVar3[0x28] = 0;
    pbVar3[0x29] = 0;
    pbVar3[0x2a] = 0;
    pbVar3[0x2b] = 0;
  }
  return;
}

