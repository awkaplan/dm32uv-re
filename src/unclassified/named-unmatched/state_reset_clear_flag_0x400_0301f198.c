/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: state_reset_clear_flag_0x400 @ 0301f198 (file base 0x03000000; code starts at 0x03001000)
 * Size: 24 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void state_reset_clear_flag_0x400(void)

{
  undefined2 *puVar1;
  
  os_flag_post_clear_0300c8d4(0x400);
  ucos3_task_create_prio25_stk0x100();
  puVar1 = PTR_DAT_0301f2f4;
  PTR_DAT_0301f2f4[10] = 0;
  *(undefined1 *)(puVar1 + 6) = 0;
  return;
}

