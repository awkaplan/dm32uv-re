/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: scan_list_flash_field_bit_update @ 030519a0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 478 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void scan_list_flash_field_bit_update(void)

{
  char cVar1;
  undefined4 *puVar2;
  byte bVar3;
  short local_14 [2];
  byte local_10 [3];
  short sStack_d;
  short sStack_b;
  
  puVar2 = PTR_DAT_03051b00;
  flash_field_read_cached(0x11,(*(byte *)PTR_DAT_03051b00 - 1) * 0x39 + 0xf,local_10,7);
  flash_field_read_cached
            (0x11,(*(byte *)puVar2 - 1) * 0x39 + (p_menu_screen_state->index_0x5 - 1) * 2 + 0x1b,
             local_14,2);
  puVar2 = PTR_DAT_03051ccc;
  cVar1 = *(char *)p_active_screen_state_word;
  if (cVar1 == '\0') {
    if (p_menu_screen_state->index_0x5 == 0) {
      if ((p_vfo_freq_display_state->field_0x4 & 0xf) == 1) {
        local_10[0] = 0;
        sStack_d = 0;
        sStack_b = 0;
      }
      else if ((p_vfo_freq_display_state->field_0x4 & 0xf0) == 0x10) {
        local_10[0] = local_10[0] & 0xf;
        sStack_b = 0;
      }
    }
    else if (local_14[0] == sStack_d) {
      local_10[0] = 0;
      sStack_d = 0;
      sStack_b = 0;
    }
    else if (sStack_b == local_14[0]) {
      local_10[0] = local_10[0] & 0xf;
      sStack_b = 0;
    }
  }
  else if (cVar1 == '\x01') {
    if (p_menu_screen_state->index_0x5 == 0) {
      local_10[0] = local_10[0] & 0xf0 | 1;
      sStack_d = 1;
      if ((p_vfo_freq_display_state->field_0x4 & 0xf0) == 0x10) {
        local_10[0] = 1;
        sStack_b = 0;
      }
    }
    else {
      sStack_d = local_14[0];
      local_10[0] = local_10[0] & 0xf0 | 2;
      if (*(short *)&p_vfo_freq_display_state->field_0xa_0 == local_14[0]) {
        local_10[0] = 2;
        sStack_b = 0;
      }
    }
  }
  else if (cVar1 == '\x02') {
    if (p_menu_screen_state->index_0x5 == 0) {
      local_10[0] = local_10[0] & 0xf | 0x10;
      sStack_b = 1;
      if ((p_vfo_freq_display_state->field_0x4 & 0xf) == 1) {
        local_10[0] = 0x10;
        sStack_d = 0;
      }
    }
    else {
      sStack_b = local_14[0];
      local_10[0] = local_10[0] & 0xf | 0x20;
      if (*(short *)&p_vfo_freq_display_state->field_0x8_0 == local_14[0]) {
        local_10[0] = 0x20;
        sStack_d = 0;
      }
    }
  }
  flash_block_write(0x11,(*(byte *)PTR_DAT_03051ccc - 1) * 0x39 + 0xf,local_10,7);
  zone_record_read(*(undefined1 *)puVar2);
  bVar3 = scan_list_entry_byte_read(*(undefined1 *)puVar2);
  p_vfo_freq_display_state->field_0x1 = bVar3;
  dialog_show_icon_and_number_from_ptr();
  history_queue_pop();
  return;
}

