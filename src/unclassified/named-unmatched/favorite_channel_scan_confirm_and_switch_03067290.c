/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: favorite_channel_scan_confirm_and_switch @ 03067290 (file base 0x03000000; code starts at 0x03001000)
 * Size: 480 bytes
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

void favorite_channel_scan_confirm_and_switch(void)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  byte *pbVar6;
  byte *pbVar7;
  byte *pbVar8;
  char *pcVar9;
  char *pcVar10;
  char *pcVar11;
  
  pcVar9 = PTR_DAT_03067340 + 4;
  pbVar6 = PTR_DAT_03067340 + 0xc;
  pbVar7 = PTR_DAT_03067340 + 8;
  pcVar11 = (char *)(PTR_DAT_0306733c + 2);
  pbVar8 = (byte *)(PTR_DAT_0306733c + 0xc);
  pcVar4 = PTR_DAT_03067340;
  pcVar5 = (char *)PTR_DAT_0306733c;
  pcVar10 = pcVar9;
  do {
    if ((byte)pcVar5[0x14] < 0x40) {
      cVar1 = *pcVar4;
      if (cVar1 == '\0') {
        if ((1 < (byte)PTR_DAT_03067344[1]) && (*pcVar5 == PTR_DAT_03067344[2])) {
          if ((pcVar5[0x14] & 0xfU) < 4) {
            *pcVar4 = '\x01';
            *pcVar10 = '\0';
            *pbVar7 = 1;
            *pbVar6 = 0;
          }
          else {
            *pcVar4 = '\x03';
            *pcVar10 = '\0';
            *pbVar7 = 1;
            *pbVar6 = 0;
          }
        }
      }
      else if (cVar1 == '\x01') {
        if (1 < (byte)PTR_DAT_03067344[1]) {
          if (*pcVar5 == PTR_DAT_03067344[2]) {
            bVar2 = *pbVar7;
            *pbVar7 = bVar2 + 1;
            if (1 < (byte)(bVar2 + 1)) {
              *pcVar4 = '\x02';
              *pcVar10 = '\0';
              *pbVar6 = 0;
            }
          }
          else if (*pcVar11 == PTR_DAT_03067344[2]) {
            *pcVar4 = '\x03';
            *pcVar10 = '\0';
            *pbVar6 = 0;
          }
          else {
            bVar2 = *pbVar6;
            *pbVar6 = bVar2 + 1;
            if (1 < (byte)(bVar2 + 1)) {
              *pcVar4 = '\0';
            }
          }
        }
      }
      else if (cVar1 == '\x02') {
        if (1 < *(byte *)(_LAB_0306747c + 1)) {
          if (*pcVar11 == *(char *)(_LAB_0306747c + 2)) {
            *pcVar4 = '\x03';
            *pcVar10 = '\0';
            *pbVar7 = 1;
            *pbVar6 = 0;
          }
          else {
            bVar2 = *pbVar6;
            *pbVar6 = bVar2 + 1;
            if (1 < (byte)(bVar2 + 1)) {
              *pcVar4 = '\0';
            }
          }
        }
      }
      else if (cVar1 == '\x03') {
        *pcVar4 = '\0';
        if (*pbVar8 != 0) {
          if (pbVar8[4] == 0) {
            _LAB_03067480[3] = 1;
          }
          else {
            *_LAB_03067480 = *_LAB_03067480 & 0xef | 0x10;
            *(undefined1 *)(_LAB_03067484 + 5) = *(undefined1 *)(_LAB_03067484 + 4);
          }
          if (*pbVar8 != 1) {
            radio_mode_enter_and_refresh(*(byte *)(_LAB_03067488 + 0x2d) >> 7);
            if (2 < *pbVar8) goto LAB_03067430;
          }
          _LAB_03067480[4] = 0;
          *(byte *)(_LAB_0306748c + 0x15) = *(byte *)(_LAB_0306748c + 0x15) & 0xbf | 0x40;
        }
LAB_03067430:
        iVar3 = get_current_mode_state2();
        if (iVar3 != 0) {
          set_flag_byte_03064328(3);
        }
      }
    }
    pcVar5 = pcVar5 + 1;
    pcVar4 = pcVar4 + 1;
    pcVar10 = pcVar10 + 1;
    pbVar6 = pbVar6 + 1;
    pbVar7 = pbVar7 + 1;
    pcVar11 = pcVar11 + 1;
    pbVar8 = pbVar8 + 1;
    if (pcVar4 == pcVar9) {
      if (1 < *(byte *)(_LAB_0306747c + 1)) {
        *(undefined1 *)(_LAB_0306747c + 1) = 1;
        fd6818b_reg_write(FD6818_PAGE0_REG_3FH,0);
        fd6818b_reg_write(FD6818_PAGE0_REG_3FH,*_LAB_03067490);
      }
      return;
    }
  } while( true );
}

