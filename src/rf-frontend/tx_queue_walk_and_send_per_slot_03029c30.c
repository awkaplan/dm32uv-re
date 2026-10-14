/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: tx_queue_walk_and_send_per_slot @ 03029c30 (file base 0x03000000; code starts at 0x03001000)
 * Size: 82 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rf-frontend
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void tx_queue_walk_and_send_per_slot(uint param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar2 = PTR_DAT_03029d8c[(param_1 & 0xff) + 0x29];
  while( true ) {
    while( true ) {
      if (iVar2 == 0) {
        return;
      }
      if ((*(char *)(iVar2 + 2) == '\x01') && (*(byte *)(iVar2 + 3) < 6)) break;
      iVar2 = *(int *)(iVar2 + 0x20);
    }
    iVar3 = *(int *)(iVar2 + 0x20);
    if (iVar3 == 0) break;
    if (*(short *)(iVar3 + 2) == 0x200) {
      iVar4 = *(int *)(iVar3 + 0x20);
      if (iVar4 == 0) {
        return;
      }
      if (*(short *)(iVar4 + 2) == 0x100) {
        iVar5 = *(int *)(iVar4 + 0x20);
        if (iVar5 == 0) {
          return;
        }
        if (*(short *)(iVar5 + 2) == 1) {
          iVar1 = buffer_compare_memcmp_style(iVar4 + 5,iVar3 + 5,9);
          if (iVar1 == 0) {
            *(undefined4 *)(iVar2 + 0x20) = *(undefined4 *)(iVar5 + 0x20);
            clear_byte_at_ptr(iVar3);
            clear_byte_at_ptr(iVar4);
            clear_byte_at_ptr(iVar5);
            if (*(int *)(iVar2 + 0x20) == 0) {
              PTR_DAT_03029d8c[(param_1 & 0xff) + 0x2b] = iVar2;
              return;
            }
          }
          else {
            iVar2 = *(int *)(iVar5 + 0x20);
          }
        }
        else {
          iVar2 = *(int *)(iVar5 + 0x20);
        }
      }
      else {
        iVar2 = *(int *)(iVar4 + 0x20);
      }
    }
    else {
      iVar2 = *(int *)(iVar3 + 0x20);
    }
  }
  return;
}

