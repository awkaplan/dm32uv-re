/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: recording_playback_to_speaker @ 0306158c (file base 0x03000000; code starts at 0x03001000)
 * Size: 584 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void recording_playback_to_speaker(undefined4 param_1)

{
  byte bVar1;
  short sVar2;
  dword dVar3;
  radio_mode_state_0003e318 *prVar4;
  undefined4 *puVar5;
  undefined1 *puVar6;
  ushort block_id;
  undefined2 uVar7;
  undefined4 uVar8;
  int iVar9;
  undefined1 uVar10;
  undefined1 uStack_5c;
  byte bStack_5b;
  byte bStack_57;
  byte bStack_56;
  byte bStack_55;
  undefined1 uStack_51;
  undefined1 uStack_4f;
  undefined1 uStack_4e;
  undefined1 uStack_4d;
  undefined1 uStack_4c;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [28];
  
  prVar4 = p_radio_mode_state_0003e318;
  bVar1 = p_radio_mode_state_0003e318->flags_0x7;
  while ((bVar1 & 2) != 0) {
    OSTimeDly_ms_wrapper(10);
    bVar1 = prVar4->flags_0x7;
  }
  block_id = recording_index_lookup(param_1);
  flash_block_read(block_id,0,&uStack_5c,0x14);
  if (bStack_5b >> 4 == 1) {
    uVar10 = 3;
  }
  else if (bStack_5b >> 4 == 2) {
    uVar10 = 4;
  }
  else {
    uVar10 = 5;
  }
  contact_name_lookup_or_format
            (1,(uint)bStack_55 << 0x10 | (uint)bStack_57 | (uint)bStack_56 << 8,auStack_40,uVar10);
  number_to_string_format_2args
            (&uStack_5c,PTR_s__0_2d__0_2d__0_2d__0_2d__0_2d_030616f4,uStack_51,uStack_4f,uStack_4e,
             uStack_4d,uStack_4c);
  dialog_show_icon_and_two_numbers(0x30,0x2f,PTR_DAT_030616f8,auStack_40,&uStack_5c);
  display_fill_rect(0,0x122,0xf0,0x140,0);
  display_draw_string_from_table(0);
  dialog_state_set_bit_0301ecdc(1);
  memset_bytes(auStack_48,0,7);
  indexed_ramp_field_store_b(auStack_48,7);
  puVar5 = PTR_DAT_030616fc;
  PTR_DAT_030616fc[4] = param_1;
  *(byte *)((int)puVar5 + 0x2b) = *(byte *)((int)puVar5 + 0x2b) & 0xf7;
  OSTimeDly_ms_wrapper(10);
  FUN_00016000(1);
  FUN_000160c0();
  modem_buffer_char_remap_write_03055850(0xd);
  dVar3 = SystemControl_Type_11000000.WORK_MODE;
  SystemControl_Type_11000000.WORK_MODE = dVar3 & 0xffffff7f;
  audio_pa_enable_gate(1);
  puVar6 = PTR_DAT_03061700;
  puVar5 = PTR_DAT_030616fc;
  while( true ) {
    do {
      while ((*(byte *)((int)puVar5 + 0x2b) & 8) == 0) {
        uVar8 = recording_index_lookup(puVar5[4]);
        puVar5[6] = uVar8;
        *(undefined1 *)(puVar5 + 9) = 0;
        uVar8 = flash_page_indexed_2byte_read(uVar8,0);
        puVar5[7] = uVar8;
        uVar7 = flash_page_trailing_count_read();
        *(undefined2 *)((int)puVar5 + 0x26) = uVar7;
        *(byte *)((int)puVar5 + 0x2b) = *(byte *)((int)puVar5 + 0x2b) & 0xf7 | 8;
        *(undefined1 *)(puVar5 + 9) = 1;
        *(undefined2 *)(puVar5 + 10) = 0;
      }
      flash_block_read(*(ushort *)(puVar5 + 7),(uint)*(ushort *)(puVar5 + 10),auStack_40,0x1b);
      FUN_000161a8(0,auStack_40,0x1b,0x46);
      sVar2 = *(short *)(puVar5 + 10);
      *(ushort *)(puVar5 + 10) = sVar2 + 0x1bU;
    } while (((ushort)(sVar2 + 0x1bU) <= *(ushort *)((int)puVar5 + 0x26)) && (*puVar6 == '\0'));
    iVar9 = flash_page_indexed_2byte_read(puVar5[6],*(undefined1 *)(puVar5 + 9));
    puVar5[7] = iVar9;
    if ((iVar9 == 0xffff) || (*puVar6 != '\0')) break;
    uVar7 = flash_page_trailing_count_read();
    *(undefined2 *)((int)puVar5 + 0x26) = uVar7;
    *(char *)(puVar5 + 9) = *(char *)(puVar5 + 9) + '\x01';
    *(undefined2 *)(puVar5 + 10) = 0;
  }
  FUN_00016000(0);
  PTR_DAT_03061904[0x2b] = PTR_DAT_03061904[0x2b] & 0xf7;
  indexed_ramp_field_store_b(DAT_03061908,7);
  if ((p_vfo_display_state->flags_0x8 & 0xf0) == 0) {
    dVar3 = SystemControl_Type_11000000.WORK_MODE;
    SystemControl_Type_11000000.WORK_MODE = dVar3 | 0x80;
  }
  tone_or_volume_step_lookup(*(undefined1 *)PTR_DAT_03061910);
  FUN_00016104();
  audio_pa_enable_gate(0);
  dialog_state_set_bit_0301ecdc(0);
  if (*(char *)PTR_DAT_03061914 != '\0') {
    dialog_show_icon_and_two_numbers
              (0x30,0x30,PTR_DAT_03061924,
               PTR_PTR_0306191c[(byte)p_dm32_settings_block04[0x30] >> 6 & 1],PTR_LAB_03061920);
    *(undefined1 *)PTR_DAT_03061914 = 0;
    OSTimeDly_ms_wrapper(1000);
  }
  return;
}

