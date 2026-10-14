/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: xmodem_ymodem_block_receive_loop @ 03004618 (file base 0x03000000; code starts at 0x03001000)
 * Size: 578 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

uint xmodem_ymodem_block_receive_loop(undefined4 param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  bool bVar3;
  bool bVar4;
  undefined4 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  int iVar8;
  undefined1 *puVar9;
  int iVar10;
  uint uVar11;
  char *pcVar12;
  char *pcVar13;
  char cVar14;
  undefined1 *puVar15;
  uint uVar16;
  uint uVar17;
  byte bStack_29;
  uint uStack_28;
  
  uStack_28 = 0;
  *PTR_keypad_poll_enable_word_030047ac = cpu_sr_restore_irq_inlined_fragment;
  func_0x05ff37a4(0x43);
  iVar8 = _DAT_030047bc;
  puVar7 = PTR_DAT_030047b8;
  puVar6 = PTR_LAB_030047b4;
  puVar5 = PTR_LAB_00012e76_2_030047b0;
  uVar17 = 0;
  bVar3 = false;
  bVar4 = false;
  puVar15 = PTR_LAB_030047b4 + 1;
  do {
    iVar10 = FUN_03004580(&bStack_29,0x100000);
    if (iVar10 != 0) goto LAB_03004870;
    func_0x05ff37a4(0x43);
    if (bStack_29 == 4) {
      *puVar5 = 0;
      bVar3 = true;
    }
    else {
      if (bStack_29 < 5) {
        if (bStack_29 == 1) {
          uVar16 = 0x80;
        }
        else {
          if (bStack_29 != 2) goto LAB_03004870;
          uVar16 = 0x400;
        }
        *puVar6 = bStack_29;
        iVar10 = FUN_0300460c(puVar15,uVar16 + 4,0x100000);
        if ((iVar10 == 0) || (puVar6[1] != (undefined1)~puVar6[2])) {
LAB_03004870:
          *puVar5 = 0xffffffff;
          goto LAB_03004826;
        }
      }
      else {
        if ((bStack_29 == 0x41) || (bStack_29 == 0x61)) {
          *PTR_LAB_00012e76_2_03004918 = 1;
          func_0x05ff37a4(0x18);
          func_0x05ff37a4(0x18);
          return 0xfffffffd;
        }
        if (((bStack_29 != 0x18) || (iVar10 = FUN_03004580(&bStack_29,0x100000), iVar10 != 0)) ||
           (bStack_29 != 0x18)) goto LAB_03004870;
        uVar16 = 0xffffffff;
      }
      *puVar5 = 0;
      if (uVar16 == 0xffffffff) {
        return 0;
      }
      if (uVar16 == 0) {
        bVar3 = true;
      }
      else {
        if ((uint)(byte)puVar6[1] != (uVar17 & 0xff)) {
          return 0;
        }
        if (uVar17 == 0) {
          cVar14 = puVar6[3];
          if (cVar14 == '\0') {
            bVar3 = true;
            bVar4 = true;
          }
          else {
            iVar10 = 0;
            pcVar12 = puVar7;
            do {
              pcVar13 = pcVar12;
              *(char *)(iVar8 + iVar10) = cVar14;
              iVar10 = iVar10 + 1;
              pcVar12 = pcVar13 + 1;
              cVar14 = *pcVar12;
              if (cVar14 == '\0') break;
            } while (iVar10 != 0x100);
            *(undefined1 *)(iVar8 + iVar10) = 0;
            pcVar13 = pcVar13 + 2;
            cVar14 = *pcVar13;
            if (cVar14 == ' ') {
              iVar10 = 0;
            }
            else {
              iVar10 = 0;
              do {
                PTR_LAB_030047c0[iVar10] = cVar14;
                iVar10 = iVar10 + 1;
                pcVar13 = pcVar13 + 1;
                cVar14 = *pcVar13;
                if (cVar14 == ' ') break;
              } while (iVar10 != 0x10);
            }
            puVar9 = PTR_LAB_030047c0;
            PTR_LAB_030047c0[iVar10] = 0;
            parse_numeric_string_hex_or_decimal_with_suffix(puVar9,&uStack_28);
            if (_DAT_030047c4 < uStack_28) {
              func_0x05ff37a4(0x18);
              func_0x05ff37a4(0x18);
              return 0xffffffff;
            }
            flash_erase_firmware_region_locked();
            func_0x05ff37a4(6);
            func_0x05ff37a4(0x43);
          }
        }
        else {
          libc_memcpy_bytes(param_1,puVar7,uVar16);
          uVar11 = func_0x05ff3758(puVar7,uVar16 & 0xffff);
          uVar1 = puVar7[uVar16];
          uVar2 = puVar7[uVar16 + 1];
          if (*(char *)(puVar5 + 1) == '\0') {
            *(undefined1 *)(puVar5 + 1) = 1;
            gpio_set_output_bit_variant2(0x20);
          }
          else {
            *(undefined1 *)(puVar5 + 1) = 0;
            gpio_clear_output_bit_variant2(0x20);
          }
          if (uVar11 != CONCAT11(uVar1,uVar2)) {
            func_0x05ff37a4(0x18);
            func_0x05ff37a4(0x18);
            return 0xfffffffe;
          }
          iVar10 = ymodem_flash_block_program(_DAT_03004914,param_1,uVar16);
          if (iVar10 != 0) {
            func_0x05ff37a4(0x18);
            func_0x05ff37a4(0x18);
            return 0xfffffffe;
          }
          func_0x05ff37a4(6);
        }
        uVar17 = uVar17 + 1;
      }
    }
LAB_03004826:
    if (bVar3) {
      func_0x05ff374c();
      if (bVar4) {
        return uStack_28;
      }
      uVar17 = 0;
      bVar3 = false;
    }
  } while( true );
}

