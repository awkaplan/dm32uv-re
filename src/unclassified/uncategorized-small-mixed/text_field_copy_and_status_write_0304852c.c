/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: text_field_copy_and_status_write @ 0304852c (file base 0x03000000; code starts at 0x03001000)
 * Size: 78 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void text_field_copy_and_status_write(undefined1 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = DAT_030486b8;
  memcpy_bytes_iram(DAT_030486b8,param_3,0x40);
  *(undefined1 *)(iVar1 + 0x40) = 0;
  if (param_2 == 0) {
    param_2 = 1;
  }
  if (*(char *)PTR_DAT_030486ac == 'T') {
    write_field_and_mbox_post(1,0xfe);
  }
  else {
    *(undefined1 *)PTR_active_screen_subtype_030486b0 = param_1;
    write_field_and_mbox_post(1,0x2d);
  }
  status_queue_push_and_signal(param_2,PTR_tx_pending_mbox_post_clear_030486b4,0);
  return;
}

