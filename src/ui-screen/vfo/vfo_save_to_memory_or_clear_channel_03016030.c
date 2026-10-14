/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: vfo_save_to_memory_or_clear_channel @ 03016030 (file base 0x03000000; code starts at 0x03001000)
 * Size: 436 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-screen
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void vfo_save_to_memory_or_clear_channel(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 unaff_r7;
  undefined1 auStack_44 [36];
  undefined4 uStack_20;
  byte abStack_1c [4];
  short sStack_18;
  undefined2 uStack_16;
  
  iVar5 = vfo_active_side_mode_nibble();
  if ((iVar5 == 1) || (iVar5 = vfo_active_side_mode_nibble(), iVar5 == 3)) {
    if ((*(byte *)PTR_DAT_0301619c & 1) == 0) {
      ui_event_notify(0x21);
    }
    else {
      iVar5 = poll_condition_group(0x21);
      if (iVar5 != 0) {
        settings_bitfield_remap_0x2d();
        if ((PTR_DAT_03016190[0x2d] & 4) == 0) {
          if ((PTR_DAT_03016190[0x2d] & 0x80) == 0) {
            sStack_18 = 0xfaf;
          }
          else {
            sStack_18 = 0xfdf;
          }
          uStack_16 = 0x41;
        }
        else {
          vfo_load_side_config();
          unaff_r7 = channel_list_index_resolve(PTR_DAT_03016190[0x29],PTR_DAT_03016190[0x26]);
          channel_num_to_block_offset(unaff_r7,&uStack_16,&sStack_18);
        }
        PTR_DAT_03016198[8] = PTR_DAT_03016198[8] & 0xfe | PTR_DAT_03016198[8] & 1 ^ 1;
        iVar5 = is_memory_channel_not_vfo();
        if (iVar5 == 1) {
          uStack_20 = 1;
          uVar1 = *(undefined4 *)PTR_DAT_03016198;
          uVar2 = *(undefined4 *)(PTR_DAT_03016198 + 4);
          uVar3 = *(undefined4 *)(PTR_DAT_03016198 + 8);
          uVar4 = *(undefined4 *)(PTR_DAT_03016198 + 0xc);
          memcpy_ck803s(auStack_44,PTR_DAT_03016198 + 0x10,0x23);
          commit_channel_record_dual_vfo(uVar1,uVar2,uVar3,uVar4);
        }
        else {
          sStack_18 = sStack_18 + 8;
          flash_field_read_cached((undefined1)uStack_16,sStack_18,abStack_1c,1);
          abStack_1c[0] = abStack_1c[0] ^ 1;
          flash_block_write((undefined1)uStack_16,sStack_18,abStack_1c,1);
          iVar5 = get_current_mode_state2();
          if (iVar5 == 0) {
            *(short *)PTR_DAT_0301632c = (short)unaff_r7;
            ui_event_notify_alt(0xc);
          }
          else {
            vfo_exit_dual_watch_and_refresh();
            set_flag_byte_03064328(3);
          }
          *PTR_DAT_03016330 = 0;
          if ((PTR_DAT_03016334[8] & 1) == 0) {
            ui_event_notify(0x19);
            format_and_write_status_field2
                      (*(undefined4 *)PTR_PTR_0301633c[((byte)PTR_DAT_03016338[0x30] >> 6 & 1) * 2])
            ;
          }
          else {
            ui_event_notify(0x18);
            format_and_write_status_field2
                      (*(undefined4 *)
                        (PTR_PTR_0301633c[((byte)PTR_DAT_03016338[0x30] >> 6 & 1) * 2] + 4));
          }
        }
      }
    }
  }
  else {
    ui_event_notify(0x21);
  }
  return;
}

