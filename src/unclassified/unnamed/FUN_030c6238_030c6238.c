/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_030c6238 @ 030c6238 (file base 0x03000000; code starts at 0x03001000)
 * Size: 128 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_030c6238(void)

{
  undefined1 *puVar1;
  int iVar2;
  undefined1 *puVar3;
  
  puVar1 = PTR_DAT_030c62c4;
  puVar3 = PTR_DAT_030c62c4 + 0x1156;
  PTR_DAT_030c62c4[0x1493] = 0;
  puVar1[0x1150] = 0;
  *(undefined2 *)(puVar1 + 0x1162) = 0;
  *(undefined2 *)(puVar1 + 0x1164) = 0;
  *(undefined2 *)(puVar1 + 0x1352) = 0;
  *(undefined2 *)(puVar1 + 0x1350) = 0;
  *(undefined2 *)(puVar1 + 0x134e) = 0;
  func_0x030deca4(puVar3,0,3);
  func_0x030deca4(puVar1 + 0x115c,0,3);
  iVar2 = _DAT_030c62cc;
  *(undefined1 *)PTR_DAT_030c62c8 = 0;
  func_0x030deca4(iVar2,0,0x1b);
  func_0x030deca4(iVar2 + 0x1b,0,0x1b);
  iVar2 = _DAT_030c62d0;
  *(undefined1 *)PTR_DAT_030c62d4 = 0;
  func_0x030deca4(iVar2,0,0x1b);
  func_0x030deca4(iVar2 + 0x1b,0,0x1b);
  return;
}

