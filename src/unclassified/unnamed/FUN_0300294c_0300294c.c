/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_0300294c @ 0300294c (file base 0x03000000; code starts at 0x03001000)
 * Size: 40 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

void FUN_0300294c(int param_1)

{
  FUN_03002ff4(*(undefined1 *)(param_1 + 0x37));
  if (*(char *)(param_1 + 0x37) == *(char *)PTR_LAB_00016db4_1_03002974) {
    slot_list_push_back_a(param_1);
  }
  else {
    slot_list_push_front_a(param_1);
  }
  return;
}

