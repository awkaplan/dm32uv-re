/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: radio_config_tables_init_with_guard @ 03012e84 (file base 0x03000000; code starts at 0x03001000)
 * Size: 196 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: radio-state
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void radio_config_tables_init_with_guard(void)

{
  undefined1 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined1 auStack_18 [4];
  
  puVar1 = PTR_keypad_confirmed_key_cur_03013018;
  *PTR_keypad_confirmed_key_cur_03013018 = 0;
  puVar1[1] = 0;
  puVar2 = PTR_DAT_0301301c;
  *(undefined1 *)PTR_DAT_0301301c = 0;
  *(byte *)((int)puVar2 + 1) = *(byte *)((int)puVar2 + 1) & 0xfe | 1;
  FUN_0301d27c(0x31,1,2);
  FUN_0301d27c(0x32,1,2);
  FUN_0301d27c(0x33,1,2);
  FUN_0301d27c(0x34,1,2);
  FUN_0301d27c(0x2b,1,1);
  critical_section_counted_init_dispatch(_DAT_03013020,_DAT_03013024,5,auStack_18);
  uVar3 = _DAT_03013028;
  memset_bytes(_DAT_03013028,0,0x400);
  OSTaskCreate(_DAT_0301302c,_DAT_03013030,_DAT_03013034,0,8,uVar3,0,0x100,0,0,0,3,auStack_18);
  uVar3 = _DAT_03013038;
  memset_bytes(_DAT_03013038,0,0x300);
  OSTaskCreate(_DAT_0301303c,_DAT_03013040,_DAT_03013044,0,7,uVar3,0,0xc0,0,0,0,3,auStack_18);
  return;
}

