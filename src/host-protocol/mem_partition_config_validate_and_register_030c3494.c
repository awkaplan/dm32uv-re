/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: mem_partition_config_validate_and_register @ 030c3494 (file base 0x03000000; code starts at 0x03001000)
 * Size: 114 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: host-protocol
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void mem_partition_config_validate_and_register(undefined4 *param_1)

{
  *PTR_DAT_030c35ec = 0;
  *PTR_DAT_030c35f0 = 0;
  clear_slot_table_records_variant2();
  if (*(int *)PTR_LAB_030c35f4 == 0) {
    *param_1 = 0x7212;
  }
  else if (*(uint *)PTR_LAB_030c35f8 < *(uint *)PTR_LAB_030c35fc) {
    *param_1 = 0x7213;
  }
  else if ((byte)*PTR_LAB_030c3600 < 0x3f) {
    OSTaskCreate_variant2
              (_DAT_030c3608,_DAT_030c360c,_DAT_030c3610,0,*PTR_LAB_030c3600,
               *(int *)PTR_LAB_030c35f4,*(undefined4 *)PTR_LAB_030c3604,*(uint *)PTR_LAB_030c35f8,0,
               0,0,0xb,param_1);
  }
  else {
    *param_1 = 0x7211;
  }
  return;
}

