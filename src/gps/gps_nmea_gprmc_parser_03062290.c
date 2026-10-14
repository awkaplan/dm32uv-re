/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: gps_nmea_gprmc_parser @ 03062290 (file base 0x03000000; code starts at 0x03001000)
 * Size: 594 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: gps
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void gps_nmea_gprmc_parser(char param_1,undefined4 param_2)

{
  undefined1 *puVar1;
  int iVar2;
  undefined1 uVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  undefined *puVar9;
  uint uVar10;
  byte *pbVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  byte *pbVar15;
  byte local_3c [16];
  uint local_2c;
  undefined *puStack_28;
  
  os_sem_pend_ms(p_ucos_mutex_00038d48,0);
  memset_bytes(PTR_DAT_03062498,0,0x96);
  memset_bytes(local_3c,0,0x10);
  if (((*(byte *)PTR_DAT_0306249c & 0x40) != 0) || ((*(byte *)PTR_DAT_030624a0 & 4) != 0)) {
    p_radio_mode_state_0003e318[1].flags_0x6 =
         p_radio_mode_state_0003e318[1].flags_0x6 & 0x7f | 0x80;
    uVar5 = DAT_0306262c;
    puVar1 = PTR_DAT_03062498;
    if ((*(byte *)PTR_DAT_030624a0 & 4) == 0) {
      uVar3 = strlen_ck803s(DAT_0306262c);
      uVar7 = DAT_03062630;
      memcpy_bytes_iram(DAT_03062630,uVar5,uVar3);
      memcpy_bytes_iram(uVar7,PTR_s__GPRMC_03062634,6);
    }
    else {
      puVar9 = PTR_s__GPRMC_072431_000_A_2452_4974_N__030624a8;
      memcpy_bytes_iram(PTR_DAT_03062498,PTR_s__GPRMC_072431_000_A_2452_4974_N__030624a8,0x46);
      local_2c = rtc_decode_calendar_date();
      uVar4 = local_2c & 0xff;
      uVar12 = local_2c >> 8 & 0xff;
      uVar13 = local_2c >> 0x10 & 0xff;
      uVar10 = (uint)puVar9 >> 8 & 0xff;
      uVar14 = ((uint)puVar9 >> 0x10) % 100;
      puStack_28 = puVar9;
      gps_time_compact_format(0,uVar4,uVar12,uVar13,(uint)puVar9 & 0xff,uVar10,uVar14,local_3c);
      pbVar15 = local_3c;
      memcpy_bytes_iram(puVar1 + 7,local_3c,6);
      iVar2 = DAT_030624ac;
      uVar5 = strtod(DAT_030624ac);
      pbVar11 = pbVar15;
      iVar6 = softdouble_to_int32();
      uVar7 = soft_double_from_int();
      soft_double_sub(uVar5,pbVar15,uVar7,pbVar11);
      soft_double_multiply();
      iVar8 = soft_double_to_int();
      uVar5 = float32_pack_const_two((uint)(iVar8 * 6) / 10 + iVar6 * 1000000);
      uVar7 = *PTR_DAT_030624b4;
      decimal_string_pair_to_fixed(uVar5,uVar7);
      uVar5 = float32_unpack_then_softdouble_pack_round_wrapper();
      number_to_string_format_2args(local_3c,PTR_s__04_4f_030624b8,uVar5,uVar7);
      pbVar15 = local_3c;
      memcpy_bytes_iram(puVar1 + 0x14,local_3c,9);
      puVar1[0x1e] = *(undefined1 *)(iVar2 + 9);
      uVar5 = strtod(iVar2 + 10);
      pbVar11 = pbVar15;
      iVar6 = softdouble_to_int32();
      uVar7 = soft_double_from_int();
      soft_double_sub(uVar5,pbVar15,uVar7,pbVar11);
      soft_double_multiply();
      iVar8 = soft_double_to_int();
      uVar5 = float32_pack_const_two((uint)(iVar8 * 6) / 10 + iVar6 * 1000000);
      uVar7 = *PTR_DAT_030624b4;
      decimal_string_pair_to_fixed(uVar5,uVar7);
      uVar5 = float32_unpack_then_softdouble_pack_round_wrapper();
      number_to_string_format_2args(local_3c,PTR_s__05_4f_030624bc,uVar5,uVar7);
      memcpy_bytes_iram(puVar1 + 0x20,local_3c,10);
      puVar1[0x2b] = *(undefined1 *)(iVar2 + 0x13);
      gps_time_compact_format(1,uVar4,uVar12,uVar13,(uint)puVar9 & 0xff,uVar10,uVar14,local_3c);
      memcpy_bytes_iram(puVar1 + 0x37,local_3c,6);
      pbVar15 = puVar1 + 1;
      local_3c[0] = 0;
      do {
        local_3c[0] = local_3c[0] ^ *pbVar15;
        pbVar15 = pbVar15 + 1;
      } while (pbVar15 != puVar1 + 0x41);
      PTR_DAT_03062498[0x42] = local_3c[0];
      uVar3 = 0x41;
    }
    if (param_1 == '\0') {
      channel_select_input_gate(3,param_2,DAT_03062630,uVar3,0);
    }
    else {
      channel_select_input_gate(4,param_2,DAT_03062630,uVar3,0);
    }
  }
  os_sem_post(p_ucos_mutex_00038d48);
  return;
}

