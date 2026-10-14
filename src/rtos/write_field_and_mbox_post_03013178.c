/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: write_field_and_mbox_post @ 03013178 (file base 0x03000000; code starts at 0x03001000)
 * Size: 68 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rtos
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void write_field_and_mbox_post(uint field,uint value)

{
  undefined1 auStack_8 [4];
  
  *(char *)PTR_DAT_030131e0 = (char)value;
  if (((field & 0xff) == 1) || ((field & 0xff) == 3)) {
    os_post_message_opt_validated(p_ucos_queue_keymsgq,PTR_DAT_030131e0,1,0,auStack_8);
  }
  else if (PTR_DAT_030131d4[0x404] == '\x01') {
    os_post_message_opt_validated(p_ucos_queue_keymsgq,PTR_DAT_030131e0,1,0,auStack_8);
  }
  return;
}

