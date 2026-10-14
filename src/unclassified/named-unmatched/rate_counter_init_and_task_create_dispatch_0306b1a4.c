/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: rate_counter_init_and_task_create_dispatch @ 0306b1a4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 200 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void rate_counter_init_and_task_create_dispatch(undefined4 *param_1)

{
  ushort uVar1;
  ushort uVar2;
  undefined4 *puVar3;
  
  *PTR_DAT_0306b308 = 0;
  if (*PTR_LAB_0306b30c == 0) {
    *PTR_OSPrioCur_0306b314 = (uint)*PTR_LAB_0306b310 / 10;
  }
  else {
    *PTR_OSPrioCur_0306b314 = (uint)*PTR_LAB_0306b310 / (uint)*PTR_LAB_0306b30c;
  }
  *PTR_DAT_0306b318 = *PTR_OSPrioCur_0306b314;
  *PTR_DAT_0306b31c = 0;
  *PTR_DAT_0306b320 = 0;
  uVar1 = *PTR_DAT_0306b324;
  if (uVar1 != 0) {
    uVar2 = 0;
    puVar3 = PTR_DAT_0306b328;
    do {
      *(undefined2 *)puVar3 = 0;
      *(undefined2 *)((int)puVar3 + 2) = 0;
      puVar3[-1] = 0;
      uVar2 = uVar2 + 1;
      puVar3 = puVar3 + 2;
    } while (uVar2 < uVar1);
  }
  if (*(int *)PTR_LAB_0306b32c == 0) {
    *param_1 = 0x7347;
  }
  else if (*(uint *)PTR_LAB_0306b330 < *(uint *)PTR_LAB_0306b334) {
    *param_1 = 0x7348;
  }
  else if ((byte)*PTR_LAB_0306b338 < 0x3f) {
    OSTaskCreate(_DAT_0306b340,_DAT_0306b344,_DAT_0306b348,0,*PTR_LAB_0306b338,
                 *(int *)PTR_LAB_0306b32c,*(undefined4 *)PTR_LAB_0306b33c,*(uint *)PTR_LAB_0306b330,
                 0,0,0,0xb,param_1);
  }
  else {
    *param_1 = 0x7346;
  }
  return;
}

