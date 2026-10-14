/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: message_notification_dialog_draw @ 0302c9e4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 80 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-dialog
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void message_notification_dialog_draw(void)

{
  undefined1 *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  void *src;
  int n;
  undefined4 in_stack_00000018;
  undefined1 auStack_2 [2];
  
  puVar1 = p_dm32_settings_block04;
  src = (void *)**(undefined4 **)
                  (PTR_PTR_0302cb0c + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8);
  uVar2 = strlen_ck803s(src);
  memcpy_ck803s(&stack0x00000014,src,uVar2 & 0xff);
  puVar3 = PTR_DAT_0302ce74;
  if ((puVar1[0x30] & 0x40) != 0) {
    SUBPIECE_SET(in_stack_00000018, 1, 1, 0);
    n = (uVar2 & 0xff) - 6;
    memcpy_ck803s(&stack0x00000004,(void *)((int)&stack0x00000018 + 2),n);
    (&stack0x00000004)[n] = 0;
    puVar3 = PTR_DAT_0302cb10;
  }
  dialog_show_icon_and_two_numbers(0x21,0x30,puVar3,&stack0x00000014);
  display_fill_rect(0,0x122,0xf0,0x140,0);
  display_draw_string_gb2312
            (0x122,0xb4,
             (byte *)**(undefined4 **)
                       (PTR_PTR_0302ce80 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8),
             0xffff,0);
  return;
}

