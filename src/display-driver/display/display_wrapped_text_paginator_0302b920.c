/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: display_wrapped_text_paginator @ 0302b920 (file base 0x03000000; code starts at 0x03001000)
 * Size: 204 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: display-driver
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void display_wrapped_text_paginator(int param_1,ushort param_2,ushort param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  short sVar4;
  short sVar5;
  byte abStack_44 [32];
  
  uVar1 = strlen_ck803s();
  uVar1 = uVar1 & 0xff;
  sVar5 = 0;
  sVar4 = 0x46;
  uVar3 = 0;
  while (memset_bytes(abStack_44,0,0x20), uVar1 <= uVar3) {
LAB_0302b97e:
    if (sVar4 == 0x46) {
      display_draw_string_gb2312
                (sVar5 * 0x1e + 0x46,10,abStack_44,PTR_DAT_0302ba08[(byte)PTR_DAT_0302ba04[0x62]],
                 param_3);
    }
    else {
      display_draw_string_gb2312(sVar5 * 0x1e + 0x46,10,abStack_44,param_2,param_3);
      if (sVar4 == 0xa0) {
        return;
      }
    }
    uVar3 = uVar3 + 1 & 0xff;
    sVar5 = sVar5 + 1;
    if (uVar1 <= uVar3) {
      display_draw_glyph_row_mutex(0xa0,10,_DAT_0302bbf0,param_2,0);
      return;
    }
    sVar4 = sVar4 + 0x1e;
  }
  uVar2 = 0;
  do {
    if (*(byte *)(param_1 + uVar3) == 0x20) {
      if (4 < uVar2) goto LAB_0302b97e;
      abStack_44[uVar2] = 0x20;
    }
    else {
      abStack_44[uVar2] = *(byte *)(param_1 + uVar3);
    }
    uVar3 = uVar3 + 1 & 0xff;
    if (uVar1 <= uVar3) goto LAB_0302b97e;
    uVar2 = uVar2 + 1 & 0xff;
  } while( true );
}

