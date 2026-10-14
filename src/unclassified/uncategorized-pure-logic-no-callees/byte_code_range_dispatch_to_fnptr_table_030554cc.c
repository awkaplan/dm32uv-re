/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: byte_code_range_dispatch_to_fnptr_table @ 030554cc (file base 0x03000000; code starts at 0x03001000)
 * Size: 134 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void byte_code_range_dispatch_to_fnptr_table(void)

{
  byte bVar1;
  
  bVar1 = *(byte *)PTR_DAT_03055524;
  if (bVar1 < 0xf) {
    (*(code *)(*PTR_DAT_03055528 & 0xfffffffe))(*(undefined2 *)PTR_DAT_0305552c);
  }
  else if (bVar1 == 0xf) {
    (*(code *)(PTR_DAT_03055528[1] & 0xfffffffe))(*(undefined2 *)PTR_DAT_0305552c);
  }
  else if (bVar1 < 0x15) {
    (*(code *)(PTR_DAT_03055528[2] & 0xfffffffe))(*(undefined2 *)PTR_DAT_0305552c);
  }
  else if ((byte)(bVar1 - 0x1b) < 6) {
    (*(code *)(PTR_DAT_03055528[5] & 0xfffffffe))(*(undefined2 *)PTR_DAT_0305552c);
  }
  else if ((byte)(bVar1 - 0x21) < 0xc) {
    (*(code *)(*(uint *)(_LAB_0305556c + 0x18) & 0xfffffffe))(*_DAT_03055570);
  }
  else if (bVar1 == 0x1a) {
    (*(code *)(*(uint *)(_LAB_0305556c + 0x10) & 0xfffffffe))(*_DAT_03055570);
  }
  else if ((byte)(bVar1 - 0x35) < 0x10) {
    (*(code *)(*(uint *)(_LAB_0305556c + 0x24) & 0xfffffffe))(*_DAT_03055570);
  }
  return;
}

