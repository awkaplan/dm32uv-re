/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: radio_event_dispatch_by_name @ 0300c438 (file base 0x03000000; code starts at 0x03001000)
 * Size: 22 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: radio-state
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4 radio_event_dispatch_by_name(undefined4 param_1,undefined4 param_2)

{
  undefined4 uStack_c;
  
  queue_list_init_and_register(param_1,PTR_s_event_0300c5d8,param_2,&uStack_c);
  return uStack_c;
}

