/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: draw_string_mixed_charset @ 0301a2b4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 194 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: display-driver
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void draw_string_mixed_charset
               (short param_1,ushort param_2,byte *param_3,ushort param_4,undefined2 param_5,
               undefined2 param_6)

{
  byte bVar1;
  byte bVar2;
  byte local_6c;
  byte bStack_6b;
  
  while( true ) {
    bVar2 = *param_3;
    if (bVar2 == 0) {
      return;
    }
    if (param_4 == 0) break;
    if ((bVar2 < 0x81) || (bVar1 = param_3[1], bVar1 < 0x81)) {
      if ((byte)(bVar2 - 0x20) < 0x60) {
        param_4 = param_4 - 1;
        if (0xe4 < param_2) {
          param_1 = param_1 + 0xc;
          param_2 = 5;
        }
        display_draw_glyph_ascii(param_2,param_1,bVar2,0x18,param_5,param_6);
        param_3 = param_3 + 1;
        param_2 = param_2 + 8;
      }
    }
    else {
      if (param_4 < 2) {
        return;
      }
      param_4 = param_4 - 2;
      if (0xd8 < param_2) {
        param_1 = param_1 + 0x18;
        param_2 = 5;
      }
      local_6c = bVar2;
      bStack_6b = bVar1;
      if (bVar2 < 0xa6) {
        gb2312_glyph_index_lookup1(&local_6c);
      }
      else {
        if (0xf < bVar2) {
          local_6c = bVar2 - 0xf;
        }
        gb2312_glyph_index_lookup2(&local_6c);
      }
      display_draw_glyph_gb2312(param_1,param_2,&local_6c,param_5,param_6);
      param_3 = param_3 + 2;
      param_2 = param_2 + 0x18;
    }
  }
  return;
}

