/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: grid_draw_checked_timed_a @ 030c5dc8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 100 bytes
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

undefined4 grid_draw_checked_timed_a(uint param_1,undefined4 param_2,uint param_3,int param_4)

{
  param_1 = param_1 & 0xff;
  param_3 = param_3 & 0xff;
  if (0x1a < param_1) {
    return 1;
  }
  if (0x1b < param_3) {
    return 2;
  }
  if (0x1b < param_3 + param_1) {
    return 3;
  }
  if (param_4 != 0) {
    decisecond_round_up_dispatch(_DAT_030c5ea0,param_4);
  }
  if (*(char *)PTR_DAT_030c5e94 != '\0') {
    func_0x030dec8c(_DAT_030c5e98 + param_1,param_2,param_3);
    return 0;
  }
  func_0x030dec8c(_DAT_030c5e9c + param_1,param_2,param_3);
  return 0;
}

