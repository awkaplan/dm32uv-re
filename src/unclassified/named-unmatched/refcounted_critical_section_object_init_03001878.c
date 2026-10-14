/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: refcounted_critical_section_object_init @ 03001878 (file base 0x03000000; code starts at 0x03001000)
 * Size: 134 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void refcounted_critical_section_object_init
               (undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  char cVar1;
  undefined4 uVar2;
  
  if (*(char *)PTR_DAT_03001900 == '\0') {
    uVar2 = cpu_sr_save_and_disable_irq_iram();
    func_0x000101f4();
    cVar1 = *(char *)PTR_LAB_03001904;
    *(char *)PTR_LAB_03001904 = cVar1 + '\x01';
    if ((char)(cVar1 + '\x01') == '\x01') {
      FUN_00010b3c();
    }
    irq_lock_release_global_value();
    cpu_sr_restore_irq_iram(uVar2);
    *param_1 = _DAT_03001908;
    param_1[1] = param_2;
    param_1[5] = param_3;
    param_1[6] = 0;
    FUN_00010708(param_1 + 2);
    *(short *)PTR_DAT_0300190c = *(short *)PTR_DAT_0300190c + 1;
    uVar2 = cpu_sr_save_and_disable_irq_iram();
    func_0x000101f4();
    cVar1 = *(char *)PTR_LAB_03001904;
    *(char *)PTR_LAB_03001904 = cVar1 + -1;
    if ((char)(cVar1 + -1) == '\0') {
      FUN_00010b58();
    }
    irq_lock_release_global_value();
    cpu_sr_restore_irq_iram(uVar2);
    *param_4 = 0;
  }
  else {
    *param_4 = 0x2ee1;
  }
  return;
}

