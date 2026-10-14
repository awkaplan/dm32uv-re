/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: display_format_id_with_separators @ 03059188 (file base 0x03000000; code starts at 0x03001000)
 * Size: 758 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: display-driver
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void display_format_id_with_separators(void)

{
  byte bVar1;
  short sVar2;
  uint uVar3;
  byte *pbVar4;
  uint uVar5;
  byte *pbVar6;
  byte local_50 [68];
  
  bVar1 = p_radio_mode_state_0003e318->flags_0x4;
  if (((((bVar1 & 0x60) == 0) && ((p_radio_mode_state_0003e318->flags_0x6 & 8) == 0)) ||
      ((p_radio_mode_state_0003e318[2].field_0x1 & 4) != 0)) &&
     ((*PTR_DAT_030592e0 & 0x18000) != 0x8000)) {
    if ((p_radio_mode_state_0003e318->flags_0x5 & 0x10) == 0) {
      uVar3 = (uint)*(byte *)PTR_DAT_0305946c;
      if (uVar3 != 0) {
        uVar5 = 0;
        do {
          local_50[uVar5] = PTR_DAT_03059474[uVar5];
          uVar5 = uVar5 + 1;
        } while ((uVar5 & 0xff) < uVar3);
      }
      local_50[uVar3] = 0;
    }
    else {
      uVar3 = (uint)*(byte *)PTR_DAT_0305946c;
      if (uVar3 != 0) {
        uVar5 = 0;
        do {
          local_50[uVar5] = (&p_state_0003ff3c->field_0x3)[uVar5];
          uVar5 = uVar5 + 1;
        } while ((uVar5 & 0xff) < uVar3);
      }
      local_50[uVar3] = 0;
    }
  }
  else {
    if ((bVar1 & 0x60) == 0) {
      if ((*PTR_DAT_030592e0 & 0x18000) == 0x8000) {
        uVar3 = 6;
      }
      else {
        uVar3 = 9;
      }
      uVar5 = (uint)*DAT_030592e4;
      if (uVar5 < uVar3) {
        memset_ck803s((int)PTR_DAT_030592e8 + uVar5,0x2d,uVar3 - uVar5);
      }
      if (uVar3 == 0) {
        uVar5 = 0;
      }
      else {
        local_50[0] = *(byte *)PTR_DAT_030594d8;
        pbVar4 = (byte *)((int)PTR_DAT_030594d8 + 1);
        pbVar6 = pbVar4 + (uVar3 - 1 & 0xff);
        uVar5 = 1;
        for (; pbVar4 != pbVar6; pbVar4 = pbVar4 + 1) {
          local_50[uVar5] = *pbVar4;
          uVar5 = uVar5 + 1 & 0xff;
          if (uVar5 == 3) {
            local_50[3] = 0x2e;
            uVar5 = 4;
          }
        }
      }
      local_50[uVar3] = 0;
    }
    else if ((bVar1 & 0x60) == 0x60) {
      uVar5 = (uint)*DAT_030592e4;
      if (uVar5 < 2) {
        if (uVar5 != 0) {
          local_50[0] = *(byte *)PTR_DAT_030594d8;
        }
        local_50[uVar5] = 0;
      }
      else {
        local_50[0] = *(byte *)PTR_DAT_030592e8;
        local_50[1] = *(undefined1 *)((int)PTR_DAT_030592e8 + 1);
        local_50[2] = 0x2e;
        if (2 < uVar5) {
          uVar3 = 3;
          do {
            local_50[uVar3] = *(byte *)((int)PTR_DAT_030592e8 + (uVar3 - 1));
            uVar3 = uVar3 + 1 & 0xff;
          } while (uVar3 <= uVar5);
        }
        local_50[uVar5 + 1] = 0;
        uVar5 = uVar5 + 1 & 0xff;
      }
    }
    else {
      uVar5 = (uint)*DAT_030592e4;
      if (uVar5 < 3) {
        if (uVar5 != 0) {
          uVar3 = 0;
          do {
            local_50[uVar3] = *(byte *)((int)PTR_DAT_030592e8 + uVar3);
            uVar3 = uVar3 + 1;
          } while ((uVar3 & 0xff) < uVar5);
        }
        local_50[uVar5] = 0;
      }
      else {
        local_50[0] = *(byte *)PTR_DAT_030592e8;
        local_50[1] = *(undefined1 *)((int)PTR_DAT_030592e8 + 1);
        local_50[2] = *(undefined1 *)((int)PTR_DAT_030592e8 + 2);
        local_50[3] = 0x2e;
        if (3 < uVar5) {
          uVar3 = 4;
          do {
            local_50[uVar3] = *(byte *)((int)PTR_DAT_030592e8 + (uVar3 - 1));
            uVar3 = uVar3 + 1 & 0xff;
          } while (uVar3 <= uVar5);
        }
        local_50[uVar5 + 1] = 0;
        uVar5 = uVar5 + 1 & 0xff;
      }
    }
    sVar2 = (short)uVar5;
    if ((p_radio_mode_state_0003e318->flags_0x4 & 0x60) == 0) {
      if ((PTR_DAT_03059468[1] & 0x80) == 0) {
        *(short *)p_text_entry_current_char = sVar2 * 0xc + 8;
      }
      else {
        *(short *)p_text_entry_current_char = sVar2 * 0xc + 0x5a;
      }
    }
    else {
      *(short *)p_text_entry_current_char = sVar2 * 0xc + 5;
    }
    if ((PTR_DAT_03059468[1] & 0x80) == 0) {
      if (((p_radio_mode_state_0003e318->flags_0x6 & 8) != 0) && (7 < *(byte *)PTR_DAT_0305946c)) {
        PTR_DAT_03059468[4] = PTR_DAT_03059468[4] & 0xdf | 0x20;
        write_field_and_mbox_post(1,5);
      }
    }
    else if (3 < *(byte *)PTR_DAT_0305946c) {
      PTR_DAT_03059468[4] = PTR_DAT_03059468[4] & 0xdf | 0x20;
      write_field_and_mbox_post(1,5);
    }
  }
  if ((p_radio_mode_state_0003e318->flags_0x6 & 4) == 0) {
    if (((p_radio_mode_state_0003e318->flags_0x6 & 8) == 0) &&
       ((*(uint *)PTR_DAT_03059468 & 0x18000) != 0x8000)) {
      display_draw_string_gb2312(0x20,5,local_50,0xffff,0);
    }
    else {
      display_draw_decimal_string_2color(local_50);
    }
  }
  else {
    if (*(byte *)PTR_DAT_0305946c < 2) {
      local_50[1] = 0x2d;
      local_50[2] = 0;
    }
    display_draw_digit_string_indicators(local_50);
    if (1 < *(byte *)PTR_DAT_0305946c) {
      write_field_and_mbox_post(1,5);
    }
  }
  return;
}

