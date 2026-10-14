/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: list_screen_none_placeholder @ 0305cb44 (file base 0x03000000; code starts at 0x03001000)
 * Size: 194 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void list_screen_none_placeholder(char param_1,byte param_2,byte param_3)

{
  int iVar1;
  ushort block_id;
  byte bVar2;
  byte bVar3;
  uint offset;
  byte bVar4;
  undefined1 auStack_38 [2];
  undefined1 uStack_36;
  undefined1 uStack_34;
  undefined1 uStack_2e;
  
  block_id = flash_block_id_resolve_locked(0x10);
  iVar1 = p_dm32_settings_block04;
  if (param_3 != 0) {
    bVar3 = (param_2 - param_1) + 1;
    offset = 0x2d5;
    bVar4 = 1;
    bVar2 = 0;
    do {
      if (bVar3 == bVar2) {
        if (bVar3 == 0) {
          if ((*(byte *)(iVar1 + 0x30) & 0x40) == 0) {
            memcpy_bytes_iram(auStack_38,PTR_LAB_0305cbec,2);
            uStack_36 = 0;
          }
          else {
            memcpy_bytes_iram(auStack_38,PTR_LAB_0305cbf0,4);
            uStack_34 = 0;
          }
        }
        else {
          flash_block_read(block_id,offset,auStack_38,10);
          uStack_2e = 0;
        }
        if (bVar3 == param_2) {
          display_draw_list_row(bVar4,auStack_38,1);
        }
        else {
          display_draw_list_row(bVar4,auStack_38,0);
        }
        *(undefined1 *)PTR_DAT_0305ce08 = 2;
        menu_icon_draw_dispatch(bVar4,bVar3);
        bVar3 = bVar3 + 1;
        if (param_3 <= bVar3) {
          return;
        }
        bVar4 = bVar4 + 1;
        if (8 < bVar4) {
          return;
        }
      }
      bVar2 = bVar2 + 1;
      offset = offset + 0x2c;
    } while (bVar2 < param_3);
  }
  return;
}

