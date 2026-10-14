/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: subsystem_buffer_reset_and_task_init_0x600 @ 03030360 (file base 0x03000000; code starts at 0x03001000)
 * Size: 70 bytes
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

void subsystem_buffer_reset_and_task_init_0x600(void)

{
  undefined4 uVar1;
  undefined1 auStack_c [4];
  
  OSSemCreate_shared_name_wrapper(_DAT_030303a8,1);
  uVar1 = _DAT_030303ac;
  memset_bytes(_DAT_030303ac,0,0x600);
  OSTaskCreate(_DAT_030303b0,_DAT_030303b4,_DAT_030303b8,0,0x1c,uVar1,0,0x180,0,0,0,3,auStack_c);
  return;
}

