/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: OSIntCtxSw @ 000105e6 (IRAM address; the boot stub copies these bytes from program flash 0x030c0206)
 * Size: 30 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rtos
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void OSIntCtxSw(void)

{
  undefined4 *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined4 *puVar4;
  
  puVar3 = PTR_OSTCBHighRdyPtr_000106bc;
  puVar2 = PTR_OSTCBCurPtr_000106b8;
  puVar1 = DAT_000106b4;
  **(undefined4 **)PTR_OSTCBCurPtr_000106b8 = *DAT_000106b4;
  puVar4 = *(undefined4 **)puVar3;
  *(undefined4 **)puVar2 = puVar4;
  *puVar1 = *puVar4;
  return;
}

