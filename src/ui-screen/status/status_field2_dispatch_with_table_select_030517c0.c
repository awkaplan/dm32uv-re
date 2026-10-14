/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: status_field2_dispatch_with_table_select @ 030517c0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 154 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-screen
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void status_field2_dispatch_with_table_select(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  
  puVar3 = PTR_PTR_03051920;
  puVar2 = PTR_PTR_0305191c;
  puVar1 = PTR_PTR_03051918;
  if ((p_dialog_flags_from_flash->flags_0x1e & 0xf) == 2) {
    if ((p_dialog_flags_from_flash->flags_0x1e & 0x70) == 0x10) {
      uVar4 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
      *(undefined1 *)p_active_screen_option_count =
           *(undefined1 *)(PTR_PTR_03051918 + uVar4 * 2 + 1);
      *p_active_screen_option_ptr_array = puVar1[uVar4 * 2];
      *(undefined1 *)PTR_active_screen_subtype_0305190c =
           *(undefined1 *)((int)puVar1 + uVar4 * 8 + 5);
    }
    else {
      uVar4 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
      *(undefined1 *)p_active_screen_option_count =
           *(undefined1 *)(PTR_PTR_0305191c + uVar4 * 2 + 1);
      *p_active_screen_option_ptr_array = puVar2[uVar4 * 2];
      *(undefined1 *)PTR_active_screen_subtype_0305190c =
           *(undefined1 *)((int)puVar2 + uVar4 * 8 + 5);
    }
  }
  else {
    uVar4 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
    *(undefined1 *)p_active_screen_option_count = *(undefined1 *)(PTR_PTR_03051920 + uVar4 * 2 + 1);
    *p_active_screen_option_ptr_array = puVar3[uVar4 * 2];
    *(undefined1 *)PTR_active_screen_subtype_0305190c = *(undefined1 *)((int)puVar3 + uVar4 * 8 + 5)
    ;
    if ((p_vfo_display_state->flags_0x8 & 8) == 0) {
      dialog_request_enqueue(5,(void *)*PTR_DAT_03051af4);
    }
    else {
      format_and_write_status_field2
                (**(undefined4 **)
                   (PTR_PTR_03051af0 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
    }
  }
  write_status_mode_byte_pair(*(undefined1 *)((uint)*DAT_03051af8 + DAT_03051afc),0);
  return;
}

