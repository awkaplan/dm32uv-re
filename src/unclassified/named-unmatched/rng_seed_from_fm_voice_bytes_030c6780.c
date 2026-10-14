/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: rng_seed_from_fm_voice_bytes @ 030c6780 (file base 0x03000000; code starts at 0x03001000)
 * Size: 110 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

uint rng_seed_from_fm_voice_bytes(void)

{
  dword dVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  
  iVar7 = func_0x0611fac4();
  puVar6 = PTR_DAT_030c67f0;
  dVar1 = SystemControl_Type_11000000.RSSI_BIAS_VALUE;
  iVar11 = PTR_DAT_030c67f0[8];
  iVar8 = FUN_030c6eb8();
  iVar9 = FUN_030c6ed0();
  bVar2 = DAT_16000032;
  bVar3 = DAT_16000033;
  bVar4 = Modem_Buffer_16000232;
  bVar5 = Modem_Buffer_16000233;
  uVar10 = _DAT_030c67f8 *
           (dVar1 + iVar11 + (uint)bVar5 +
            ((uint)bVar4 + ((uint)bVar2 * 0x100 + (uint)bVar3) * 0x100) * 0x100 + iVar8 + iVar9 +
           iVar7) + 0x3039;
  puVar6[8] = uVar10;
  return uVar10 >> 0x10 & 0xff;
}

