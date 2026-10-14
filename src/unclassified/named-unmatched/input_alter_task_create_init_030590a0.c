/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: input_alter_task_create_init @ 030590a0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 86 bytes
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

void input_alter_task_create_init(void)

{
  undefined4 uVar1;
  undefined1 auStack_10 [4];
  
  uVar1 = _DAT_03059120;
  memset_bytes(_DAT_03059120,0,800);
  OSTaskCreate(_DAT_03059124,PTR_s_task_InputAlter_030b15ef_1_03059128,
               PTR_text_entry_input_loop_blocking_0305912c,0,0x25,uVar1,0,200,0,0,0,3,auStack_10);
  OSTmrCreate(_DAT_03059134,_DAT_03059138,1,6,2,PTR_text_entry_backspace_and_channel_insert_03059130
              ,0,auStack_10);
  return;
}

