/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: aprs_waypoint_list_conditional_show @ 03062cdc (file base 0x03000000; code starts at 0x03001000)
 * Size: 38 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: analog-signaling
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void aprs_waypoint_list_conditional_show(undefined2 *param_1,undefined2 *param_2)

{
  int iVar1;
  
  iVar1 = aprs_log_count_read();
  if (iVar1 != 1) {
    circular_index_advance_with_capped_depth_counter(param_1,param_2,iVar1);
    aprs_info_list_screen(*param_1,*param_2,iVar1);
  }
  return;
}

