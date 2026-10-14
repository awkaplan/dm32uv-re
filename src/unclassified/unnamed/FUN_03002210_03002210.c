/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_03002210 @ 03002210 (file base 0x03000000; code starts at 0x03001000)
 * Size: 38 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Control flow encountered bad instruction data */

void FUN_03002210(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 unaff_r4;
  int iVar3;
  
  puVar2 = puRam03002310;
  uVar1 = *puRam03002314;
  *puRam03002310 = uVar1;
  iVar3 = *(int *)uVar1;
  FUN_030023e4();
  control_register_write(*(undefined4 *)(iVar3 + 0x40),unaff_r4);
  control_register_write(*(undefined4 *)(iVar3 + 0x3c),puVar2);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

