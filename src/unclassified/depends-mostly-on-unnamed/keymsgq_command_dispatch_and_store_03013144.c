/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: keymsgq_command_dispatch_and_store @ 03013144 (file base 0x03000000; code starts at 0x03001000)
 * Size: 50 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void keymsgq_command_dispatch_and_store(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 auStack_14 [6];
  undefined1 auStack_e [2];
  undefined1 auStack_c [4];
  
  puVar1 = PTR_DAT_030131d4;
  PTR_DAT_030131d4[0x404] = 1;
  puVar2 = (undefined1 *)
           guarded_request_command_dispatch(p_ucos_queue_keymsgq,0,0,auStack_e,auStack_14,auStack_c)
  ;
  puVar1[0x404] = 0;
  *(undefined1 *)PTR_DAT_030131dc = *puVar2;
  return;
}

