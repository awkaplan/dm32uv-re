/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: uart_rx_frame_assemble_polarity_correct @ 03067978 (file base 0x03000000; code starts at 0x03001000)
 * Size: 362 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: peripheral-uart
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void uart_rx_frame_assemble_polarity_correct(uint param_1)

{
  bool bVar1;
  undefined4 *puVar2;
  ushort uVar3;
  uint uVar4;
  byte *pbVar5;
  uint uVar6;
  int iVar7;
  byte bVar8;
  uint uVar9;
  byte *pbVar10;
  uint uVar11;
  uint uVar12;
  byte *pbVar13;
  int iVar14;
  
  uVar4 = fd6818_reg_read(FD6818_PAGE0_REG_0BH);
  uVar3 = fd6818_reg_read(FD6818_PAGE0_REG_59H);
  puVar2 = PTR_DAT_03067af4;
  uVar3 = uVar3 & 0x27ff;
  bVar1 = (uVar4 & 0x80) != 0;
  if ((param_1 & 2) != 0) {
    *PTR_DAT_03067af4 = 0;
    iVar7 = DAT_03067af8;
    memset_bytes(DAT_03067af8,0,0x13);
    iVar14 = *puVar2;
    pbVar13 = (byte *)(iVar7 + iVar14);
    pbVar5 = PTR_DAT_03067afc + 5;
    pbVar10 = PTR_DAT_03067afc;
    do {
      if (bVar1) {
        bVar8 = 0xff;
      }
      else {
        bVar8 = 0;
      }
      *pbVar13 = *pbVar10 ^ bVar8;
      pbVar10 = pbVar10 + 1;
      pbVar13 = pbVar13 + 1;
    } while (pbVar10 != pbVar5);
    *PTR_DAT_03067af4 = iVar14 + 5;
  }
  if ((param_1 & 0x1000) != 0) {
    uVar4 = fd6818_reg_read(FD6818_PAGE0_REG_5EH);
    iVar7 = DAT_03067af8;
    puVar2 = PTR_DAT_03067af4;
    if ((uVar4 & 7) != 0) {
      uVar12 = 0;
      do {
        uVar6 = fd6818_reg_read(FD6818_PAGE0_REG_5FH);
        if (bVar1) {
          uVar9 = 0xffff;
        }
        else {
          uVar9 = 0;
        }
        uVar11 = *puVar2;
        if (uVar11 < 0x13) {
          uVar6 = (uVar6 ^ uVar9) & 0xffff;
          *(char *)(iVar7 + uVar11) = (char)uVar6;
          uVar9 = uVar11 + 1;
          *puVar2 = uVar9;
          if (uVar9 < 0x13) {
            *(char *)(iVar7 + uVar9) = (char)(uVar6 >> 8);
            *puVar2 = uVar11 + 2;
          }
        }
        uVar12 = uVar12 + 1;
      } while (uVar12 < (uVar4 & 7));
    }
    if (0x12 < (uint)*PTR_DAT_03067af4) {
      fd6818b_reg_write(FD6818_PAGE0_REG_59H,uVar3 | 0xc000);
      fd6818b_reg_write(FD6818_PAGE0_REG_59H,uVar3 | 0x1000);
      iVar7 = fsk_diff_decode_dmr_sync_frame
                        (DAT_03067af8,*PTR_DAT_03067af4,PTR_DAT_03067b04,PTR_DAT_03067b08,
                         DAT_03067b00);
      if (iVar7 != 0) {
        *(undefined1 *)PTR_DAT_03067b0c = 10;
        if ((CONCAT11(*(undefined1 *)PTR_DAT_03067b04,*(undefined1 *)PTR_DAT_03067b08) == 0x180) ||
           (CONCAT11(*(undefined1 *)PTR_DAT_03067b04,*(undefined1 *)PTR_DAT_03067b08) == 0x100)) {
          p_radio_mode_state_0003e318[2].field_0x1 =
               p_radio_mode_state_0003e318[2].field_0x1 & 0xbf | 0x40;
        }
        PTR_DAT_03067b14[4] = 0;
      }
      *PTR_DAT_03067af4 = 0;
    }
  }
  if ((param_1 & 0x2000) != 0) {
    *PTR_DAT_03067af4 = 0;
    fd6818b_reg_write(FD6818_PAGE0_REG_59H,uVar3 | 0xc000);
    fd6818b_reg_write(FD6818_PAGE0_REG_59H,uVar3 | 0x1000);
  }
  return;
}

