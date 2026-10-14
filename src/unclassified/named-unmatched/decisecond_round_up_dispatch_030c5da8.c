/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: decisecond_round_up_dispatch @ 030c5da8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 30 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4 decisecond_round_up_dispatch(undefined4 param_1,int param_2)

{
  undefined1 auStack_10 [4];
  undefined4 uStack_c;
  
  timed_task_teardown_with_status_report(param_1,(param_2 + 9U) / 10,0,auStack_10,&uStack_c);
  return uStack_c;
}

