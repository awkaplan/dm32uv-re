/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: vfprintf_core @ 03070724 (file base 0x03000000; code starts at 0x03001000)
 * Size: 150 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

int vfprintf_core(undefined4 *param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  cVar1 = *param_2;
joined_r0x0307073c:
  if (cVar1 == '\0') {
    return iVar3;
  }
  pcVar2 = param_2;
  if (cVar1 != '%') goto code_r0x03070746;
  goto LAB_03070788;
code_r0x03070746:
  iVar4 = 0;
  do {
    pcVar2 = pcVar2 + 1;
    iVar4 = iVar4 + 1;
    if (*pcVar2 == '\0') break;
  } while (*pcVar2 != '%');
  if (iVar4 != 0) {
    (*(code *)(param_1[1] & 0xfffffffe))(param_2,iVar4,*param_1);
    cVar1 = *pcVar2;
    iVar3 = iVar4 + iVar3;
    param_2 = pcVar2;
    if (cVar1 == '%') {
LAB_03070788:
      if ((byte)pcVar2[1] < 0x7b) {
                    /* WARNING: Could not recover jumptable at 0x030707b8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        iVar3 = (*(code *)(PTR_DAT_030707c0[(byte)pcVar2[1]] & 0xfffffffe))();
        return iVar3;
      }
      cVar1 = pcVar2[2];
      param_2 = pcVar2 + 2;
    }
  }
  goto joined_r0x0307073c;
}

