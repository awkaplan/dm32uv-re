/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: event_flags14_dispatch_hw_and_flaggrp @ 0305edfc (file base 0x03000000; code starts at 0x03001000)
 * Size: 90 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rtos
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void event_flags14_dispatch_hw_and_flaggrp(void)

{
  byte bVar1;
  
  bVar1 = get_event_flags_byte_dispatch(0x14);
  if ((bVar1 & 1) == 0) {
    if ((bVar1 & 2) == 0) {
      if ((bVar1 & 4) != 0) {
        update_event_flags_byte_dispatch(0x14,4);
        mmio_11000074_bits78_set_from_status_nibble();
        OSFlagPost_wrapper_set(p_ucos_flaggrp_0003fd90,0x2000);
      }
    }
    else {
      update_event_flags_byte_dispatch(0x14,2);
      ui_event_notify(0x1b);
    }
  }
  else {
    update_event_flags_byte_dispatch(0x14,1);
    OSFlagPost_wrapper_set(p_ucos_flaggrp_0003fd90,0x20);
  }
  return;
}

