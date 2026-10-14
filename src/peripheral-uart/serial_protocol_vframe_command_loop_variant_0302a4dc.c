/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: serial_protocol_vframe_command_loop_variant @ 0302a4dc (file base 0x03000000; code starts at 0x03001000)
 * Size: 1252 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: peripheral-uart
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4 serial_protocol_vframe_command_loop_variant(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined *puVar7;
  undefined *puVar8;
  byte bVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  undefined1 *puVar13;
  int iVar14;
  undefined4 uVar15;
  uint unaff_r7;
  uint unaff_r11;
  uint local_3c;
  uint uStack_38;
  int local_28;
  
  puVar1 = PTR_DAT_0302a5dc;
  *(undefined1 *)PTR_DAT_0302a5dc = 6;
  puVar2 = PTR_DAT_0302a5e0;
  (*(code *)(PTR_DAT_0302a5e0[1] & 0xfffffffe))(puVar1,1);
  iVar10 = (*(code *)(*puVar2 & 0xfffffffe))(puVar1,1,500,&local_28);
  if (iVar10 == 0) {
    uVar15 = 0;
  }
  else if (*(char *)puVar1 == '\x02') {
    memset_bytes(puVar1,0xff,8);
    puVar2 = PTR_DAT_0302a5e0;
    (*(code *)(PTR_DAT_0302a5e0[1] & 0xfffffffe))(puVar1,8);
    iVar10 = (*(code *)(*puVar2 & 0xfffffffe))(puVar1,1,500,&local_28);
    if (iVar10 == 0) {
      uVar15 = 0;
    }
    else if (*(char *)puVar1 == '\x06') {
      *(undefined1 *)puVar1 = 6;
      (*(code *)(puVar2[1] & 0xfffffffe))(puVar1,1);
      puVar3 = PTR_DAT_0302a5e4;
      puVar2 = PTR_DAT_0302a5e0;
      local_3c = 0;
      uVar15 = 0;
      iVar14 = 0;
      iVar12 = (int)puVar1 + 3;
      puVar13 = (undefined1 *)(DAT_0302a5e8 + -6);
      iVar10 = 0;
      while( true ) {
        while (iVar14 != 1) {
          if (iVar14 == 0) {
            (*(code *)(*puVar2 & 0xfffffffe))(puVar1,5,2000,&local_28);
            if (local_28 == 0x72d9) {
              return uVar15;
            }
            if (*(char *)puVar1 == 'V') {
              local_3c = (uint)*(byte *)(puVar1 + 1);
              unaff_r7 = 0x56;
              if (local_3c == 0xd) {
                uStack_38 = (uint)CONCAT11(*(undefined1 *)((int)puVar1 + 1),
                                           *(undefined1 *)((int)puVar1 + 2));
                iVar14 = 2;
              }
              else {
                if (*(char *)((int)puVar1 + 1) != '\0') {
                  return uVar15;
                }
                if (*(char *)((int)puVar1 + 2) != '\0') {
                  return uVar15;
                }
                if (*(char *)((int)puVar1 + 3) != '\0') {
                  return uVar15;
                }
                iVar14 = 2;
              }
            }
            else {
              (*(code *)(*puVar2 & 0xfffffffe))(DAT_0302a7a0,1,1000,&local_28);
              if (local_28 == 0x72d9) {
                return uVar15;
              }
              uStack_38 = (uint)*(byte *)((int)puVar1 + 1) |
                          (uint)*(byte *)((int)puVar1 + 3) << 0x10 |
                          (uint)*(byte *)((int)puVar1 + 2) << 8;
              unaff_r11 = (uint)*(ushort *)(puVar1 + 1);
              unaff_r7 = (uint)*(byte *)puVar1;
              if (unaff_r7 == 0x57) {
                uVar15 = 1;
                iVar14 = 1;
              }
              else if (unaff_r7 == 0x52) {
                iVar14 = 2;
              }
              else if (unaff_r7 == 0x44) {
                iVar14 = 2;
              }
              else if (unaff_r7 == 0x53) {
                iVar14 = 1;
              }
              else {
                if (unaff_r7 != 0x47) {
                  return uVar15;
                }
                iVar14 = 2;
              }
            }
          }
          else if (iVar14 == 2) {
            if (unaff_r7 == 0x52) {
              flash_read_mutex_guarded(uStack_38,DAT_0302a7a8,unaff_r11);
              *puVar13 = 0x57;
              (*(code *)(puVar2[1] & 0xfffffffe))(puVar13,unaff_r11 + 6 & 0xffff);
            }
            else if (unaff_r7 == 0x44) {
              if (unaff_r11 < 0x200) {
                sdcard_data_block_read(DAT_0302a7a8,uStack_38,1);
              }
              else {
                sdcard_data_block_read(DAT_0302a7a8,uStack_38,unaff_r11 >> 9 & 0xff);
              }
              *(undefined1 *)puVar1 = 0x57;
              (*(code *)(puVar2[1] & 0xfffffffe))(puVar1,unaff_r11 + 6 & 0xffff);
            }
            else if (unaff_r7 == 0x47) {
              mutex_guarded_call_generic3arg(uStack_38,DAT_0302a7a8,unaff_r11);
              *puVar13 = 0x53;
              (*(code *)(puVar2[1] & 0xfffffffe))(puVar13,unaff_r11 + 6 & 0xffff);
            }
            else if (unaff_r7 == 0x56) {
              *(undefined1 *)puVar1 = 0x56;
              *(char *)((int)puVar1 + 1) = (char)local_3c;
              puVar8 = PTR_s_C1_00_01_001_0302a99c;
              puVar7 = PTR_s_R1_00_01_001_0302a970;
              puVar6 = PTR_s_D1_01_01_004_0302a96c;
              puVar5 = PTR_LAB_0302a964;
              puVar4 = PTR_s_DM32_00_01_048_0302a7ac;
              if (local_3c == 1) {
                bVar9 = strlen_ck803s(PTR_s_DM32_00_01_048_0302a7ac);
                local_3c = (uint)bVar9;
                *(byte *)((int)puVar1 + 2) = bVar9;
                memcpy_bytes_iram(iVar12,puVar4,local_3c);
              }
              else if (local_3c == 3) {
                bVar9 = strlen_ck803s(PTR_LAB_0302a964);
                local_3c = (uint)bVar9;
                *(byte *)((int)puVar1 + 2) = bVar9;
                memcpy_bytes_iram(iVar12,puVar5,local_3c);
              }
              else if (local_3c == 2) {
                struct_init_const_wrapper(DAT_0302a968);
                puVar3[8] = *puVar3 ^ puVar3[4];
                puVar3[9] = puVar3[1] | puVar3[5];
                puVar3[10] = puVar3[2] ^ puVar3[6];
                puVar3[0xb] = puVar3[3] ^ puVar3[7];
                puVar3[-1] = 0xc;
                local_3c = 0xc;
              }
              else if (local_3c == 4) {
                bVar9 = strlen_ck803s(PTR_s_D1_01_01_004_0302a96c);
                local_3c = (uint)bVar9;
                *(byte *)((int)puVar1 + 2) = bVar9;
                memcpy_bytes_iram(iVar12,puVar6,local_3c);
              }
              else if (local_3c == 5) {
                bVar9 = strlen_ck803s(PTR_s_R1_00_01_001_0302a970);
                local_3c = (uint)bVar9;
                *(byte *)((int)puVar1 + 2) = bVar9;
                memcpy_bytes_iram(iVar12,puVar7,local_3c);
              }
              else if (local_3c == 6) {
                *(undefined1 *)((int)puVar1 + 2) = 8;
                store_u32_le(*(undefined4 *)PTR_LAB_0302a974,iVar12);
                store_u32_le(*(undefined4 *)PTR_LAB_0302a978,(int)puVar1 + 7);
                local_3c = 8;
              }
              else if (local_3c == 7) {
                *(undefined1 *)((int)puVar1 + 2) = 8;
                store_u32_le(*PTR_DAT_0302a97c,iVar12);
                store_u32_le(*(undefined4 *)PTR_LAB_0302a980,(int)puVar1 + 7);
                local_3c = 8;
              }
              else if (local_3c == 8) {
                *(undefined1 *)((int)puVar1 + 2) = 8;
                store_u32_le(*PTR_DAT_0302a984,iVar12);
                store_u32_le(*(undefined4 *)PTR_LAB_0302a988,(int)puVar1 + 7);
              }
              else if (local_3c == 9) {
                *(undefined1 *)((int)puVar1 + 2) = 8;
                store_u32_le(*PTR_DAT_0302a98c,iVar12);
                store_u32_le(*PTR_DAT_0302a990,(int)puVar1 + 7);
                local_3c = 8;
              }
              else if (local_3c == 10) {
                *(undefined1 *)((int)puVar1 + 2) = 8;
                store_u32_le(*(undefined4 *)PTR_LAB_0302a994,iVar12);
                store_u32_le(*(undefined4 *)PTR_LAB_0302a998,(int)puVar1 + 7);
                local_3c = 8;
              }
              else if (local_3c == 0xb) {
                bVar9 = strlen_ck803s(PTR_s_C1_00_01_001_0302a99c);
                local_3c = (uint)bVar9;
                *(byte *)((int)puVar1 + 2) = bVar9;
                memcpy_bytes_iram(iVar12,puVar8,local_3c);
              }
              else if (local_3c == 0xd) {
                bVar9 = *(byte *)((int)puVar1 + 3);
                local_3c = (uint)bVar9;
                memcpy_bytes_iram(iVar12,PTR_LAB_0302a9a0 + uStack_38,local_3c);
                *(byte *)((int)puVar1 + 2) = bVar9;
              }
              else if (local_3c == 0xf) {
                *(undefined1 *)((int)puVar1 + 2) = 8;
                store_u32_le(*PTR_DAT_0302a9a4,iVar12);
                store_u32_le(*(undefined4 *)PTR_LAB_0302a9a8,(int)puVar1 + 7);
                local_3c = 8;
              }
              else if (local_3c == 0x10) {
                *(undefined1 *)((int)puVar1 + 2) = 3;
                *(undefined1 *)((int)puVar1 + 3) = 0x50;
                *(undefined1 *)(puVar1 + 1) = 0xc3;
                *(undefined1 *)((int)puVar1 + 5) = 0;
                local_3c = 3;
              }
              (*(code *)(puVar2[1] & 0xfffffffe))(puVar1,local_3c + 3);
            }
            if (iVar10 == 0) {
              tx_led_or_tone_off_conditional();
              iVar10 = 1;
              iVar14 = 0;
            }
            else {
              tx_led_or_tone_on();
              iVar14 = 0;
              iVar10 = iVar14;
            }
          }
          else if (iVar14 == 3) {
            iVar14 = (*(code *)(*puVar2 & 0xfffffffe))(puVar1,1,600,&local_28);
            if (local_28 == 0x72d9) {
              return uVar15;
            }
            if (iVar14 != 1) {
              return uVar15;
            }
            if (*(char *)puVar1 != '\x06') {
              return uVar15;
            }
            (*(code *)(puVar2[1] & 0xfffffffe))(puVar1,1);
            iVar14 = 0;
          }
        }
        uVar11 = (*(code *)(*puVar2 & 0xfffffffe))(puVar1,unaff_r11,2000,&local_28);
        if ((local_28 == 0x72d9) || (uVar11 != unaff_r11)) break;
        if (unaff_r7 == 0x53) {
          if ((uStack_38 & 0xfff) == 0) {
            serial_flash_sector_erase_then_poll_ready();
          }
          serial_flash_write_chunk_with_retry(uStack_38,puVar1,uVar11);
        }
        else if (unaff_r7 == 0x57) {
          if ((uStack_38 & 0xfff) == 0) {
            *PTR_DAT_0302a7a4 = uStack_38;
            flash_mutex_guarded_op(uStack_38 >> 0xc);
          }
          spi_flash_write_multi_sector(uStack_38,puVar1,unaff_r11);
        }
        *(undefined1 *)puVar1 = 6;
        (*(code *)(puVar2[1] & 0xfffffffe))(puVar1,1);
        if (iVar10 == 0) {
          tx_led_or_tone_off_conditional_variant_030609ec();
          tx_led_or_tone_on();
          iVar10 = 1;
          iVar14 = 0;
        }
        else {
          tx_led_or_tone_off();
          iVar10 = 0;
          iVar14 = 0;
        }
      }
    }
    else {
      uVar15 = 0;
    }
  }
  else {
    uVar15 = 0;
  }
  return uVar15;
}

