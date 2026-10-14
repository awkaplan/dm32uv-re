/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_030c66f0 @ 030c66f0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 82 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_030c66f0(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = _DAT_030c67f4;
  puVar1 = PTR_DAT_030c67f0;
  SystemControl_Type_11000000.RF_MODE = *PTR_DAT_030c67f0;
  SystemControl_Type_11000000.WORK_MODE = PTR_DAT_030c67f0[1];
  SystemControl_Type_11000000.AUDIO_CONTROL = PTR_DAT_030c67f0[2];
  SystemControl_Type_11000000.FM_PTT = PTR_DAT_030c67f0[3];
  SystemControl_Type_11000000.SYS_INTERP_MASK = PTR_DAT_030c67f0[4];
  *(undefined1 *)(_DAT_030c67f4 + 0xd2) = *(undefined1 *)(PTR_DAT_030c67f0 + 6);
  *(undefined1 *)(iVar2 + 0xd3) = *(undefined1 *)((int)puVar1 + 0x19);
  *(undefined1 *)(iVar2 + 0xcb) = *(undefined1 *)((int)puVar1 + 0x1a);
  *(undefined1 *)(iVar2 + 0xcc) = *(undefined1 *)((int)puVar1 + 0x1b);
  *(undefined1 *)(iVar2 + 0xc9) = *(undefined1 *)(puVar1 + 7);
  *(undefined1 *)(iVar2 + 0xcf) = *(undefined1 *)((int)puVar1 + 0x1d);
  return;
}

