/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: FUN_000105b8 @ 000105b8 (IRAM address; the boot stub copies these bytes from program flash 0x030c01d8)
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

void FUN_000105b8(void)

{
  undefined4 uVar1;
  undefined *puVar2;
  undefined4 unaff_r4;
  int iVar3;
  
  puVar2 = PTR_OSTCBCurPtr_000106b8;
  uVar1 = *(undefined4 *)PTR_OSTCBHighRdyPtr_000106bc;
  *(undefined4 *)PTR_OSTCBCurPtr_000106b8 = uVar1;
  iVar3 = *(int *)uVar1;
  func_0x000107c0();
  control_register_write(*(undefined4 *)(iVar3 + 0x40),unaff_r4);
  control_register_write(*(undefined4 *)(iVar3 + 0x3c),puVar2);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

