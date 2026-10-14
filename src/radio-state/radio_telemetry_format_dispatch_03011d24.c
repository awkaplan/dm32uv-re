/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: radio_telemetry_format_dispatch @ 03011d24 (file base 0x03000000; code starts at 0x03001000)
 * Size: 688 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: radio-state
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void radio_telemetry_format_dispatch(char param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined1 auStack_34 [20];
  char local_20 [4];
  
  local_20[0] = '\0';
  local_20[1] = '\0';
  memset_bytes(auStack_34,0,0x14);
  iVar1 = DAT_030120b8;
  iVar4 = DAT_03011ed8;
  if (param_1 == '\0') {
    if ((*(byte *)PTR_DAT_03011ed4 & 0x40) == 0) {
      memset_bytes(param_2,0,0x14);
    }
    else {
      iVar1 = string_find_nth_comma_index(DAT_03011ed8,3);
      iVar2 = string_find_nth_comma_index(iVar4,4);
      local_20[0] = *(undefined1 *)(iVar4 + iVar2);
      memcpy_bytes_iram(auStack_34,iVar4 + iVar1,iVar2 - iVar1);
      if ((*(byte *)(iVar4 + 0xcb) & 0x40) == 0) {
        format_computed_ratio_as_string(1,auStack_34,param_2);
      }
      else {
        gps_coordinate_seconds_to_hms_string_format(1,auStack_34,param_2);
      }
      strcat(param_2,local_20);
    }
  }
  else if (param_1 == '\x01') {
    if ((*(byte *)PTR_DAT_03011ed4 & 0x40) == 0) {
      memset_bytes(param_2,0,0x14);
    }
    else {
      iVar1 = string_find_nth_comma_index(DAT_03011ed8,5);
      iVar2 = string_find_nth_comma_index(iVar4,6);
      local_20[0] = *(undefined1 *)(iVar4 + iVar2);
      memcpy_bytes_iram(auStack_34,iVar4 + iVar1,iVar2 - iVar1);
      if ((*(byte *)(iVar4 + 0xcb) & 0x40) == 0) {
        format_computed_ratio_as_string(0,auStack_34,param_2);
      }
      else {
        gps_coordinate_seconds_to_hms_string_format(0,auStack_34,param_2);
      }
      strcat(param_2,local_20);
    }
  }
  else if (param_1 == '\x02') {
    if ((*(byte *)PTR_DAT_03011ed4 & 0x40) == 0) {
      memset_bytes(param_2,0,0x14);
    }
    else {
      soft_double_from_int(PTR_DAT_03011ed4[0x6a]);
      soft_double_multiply();
      uVar3 = softdouble_extract_exponent_mantissa();
      decimal_string_pair_to_fixed(uVar3,*PTR_DAT_03011ee0);
      uVar3 = mutex_guarded_call_wrapper();
      number_to_string_format_2args(param_2,PTR_s__dKM_H_03011ee4,uVar3);
    }
  }
  else if (param_1 == '\x03') {
    if ((*(byte *)PTR_DAT_03011ed4 & 0x40) == 0) {
      memset_bytes(param_2,0,0x14);
    }
    else {
      number_to_string_format_2args(param_2,PTR_LAB_03011ee8,(int)(short)PTR_DAT_03011ed4[0x68]);
    }
  }
  else if (param_1 == '\x04') {
    if ((*(byte *)PTR_DAT_03011ed4 & 0x40) == 0) {
      *(undefined1 *)((int)PTR_DAT_03011ed4 + 0xb5) = 0;
    }
    number_to_string_format_2args
              (param_2,DAT_03011eec,*(undefined1 *)((int)PTR_DAT_03011ed4 + 0xb5));
  }
  else if (param_1 == '\x05') {
    if ((*(byte *)PTR_DAT_030120b4 & 0x40) == 0) {
      memset_bytes(param_2,0,0x14);
    }
    else {
      iVar4 = string_find_nth_comma_index(DAT_030120b8,1);
      iVar2 = string_find_nth_comma_index(iVar1,2);
      iVar5 = iVar1 + 0x96;
      memset_bytes(iVar5,0,0xb);
      memcpy_bytes_iram(iVar5,iVar1 + iVar4,iVar2 - iVar4);
      gps_datetime_format(0,iVar1 + 0xa1,iVar5,auStack_34);
      strcpy_ck803s(param_2,auStack_34);
    }
  }
  else if (param_1 == '\x06') {
    if ((*(byte *)PTR_DAT_030120b4 & 0x40) == 0) {
      memset_bytes(param_2,0,0x14);
    }
    else {
      iVar4 = string_find_nth_comma_index(DAT_030120b8,1);
      iVar2 = string_find_nth_comma_index(iVar1,2);
      iVar6 = iVar1 + 0x96;
      memset_bytes(iVar6,0,0xb);
      memcpy_bytes_iram(iVar6,iVar1 + iVar4,iVar2 - iVar4);
      iVar4 = string_find_nth_comma_index(iVar1,9);
      iVar2 = string_find_nth_comma_index(iVar1,10);
      iVar5 = iVar1 + 0xa1;
      memset_bytes(iVar5,0,7);
      memcpy_bytes_iram(iVar5,iVar1 + iVar4,iVar2 - iVar4);
      gps_datetime_format(1,iVar5,iVar6,auStack_34);
      strcpy_ck803s(param_2,auStack_34);
    }
  }
  return;
}

