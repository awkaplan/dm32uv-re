/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: format_and_write_status_field2 @ 030472d0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 82 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: display-driver
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined4
format_and_write_status_field2
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_c = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  uVar1 = number_to_string_format(DAT_0304735c,param_1,&uStack_c);
  if (*(char *)PTR_DAT_03047360 == 'T') {
    write_field_and_mbox_post(1,0xfe);
  }
  else {
    *(undefined1 *)PTR_active_screen_subtype_03047364 = 0;
    write_field_and_mbox_post(1,0x2d);
  }
  status_queue_push_and_signal(10,PTR_tx_pending_mbox_post_clear_03047368,0);
  return uVar1;
}

