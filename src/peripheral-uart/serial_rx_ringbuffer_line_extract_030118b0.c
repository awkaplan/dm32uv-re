/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: serial_rx_ringbuffer_line_extract @ 030118b0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 124 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: peripheral-uart
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void serial_rx_ringbuffer_line_extract(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  short sVar3;
  uint uVar4;
  
  puVar2 = PTR_DAT_030119a4;
  sVar3 = *(short *)(PTR_DAT_030119a0 + 4);
  uVar4 = (uint)*(ushort *)PTR_DAT_030119a0;
  do {
    puVar1 = PTR_DAT_030119a0;
    if (puVar2[uVar4] == '\n') {
      *(short *)(PTR_DAT_030119a0 + 4) = sVar3;
      *(short *)puVar1 = (short)uVar4;
      if (sVar3 != 0) {
        PTR_DAT_030119a4[uVar4] = 0;
        *(short *)PTR_DAT_030119a0 = (short)(uVar4 + 1);
        if (0x3ff < (uVar4 + 1 & 0xffff)) {
          *(undefined2 *)PTR_DAT_030119a0 = 0;
        }
        *(short *)(PTR_DAT_030119a0 + 4) = sVar3 + -1;
      }
LAB_0301191c:
      if (PTR_DAT_030119a0[6] != '\0') {
        PTR_DAT_030119a0[6] = PTR_DAT_030119a0[6] + -1;
      }
      return;
    }
    puVar2[uVar4] = 0;
    puVar1 = PTR_DAT_030119a0;
    if (sVar3 == 0) {
      *(undefined2 *)(PTR_DAT_030119a0 + 4) = 0;
      *(short *)puVar1 = (short)uVar4;
      goto LAB_0301191c;
    }
    sVar3 = sVar3 + -1;
    uVar4 = uVar4 + 1 & 0xffff;
    if (0x3ff < uVar4) {
      uVar4 = 0;
    }
  } while( true );
}

