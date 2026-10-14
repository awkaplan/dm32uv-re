/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_030c0bc0 @ 030c0bc0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 40 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

void FUN_030c0bc0(int param_1)

{
  FUN_030c1634(*(undefined1 *)(param_1 + 0x37));
  if (*(char *)(param_1 + 0x37) == *(char *)PTR_DAT_030c0cb0) {
    slot_list_push_back_b(param_1);
  }
  else {
    slot_list_push_front_b(param_1);
  }
  return;
}

