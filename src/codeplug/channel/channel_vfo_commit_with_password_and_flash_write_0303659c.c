/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_vfo_commit_with_password_and_flash_write @ 0303659c (file base 0x03000000; code starts at 0x03001000)
 * Size: 838 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void channel_vfo_commit_with_password_and_flash_write(void)

{
  undefined2 *puVar1;
  byte bVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  
  if ((*(byte *)PTR_DAT_030366a0 & 2) == 0) {
    if ((PTR_DAT_030366b0[8] & 1) == 0) {
      if (((*(byte *)PTR_call_active_flag_0303685c & 8) == 0) ||
         (iVar6 = bitwise_not_of_boolean_result(), iVar6 == 0)) {
        puVar4 = PTR_DAT_0303687c;
        if ((*PTR_DAT_03036864 & 0x18000) == 0x8000) {
          if ((*(byte *)PTR_DAT_03036868 & 2) == 0) {
            *(byte *)PTR_DAT_03036868 = *(byte *)PTR_DAT_03036868 & 0xfd | 2;
            *(undefined2 *)PTR_DAT_0303686c = 0x1db0;
            format_and_write_status_field2(DAT_03036874);
          }
          else {
            *(byte *)PTR_DAT_03036868 = *(byte *)PTR_DAT_03036868 & 0xfd;
            *(undefined2 *)PTR_DAT_0303686c = 0x1964;
            format_and_write_status_field2(PTR_LAB_03036870);
          }
          *(byte *)((int)PTR_DAT_03036864 + 2) = *(byte *)((int)PTR_DAT_03036864 + 2) & 0xfd;
          flash_block4_write_offset0x700_u16(PTR_DAT_03036868);
          puVar4 = PTR_DAT_0303686c;
          bcd_pack_and_write_flash_block4_0x702(*(undefined2 *)PTR_DAT_0303686c);
          rda5807m_tune(*(undefined2 *)puVar4);
        }
        else {
          bVar2 = *(byte *)((int)PTR_DAT_03036864 + 3);
          if ((bVar2 & 2) == 0) {
            write_status_mode_byte_pair(7,1);
          }
          else if ((bVar2 & 8) == 0) {
            write_status_mode_byte_pair
                      (*(undefined1 *)((uint)p_dialog_history_ui_state->index_0x2 + DAT_03036a24),0)
            ;
            tx_gate_write_call_record(0);
          }
          else {
            if ((bVar2 & 4) == 0) {
              *(undefined1 *)((int)PTR_DAT_0303687c + 0x11) = 0xff;
              *(undefined1 *)((int)puVar4 + 0x12) = 0xff;
              *(undefined1 *)((int)puVar4 + 0x13) = 0xff;
              *(undefined1 *)(puVar4 + 5) = 0xff;
            }
            else if (PTR_DAT_03036878[0x5e] == '\0') {
              puVar1 = (undefined2 *)((int)PTR_DAT_0303687c + 0x11);
              *(char *)((int)PTR_DAT_0303687c + 0x13) = (char)*puVar1;
              *(char *)(puVar4 + 5) = (char)((ushort)*puVar1 >> 8);
              *(undefined1 *)((int)puVar4 + 0x11) = 0xff;
              *(undefined1 *)((int)puVar4 + 0x12) = 0xff;
            }
            else if (PTR_DAT_03036878[0x5e] == '\x01') {
              *(undefined1 *)((int)PTR_DAT_0303687c + 0x13) = 0xff;
              *(undefined1 *)(puVar4 + 5) = 0xff;
            }
            else {
              puVar1 = (undefined2 *)((int)PTR_DAT_0303687c + 0x11);
              *(char *)((int)PTR_DAT_0303687c + 0x13) = (char)*puVar1;
              *(char *)(puVar4 + 5) = (char)((ushort)*puVar1 >> 8);
            }
            puVar5 = PTR_DAT_03036a10;
            puVar4 = PTR_DAT_0303687c;
            if ((PTR_DAT_03036854[0x2d] & 4) == 0) {
              bcd_pack_and_write_flash_block_0x41
                        (*PTR_DAT_03036a10,(byte)PTR_DAT_03036a14[0x2d] >> 7);
              vfo_frequency_write(0,*(undefined2 *)((int)puVar5 + 0x11));
              vfo_frequency_write(1,*(undefined2 *)((int)puVar5 + 0x13));
            }
            else {
              channel_field_bcd_write_to_flash_block(*PTR_DAT_0303687c,0);
              uVar3 = *puVar4;
              *(char *)(puVar4 + 1) = (char)uVar3;
              *(char *)((int)puVar4 + 5) = (char)((uint)uVar3 >> 8);
              *(char *)((int)puVar4 + 6) = (char)((uint)uVar3 >> 0x10);
              *(char *)((int)puVar4 + 7) = (char)((uint)uVar3 >> 0x18);
              channel_field_bcd_write_to_flash_block(uVar3,1);
              channel_field_write_and_notify(0,*(undefined2 *)((int)puVar4 + 0x11));
              channel_field_write_and_notify(1,*(undefined2 *)((int)puVar4 + 0x13));
            }
            vfo_field_write_nibble_high(0);
            if ((PTR_DAT_03036a14[0x2d] & 0x80) == 0) {
              memcpy_ck803s(DAT_03036a18,PTR_DAT_03036a10,0x33);
            }
            else {
              memcpy_ck803s(DAT_03036a1c,PTR_DAT_03036a10,0x33);
            }
            write_status_mode_byte_pair
                      (*(undefined1 *)((uint)p_dialog_history_ui_state->index_0x2 + DAT_03036a24),0)
            ;
            radio_idle_state_reset(0);
          }
        }
      }
      else {
        *(undefined1 *)PTR_DAT_03036860 = 0x43;
        write_status_mode_byte_pair(0x70,1);
      }
    }
    else {
      memset_bytes(DAT_030366a4,0,8);
      iVar6 = DAT_030366a8;
      iVar9 = (uint)(byte)PTR_DAT_03036698[0xa08] * 2 + -1;
      if (0 < iVar9) {
        uVar7 = 0;
        uVar8 = 0;
        do {
          *(undefined1 *)(iVar6 + uVar8 + 0x14) = *(undefined1 *)(iVar6 + uVar7);
          uVar8 = uVar8 + 1 & 0xff;
          uVar7 = uVar8 * 2 & 0xff;
        } while ((int)uVar7 < iVar9);
      }
      iVar6 = buffer_compare_memcmp_style(DAT_030366a4,PTR_DAT_030366b0,8);
      if (iVar6 == 0) {
        PTR_DAT_030366b0[8] = PTR_DAT_030366b0[8] & 0xfe;
        channel_change_apply_with_zone_and_flash_validate();
        write_status_mode_byte_pair(0,1);
      }
      else {
        format_and_write_status_field2
                  (**(undefined4 **)(PTR_PTR_03036858 + ((byte)PTR_DAT_03036854[0x30] >> 6 & 1) * 8)
                  );
      }
    }
  }
  else if (PTR_DAT_03036698[0xa08] == 0xa5) {
    *(byte *)PTR_DAT_030366a0 = *(byte *)PTR_DAT_030366a0 & 0xf7 | 8;
    write_status_mode_byte_pair(7);
  }
  else if ((byte)PTR_DAT_03036698[0xa08] < 10) {
    memset_bytes(DAT_030366a4,0,8);
    iVar6 = DAT_030366a8;
    iVar9 = (uint)(byte)PTR_DAT_03036698[0xa08] * 2 + -1;
    if (0 < iVar9) {
      uVar7 = 0;
      uVar8 = 0;
      do {
        *(undefined1 *)(iVar6 + uVar8 + 0x14) = *(undefined1 *)(iVar6 + uVar7);
        uVar8 = uVar8 + 1 & 0xff;
        uVar7 = uVar8 * 2 & 0xff;
      } while ((int)uVar7 < iVar9);
    }
    iVar6 = buffer_compare_memcmp_style(DAT_030366a4,PTR_s_66660501_030366ac,8);
    if (iVar6 == 0) {
      *(byte *)PTR_DAT_030366a0 = *(byte *)PTR_DAT_030366a0 & 0xf7 | 8;
      write_status_mode_byte_pair(7);
    }
    else {
      write_status_mode_byte_pair(0,1);
    }
  }
  return;
}

