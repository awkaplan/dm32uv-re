/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: format_and_plot_number_with_decimals @ 03019868 (file base 0x03000000; code starts at 0x03001000)
 * Size: 154 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: display-driver
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void format_and_plot_number_with_decimals
               (undefined4 param_1,short param_2,short param_3,undefined2 param_4,undefined2 param_5
               ,uint param_6)

{
  undefined4 uVar1;
  uint uVar2;
  byte bVar3;
  char acStack_30 [9];
  undefined1 uStack_27;
  
  uStack_27 = 0;
  number_to_string_format_2args
            (acStack_30,PTR_s__03d__05d_03019a0c,param_6 / 100000,param_6 % 100000);
  bVar3 = 1;
  uVar2 = 0;
  do {
    if ((uVar2 & 0xff) == 3) {
      display_plot_glyph_2color(param_3,param_2 + 0x14,10,0xe,PTR_LAB_03019a10,param_4,param_5);
      param_3 = param_3 + 10;
    }
    else {
      uVar1 = table_index_ptr_0x6c_byte(acStack_30[uVar2 & 0xff] + -0x30);
      display_plot_glyph_2color(param_3,param_2,0x1b,0x6c,uVar1,param_4,param_5);
      if (8 < bVar3) {
        return;
      }
      param_3 = param_3 + 0x1b;
    }
    uVar2 = uVar2 + 1;
    bVar3 = bVar3 + 1;
  } while( true );
}

