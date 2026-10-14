/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: draw_wrapped_text_conditional @ 0305ab40 (file base 0x03000000; code starts at 0x03001000)
 * Size: 156 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: display-driver
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void draw_wrapped_text_conditional(void)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  undefined2 local_8;
  undefined1 uStack_6;
  
  uStack_6 = 0;
  if (*(char *)PTR_active_screen_subtype_0305abc8 != '\b') {
    uVar4 = (uint)*DAT_0305abcc;
    if (uVar4 == 0) {
      uVar2 = *(ushort *)p_text_entry_current_char;
    }
    else if (*(char *)(uVar4 + p_text_entry_buffer_alias) < '\0') {
      uVar2 = *(ushort *)p_text_entry_current_char;
      if (0x17 < uVar2) {
        uVar2 = uVar2 - 0x18;
        uVar4 = uVar4 - 2 & 0xff;
      }
    }
    else {
      uVar2 = *(ushort *)p_text_entry_current_char;
      if (0xb < uVar2) {
        uVar2 = uVar2 - 0xc;
        uVar4 = uVar4 - 1 & 0xff;
      }
    }
    bVar1 = p_text_entry_buffer[uVar4];
    if ((char)bVar1 < '\0') {
      local_8 = CONCAT11(*(undefined1 *)(uVar4 + p_text_entry_buffer_alias),bVar1);
      uVar3 = uVar2 + 0x18;
    }
    else {
      local_8 = (ushort)bVar1;
      uVar3 = uVar2 + 0xc;
    }
    if ((uVar3 & 0xff) < 0xe5) {
      display_draw_string_wrapped2(*(undefined2 *)PTR_DAT_0305ad20,uVar2,&local_8,0xffff,0);
    }
  }
  return;
}

