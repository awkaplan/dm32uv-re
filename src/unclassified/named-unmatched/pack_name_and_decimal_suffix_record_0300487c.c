/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: pack_name_and_decimal_suffix_record @ 0300487c (file base 0x03000000; code starts at 0x03001000)
 * Size: 150 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void pack_name_and_decimal_suffix_record(undefined1 *param_1,char *param_2,undefined4 *param_3)

{
  char cVar1;
  uint uVar2;
  short sVar3;
  uint uVar4;
  int iVar5;
  char acStack_1c [12];
  
  *param_1 = 1;
  param_1[1] = 0;
  param_1[2] = 0xff;
  cVar1 = *param_2;
  if (cVar1 == '\0') {
    iVar5 = 0;
    sVar3 = 0;
  }
  else {
    iVar5 = 0;
    sVar3 = 0;
    do {
      param_2 = param_2 + 1;
      param_1[iVar5 + 3] = cVar1;
      sVar3 = sVar3 + 1;
      iVar5 = iVar5 + 1;
      cVar1 = *param_2;
      if (cVar1 == '\0') break;
    } while (sVar3 != 0x100);
  }
  param_1[iVar5 + 3] = 0;
  uint_to_trimmed_decimal_ascii(acStack_1c,*param_3);
  uVar4 = (uint)(ushort)(sVar3 + 4);
  if (acStack_1c[0] != '\0') {
    uVar2 = 0;
    do {
      param_1[uVar4] = acStack_1c[0];
      uVar4 = uVar4 + 1 & 0xffff;
      uVar2 = uVar2 + 1 & 0xffff;
      acStack_1c[0] = acStack_1c[uVar2];
    } while (acStack_1c[0] != '\0');
  }
  if (uVar4 < 0x83) {
    do {
      param_1[uVar4] = 0;
      uVar4 = uVar4 + 1 & 0xffff;
    } while (uVar4 != 0x83);
  }
  return;
}

