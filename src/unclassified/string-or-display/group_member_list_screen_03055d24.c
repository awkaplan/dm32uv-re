/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: group_member_list_screen @ 03055d24 (file base 0x03000000; code starts at 0x03001000)
 * Size: 214 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void group_member_list_screen(uint param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 local_3c;
  undefined1 auStack_38 [8];
  undefined1 uStack_30;
  undefined1 uStack_2e;
  
  iVar1 = p_dm32_settings_block04;
  param_3 = param_3 & 0xffff;
  local_3c = 0;
  if (param_3 != 0) {
    uVar3 = ((param_2 & 0xffff) - (param_1 & 0xffff)) + 1 & 0xff;
    uVar4 = 0;
    do {
      if ((int)uVar3 < (int)(param_3 - 1)) {
        flash_field_read_cached
                  (0xf,(((param_4 & 0xff) - 1) * 0x6d + 0x1c & 0xffff) + uVar3 * 3 & 0xffff,
                   &local_3c,3);
        contact_name_lookup_or_format(1,local_3c,auStack_38,4);
      }
      else if ((*(byte *)(iVar1 + 0x30) & 0x40) == 0) {
        memcpy_bytes_iram(auStack_38,PTR_LAB_03055e54,8);
        uStack_30 = 0;
      }
      else {
        memcpy_bytes_iram(auStack_38,PTR_s_Add_Member_03055e58,10);
        uStack_2e = 0;
      }
      if (uVar3 == (param_2 & 0xffff)) {
        display_draw_list_row(uVar4 + 1,auStack_38,1);
        uVar2 = PTR_DAT_03055e5c[1];
      }
      else {
        display_draw_list_row(uVar4 + 1,auStack_38,0);
        uVar2 = PTR_DAT_03055e60[1];
      }
      if ((int)uVar3 < (int)(param_3 - 1)) {
        display_blit_bitmap_1bpp_clipped(8,uVar4 + 1,0x18,0x18,uVar2);
      }
      uVar3 = uVar3 + 1 & 0xff;
    } while (((uVar3 < param_3) && (uVar4 != 7)) && (uVar4 = uVar4 + 1, (uVar4 & 0xffff) < param_3))
    ;
  }
  return;
}

