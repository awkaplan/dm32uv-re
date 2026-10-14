/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: hr_c7000_bringup_sequence @ 03004474 (file base 0x03000000; code starts at 0x03001000)
 * Size: 80 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void hr_c7000_bringup_sequence(void)

{
  undefined4 uVar1;
  undefined1 auStack_10 [4];
  
  hr_c7000_modem_core_reset_and_poll_ready();
  func_0x05ff3a88();
  radio_device_state_reset_and_bringup_variant(auStack_10);
  uVar1 = _DAT_030044e0;
  libc_memset_bytes(_DAT_030044e0,0,0x2000);
  protocol_request_struct_build_and_dispatch
            (_DAT_030044e4,_DAT_030044e8,_DAT_030044ec,0,5,uVar1,0,0x800,0,0,0,0,auStack_10);
  lazy_device_descriptor_init_once(auStack_10);
  return;
}

