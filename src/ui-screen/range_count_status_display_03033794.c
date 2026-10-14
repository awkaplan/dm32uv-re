/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: range_count_status_display @ 03033794 (file base 0x03000000; code starts at 0x03001000)
 * Size: 232 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-screen
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void range_count_status_display(int param_1,int param_2,uint param_3)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  undefined1 auStack_38 [20];
  
  if (param_3 == 0) {
    format_and_write_status_field
              (0,10,**(undefined4 **)
                      (PTR_PTR_03033934 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
    ui_event_notify(0x1b);
  }
  else {
    uVar3 = (param_2 - param_1) + 1;
    uVar2 = 1;
    do {
      uVar3 = uVar3 + 1;
      flash_config_record_read_16byte(uVar3,auStack_38);
      if (uVar2 + (param_2 - param_1) == param_2) {
        display_draw_list_row(uVar2,auStack_38,1);
        display_blit_bitmap_1bpp_clipped(8,uVar2,0x18,0x18,*PTR_DAT_0303385c);
      }
      else {
        display_draw_list_row(uVar2,auStack_38,0);
        display_blit_bitmap_1bpp_clipped(8,uVar2,0x18,0x18,*PTR_DAT_03033860);
      }
      if ((param_3 <= uVar3) || (uVar2 + 1 == 9)) {
        if ((p_dm32_settings_block04[0x30] & 0x40) == 0) {
          number_to_string_format_2args(auStack_38,PTR_s_CSV__d__d_03033868,param_2 + 1,param_3);
        }
        else {
          number_to_string_format_2args(auStack_38,PTR_s_CSV__d__d_03033868,param_2 + 1,param_3);
        }
        display_clear_status_row(0,0);
        display_draw_number_centered(1,0xffff,0,(uint)auStack_38);
        return;
      }
      bVar1 = uVar2 < param_3;
      uVar2 = uVar2 + 1;
    } while (bVar1);
  }
  return;
}

