/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_030c08b8 @ 030c08b8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 56 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

void FUN_030c08b8(int param_1,undefined1 param_2)

{
  int iVar1;
  int iVar2;
  short sVar3;
  
  *(undefined1 *)(param_1 + 0x37) = param_2;
  iVar1 = *(int *)(param_1 + 0x30);
  sVar3 = *(short *)(param_1 + 0x3e);
  if (sVar3 != 0) {
    while( true ) {
      if (1 < *(ushort *)(*(int *)(iVar1 + 0xc) + 0x10)) {
        iVar2 = *(int *)(iVar1 + 0xc) + 8;
        list_node_unlink_c(iVar2,iVar1);
        pend_list_insert_by_prio_b(iVar2,iVar1);
      }
      sVar3 = sVar3 + -1;
      if (sVar3 == 0) break;
      iVar1 = iVar1 + 0x20;
    }
  }
  return;
}

