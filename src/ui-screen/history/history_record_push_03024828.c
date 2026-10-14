/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: history_record_push @ 03024828 (file base 0x03000000; code starts at 0x03001000)
 * Size: 210 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-screen
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void history_record_push(void)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  iVar5 = history_slot_allocate();
  if (iVar5 == 0) {
    OSTimeDly_ms_wrapper(0x46);
    iVar5 = history_slot_allocate();
    if (iVar5 == 0) {
      return;
    }
  }
  if (PTR_DAT_03024a84[3] == 0) {
    uVar8 = 0;
  }
  else {
    uVar8 = (uint)*(byte *)((int)PTR_DAT_03024a84 + 7);
  }
  bVar1 = *(byte *)((int)PTR_DAT_03024a84 + 9);
  uVar2 = *(ushort *)(PTR_DAT_03024a84 + 2);
  uVar3 = *(ushort *)((int)PTR_DAT_03024a84 + 0xe);
  uVar6 = PTR_DAT_03024a84[3] & 0xfffff;
  uVar4 = *(ushort *)((int)PTR_DAT_03024a84 + 0x12);
  uVar7 = PTR_DAT_03024a84[4] & 0xfffff;
  *(undefined1 *)(iVar5 + 2) = 0;
  *(undefined1 *)(iVar5 + 3) = 3;
  memset_bytes(iVar5 + 5,0,0x18);
  *(undefined1 *)(iVar5 + 5) = 0x87;
  *(undefined1 *)(iVar5 + 6) = 0;
  *(char *)(iVar5 + 7) = (char)((int)(uVar2 & 0x7ff) >> 3);
  *(byte *)(iVar5 + 8) = (byte)((uVar2 & 0x7ff) << 5) | bVar1 >> 3;
  *(char *)(iVar5 + 9) = (char)(uVar6 >> 0xc);
  *(byte *)(iVar5 + 10) = (byte)(uVar6 >> 4) & 0xfe;
  *(byte *)(iVar5 + 0xb) = (byte)(uVar6 << 3) | (char)(uVar3 >> 4) * '\x02' | (byte)(uVar8 >> 1);
  *(char *)(iVar5 + 0xc) = (char)(uVar7 >> 0xc);
  *(byte *)(iVar5 + 0xd) = (byte)(uVar7 >> 4) & 0xfe;
  *(byte *)(iVar5 + 0xe) = (byte)uVar8 & 1 | (char)(uVar4 >> 4) * '\x02' | (byte)(uVar7 << 3);
  history_slot_link_append(iVar5);
  return;
}

