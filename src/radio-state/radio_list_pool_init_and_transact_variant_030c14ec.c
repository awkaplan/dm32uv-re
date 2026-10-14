/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: radio_list_pool_init_and_transact_variant @ 030c14ec (file base 0x03000000; code starts at 0x03001000)
 * Size: 206 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: radio-state
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void radio_list_pool_init_and_transact_variant(undefined4 *param_1)

{
  ushort uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  *(undefined2 *)PTR_DAT_030c15cc = 0;
  puVar5 = (undefined4 *)*_DAT_030c15d0;
  if (puVar5 == (undefined4 *)0x0) {
    *param_1 = 0x4652;
  }
  else {
    uVar1 = *(ushort *)PTR_LAB_030c15d4;
    if (uVar1 < 2) {
      *param_1 = 0x4654;
    }
    else {
      *PTR_DAT_030c15c4 = 0;
      uVar2 = _DAT_030c15d8;
      puVar4 = puVar5;
      if (uVar1 != 0) {
        do {
          *puVar4 = uVar2;
          puVar4[2] = 0;
          puVar4[3] = 0;
          *(undefined2 *)(puVar4 + 4) = 0;
          puVar4[5] = 0;
          *(undefined2 *)(puVar4 + 6) = 0;
          puVar3 = puVar4 + 8;
          puVar4[1] = puVar3;
          puVar4 = puVar3;
        } while (puVar3 != puVar5 + (uint)(ushort)(uVar1 - 1) * 8 + 8);
        puVar4 = puVar5 + ((ushort)(uVar1 - 1) + 1) * 8;
      }
      puVar4[-7] = puVar5;
      *PTR_DAT_030c15dc = puVar5;
      *PTR_DAT_030c15c8 = puVar5;
      *(undefined2 *)PTR_DAT_030c15bc = 0;
      *(undefined2 *)PTR_DAT_030c15e0 = 0;
      if (*(int *)PTR_LAB_030c15e4 == 0) {
        *param_1 = 0x4655;
      }
      else if (*(uint *)PTR_LAB_030c15e8 < *(uint *)PTR_LAB_030c15ec) {
        *param_1 = 0x4656;
      }
      else {
        OSTaskCreate_variant2
                  (_DAT_030c15f4,_DAT_030c15f8,_DAT_030c15fc,0,0,*(int *)PTR_LAB_030c15e4,
                   *(undefined4 *)PTR_LAB_030c15f0,*(uint *)PTR_LAB_030c15e8,0,0,0,3,param_1);
      }
    }
  }
  return;
}

