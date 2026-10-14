/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: screen_mode_static_table_dispatch @ 0305279c (file base 0x03000000; code starts at 0x03001000)
 * Size: 86 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: display-driver
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void screen_mode_static_table_dispatch(void)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  
  if (*(char *)PTR_DAT_03052814 == '\x01') {
    if ((*(char *)((int)PTR_DAT_03052814 + 2) == *(char *)PTR_DAT_03052818) &&
       (iVar2 = buffer_compare_memcmp_style
                          (DAT_03052824,p_menu_screen_state,*(undefined1 *)p_dialog_history_ui_state
                          ), puVar1 = PTR_DAT_03052814, iVar2 == 0)) {
      *(undefined1 *)((int)PTR_DAT_03052814 + 1) = 0;
      *(undefined1 *)puVar1 = 0;
      history_queue_pop();
      uVar3 = PTR_PTR_0305282c[(uint)*DAT_03052828 * 3];
      *PTR_DAT_03052830 = uVar3;
      (*(code *)(uVar3 & 0xfffffffe))();
      *(undefined1 *)PTR_DAT_03052834 = 0;
    }
    else {
      *(undefined1 *)((int)PTR_DAT_03052814 + 1) = 1;
    }
  }
  return;
}

