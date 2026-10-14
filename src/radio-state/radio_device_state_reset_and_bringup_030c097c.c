/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: radio_device_state_reset_and_bringup @ 030c097c (file base 0x03000000; code starts at 0x03001000)
 * Size: 298 bytes
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

void radio_device_state_reset_and_bringup(int *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  word_buffer_clear_set_end_b();
  *(undefined1 *)PTR_OSIntNestingCtr_030c0aac = 0;
  *(undefined1 *)PTR_DAT_030c0ab0 = 0;
  *(undefined1 *)PTR_OSSchedLockNestingCtr_030c0ab4 = 0;
  *PTR_OSTCBCurPtr_030c0ab8 = 0;
  *PTR_OSTCBHighRdyPtr_030c0abc = 0;
  *(undefined1 *)PTR_DAT_030c0ac0 = 0;
  *(undefined1 *)PTR_OSPrioHighRdy_030c0ac4 = 0;
  *(undefined1 *)PTR_DAT_030c0ac8 = 0;
  *PTR_DAT_030c0acc = 0;
  *PTR_DAT_030c0ad0 = 0;
  *PTR_DAT_030c0ad4 = 0;
  *(undefined1 *)PTR_DAT_030c0ad8 = 0;
  *PTR_DAT_030c0ae0 = (uint)*PTR_LAB_030c0adc / 10;
  puVar3 = (undefined4 *)*_DAT_030c0ae4;
  if (puVar3 != (undefined4 *)0x0) {
    puVar2 = (undefined4 *)*_DAT_030c0ae8;
    puVar1 = puVar2;
    while (puVar1 != (undefined4 *)0x0) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
      puVar3 = (undefined4 *)((int)puVar3 + -1);
      puVar1 = puVar3;
    }
  }
  *PTR_DAT_030c0aec = 0;
  *PTR_DAT_030c0af0 = 0;
  *PTR_DAT_030c0af4 = 0;
  *PTR_DAT_030c0af8 = 0;
  *PTR_DAT_030c0afc = 0;
  *PTR_DAT_030c0b00 = 0;
  *PTR_DAT_030c0b04 = 0;
  *(undefined1 *)PTR_DAT_030c0b08 = 0;
  FUN_030c1600();
  slot_list_table_clear_64();
  func_0x061189a4(param_1);
  if (((((*param_1 == 0) && (func_0x0611914c(param_1), *param_1 == 0)) &&
       (func_0x06119164(param_1), *param_1 == 0)) &&
      ((((func_0x06119d00(param_1), *param_1 == 0 && (func_0x0611a360(param_1), *param_1 == 0)) &&
        ((FUN_030c1bf8(param_1), *param_1 == 0 &&
         ((FUN_030c2790(param_1), *param_1 == 0 &&
          (radio_list_pool_init_and_transact_variant(param_1), *param_1 == 0)))))) &&
       (radio_bringup_mem_partition_0x3f(param_1), *param_1 == 0)))) &&
     (((mem_partition_config_validate_and_register(param_1), *param_1 == 0 &&
       (func_0x0611aa64(param_1), *param_1 == 0)) && (func_0x0611adc4(param_1), *param_1 == 0)))) {
    func_0x061182c0();
    func_0x061182bc();
  }
  return;
}

