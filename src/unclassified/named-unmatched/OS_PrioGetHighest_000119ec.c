/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: OS_PrioGetHighest @ 000119ec (IRAM address; the boot stub copies these bytes from program flash 0x030c160c)
 * Size: 38 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

char OS_PrioGetHighest(void)

{
  char cVar1;
  int *piVar2;
  char cVar3;
  
  if (*piRam00011a54 == 0) {
    cVar3 = '\0';
    piVar2 = piRam00011a54;
    do {
      cVar3 = cVar3 + ' ';
      piVar2 = piVar2 + 1;
    } while (*piVar2 == 0);
  }
  else {
    cVar3 = '\0';
  }
  cVar1 = call_and_return_wrapper();
  return cVar3 + cVar1;
}

