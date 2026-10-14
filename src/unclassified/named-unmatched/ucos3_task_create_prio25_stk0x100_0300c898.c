/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: ucos3_task_create_prio25_stk0x100 @ 0300c898 (file base 0x03000000; code starts at 0x03001000)
 * Size: 60 bytes
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

void ucos3_task_create_prio25_stk0x100(void)

{
  undefined4 uVar1;
  undefined1 auStack_10 [4];
  
  uVar1 = _DAT_0300c8f4;
  radio_command_jumptable_dispatch_iram(_DAT_0300c8f4,auStack_10);
  OSTaskCreate(uVar1,_DAT_0300c8fc,_DAT_0300c900,0,0x19,_DAT_0300c8f8,0,0x100,0,0,0,3,auStack_10);
  return;
}

