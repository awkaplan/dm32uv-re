/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: protocol_command_byte_dispatch @ 03064f88 (file base 0x03000000; code starts at 0x03001000)
 * Size: 420 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: host-protocol
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

bool protocol_command_byte_dispatch(uint param_1,char param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  char cVar3;
  bool bVar4;
  int iVar5;
  uint uVar6;
  byte bVar7;
  uint uVar8;
  char cStack_35;
  void *pvStack_30;
  undefined1 auStack_2c [19];
  undefined1 auStack_19 [3];
  undefined1 uStack_16;
  
  uVar6 = param_1 & 0xff;
  uVar8 = param_1 >> 8 & 0xffff;
  cStack_35 = (char)(param_1 >> 0x18);
  pvStack_30 = (void *)0x0;
  if (uVar6 == 0) {
    bVar4 = false;
  }
  else {
    if (uVar6 == 2) {
      bVar7 = p_vfo_display_state->flags_0x8 & 0xf0;
      if ((bVar7 != 0x10) && (bVar7 != 0x30)) {
        return false;
      }
    }
    else if (uVar6 == 1) {
      bVar7 = p_vfo_display_state->flags_0x8 & 0xf0;
      if ((bVar7 != 0) && (bVar7 != 0x20)) {
        return false;
      }
      iVar5 = flash_stored_setting_load_and_dispatch(param_1 >> 8 & 0xff);
      return iVar5 != 0;
    }
    if (cStack_35 == '\x03') {
      dialog_request_init(0x80);
      if (param_2 == '\0') {
        *(undefined1 *)p_text_entry_buffer = 0;
      }
      else {
        list_record_lookup_and_toggle_by_index(4,param_2);
      }
      puVar1 = p_text_entry_buffer;
      cVar3 = strlen_ck803s(p_text_entry_buffer);
      puVar2 = PTR_DAT_03065130;
      *(char *)PTR_DAT_03065130 = cVar3 + '\x01';
      record_read_by_index(uVar8,auStack_2c);
      memcpy_bytes_iram(&pvStack_30,auStack_19,3);
      channel_select_commit_and_notify
                (uStack_16,pvStack_30,puVar1,*(undefined1 *)puVar2,p_dm32_settings_block04[0x54]);
      bVar4 = true;
    }
    else if ((byte)(cStack_35 - 1U) < 2) {
      if (*(char *)PTR_DAT_03065138 == 'i') {
        bVar4 = false;
      }
      else {
        p_radio_mode_state_0003e318[1].flags_0x7 = p_radio_mode_state_0003e318[1].flags_0x7 & 0xfe;
        write_status_mode_byte_pair(0x69,1);
        bVar4 = true;
      }
    }
    else if ((byte)(cStack_35 - 4U) < 5) {
      if ((p_vfo_display_state->flags_0x8 & 8) == 0) {
        record_read_by_index(uVar8,auStack_2c);
        memcpy_bytes_iram(&pvStack_30,auStack_19,3);
        if (cStack_35 == '\x04') {
          dialog_request_enqueue(4,pvStack_30);
          bVar4 = true;
        }
        else if (cStack_35 == '\x06') {
          dialog_request_enqueue(5,pvStack_30);
          bVar4 = true;
        }
        else if (cStack_35 == '\b') {
          dialog_request_enqueue(6,pvStack_30);
          bVar4 = true;
        }
        else if (cStack_35 == '\a') {
          dialog_request_enqueue(7,pvStack_30);
          bVar4 = true;
        }
        else if (cStack_35 == '\x05') {
          dialog_request_enqueue(8,pvStack_30);
          bVar4 = true;
        }
        else {
          bVar4 = true;
        }
      }
      else {
        *PTR_DAT_03065140 = 0;
        format_and_write_status_field2
                  (**(undefined4 **)
                     (PTR_PTR_03065144 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
        bVar4 = false;
      }
    }
    else {
      bVar4 = false;
    }
  }
  return bVar4;
}

