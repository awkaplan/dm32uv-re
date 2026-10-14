/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_03054980 @ 03054980 (file base 0x03000000; code starts at 0x03001000)
 * Size: 28 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_03054980(void)

{
  undefined4 *puVar1;
  
  OSSemCreate_shared_name_wrapper(_DAT_03054b78,1);
  puVar1 = PTR_DAT_03054b7c;
  *(undefined1 *)((int)PTR_DAT_03054b7c + 1) = 0;
  *(undefined1 *)puVar1 = 0;
  PTR_DAT_03054b80[2] = 0;
  *(undefined1 *)((int)puVar1 + 2) = 0;
  return;
}

