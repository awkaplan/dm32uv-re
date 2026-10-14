/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dialog_show_icon_and_two_numbers_gb2312_v2 @ 0302c96e (file base 0x03000000; code starts at 0x03001000)
 * Size: 38 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-dialog
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void dialog_show_icon_and_two_numbers_gb2312_v2(void)

{
  uint uVar1;
  void *src;
  
  src = (void *)**(undefined4 **)
                  (PTR_PTR_0302cafc + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8);
  uVar1 = strlen_ck803s(src);
  memcpy_ck803s(&stack0x00000014,src,uVar1 & 0xff);
  dialog_show_icon_and_two_numbers(0x21,0x30,PTR_DAT_0302cb00,&stack0x00000014);
  display_fill_rect(0,0x122,0xf0,0x140,0);
  display_draw_string_gb2312
            (0x122,0xb4,
             (byte *)**(undefined4 **)
                       (PTR_PTR_0302ce80 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8),
             0xffff,0);
  return;
}

