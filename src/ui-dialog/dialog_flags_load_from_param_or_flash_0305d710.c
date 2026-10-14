/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dialog_flags_load_from_param_or_flash @ 0305d710 (file base 0x03000000; code starts at 0x03001000)
 * Size: 514 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-dialog
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void dialog_flags_load_from_param_or_flash(undefined4 param_1,undefined4 param_2,uint param_3)

{
  dialog_flags_from_flash *pdVar1;
  uint uVar2;
  undefined1 auStack_30 [10];
  byte bStack_26;
  byte bStack_25;
  undefined2 uStack_24;
  byte bStack_22;
  undefined1 uStack_21;
  byte bStack_20;
  byte bStack_1f;
  byte bStack_1e;
  byte bStack_1d;
  
  uVar2 = param_3 >> 0x18 & 0x1f;
  if ((param_3 & 0x80000000) == 0) {
    p_dialog_flags_from_flash->flags_0x2f = p_dialog_flags_from_flash->flags_0x2f & 0xfd;
  }
  else {
    p_dialog_flags_from_flash->flags_0x2f = p_dialog_flags_from_flash->flags_0x2f & 0xfd | 2;
  }
  if ((param_3 & 0x40000000) == 0) {
    p_dialog_flags_from_flash->flags_0x2f = p_dialog_flags_from_flash->flags_0x2f & 0xfb;
  }
  else {
    p_dialog_flags_from_flash->flags_0x2f = p_dialog_flags_from_flash->flags_0x2f & 0xfb | 4;
  }
  if ((param_3 & 0x80000000) == 0) {
    p_dialog_flags_from_flash->flags_0x2f = p_dialog_flags_from_flash->flags_0x2f & 0xf7;
  }
  else {
    p_dialog_flags_from_flash->flags_0x2f = p_dialog_flags_from_flash->flags_0x2f & 0xf7 | 8;
  }
  pdVar1 = p_dialog_flags_from_flash;
  if (((param_3 & 0x1f000000) == 0) || (0xf < uVar2)) {
    p_dialog_flags_from_flash->flags_0x2f = p_dialog_flags_from_flash->flags_0x2f & 0xfe;
    pdVar1->field_0x32 = 0;
    pdVar1->field_0x3f = 0;
    pdVar1->field_0x33 = 0;
    *(undefined2 *)&pdVar1->field_0x34_0 = 0;
    pdVar1->field_0x38 = 0;
    pdVar1->field_0x39 = 0;
    pdVar1->field_0x3a = 0;
  }
  else {
    p_dialog_flags_from_flash->flags_0x2f = p_dialog_flags_from_flash->flags_0x2f & 0xfe | 1;
    flash_field_read_cached(0x10,(uVar2 - 1) * 0x14 & 0xfffc,auStack_30);
    pdVar1->field_0x32 = bStack_26;
    pdVar1->field_0x3f = bStack_26;
    pdVar1->field_0x33 = bStack_25;
    *(undefined2 *)&pdVar1->field_0x34_0 = uStack_24;
    pdVar1->field_0x38 = bStack_22;
    pdVar1->field_0x39 = uStack_21;
    pdVar1->field_0x3a = bStack_20;
    if (bStack_25 == 1) {
      pdVar1->field_0x3e = pdVar1->field_0x3e & 0xfe;
    }
    else {
      p_dialog_flags_from_flash->field_0x3e =
           p_dialog_flags_from_flash->field_0x3e & 0xfe | bStack_1f & 1;
    }
    if (0xb < bStack_20) {
      p_dialog_flags_from_flash->field_0x3a = 0;
    }
    pdVar1 = p_dialog_flags_from_flash;
    p_dialog_flags_from_flash->field_0x3a = (p_dialog_flags_from_flash->field_0x3a + 1) * '\n';
    pdVar1->field_0x3b = bStack_1d;
    if (0xb < bStack_1d) {
      p_dialog_flags_from_flash->field_0x3b = 0;
    }
    pdVar1 = p_dialog_flags_from_flash;
    p_dialog_flags_from_flash->field_0x3b = (p_dialog_flags_from_flash->field_0x3b + 1) * '\n';
    pdVar1->field_0x3c = bStack_1e;
    if (bStack_1e == 0) {
      pdVar1->field_0x3c = 1;
    }
  }
  pdVar1 = p_dialog_flags_from_flash;
  dialog_state_set_bit_0301ed30(p_dialog_flags_from_flash->flags_0x2f >> 1 & 1);
  dialog_state_set_bit_0301ed3c(pdVar1->flags_0x2f >> 2 & 1);
  if (pdVar1->field_0x3f == 3) {
    write_field_0x18_bit7(1);
  }
  else {
    write_field_0x18_bit7(0);
  }
  write_byte_field_0301ed54(p_dialog_flags_from_flash->field_0x38);
  return;
}

