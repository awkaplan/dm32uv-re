/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: gps_nmea_rmc_gga_sentence_parser @ 03012758 (file base 0x03000000; code starts at 0x03001000)
 * Size: 868 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: gps
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void gps_nmea_rmc_gga_sentence_parser(void)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  short sVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  char cVar8;
  char *pcVar9;
  uint uVar10;
  char cStack_94;
  char cStack_93;
  undefined1 auStack_80 [20];
  undefined1 auStack_6c [20];
  undefined1 auStack_58 [40];
  char acStack_30 [20];
  
  acStack_30[0] = '\0';
  acStack_30[1] = '\0';
  acStack_30[2] = '\0';
  acStack_30[3] = '\0';
  acStack_30[4] = '\0';
  acStack_30[5] = '\0';
  acStack_30[6] = '\0';
  acStack_30[7] = '\0';
  acStack_30[8] = '\0';
  acStack_30[9] = '\0';
  acStack_30[10] = '\0';
  acStack_30[0xb] = '\0';
  acStack_30[0xc] = '\0';
  acStack_30[0xd] = '\0';
  acStack_30[0xe] = '\0';
  acStack_30[0xf] = '\0';
  acStack_30[0x10] = '\0';
  acStack_30[0x11] = '\0';
  acStack_30[0x12] = '\0';
  acStack_30[0x13] = '\0';
  if ((*(char *)((int)PTR_DAT_03012924 + 6) != '\0') && ((*(byte *)PTR_DAT_03012928 & 1) == 0)) {
    os_sem_pend_ms(_DAT_0301292c,0);
    uVar10 = (uint)*(ushort *)PTR_DAT_03012924;
    cVar8 = PTR_DAT_03012930[uVar10];
    if (cVar8 != ',') {
      pcVar9 = acStack_30;
      do {
        *pcVar9 = cVar8;
        uVar10 = uVar10 + 1;
        if (0x3ff < uVar10) {
          uVar10 = 0;
        }
        if (pcVar9 == acStack_30 + 0x13) break;
        cVar8 = PTR_DAT_03012930[uVar10];
        pcVar9 = pcVar9 + 1;
      } while (cVar8 != ',');
    }
    iVar5 = strcmp_byte_ordinal(acStack_30,PTR_s__GPRMC_03012934);
    if (((iVar5 == 0) || (iVar5 = strcmp_byte_ordinal(acStack_30,PTR_s__BDRMC_03012938), iVar5 == 0)
        ) || (iVar5 = strcmp_byte_ordinal(acStack_30,PTR_s__GNRMC_0301293c), iVar5 == 0)) {
      memset_bytes(_DAT_03012940,0,0x96);
      iVar5 = nth_comma_field_offset_lookup(2);
      puVar2 = PTR_DAT_03012930;
      if (PTR_DAT_03012930[iVar5] == 'A') {
        iVar5 = nmea_sentence_checksum_from_ring_buffer(PTR_DAT_03012930);
        iVar6 = star_delimited_two_hex_digit_decode(puVar2);
        puVar2 = PTR_DAT_03012930;
        puVar1 = PTR_DAT_03012924;
        if (iVar5 == iVar6) {
          comma_delimited_field_extractor
                    (PTR_DAT_03012930 + *(ushort *)PTR_DAT_03012924,&cStack_94,4,0x14);
          comma_delimited_field_extractor(puVar2 + *(ushort *)puVar1,auStack_80,5,0x14);
          comma_delimited_field_extractor(puVar2 + *(ushort *)puVar1,auStack_6c,6,0x14);
          comma_delimited_field_extractor(puVar2 + *(ushort *)puVar1,auStack_58,7,0x14);
          iVar5 = _DAT_03012944;
          uVar7 = nmea_latlon_pack_deg_1e5(&cStack_94,_DAT_03012944);
          *(undefined4 *)(iVar5 + -4) = uVar7;
          *(undefined1 *)(iVar5 + 0x1a) = auStack_80[0];
          uVar7 = nmea_latlon_pack_deg_1e5(auStack_6c,iVar5 + 0xc);
          *(undefined4 *)(iVar5 + 8) = uVar7;
          *(undefined1 *)(iVar5 + 0x1b) = auStack_58[0];
          comma_delimited_field_extractor(puVar2 + *(ushort *)puVar1,acStack_30,8,0x14);
          pcVar9 = strchr(acStack_30,0x2e);
          if (pcVar9 == (char *)0x0) {
            PTR_DAT_03012928[0x6a] = 0;
          }
          else {
            strtod_ascii_to_double(acStack_30,0);
            soft_double_multiply();
            sVar4 = soft_double_to_int();
            if (PTR_DAT_03012928[0x6a] != sVar4) {
              PTR_DAT_03012928[0x6a] = sVar4;
            }
          }
          comma_delimited_field_extractor
                    (PTR_DAT_03012930 + *(ushort *)PTR_DAT_03012924,acStack_30,9,0x14);
          pcVar9 = strchr(acStack_30,0x2e);
          if (pcVar9 == (char *)0x0) {
            *(undefined2 *)((int)PTR_DAT_03012ab8 + 0xd2) = 0;
          }
          else {
            strtod_ascii_to_double(acStack_30,0);
            soft_double_multiply();
            sVar4 = soft_double_to_int();
            if (PTR_DAT_03012928[0x69] != sVar4) {
              PTR_DAT_03012928[0x69] = sVar4;
            }
          }
          puVar2 = PTR_DAT_03012ac0;
          uVar10 = (uint)*(ushort *)PTR_DAT_03012abc;
          cVar8 = PTR_DAT_03012ac0[uVar10];
          if (cVar8 == '\n') {
            iVar5 = 0;
          }
          else {
            iVar5 = 0;
            pcVar9 = PTR_PTR_03012ac4;
            do {
              *pcVar9 = cVar8;
              puVar1 = PTR_DAT_03012cfc;
              uVar10 = uVar10 + 1;
              if (0x3ff < uVar10) {
                uVar10 = 0;
              }
              iVar5 = iVar5 + 1;
              if (iVar5 == 0x96) {
                *(undefined1 *)((int)PTR_DAT_03012cfc + 0xa3) = PTR_DAT_03012d00[uVar10];
                memset_bytes((int)puVar1 + 0xd,0,0x96);
                *(byte *)puVar1 = *(byte *)puVar1 & 0xbf;
                goto LAB_030129ca;
              }
              cVar8 = puVar2[uVar10];
              pcVar9 = pcVar9 + 1;
            } while (cVar8 != '\n');
          }
          puVar1 = PTR_DAT_03012ab8;
          *(undefined1 *)((int)PTR_DAT_03012ab8 + iVar5 + 0xd) = PTR_DAT_03012ac0[uVar10];
          *(byte *)puVar1 = *(byte *)puVar1 & 0xbf | 0x40;
          gps_nmea_datetime_to_rtc_sync();
        }
        else {
          *(byte *)PTR_DAT_03012ab8 = *(byte *)PTR_DAT_03012ab8 & 0xbf;
        }
      }
      else {
        *(byte *)PTR_DAT_03012ab8 = *(byte *)PTR_DAT_03012ab8 & 0xbf;
      }
LAB_030129ca:
      if (*(byte *)PTR_DAT_03012ab8 >> 7 != (*(byte *)PTR_DAT_03012ab8 >> 6 & 1)) {
        if (((*(char *)PTR_DAT_03012ac8 == '\0') ||
            ((0x3f < *(byte *)PTR_DAT_03012ac8 && (*(char *)PTR_DAT_03012ac8 != 'p')))) &&
           (((PTR_DAT_03012acc[8] & 1) == 0 && (iVar5 = keypad_dispatch_not_inhibited(), iVar5 != 0)
            ))) {
          display_draw_status_bar();
        }
        *(byte *)PTR_DAT_03012ab8 =
             *(byte *)PTR_DAT_03012ab8 & 0x7f | (*(byte *)PTR_DAT_03012ab8 >> 6) << 7;
      }
    }
    else {
      iVar5 = strcmp_byte_ordinal(acStack_30,PTR_s__GPGGA_03012ad0);
      if (((iVar5 == 0) ||
          (iVar5 = strcmp_byte_ordinal(acStack_30,PTR_s__BDGGA_03012ad4), iVar5 == 0)) ||
         (iVar5 = strcmp_byte_ordinal(acStack_30,PTR_s__GNGGA_03012ad8), iVar5 == 0)) {
        puVar2 = PTR_DAT_03012ac0;
        iVar5 = nmea_sentence_checksum_from_ring_buffer(PTR_DAT_03012ac0);
        iVar6 = star_delimited_two_hex_digit_decode(puVar2);
        puVar2 = PTR_DAT_03012ac0;
        puVar1 = PTR_DAT_03012abc;
        if (iVar5 == iVar6) {
          comma_delimited_field_extractor
                    (PTR_DAT_03012ac0 + *(ushort *)PTR_DAT_03012abc,&cStack_94,8,0x14);
          puVar3 = PTR_DAT_03012ab8;
          *(char *)((int)PTR_DAT_03012ab8 + 0xb5) = cStack_93 + -0x10 + cStack_94 * '\n';
          comma_delimited_field_extractor(puVar2 + *(ushort *)puVar1,acStack_30,10,0x14);
          sVar4 = strtol_signed_wrapper(acStack_30);
          if (*(short *)(puVar3 + 0x34) != sVar4) {
            *(short *)(puVar3 + 0x34) = sVar4;
          }
        }
      }
    }
    serial_rx_ringbuffer_line_extract();
    os_sem_post(_DAT_03012adc);
  }
  return;
}

