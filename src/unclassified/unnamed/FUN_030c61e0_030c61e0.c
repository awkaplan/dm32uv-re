/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_030c61e0 @ 030c61e0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 86 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_030c61e0(void)

{
  undefined1 *puVar1;
  int iVar2;
  
  puVar1 = PTR_DAT_030c62b8;
  PTR_DAT_030c62b8[0x19d3] = 0;
  puVar1[0x1728] = 0;
  iVar2 = _DAT_030c62bc;
  *(undefined2 *)(puVar1 + 0x1732) = 0;
  *(undefined2 *)(puVar1 + 0x1734) = 0;
  *(undefined2 *)(puVar1 + 0x1896) = 0;
  *(undefined2 *)(puVar1 + 0x1894) = 0;
  puVar1[0x172a] = 0;
  *(undefined2 *)(puVar1 + 0x1730) = 0;
  *(undefined1 *)PTR_DAT_030c62c0 = 0;
  func_0x030deca4(iVar2,0,0x1b);
  func_0x030deca4(iVar2 + 0x1b,0,0x1b);
  return;
}

