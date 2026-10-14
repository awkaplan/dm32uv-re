/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_list_render_rows_free_slot @ 03056804 (file base 0x03000000; code starts at 0x03001000)
 * Size: 122 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void channel_list_render_rows_free_slot(uint param_1,uint param_2,uint param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  ushort uVar5;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined1 uStack_28;
  
  puVar1 = PTR_DAT_030569c0;
  param_3 = param_3 & 0xffff;
  local_38 = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  if (param_3 != 0) {
    uVar4 = ((param_2 & 0xffff) - (param_1 & 0xffff)) + 1 & 0xffff;
    uVar3 = 0;
    uVar5 = 1;
    do {
      uVar3 = uVar3 + 1 & 0xffff;
      if (uVar4 + 1 == uVar3) {
        uVar2 = channel_free_slot_count_until_nth(*(undefined1 *)puVar1);
        channel_record_read_full(uVar2,&local_38);
        if (uVar4 == (param_2 & 0xffff)) {
          display_draw_list_row(uVar5,&local_38,1);
        }
        else {
          display_draw_list_row(uVar5,&local_38,0);
        }
        uVar4 = uVar4 + 1 & 0xffff;
        if (param_3 <= uVar4) {
          return;
        }
        uVar5 = uVar5 + 1;
        if (8 < uVar5) {
          return;
        }
      }
    } while (uVar3 < param_3);
  }
  return;
}

