/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: rf_chip_init_and_spawn_worker_tasks @ 0300d4b0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 152 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rf-frontend
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void rf_chip_init_and_spawn_worker_tasks(void)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_1c [4];
  
  fd6818b_default_register_init();
  fd6818b_dtmf_coefficient_table_load();
  FUN_0301bfcc();
  flash_block6_keyed_field_load();
  flash_block6_read_off0x100_len13();
  block3_tonecall_record_assemble();
  flash_block3_tonecall_cache_load();
  OSSemCreate_shared_name_wrapper(_DAT_0300d548,0);
  iVar1 = _DAT_0300d54c;
  memset_bytes(_DAT_0300d54c,0,0x400);
  iVar2 = iVar1 + 0x400;
  memset_bytes(iVar2,0);
  OSTaskCreate(_DAT_0300d550,_DAT_0300d554,_DAT_0300d558,0,0x23,iVar1,0,0x100,0,0,0,3,auStack_1c);
  OSTaskCreate(_DAT_0300d55c,_DAT_0300d560,_DAT_0300d564,0,10,iVar2,0,0x100,0,0,0,3,auStack_1c);
  return;
}

