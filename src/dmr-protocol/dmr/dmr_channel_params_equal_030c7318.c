/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dmr_channel_params_equal @ 030c7318 (file base 0x03000000; code starts at 0x03001000)
 * Size: 184 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: dmr-protocol
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

bool dmr_channel_params_equal
               (short param_1,short param_2,short param_3,int param_4,short param_5,short param_6,
               short param_7,short param_8,short param_9,short param_10)

{
  bool bVar1;
  short sVar2;
  undefined1 auStack_40 [12];
  undefined1 auStack_34 [12];
  short sStack_28;
  short sStack_26;
  
  sStack_26 = param_5;
  FUN_030caaec(auStack_34,param_4 + param_6 * 4,5,&sStack_26);
  sStack_28 = param_5;
  FUN_030caaec(auStack_40,param_4 + param_8 * 4,5,&sStack_28);
  sVar2 = FUN_030c7290(auStack_34,(int)sStack_26,(int)param_1,(int)param_3,(int)param_7,(int)param_6
                       ,(int)param_10);
  bVar1 = false;
  if (sVar2 != 0) {
    sVar2 = FUN_030c7290(auStack_40,(int)sStack_28,(int)param_2,(int)param_3,(int)param_9,
                         (int)param_8,(int)param_10);
    bVar1 = sVar2 != 0;
  }
  return bVar1;
}

