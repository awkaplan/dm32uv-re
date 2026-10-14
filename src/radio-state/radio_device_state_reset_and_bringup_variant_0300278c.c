/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: radio_device_state_reset_and_bringup_variant @ 0300278c (file base 0x03000000; code starts at 0x03001000)
 * Size: 188 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: radio-state
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void radio_device_state_reset_and_bringup_variant(int *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  word_buffer_clear_set_end_a();
  *(undefined1 *)PTR_DAT_03002848 = 0;
  *(undefined1 *)PTR_LAB_00016d4c_1_0300284c = 0;
  *(undefined1 *)PTR_LAB_03002850 = 0;
  *PTR_DAT_03002854 = 0;
  *PTR_DAT_03002858 = 0;
  *(undefined1 *)PTR_LAB_00016db4_1_0300285c = 0;
  *(undefined1 *)PTR_LAB_03002860 = 0;
  *(undefined1 *)PTR_DAT_03002864 = 0;
  *PTR_DAT_03002868 = 0;
  *PTR_DAT_0300286c = 0;
  *PTR_DAT_03002870 = 0;
  *(undefined1 *)PTR_DAT_03002874 = 0;
  *PTR_DAT_0300287c = (uint)*PTR_LAB_03002878 / 10;
  puVar3 = (undefined4 *)*_DAT_03002880;
  if (puVar3 != (undefined4 *)0x0) {
    puVar2 = (undefined4 *)*_DAT_03002884;
    puVar1 = puVar2;
    while (puVar1 != (undefined4 *)0x0) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
      puVar3 = (undefined4 *)((int)puVar3 + -1);
      puVar1 = puVar3;
    }
  }
  FUN_03002fbc();
  slot_list_table_clear_8();
  func_0x05ff3858(param_1);
  if ((((*param_1 == 0) && (FUN_0300303c(param_1), *param_1 == 0)) &&
      (FUN_0300327c(param_1), *param_1 == 0)) &&
     (((radio_list_pool_init_and_transact(param_1), *param_1 == 0 &&
       (radio_bringup_protocol_request_0x0b(param_1), *param_1 == 0)) &&
      (protocol_request_validate_and_dispatch(param_1), *param_1 == 0)))) {
    func_0x05ff37bc();
  }
  return;
}

