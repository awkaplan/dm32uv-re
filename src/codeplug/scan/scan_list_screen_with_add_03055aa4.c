/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: scan_list_screen_with_add @ 03055aa4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 382 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void scan_list_screen_with_add(uint param_1,uint param_2,uint param_3)

{
  byte bVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  short sVar6;
  uint uVar7;
  undefined1 local_30;
  undefined1 uStack_2f;
  undefined1 uStack_2e;
  undefined1 uStack_2d;
  undefined1 uStack_2c;
  undefined1 uStack_2b;
  undefined1 uStack_2a;
  undefined1 uStack_29;
  undefined1 uStack_28;
  undefined1 uStack_27;
  undefined1 uStack_26;
  
  puVar3 = PTR_DAT_03055c28;
  iVar2 = p_dm32_settings_block04;
  param_2 = param_2 & 0xffff;
  param_3 = param_3 & 0xffff;
  if (param_3 != 0) {
    uVar5 = (param_2 - (param_1 & 0xffff)) + 1 & 0xffff;
    sVar6 = -0x5c;
    uVar7 = 1;
    uVar4 = 1;
    do {
      if (uVar5 + 1 == uVar4) {
        if (uVar4 < param_3) {
          if (uVar4 == 1) {
            if ((*(byte *)(iVar2 + 0x30) & 0x40) == 0) {
              memcpy_bytes_iram(&local_30,PTR_LAB_03055c2c,2);
              uStack_2e = 0;
            }
            else {
              memcpy_bytes_iram(&local_30,PTR_LAB_03055c30,4);
              uStack_2c = 0;
            }
          }
          else {
            flash_field_read_cached(0xf,sVar6,&local_30,10);
            uStack_26 = 0;
          }
          if (uVar5 == param_2) {
            display_draw_list_row(uVar7,&local_30,1);
            *(undefined1 *)puVar3 = local_30;
            *(undefined1 *)((int)puVar3 + 1) = uStack_2f;
            *(undefined1 *)((int)puVar3 + 2) = uStack_2e;
            *(undefined1 *)((int)puVar3 + 3) = uStack_2d;
            *(undefined1 *)(puVar3 + 1) = uStack_2c;
            *(undefined1 *)((int)puVar3 + 5) = uStack_2b;
            *(undefined1 *)((int)puVar3 + 6) = uStack_2a;
            *(undefined1 *)((int)puVar3 + 7) = uStack_29;
            *(undefined1 *)(puVar3 + 2) = uStack_28;
            *(undefined1 *)((int)puVar3 + 9) = uStack_27;
          }
          else {
            display_draw_list_row(uVar7,&local_30,0);
          }
          *(undefined1 *)PTR_DAT_03055c34 = 2;
          menu_icon_draw_dispatch(uVar7,uVar5 & 0xff);
        }
        else {
          if ((*(byte *)(iVar2 + 0x30) & 0x40) == 0) {
            memcpy_bytes_iram(&local_30,PTR_LAB_03055c38,8);
          }
          else {
            memcpy_bytes_iram(&local_30,PTR_s_Add_List_03055c3c,8);
          }
          uStack_28 = 0;
          bVar1 = PTR_DAT_03055c40[uVar7 - 1];
          if (uVar5 == param_2) {
            display_draw_list_row(uVar7,&local_30,1);
            display_blit_image(0xc,bVar1 + 4,0x11,0x11,PTR_LAB_03055c44);
          }
          else {
            display_draw_list_row(uVar7,&local_30,0);
            display_blit_image(0xc,bVar1 + 4,0x11,0x11,PTR_LAB_03055c48);
          }
        }
        uVar5 = uVar5 + 1 & 0xffff;
        if (param_3 <= uVar5) {
          return;
        }
        uVar7 = uVar7 + 1 & 0xffff;
        if (8 < uVar7) {
          return;
        }
      }
      uVar4 = uVar4 + 1 & 0xffff;
      sVar6 = sVar6 + 0x6d;
    } while (uVar4 <= param_3);
  }
  return;
}

