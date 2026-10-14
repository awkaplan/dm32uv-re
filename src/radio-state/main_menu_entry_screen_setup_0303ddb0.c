/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: main_menu_entry_screen_setup @ 0303ddb0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 302 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: radio-state
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void main_menu_entry_screen_setup(void)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  
  dialog_history_flush_and_reset();
  PTR_DAT_0303dee0[0xa0a] = 0;
  iVar2 = tx_is_inhibited();
  if ((iVar2 == 0) && (iVar2 = read_byte_field_0305fca8(), iVar2 == 0)) {
    uVar3 = vfo_active_side_mode_nibble();
  }
  else {
    uVar3 = (uint)((byte)PTR_DAT_0303dee4[8] >> 4);
  }
  if (PTR_DAT_0303dee0[4] == '\x01') {
    if ((*(byte *)PTR_DAT_0303dee8 & 2) == 0) {
      iVar2 = get_current_mode_state1();
      if (iVar2 != 0) {
        uVar3 = (byte)PTR_DAT_0303deec[0x10] >> 5 & 3;
      }
      if (uVar3 == 0) {
        uVar3 = 0x18;
      }
      else if (uVar3 == 2) {
        uVar3 = 0x18;
      }
      else if ((PTR_DAT_0303def0[0x11] & 0x20) == 0) {
        uVar3 = 0x17;
      }
      else {
        uVar3 = 0x18;
      }
    }
    else {
      uVar3 = 0x23;
    }
    menu_option_list_dispatch
              (uVar3,PTR_active_screen_index_list_0303def4,
               (void *)((int)PTR_active_screen_index_list_0303def4 + 2));
  }
  puVar1 = PTR_PTR_0303defc;
  if (*(short *)PTR_active_screen_index_list_0303def4 == 0) {
    display_fill_screen(0);
    display_draw_number_centered(100,0xffff,0,**(uint **)PTR_PTR_0303df14);
    OSTimeDly_ms_wrapper(1000);
    history_queue_pop();
  }
  else if ((*(byte *)PTR_DAT_0303dee8 & 2) == 0) {
    uVar3 = (byte)PTR_DAT_0303def8[0x30] >> 6 & 1;
    *(undefined1 *)PTR_active_screen_option_count_0303df00 =
         *(undefined1 *)(PTR_PTR_0303defc + uVar3 * 2 + 1);
    *PTR_active_screen_option_ptr_array_0303df04 = puVar1[uVar3 * 2];
    *(undefined1 *)PTR_active_screen_subtype_0303df08 = *(undefined1 *)((int)puVar1 + uVar3 * 8 + 5)
    ;
  }
  else {
    display_fill_rect(0,0,0xf0,0x1b,0);
    display_draw_number_centered(2,0xffff,0,(uint)PTR_LAB_0303df0c);
    puVar1 = PTR_PTR_0303df10;
    *(undefined1 *)PTR_active_screen_option_count_0303df00 = *(undefined1 *)(PTR_PTR_0303df10 + 1);
    *PTR_active_screen_option_ptr_array_0303df04 = *puVar1;
    *(undefined1 *)PTR_active_screen_subtype_0303df08 = *(undefined1 *)((int)puVar1 + 5);
  }
  main_menu_screen_dispatch();
  return;
}

