/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: gb2312_text_wrap_calculate @ 0305b984 (file base 0x03000000; code starts at 0x03001000)
 * Size: 122 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: display-driver
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void gb2312_text_wrap_calculate(byte *param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  char cVar5;
  
  puVar4 = p_text_entry_current_char_alias;
  puVar3 = PTR_DAT_0305ba50;
  puVar2 = p_text_entry_current_char;
  while (*param_1 != 0) {
    if ((*param_1 < 0x81) || (param_1[1] < 0x81)) {
      if (0xe4 < *(ushort *)puVar2) {
        *(short *)puVar3 = *(short *)puVar3 + 0x18;
        *(undefined2 *)puVar2 = 5;
      }
      *(short *)puVar2 = *(short *)puVar2 + 0xc;
      param_1 = param_1 + 1;
    }
    else {
      if (0xd8 < *(ushort *)puVar2) {
        *(short *)puVar3 = *(short *)puVar3 + 0x18;
        *(undefined2 *)puVar2 = 5;
      }
      *(short *)puVar2 = *(short *)puVar2 + 0x18;
      param_1 = param_1 + 2;
    }
    if (0x107 < *(ushort *)puVar3) {
      *(ushort *)puVar3 = *(ushort *)puVar3 - 0x18;
      cVar1 = *(char *)puVar4;
      cVar5 = text_entry_columns_remaining(cVar1);
      *(char *)puVar4 = cVar5 + cVar1;
    }
  }
  return;
}

