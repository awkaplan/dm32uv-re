/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: txslot_tx_slot_service_task @ 0002d604 (IRAM address; the boot stub copies these bytes from program flash 0x030dd224)
 * Size: 140 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void txslot_tx_slot_service_task(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  
  puVar5 = PTR_DAT_0002d6a0;
  puVar4 = PTR_DAT_0002d69c;
  puVar3 = PTR_DAT_0002d698;
  puVar2 = PTR_DAT_0002d694;
  puVar1 = PTR_DAT_0002d690;
  do {
    do {
      do {
        func_0x0300c838(0);
        *(int *)(puVar1 + 4) = *(int *)(puVar1 + 4) + 1;
      } while ((puVar2[0x19] & 1) != 0);
    } while (-1 < iRam11000404);
    if ((uRam11000100 & 0x18) != 0) {
      if (puVar4[5] == '\0') {
        puVar4[5] = 1;
      }
      func_0x0002d4e4(puVar5[1]);
      func_0x030238bc();
      *(short *)(puVar4 + 0x10) = *(short *)(puVar4 + 0x10) + 1;
      func_0x0002d7ac(*puVar4);
      func_0x03029c30(~(*puVar4 != '\0'));
      func_0x030234d0();
    }
    *(undefined4 *)puVar3 = 0;
  } while( true );
}

