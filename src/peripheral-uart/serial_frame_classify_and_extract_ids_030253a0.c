/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: serial_frame_classify_and_extract_ids @ 030253a0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 372 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: peripheral-uart
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

uint serial_frame_classify_and_extract_ids(int param_1)

{
  char cVar1;
  byte bVar2;
  undefined2 *puVar3;
  uint uVar4;
  
  puVar3 = PTR_DAT_030255c4;
  if ((*(byte *)(param_1 + 0x394) & 2) == 0) {
    cVar1 = *(char *)(param_1 + 4);
    if ((byte)(cVar1 - 2U) < 2) {
      bVar2 = *(byte *)(param_1 + 0x5a);
      if (bVar2 == 0x44) {
        uVar4 = (uint)*(byte *)(param_1 + 0x5d) * 0x100 + (uint)*(byte *)(param_1 + 0x5e);
        PTR_DAT_030255c4[0x1a] = (ushort)*(byte *)(param_1 + 0x5c);
        puVar3[0x1c] = (ushort)*(byte *)(param_1 + 0x60) * 0x100 + (ushort)*(byte *)(param_1 + 0x61)
        ;
        if (uVar4 == 3) {
          uVar4 = 8;
        }
        else if (uVar4 < 4) {
          uVar4 = 0;
        }
        else {
          uVar4 = 4;
        }
      }
      else if (bVar2 == 0x45) {
        uVar4 = (uint)*(byte *)(param_1 + 0x5c) * 0x100 + (uint)*(byte *)(param_1 + 0x5d);
        PTR_DAT_030255c4[0x1a] =
             (ushort)*(byte *)(param_1 + 0x5f) + (ushort)*(byte *)(param_1 + 0x5e) * 0x100;
        puVar3[0x1c] = (ushort)*(byte *)(param_1 + 0x7a) + (ushort)*(byte *)(param_1 + 0x79) * 0x100
        ;
        if (uVar4 == 0x21) {
          uVar4 = 2;
        }
        else {
          uVar4 = (uint)(0x21 < uVar4);
        }
      }
      else if (*(char *)(param_1 + 6) == '\x03') {
        if (((bVar2 == 0) && (*(char *)(param_1 + 0x5f) == '\'')) &&
           (*(char *)(param_1 + 0x60) == '~')) {
          PTR_DAT_030255c4[0x1a] = (ushort)*(byte *)(param_1 + 0x5e) * 0x100 + 0x27;
          puVar3[0x1c] = (ushort)*(byte *)(param_1 + 0x79) * 0x100 +
                         (ushort)*(byte *)(param_1 + 0x7a);
          uVar4 = 0x2000;
        }
        else if ((*(char *)(param_1 + 0x5c) == '\0') || (*(char *)(param_1 + 0x5c) == '\x02')) {
          if ((undefined **)(*(uint *)(param_1 + 0x5c) & 0xffff00) == &PTR_DAT_00010100) {
            PTR_DAT_030255c4[0x1a] = (ushort)bVar2 + (ushort)*(byte *)(param_1 + 0x5b) * 0x100;
            puVar3[0x1c] = (ushort)*(byte *)(param_1 + 0x79) * 0x100 +
                           (ushort)*(byte *)(param_1 + 0x7a);
            uVar4 = 0x8000;
          }
          else {
            uVar4 = 0;
          }
        }
        else {
          uVar4 = 0;
        }
      }
      else {
        uVar4 = 0;
      }
    }
    else if (cVar1 == '\r') {
      PTR_DAT_030255c4[0x1a] =
           (ushort)*(byte *)(param_1 + 0x5e) * 0x100 + (ushort)*(byte *)(param_1 + 0x5f);
      puVar3[0x1c] = (ushort)*(byte *)(param_1 + 0x79) * 0x100 + (ushort)*(byte *)(param_1 + 0x7a);
      uVar4 = 0x10;
    }
    else if (cVar1 == '\x0e') {
      uVar4 = 0x20;
    }
    else if (cVar1 == '\x01') {
      uVar4 = 0x80;
    }
    else {
      uVar4 = 0;
    }
  }
  else {
    uVar4 = 0x800;
  }
  return uVar4;
}

