/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: display_buffer_command_dispatch @ 030c9958 (file base 0x03000000; code starts at 0x03001000)
 * Size: 128 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: display-driver
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void display_buffer_command_dispatch(short *param_1)

{
  ushort uVar1;
  short sVar2;
  int iVar3;
  
  sVar2 = *param_1;
  if (sVar2 == 2) {
    u16_buffer_fill_memset(*(undefined4 *)(param_1 + 0x40),0,0x38);
    return;
  }
  if (sVar2 == 3) {
    u16_buffer_fill_memset(*(undefined4 *)(param_1 + 0x40),0,0x38);
    sVar2 = classify_id_into_range_bucket((int)param_1[1]);
    if (sVar2 == 0) {
      *(undefined2 *)(*(int *)(param_1 + 0x40) + param_1[3] * 2) = 1;
      return;
    }
    if ((-1 < sVar2) && (sVar2 < 4)) {
      uVar1 = param_1[3];
      iVar3 = *(int *)(param_1 + 0x40);
      *(undefined2 *)(iVar3 + (uint)(uVar1 >> 8) * 2) = 1;
      *(undefined2 *)(iVar3 + (uVar1 & 0xff) * 2) = 1;
      return;
    }
  }
  else if (sVar2 == 1) {
    func_0x030d28f0(*(undefined4 *)(param_1 + 0x40),*(undefined4 *)(param_1 + 4),(int)param_1[6],
                    (int)param_1[2]);
    return;
  }
  return;
}

