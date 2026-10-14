/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_roaming_list_render_rows @ 03066568 (file base 0x03000000; code starts at 0x03001000)
 * Size: 138 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void channel_roaming_list_render_rows(uint param_1,uint param_2,uint param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  ushort uVar6;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined1 uStack_28;
  
  puVar1 = PTR_DAT_03066670;
  param_3 = param_3 & 0xff;
  local_38 = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  if ((param_3 != 0) && (param_3 != 0)) {
    uVar5 = ((param_2 & 0xff) - (param_1 & 0xff)) + 1 & 0xffff;
    uVar3 = 0;
    uVar6 = 1;
    do {
      uVar4 = uVar3 + 1;
      uVar3 = uVar4 & 0xffff;
      if (uVar5 + 1 == uVar3) {
        uVar2 = flash_field_channel_table_lookup(*(undefined1 *)puVar1,uVar4 & 0xff);
        channel_and_roaming_record_read(uVar2,&local_38);
        if (uVar5 == (param_2 & 0xff)) {
          display_draw_list_row(uVar6,&local_38,1);
        }
        else {
          display_draw_list_row(uVar6,&local_38,0);
        }
        uVar5 = uVar5 + 1 & 0xffff;
        if (param_3 <= uVar5) {
          return;
        }
        uVar6 = uVar6 + 1;
        if (8 < uVar6) {
          return;
        }
      }
    } while (uVar3 < param_3);
  }
  return;
}

