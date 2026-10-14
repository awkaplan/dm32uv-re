/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: protocol_request_validate_and_dispatch @ 03003768 (file base 0x03000000; code starts at 0x03001000)
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

void protocol_request_validate_and_dispatch(undefined4 *param_1)

{
  *PTR_DAT_030037dc = 0;
  *PTR_DAT_030037e0 = 0;
  clear_slot_table_records();
  if (*(int *)PTR_LAB_030037e4 == 0) {
    *param_1 = 0x7212;
  }
  else if (*(uint *)PTR_LAB_030037e8 < *(uint *)PTR_LAB_030037ec) {
    *param_1 = 0x7213;
  }
  else if ((byte)*PTR_LAB_030037f0 < 7) {
    protocol_request_struct_build_and_dispatch
              (_DAT_030037f8,_DAT_030037fc,_DAT_03003800,0,*PTR_LAB_030037f0,
               *(int *)PTR_LAB_030037e4,*(undefined4 *)PTR_LAB_030037f4,*(uint *)PTR_LAB_030037e8,0,
               0,0,0xb,param_1);
  }
  else {
    *param_1 = 0x7211;
  }
  return;
}

