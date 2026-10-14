/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_context_mode_dispatch @ 030442ac (file base 0x03000000; code starts at 0x03001000)
 * Size: 52 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void menu_context_mode_dispatch(void)

{
  char cVar1;
  byte bVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  
  puVar4 = PTR_DAT_03044500;
  puVar3 = PTR_PTR_030444fc;
  cVar1 = *(char *)((uint)p_menu_screen_state->index_0x3 + DAT_030442f8 + 2);
  if (cVar1 == '\0') {
    p_radio_mode_state_0003e318->field_0x8 = p_radio_mode_state_0003e318->field_0x8 & 0xdf;
    uVar5 = (uint)*(byte *)((uint)p_menu_screen_state->index_0x4 + DAT_03044300 + 2);
    if (uVar5 < 0xb) {
                    /* WARNING: Could not recover jumptable at 0x030442de. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(PTR_PTR_03044304[uVar5] & 0xfffffffe))();
      return;
    }
  }
  else if (cVar1 == '\x01') {
    bVar2 = *(byte *)((uint)p_menu_screen_state->index_0x4 + DAT_030444f8 + 2);
    if (bVar2 < 0xb) {
      if (bVar2 == 0) {
        uVar5 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
        bVar2 = *(byte *)(PTR_PTR_030444fc + uVar5 * 2 + 1);
        *(byte *)p_active_screen_option_count = bVar2;
        *p_active_screen_option_ptr_array = puVar3[uVar5 * 2];
        *(undefined1 *)PTR_active_screen_subtype_030444d4 =
             *(undefined1 *)((int)puVar3 + uVar5 * 8 + 5);
        if (*(char *)PTR_DAT_030444d8 == '\x01') {
          build_sequential_index_list
                    ((ushort)bVar2,p_active_screen_index_list,
                     (byte *)(p_active_screen_index_list + 1));
        }
      }
      else {
        settings_code_read_and_status_dispatch();
      }
    }
    else if (bVar2 == 0xb) {
      *(undefined1 *)p_active_screen_option_count = *(undefined1 *)(PTR_DAT_03044500 + 1);
      *p_active_screen_option_ptr_array = *puVar4;
      *(undefined1 *)PTR_active_screen_subtype_030444d4 = *(undefined1 *)((int)puVar4 + 5);
      *(undefined1 *)PTR_DAT_03044504 = 0x51;
    }
  }
  else if (cVar1 == '\x02') {
    uVar5 = (uint)*(byte *)((uint)p_menu_screen_state->index_0x4 + DAT_030444f8 + 2);
    if (uVar5 < 0x12) {
                    /* WARNING: Could not recover jumptable at 0x030444c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(PTR_PTR_03044508[uVar5] & 0xfffffffe))();
      return;
    }
  }
  else if ((cVar1 == '\x03') &&
          (uVar5 = (uint)*(byte *)((uint)p_menu_screen_state->index_0x4 + DAT_03044934 + 2),
          uVar5 < 0x15)) {
                    /* WARNING: Could not recover jumptable at 0x0304492c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(PTR_PTR_03044938[uVar5] & 0xfffffffe))();
    return;
  }
  return;
}

