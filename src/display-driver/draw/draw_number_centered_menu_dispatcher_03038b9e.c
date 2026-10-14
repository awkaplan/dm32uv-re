/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: draw_number_centered_menu_dispatcher @ 03038b9e (file base 0x03000000; code starts at 0x03001000)
 * Size: 320 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: display-driver
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void draw_number_centered_menu_dispatcher(void)

{
  char cVar1;
  undefined *puVar2;
  
  cVar1 = *(char *)((uint)p_menu_screen_state->index_0x1 + DAT_03038cd8 + 2);
  if (cVar1 == '\x03') {
    puVar2 = *(undefined **)
              (PTR_PTR_03038ce0[((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 2] +
              (uint)*(byte *)((uint)p_menu_screen_state->index_0x2 + DAT_03038cdc + 2) * 4);
  }
  else {
    puVar2 = PTR_LAB_03039018;
    if (cVar1 == '\x05') {
      cVar1 = *(char *)((uint)p_menu_screen_state->index_0x3 + DAT_03038cc0 + 2);
      if (cVar1 == '\x01') {
        puVar2 = (undefined *)
                 **(undefined4 **)
                   (PTR_PTR_03038ce4 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8);
      }
      else if (cVar1 == '\x02') {
        if (*(char *)((uint)p_menu_screen_state->index_0x4 + DAT_03038cc8 + 2) == '\x11') {
          puVar2 = *(undefined **)
                    (PTR_PTR_03038cec[((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 2] +
                    (uint)*(byte *)((uint)p_menu_screen_state->index_0x5 + DAT_03038ce8 + 2) * 4);
        }
      }
      else if ((cVar1 == '\x03') &&
              (*(char *)((uint)p_menu_screen_state->index_0x4 + DAT_03038cc8 + 2) == '\x03')) {
        puVar2 = *(undefined **)
                  (PTR_PTR_03038cf0[((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 2] +
                  (uint)*(byte *)((uint)p_menu_screen_state->index_0x5 + DAT_03038ce8 + 2) * 4);
      }
    }
    else if (cVar1 == '\0') {
      cVar1 = *(char *)((uint)p_menu_screen_state->index_0x2 + DAT_03038cdc + 2);
      if (cVar1 == '\0') {
        puVar2 = (undefined *)
                 **(undefined4 **)
                   (PTR_PTR_03038cf4 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 4);
      }
      else if (cVar1 == '\x03') {
        memcpy_bytes_iram(&stack0x00000004,DAT_03038cb8,0x10);
        puVar2 = &stack0x00000004;
      }
    }
    else if (cVar1 == '\x01') {
      if (*(char *)((uint)p_menu_screen_state->index_0x2 + DAT_03038cdc + 2) == '\x01') {
        puVar2 = (undefined *)
                 **(undefined4 **)
                   (PTR_PTR_03038cf8 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 4);
      }
    }
    else if (cVar1 == '\x04') {
      puVar2 = (undefined *)
               **(undefined4 **)
                 (PTR_PTR_03038e50 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 4);
    }
    else {
      puVar2 = PTR_LAB_03038e58;
      if (cVar1 == '\a') {
        puVar2 = p_text_entry_buffer;
      }
    }
  }
  display_draw_number_centered(1,0xffff,0,(uint)puVar2);
  return;
}

