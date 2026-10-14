/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: aprs_info_list_screen @ 03062c14 (file base 0x03000000; code starts at 0x03001000)
 * Size: 200 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: analog-signaling
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void aprs_info_list_screen(uint param_1,uint param_2,uint param_3)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  ushort uVar5;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined1 uStack_28;
  
  param_2 = param_2 & 0xffff;
  local_38 = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  if ((param_3 & 0xffff) != 0) {
    uVar1 = aprs_log_count_read();
    number_to_string_format_2args(&local_38,PTR_s_APRS_Info__d__d_03062e84,param_2 + 1,uVar1);
    uVar3 = 0;
    display_fill_rect(0,0,0xf0,0x1b,0);
    display_draw_number_centered(1,0xffff,0,(uint)&local_38);
    if (uVar1 != 0) {
      uVar4 = (param_2 - (param_1 & 0xffff)) + 1 & 0xffff;
      uVar5 = 1;
      do {
        uVar3 = uVar3 + 1 & 0xffff;
        if (uVar4 + 1 == uVar3) {
          uVar2 = aprs_log_record_id_read(uVar4);
          contact_name_lookup_or_format(1,uVar2,&local_38,3);
          if (uVar4 == param_2) {
            display_draw_list_row(uVar5,&local_38,1);
          }
          else {
            display_draw_list_row(uVar5,&local_38,0);
          }
          menu_icon_with_index_label_draw(uVar5,uVar4,0xffff,0);
          uVar4 = uVar4 + 1 & 0xffff;
          if ((param_3 & 0xffff) <= uVar4) {
            return;
          }
          uVar5 = uVar5 + 1;
          if (8 < uVar5) {
            return;
          }
        }
      } while (uVar3 < uVar1);
    }
  }
  return;
}

