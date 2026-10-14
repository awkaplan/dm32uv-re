/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_030c3de8 @ 030c3de8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 62 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

void FUN_030c3de8(void)

{
  dword dVar1;
  
  if (*PTR_DAT_030c3fc8 != 0) {
    dVar1 = SystemControl_Type_11000000.IO_DIPLEX0;
    SystemControl_Type_11000000.IO_DIPLEX0 = dVar1 | 0x180;
    FUN_030c3dac(7);
    FUN_030c3dac(8);
    return;
  }
  dVar1 = SystemControl_Type_11000000.IO_DIPLEX0;
  SystemControl_Type_11000000.IO_DIPLEX0 = dVar1 | 0x60;
  FUN_030c3dac(5);
  FUN_030c3dac(6);
  return;
}

