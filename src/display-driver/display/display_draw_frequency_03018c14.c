/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: display_draw_frequency @ 03018c14 (file base 0x03000000; code starts at 0x03001000)
 * Size: 194 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: display-driver
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void display_draw_frequency(int param_1__w,uint param_2)

{
  char param_1 = (char)param_1__w;
  undefined4 uVar1;
  uint uVar2;
  char cVar3;
  byte bVar4;
  undefined2 uVar5;
  undefined4 uStack_34;
  byte abStack_30 [9];
  undefined1 uStack_27;
  
  uStack_27 = 0;
  number_to_string_format_2args
            (abStack_30,PTR_s__03d__05d_03018dc8,param_2 / 100000,param_2 % 100000);
  if (param_1 == '\0') {
    uVar5 = PTR_DAT_03018dd0[(byte)p_dm32_settings_block04[100]];
    uStack_34 = 0x50;
  }
  else {
    uVar5 = PTR_DAT_03018dd0[(byte)p_dm32_settings_block04[0x65]];
    uStack_34 = 0xc6;
  }
  cVar3 = 'H';
  bVar4 = 1;
  uVar2 = 0;
  do {
    if ((uVar2 & 0xff) == 3) {
      uVar1 = table_index_ptr_0xe_byte(10);
      display_plot_glyph_2color(cVar3 + -0xb,uStack_34,8,0xe,uVar1,uVar5,0);
    }
    else {
      uVar1 = table_index_ptr_0xe_byte(abStack_30[uVar2 & 0xff] - 0x30);
      display_plot_glyph_2color(cVar3 + -0xb,uStack_34,8,0xe,uVar1,uVar5,0);
      if (8 < bVar4) {
        return;
      }
    }
    uVar2 = uVar2 + 1;
    bVar4 = bVar4 + 1;
    cVar3 = cVar3 + '\v';
  } while( true );
}

