/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: quick_text_insert_and_rewrap @ 03053b2c (file base 0x03000000; code starts at 0x03001000)
 * Size: 184 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4 quick_text_insert_and_rewrap(undefined1 param_1)

{
  byte bVar1;
  byte bVar2;
  undefined4 *puVar3;
  byte bVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined1 *puVar7;
  undefined4 *puVar8;
  uint uVar9;
  undefined4 *puVar10;
  
  if (*(char *)(PTR_DAT_03053ccc + 2) == '\0') {
    uVar6 = 0;
  }
  else {
    quick_text_message_read(param_1);
    bVar4 = strlen_ck803s(PTR_DAT_03053cc8);
    puVar7 = p_text_entry_buffer;
    uVar5 = (uint)bVar4;
    bVar1 = *(byte *)PTR_DAT_03053cd0;
    uVar9 = (uint)bVar1;
    if ((int)(uint)(ushort)PTR_DAT_03053ccc[0x10] < (int)((uVar9 - 1) + uVar5)) {
      uVar6 = 1;
    }
    else {
      bVar2 = *(byte *)PTR_DAT_03053cd4;
      while (uVar9 = uVar9 - 1 & 0xff, bVar2 < uVar9) {
        puVar7[uVar9 + uVar5] = puVar7[uVar9];
      }
      p_text_entry_buffer[uVar9 + uVar5] = p_text_entry_buffer[uVar9];
      if (uVar5 != 0) {
        puVar7 = p_text_entry_buffer + bVar2;
        puVar10 = (undefined4 *)((int)PTR_DAT_03053cc8 + (uVar5 - 1 & 0xff) + 1);
        puVar8 = PTR_DAT_03053cc8;
        do {
          *puVar7 = *(undefined1 *)puVar8;
          puVar8 = (undefined4 *)((int)puVar8 + 1);
          puVar7 = puVar7 + 1;
        } while (puVar8 != puVar10);
      }
      puVar8 = PTR_DAT_03053cd0;
      *(byte *)PTR_DAT_03053cd0 = bVar4 + bVar1;
      puVar10 = PTR_DAT_03053cdc;
      *(undefined2 *)PTR_DAT_03053cdc = 0x20;
      puVar3 = p_text_entry_current_char;
      *(undefined2 *)p_text_entry_current_char = 5;
      *(undefined1 *)p_text_entry_current_char_alias = 0;
      gb2312_text_wrap_calculate(p_text_entry_buffer);
      *(char *)PTR_DAT_03053cd4 = *(char *)puVar8 + -1;
      *(undefined2 *)p_text_entry_buffer_alias = *(undefined2 *)puVar10;
      *(undefined2 *)PTR_DAT_03053cec = *(undefined2 *)puVar3;
      uVar6 = 1;
    }
  }
  return uVar6;
}

