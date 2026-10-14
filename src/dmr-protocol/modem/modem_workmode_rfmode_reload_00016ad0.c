/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: modem_workmode_rfmode_reload @ 00016ad0 (IRAM address; the boot stub copies these bytes from program flash 0x030c66f0)
 * Size: 82 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: dmr-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void modem_workmode_rfmode_reload(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = iRam00016bd4;
  puVar1 = puRam00016bd0;
  uRam11000104 = *puRam00016bd0;
  uRam11000100 = puRam00016bd0[1];
  uRam11000080 = puRam00016bd0[2];
  uRam11000560 = puRam00016bd0[3];
  uRam1100039c = puRam00016bd0[4];
  *(undefined1 *)(iRam00016bd4 + 0xd2) = *(undefined1 *)(puRam00016bd0 + 6);
  *(undefined1 *)(iVar2 + 0xd3) = *(undefined1 *)((int)puVar1 + 0x19);
  *(undefined1 *)(iVar2 + 0xcb) = *(undefined1 *)((int)puVar1 + 0x1a);
  *(undefined1 *)(iVar2 + 0xcc) = *(undefined1 *)((int)puVar1 + 0x1b);
  *(undefined1 *)(iVar2 + 0xc9) = *(undefined1 *)(puVar1 + 7);
  *(undefined1 *)(iVar2 + 0xcf) = *(undefined1 *)((int)puVar1 + 0x1d);
  return;
}

