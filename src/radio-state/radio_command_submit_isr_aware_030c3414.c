/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: radio_command_submit_isr_aware @ 030c3414 (file base 0x03000000; code starts at 0x03001000)
 * Size: 72 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: radio-state
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void radio_command_submit_isr_aware(int param_1,undefined4 *param_2)

{
  if (param_1 == _DAT_030c3460) {
    *param_2 = 0x715b;
  }
  else if (param_1 == _DAT_030c3464) {
    *param_2 = 0x715c;
  }
  else if (*(char *)PTR_OSIntNestingCtr_030c3468 == '\0') {
    radio_command_jumptable_dispatch_flash();
  }
  else {
    bounded_queue_append_with_dropcount(_DAT_030c346c,param_1,0,0,0,0,0,param_2);
  }
  return;
}

