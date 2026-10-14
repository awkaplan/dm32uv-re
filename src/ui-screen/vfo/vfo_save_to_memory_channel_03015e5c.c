/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: vfo_save_to_memory_channel @ 03015e5c (file base 0x03000000; code starts at 0x03001000)
 * Size: 444 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-screen
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void vfo_save_to_memory_channel(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 unaff_r7;
  undefined1 auStack_48 [36];
  undefined4 uStack_24;
  byte abStack_20 [4];
  short sStack_1c;
  undefined2 uStack_1a;
  
  iVar5 = vfo_active_side_mode_nibble();
  if ((iVar5 == 1) || (iVar5 = vfo_active_side_mode_nibble(), iVar5 == 3)) {
    iVar5 = poll_condition_group(0x20);
    if (iVar5 == 0) {
      ui_event_notify(0x21);
    }
    else {
      settings_bitfield_remap_0x2d();
      if ((PTR_DAT_03015f90[0x2d] & 4) == 0) {
        if ((PTR_DAT_03015f90[0x2d] & 0x80) == 0) {
          sStack_1c = 0xfaf;
        }
        else {
          sStack_1c = 0xfdf;
        }
        uStack_1a = 0x41;
      }
      else {
        vfo_load_side_config();
        unaff_r7 = channel_list_index_resolve(PTR_DAT_03015f90[0x29],PTR_DAT_03015f90[0x26]);
        channel_num_to_block_offset(unaff_r7,&uStack_1a,&sStack_1c);
      }
      flash_field_read_cached((undefined1)uStack_1a,sStack_1c + 0xe,abStack_20,1);
      if (abStack_20[0] == 0) {
        ui_event_notify(0x21);
      }
      else {
        *(byte *)((int)PTR_DAT_03015f9c + 0xf) =
             *(byte *)((int)PTR_DAT_03015f9c + 0xf) & 0xbf |
             (*(byte *)((int)PTR_DAT_03015f9c + 0xf) >> 6 & 1 ^ 1) << 6;
        iVar5 = is_memory_channel_not_vfo();
        if (iVar5 == 1) {
          uStack_24 = 1;
          uVar1 = *PTR_DAT_03015f9c;
          uVar2 = PTR_DAT_03015f9c[1];
          uVar3 = PTR_DAT_03015f9c[2];
          uVar4 = PTR_DAT_03015f9c[3];
          memcpy_ck803s(auStack_48,PTR_DAT_03015f9c + 4,0x23);
          commit_channel_record_dual_vfo(uVar1,uVar2,uVar3,uVar4);
        }
        else {
          flash_field_read_cached((undefined1)uStack_1a,sStack_1c + 0xf,abStack_20,1);
          abStack_20[0] = abStack_20[0] ^ 0x40;
          flash_block_write((undefined1)uStack_1a,sStack_1c + 0xf,abStack_20,1);
        }
        iVar5 = get_current_mode_state2();
        if (iVar5 == 0) {
          *(short *)PTR_DAT_03016194 = (short)unaff_r7;
          ui_event_notify_alt(0xc);
        }
        else {
          vfo_exit_dual_watch_and_refresh();
          set_flag_byte_03064328(3);
          if (*(char *)PTR_DAT_0301618c == '\0') {
            vfo_standby_row_render((byte)PTR_DAT_03016190[0x2d] >> 7);
          }
        }
        if ((PTR_DAT_03016198[0xf] & 0x40) == 0) {
          ui_event_notify(0x19);
        }
        else {
          ui_event_notify(0x18);
        }
      }
    }
  }
  else {
    ui_event_notify(0x21);
  }
  return;
}

