/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: gps_power_set @ 030116cc (file base 0x03000000; code starts at 0x03001000)
 * Size: 122 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: gps
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void gps_power_set(char param_1)

{
  undefined4 *puVar1;
  undefined2 *puVar2;
  
  puVar1 = PTR_DAT_0301180c;
  if (param_1 == '\x01') {
    *(byte *)(PTR_DAT_0301180c + 0x36) = *(byte *)(PTR_DAT_0301180c + 0x36) & 0xfe | 1;
    gpio_clear_output_bit(0x2c);
  }
  else {
    *(byte *)(PTR_DAT_0301180c + 0x36) = *(byte *)(PTR_DAT_0301180c + 0x36) & 0xfe;
    gpio_set_output_bit(0x2c);
    *(undefined1 *)PTR_DAT_03011810 = 0;
    *(byte *)puVar1 = *(byte *)puVar1 & 0xde;
    *(undefined1 *)PTR_DAT_03011814 = 0;
    *(undefined2 *)((int)puVar1 + 10) = 0;
    puVar2 = PTR_DAT_03011818;
    *PTR_DAT_03011818 = 0;
    puVar2[1] = 0;
    puVar2[2] = 0;
    *(undefined1 *)(puVar2 + 3) = 0;
    memset_bytes(PTR_DAT_0301181c,0,0x96);
    memset_bytes(PTR_DAT_03011820,0,0x400);
    *(byte *)puVar1 = *(byte *)puVar1 & 0x3f;
  }
  return;
}

