/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: ucos3_tmr_dlyhnd_create_oneshot_10tick @ 030331d0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 44 bytes
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

void ucos3_tmr_dlyhnd_create_oneshot_10tick(void)

{
  undefined1 auStack_8 [4];
  
  OSSemCreate_shared_name_wrapper(p_ucos_mutex_00032080,1);
  OSTmrCreate(p_ucos_tmr_dlyhnd,_DAT_030332c0,10,10,1,_DAT_030332b8,0,auStack_8);
  return;
}

