/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flash_field_channel_table_lookup @ 030664ec (file base 0x03000000; code starts at 0x03001000)
 * Size: 124 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: flash-storage
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

ushort flash_field_channel_table_lookup(uint param_1,ushort param_2)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  byte *pbVar4;
  byte bVar5;
  ushort uVar6;
  byte local_28;
  byte local_27 [15];
  
  flash_field_read_cached(0x65,(param_1 & 0xff) * 0x21 + 0x21,&local_28,0x10);
  if ((byte)PTR_DAT_03066674[6] != 0) {
    bVar2 = *(byte *)PTR_DAT_0306666c;
    uVar6 = 0;
    uVar3 = 1;
    do {
      if (bVar2 == 0) {
LAB_0306653a:
        uVar6 = uVar6 + 1;
        if ((param_2 & 0xff) == uVar6) {
          return uVar3 & 0xff;
        }
      }
      else {
        pbVar4 = local_27;
        bVar5 = 0;
        if (local_28 != uVar3) {
          do {
            bVar5 = bVar5 + 1;
            if (bVar2 <= bVar5) break;
            bVar1 = *pbVar4;
            pbVar4 = pbVar4 + 1;
          } while (bVar1 != uVar3);
          if (bVar2 == bVar5) goto LAB_0306653a;
        }
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 <= (byte)PTR_DAT_03066674[6]);
  }
  return 0;
}

