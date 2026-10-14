/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_030c6e5c @ 030c6e5c (file base 0x03000000; code starts at 0x03001000)
 * Size: 50 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

undefined4 FUN_030c6e5c(int param_1,ushort param_2)

{
  undefined1 uVar1;
  uint uVar2;
  
  SSI_Type_14150000.SSIENR = 1;
  SSI_Type_14150000.SER = 1;
  if (param_2 != 0) {
    uVar2 = 0;
    do {
      uVar1 = FUN_030c6e24(0xff);
      *(undefined1 *)(param_1 + uVar2) = uVar1;
      uVar2 = uVar2 + 1;
    } while (uVar2 < param_2);
  }
  SSI_Type_14150000.SER = 0;
  return 0;
}

