/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: OSCtxSw @ 000105be (IRAM address; the boot stub copies these bytes from program flash 0x030c01de)
 * Size: 42 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rtos
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Control flow encountered bad instruction data */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void OSCtxSw(void)

{
  int *piVar1;
  undefined *puVar2;
  undefined *puVar3;
  int *piVar4;
  
  puVar3 = PTR_OSTCBHighRdyPtr_000106bc;
  puVar2 = PTR_OSTCBCurPtr_000106b8;
  piVar1 = DAT_000106b4;
  if (*DAT_000106b4 != 0) {
    **(int **)PTR_OSTCBCurPtr_000106b8 = *DAT_000106b4;
    piVar4 = *(int **)puVar3;
    *(int **)puVar2 = piVar4;
    *piVar1 = *piVar4;
    return;
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

