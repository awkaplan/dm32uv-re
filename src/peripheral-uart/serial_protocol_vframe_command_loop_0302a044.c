/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: serial_protocol_vframe_command_loop @ 0302a044 (file base 0x03000000; code starts at 0x03001000)
 * Size: 1042 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: peripheral-uart
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void serial_protocol_vframe_command_loop(void)

{
  byte bVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined *puVar7;
  undefined *puVar8;
  undefined *puVar9;
  byte bVar10;
  uint uVar11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  int iVar14;
  uint unaff_r6;
  uint unaff_r7;
  uint uVar15;
  uint unaff_r11;
  int iStack_28;
  
  puVar4 = PTR_DAT_0302a1bc;
  puVar3 = PTR_DAT_0302a1b8;
  puVar2 = PTR_DAT_0302a1b4;
  uVar15 = 0;
  iVar14 = 0;
  puVar12 = PTR_DAT_0302a1b8 + 3;
  puVar13 = (undefined1 *)(DAT_0302a1c0 + -6);
LAB_0302a072:
  do {
    while( true ) {
      while (iVar14 == 1) {
        uVar11 = (*(code *)(*puVar2 & 0xfffffffe))(puVar3,unaff_r7,1000,&iStack_28);
        if (iStack_28 == 0x72d9) {
          return;
        }
        if (uVar11 != unaff_r7) {
          return;
        }
        if (unaff_r6 == 0x53) {
          if ((unaff_r11 & 0xfff) == 0) {
            serial_flash_sector_erase_then_poll_ready();
          }
          serial_flash_write_chunk_with_retry(unaff_r11,puVar3,uVar11);
        }
        else if (unaff_r6 == 0x43) {
          mutex_guarded_call3_wrapper(0x10c,puVar3,unaff_r7);
        }
        *puVar3 = 6;
        (*(code *)(puVar2[1] & 0xfffffffe))(puVar3,1);
        unaff_r7 = uVar11;
        iVar14 = 0;
      }
      if (iVar14 == 0) break;
      if (iVar14 == 2) {
        if (unaff_r6 == 0x47) {
          mutex_guarded_call_generic3arg(unaff_r11,DAT_0302a3b4,unaff_r7);
          *puVar13 = 0x53;
          (*(code *)(puVar2[1] & 0xfffffffe))(puVar13,unaff_r7 + 6 & 0xffff);
          iVar14 = 0;
        }
        else if (unaff_r6 == 0x56) {
          *puVar3 = 0x56;
          puVar3[1] = (char)uVar15;
          puVar9 = PTR_s_C1_00_01_001_0302a5cc;
          puVar8 = PTR_s_R1_00_01_001_0302a3c8;
          puVar7 = PTR_s_D1_01_01_004_0302a3c4;
          puVar6 = PTR_LAB_0302a3bc;
          puVar5 = PTR_s_DM32_00_01_048_0302a3b8;
          if (uVar15 == 1) {
            bVar10 = strlen_ck803s(PTR_s_DM32_00_01_048_0302a3b8);
            uVar15 = (uint)bVar10;
            puVar3[2] = bVar10;
            memcpy_bytes_iram(puVar12,puVar5,uVar15);
          }
          else if (uVar15 == 3) {
            bVar10 = strlen_ck803s(PTR_LAB_0302a3bc);
            uVar15 = (uint)bVar10;
            puVar3[2] = bVar10;
            memcpy_bytes_iram(puVar12,puVar6,uVar15);
          }
          else if (uVar15 == 2) {
            struct_init_const_wrapper(DAT_0302a3c0);
            puVar4[8] = *puVar4 ^ puVar4[4];
            puVar4[9] = puVar4[1] | puVar4[5];
            puVar4[10] = puVar4[2] ^ puVar4[6];
            puVar4[0xb] = puVar4[3] ^ puVar4[7];
            puVar4[-1] = 0xc;
            uVar15 = 0xc;
          }
          else if (uVar15 == 4) {
            bVar10 = strlen_ck803s(PTR_s_D1_01_01_004_0302a3c4);
            uVar15 = (uint)bVar10;
            puVar3[2] = bVar10;
            memcpy_bytes_iram(puVar12,puVar7,uVar15);
          }
          else if (uVar15 == 5) {
            bVar10 = strlen_ck803s(PTR_s_R1_00_01_001_0302a3c8);
            uVar15 = (uint)bVar10;
            puVar3[2] = bVar10;
            memcpy_bytes_iram(puVar12,puVar8,uVar15);
          }
          else if (uVar15 == 6) {
            puVar3[2] = 8;
            store_u32_le(*(undefined4 *)PTR_LAB_0302a3cc,puVar12);
            store_u32_le(*(undefined4 *)PTR_LAB_0302a3d0,puVar3 + 7);
            uVar15 = 8;
          }
          else if (uVar15 == 7) {
            puVar3[2] = 8;
            store_u32_le(*PTR_DAT_0302a3d4,puVar12);
            store_u32_le(*(undefined4 *)PTR_LAB_0302a3d8,puVar3 + 7);
            uVar15 = 8;
          }
          else if (uVar15 == 8) {
            puVar3[2] = 8;
            store_u32_le(*PTR_DAT_0302a3dc,puVar12);
            store_u32_le(*(undefined4 *)PTR_LAB_0302a3e0,puVar3 + 7);
          }
          else if (uVar15 == 0xe) {
            puVar3[2] = 8;
            store_u32_le(*(undefined4 *)PTR_LAB_0302a3e4,puVar12);
            store_u32_le(*(undefined4 *)PTR_LAB_0302a3e8,puVar3 + 7);
            uVar15 = 8;
          }
          else if (uVar15 == 9) {
            puVar3[2] = 8;
            store_u32_le(*PTR_DAT_0302a3ec,puVar12);
            store_u32_le(*PTR_DAT_0302a3f0,puVar3 + 7);
            uVar15 = 8;
          }
          else if (uVar15 == 10) {
            puVar3[2] = 8;
            store_u32_le(*(undefined4 *)PTR_LAB_0302a3f4,puVar12);
            store_u32_le(*(undefined4 *)PTR_LAB_0302a3f8,puVar3 + 7);
            uVar15 = 8;
          }
          else if (uVar15 == 0xb) {
            bVar10 = strlen_ck803s(PTR_s_C1_00_01_001_0302a5cc);
            uVar15 = (uint)bVar10;
            puVar3[2] = bVar10;
            memcpy_bytes_iram(puVar12,puVar9,uVar15);
          }
          else if (uVar15 == 0xd) {
            bVar10 = puVar3[3];
            uVar15 = (uint)bVar10;
            memcpy_bytes_iram(puVar12,PTR_LAB_0302a5d0 + unaff_r11,uVar15);
            puVar3[2] = bVar10;
          }
          else if (uVar15 == 0xf) {
            puVar3[2] = 8;
            store_u32_le(*PTR_DAT_0302a5d4,puVar12);
            store_u32_le(*(undefined4 *)PTR_LAB_0302a5d8,puVar3 + 7);
            uVar15 = 8;
          }
          else if (uVar15 == 0x10) {
            puVar3[2] = 3;
            puVar3[3] = 0x50;
            puVar3[4] = 0xc3;
            puVar3[5] = 0;
            uVar15 = 3;
          }
          else {
            uVar15 = 0;
          }
          (*(code *)(puVar2[1] & 0xfffffffe))(puVar3,uVar15 + 3);
          iVar14 = 0;
        }
        else {
          iVar14 = 0;
        }
      }
      else if (iVar14 == 3) {
        iVar14 = (*(code *)(*puVar2 & 0xfffffffe))(puVar3,1,500,&iStack_28);
        if (iStack_28 == 0x72d9) {
          return;
        }
        if (iVar14 != 1) {
          return;
        }
        if (*puVar3 != '\x06') {
          return;
        }
        (*(code *)(puVar2[1] & 0xfffffffe))(puVar3,1);
        iVar14 = 0;
      }
    }
    (*(code *)(*puVar2 & 0xfffffffe))(puVar3,5,2000,&iStack_28);
    if (iStack_28 == 0x72d9) {
      return;
    }
    unaff_r6 = (uint)(byte)*puVar3;
    if ((unaff_r6 == 0xff) && (puVar3[1] == -1)) {
      if (((byte)puVar3[2] == 0xff) && (puVar3[3] == -1)) {
        return;
      }
      unaff_r11 = (uint)(byte)puVar3[2] << 8 | 0xff000 | (uint)(byte)puVar3[3];
    }
    else {
      bVar10 = puVar3[1];
      bVar1 = puVar3[2];
      unaff_r11 = (uint)bVar10 << 0xc | (uint)bVar1 << 8 | (uint)(byte)puVar3[3];
      if (unaff_r6 == 0x56) {
        uVar15 = (uint)(byte)puVar3[4];
        if (0x40 < uVar15) {
          return;
        }
        unaff_r7 = uVar15;
        if (uVar15 == 0xd) {
          unaff_r11 = (uint)CONCAT11(bVar10,bVar1);
          iVar14 = 2;
        }
        else {
          if (bVar10 != 0) {
            return;
          }
          if (bVar1 != 0) {
            return;
          }
          if ((byte)puVar3[3] != 0) {
            return;
          }
          iVar14 = 2;
        }
        goto LAB_0302a072;
      }
      if (unaff_r6 == 0x43) {
        iVar14 = 1;
        unaff_r7 = (uint)(byte)puVar3[4];
        goto LAB_0302a072;
      }
    }
    (*(code *)(*puVar2 & 0xfffffffe))(DAT_0302a1c4,1,2000,&iStack_28);
    if (iStack_28 == 0x72d9) {
      return;
    }
    unaff_r6 = (uint)(byte)*puVar3;
    unaff_r7 = (uint)*(ushort *)(puVar3 + 4);
    if (unaff_r6 == 0x53) {
      iVar14 = 1;
    }
    else {
      if (unaff_r6 != 0x47) {
        return;
      }
      iVar14 = 2;
    }
  } while( true );
}

